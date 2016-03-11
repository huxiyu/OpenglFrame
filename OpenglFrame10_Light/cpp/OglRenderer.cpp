/************************************************************************/
/*                                                                      */
/************************************************************************/

#include "OglRenderer.h"

#include <QOpenGLFramebufferObjectFormat>
#include <QOpenGLFunctions>
#include <gl/glu.h>
#include <QVector>
#include <QtMath>

//#include <math.h>
/************************************************************************/
/*                                                                      */
/************************************************************************/

COglRenderer::COglRenderer()
{
    //    m_oglFBO = NULL;

    globalAmbient[0] = 0.0f;
    globalAmbient[1] = 0.0f;
    globalAmbient[2] = 0.0f;
    globalAmbient[3] = 1.0f;

    enableColorMatrial = true;

    matrialAmbientDiffuse[0] = 1.0f;
    matrialAmbientDiffuse[1] = 1.0f;
    matrialAmbientDiffuse[2] = 1.0f;
    matrialAmbientDiffuse[3] = 1.0f;

    matrialSpecular[0] = 1.0f;
    matrialSpecular[1] = 1.0f;
    matrialSpecular[2] = 1.0f;
    matrialSpecular[3] = 1.0f;


    enableLight0 = false;
    light0Ambient[0] = 0.0f;
    light0Ambient[1] = 0.0f;
    light0Ambient[2] = 0.0f;
    light0Ambient[3] = 1.0f;

    light0Diffuse[0] = 0.0f;
    light0Diffuse[1] = 0.0f;
    light0Diffuse[2] = 0.0f;
    light0Diffuse[3] = 1.0f;

    light0Specular[0] = 0.0f;
    light0Specular[1] = 0.0f;
    light0Specular[2] = 0.0f;
    light0Specular[3] = 1.0f;

    light0Pos[0] = 0.0f;
    light0Pos[1] = 0.0f;
    light0Pos[2] = 10.0f;
    light0Pos[3] = 1.0f; //1.0表示光源就在此地
}

COglRenderer::~COglRenderer()
{
}
/************************************************************************/
/*                                                                      */
/************************************************************************/

float r = 0.5f;
float yrotate = 0.0f;
float xrotate = 0.0f;

/************************************************************************/
/*                                                                      */
/************************************************************************/

// render model
void COglRenderer::render()
{
    // 设置上下文（QT的设置方式）
    QOpenGLFunctions glFuncs(QOpenGLContext::currentContext());
    glFuncs.glUseProgram(0);

    // 启用顶点缓冲区
    glEnableClientState(GL_VERTEX_ARRAY);
    //    glEnableClientState(GL_COLOR_ARRAY);
    glEnable(GL_DEPTH_TEST);

    // 设置清屏色
    glClearColor(0.0f, 0.352f, 1.0f, 1.0f);

    // 清除颜色缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 操作投影矩阵，设置透视投影
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double ratio = (double)m_ViewportWidth/(double)m_ViewportHeight;
    gluPerspective(45.0, ratio, 0.1, 100.0);

    // 操作模型视图矩阵，设置视点
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,     0.0, 0.0, 0.0,     0.0, 1.0, 0.0);

    // 旋转
    glRotatef(xrotate, 1.0f, 0.0f, 0.0f);
    glRotatef(yrotate, 0.0f, 1.0f, 0.0f);

    // 设置着色模式
    //    glShadeModel(GL_FLAT);
    glShadeModel(GL_SMOOTH);

    /***************************  光照 ********************************/
    //开启光照
    glEnable(GL_LIGHTING);

    // 设置全局环境光
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    // 1.第一种设置材料的反射率
    //    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matrialAmbientDiffuse);

    // 2.第二种设置材料的反射率，颜色追踪
    // 是否启用颜色追踪
    if( enableColorMatrial )
    {
        glEnable(GL_COLOR_MATERIAL);
    } else {
        glDisable(GL_COLOR_MATERIAL);
    }
    // 设置材料属性，对应于glColor值
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // 此后，所有的材料都具有完全的强光泽的镜面反射
    glMaterialfv(GL_FRONT, GL_SPECULAR, matrialSpecular);
    glMateriali(GL_FRONT, GL_SHININESS, 128);

    glColor4f(matrialAmbientDiffuse[0], matrialAmbientDiffuse[1], matrialAmbientDiffuse[2], 1.0f);

    /*********************光源*************************/
    // 光源0 环境光
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
    // 光源0 散射光
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
    // 光源0 镜面光
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
    // 光源0 位置
    glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);

    // 特定的光点效果
    // 切角为60
