/************************************************************************/
/*                                                                      */
/************************************************************************/

#include "OglRenderer.h"

#include <QOpenGLFramebufferObjectFormat>
#include <QOpenGLFunctions>
#include <gl/glu.h>

/************************************************************************/
/*                                                                      */
/************************************************************************/

COglRenderer::COglRenderer()
{
//    m_oglFBO = NULL;
}

COglRenderer::~COglRenderer()
{
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

/************************************************************************/
/*                                                                      */
/************************************************************************/

// render model
void COglRenderer::render()
{
//    QCoreApplication::processEvents();
    QOpenGLFunctions glFuncs(QOpenGLContext::currentContext());
    glFuncs.glUseProgram(0);

    // 设置清屏色
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double ratio = (double)m_ViewportWidth/(double)m_ViewportHeight;
    //    glFrustum(-1.0, 1.0, -ratio, ratio, 3, 7);
    gluPerspective(45.0, ratio, 0.1,100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
                0.0, 0.0, 5.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0
                );

    // 画三角形
    // 绘制数组
    // 三角形坐标
    float coords[9] = {
        0.0f, 1.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f
    };

    // 启用顶点缓冲区
    glEnableClientState(GL_VERTEX_ARRAY);

    // 指定顶点缓冲区指针
    glVertexPointer(3, GL_FLOAT, 0, coords);

    // 绘制三角形
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // 关闭顶点缓冲区
    glDisableClientState(GL_VERTEX_ARRAY);


    update();

    //    SYSTEMTIME sys_time;
    //    GetLocalTime( &sys_time );
    //    static float time1 = 0;
    //    static float time2 = 0;
    //    static int fps = 0;
    //    qsrand(uint(sys_time.wMilliseconds));
    //    if (time1 == 0)
    //    {
    //        time1 = sys_time.wMinute * 60 + sys_time.wSecond + sys_time.wMilliseconds * 0.001f;
    //        fps = 0;
    //    }
    //    fps ++;
    //    if (fps >= 60)
    //    {
    //        time2 = sys_time.wMinute * 60 + sys_time.wSecond + sys_time.wMilliseconds * 0.001f;
    //        while (time2 < time1)
    //        {
    //            time2 += 3600;
    //        }
    //        float t = time2 - time1;
    //        time1 = 0;
    //        if (t < 0.00001f){t = 0.0001f;}
    //        m_fps = float(int(60.0 / t));
    //        //        qDebug("%f",m_fps);
    //    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglRenderer::resize(int width, int height)
{
    m_ViewportWidth = width;
    m_ViewportHeight = height;
}