//    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60.0f);


    // 是否启用Light0
    if (enableLight0)
    {
        glEnable(GL_LIGHT0);
    } else {
        glDisable(GL_LIGHT0);
    }

    glEnable(GL_NORMALIZE);

    //绘制正方形
    drawRect();

    // 绘制球体
    drawSphere(1.5f, 20, 20);

    update();

    // 旋转变量增加
    //    xrotate += 0.1f;
    //    yrotate += 0.1f;
}


void COglRenderer::drawRect()
{

    // 计算点坐标
    float vertexArr[24] = {
        -r,-r,r, //0
        -r,r,r,  //1
        r,r,r, //2
        r,-r,r, //3
        -r,-r,-r, //4
        -r,r,-r,  //5
        r,r,-r, //6
        r,-r,-r, //7
    };

    short indexArr[29] = {
        0,1,2,3,
        0,4,5,6,
        7,4,0,1,
        5,4,7,6,
        2,3,7,6,
        2,1,5,6,
        7,3,0,4,7
    };

    // 设置绘图颜色
//    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);

    // 启用顶点缓冲区
    //    glEnableClientState(GL_VERTEX_ARRAY);

    // 指定顶点缓冲区指针
    glVertexPointer(3, GL_FLOAT, 0, vertexArr);

    // 绘制三角形
    glDrawElements(GL_LINE_STRIP, 29, GL_UNSIGNED_SHORT, indexArr);

    // 关闭顶点缓冲区
    //    glDisableClientState(GL_VERTEX_ARRAY);

}


void COglRenderer::drawSphere(float r, int stack, int slice)
{
    QVector<float> vertexList(0);
    for (float alpha = (float) (M_PI); alpha >= 0; alpha = (float) (alpha - (M_PI / stack)))
    {
        float y0 = (float) (r * qCos(alpha));
        float y1 = (float) (r * qCos(alpha - (M_PI / stack)));
        float r0 = (float) (r * qSin(alpha));
        float r1 = (float) (r * qSin(alpha - (M_PI / stack)));
        // 纬度
        for (int j = 0; j < 2 * slice; j++) {
            float theta0 = (float) (-M_PI + ((M_PI / slice) * j));
            float theta1 = (float) (-M_PI + ((M_PI / slice) * (j + 1)));

            // 0
            vertexList.append((float) (r0 * qCos(theta0)));// x
            vertexList.append(y0);// y
            vertexList.append(-(float) (r0 * qSin(theta0)));// z
            // 1
            vertexList.append((float) (r1 * qCos(theta0)));
            vertexList.append(y1);
            vertexList.append((float) (-r1 * qSin(theta0)));
            // 2
            vertexList.append((float) (r0 * qCos(theta1)));
            vertexList.append(y0);
            vertexList.append((float) (-r0 * qSin(theta1)));
            // 3
            vertexList.append((float) (r1 * qCos(theta1)));
            vertexList.append(y1);
            vertexList.append((float) (-r1 * qSin(theta1)));
        }
    }

    // 指定顶点缓冲区指针
    glVertexPointer(3, GL_FLOAT, 0, vertexList.data());

    // 绘制三角形
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexList.size() / 3);

    // 关闭顶点缓冲区
    //    glDisableClientState(GL_VERTEX_ARRAY);
}


/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglRenderer::resize(int width, int height)
{
    m_ViewportWidth = width;
    m_ViewportHeight = height;
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

QOpenGLFramebufferObject* COglRenderer::createFramebufferObject(const QSize &size)
{
    // create opengl FBO
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    format.setSamples(4);
    m_oglFBO = new QOpenGLFramebufferObject(size, format);

    // return opengl FBO
    return m_oglFBO;
}


