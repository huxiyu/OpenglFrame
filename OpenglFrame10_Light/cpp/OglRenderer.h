/************************************************************************/
/*                                                                      */
/************************************************************************/

#ifndef OGLRENDERER_H
#define OGLRENDERER_H

/************************************************************************/
/*                                                                      */
/************************************************************************/

#include <QQuickFramebufferObject>

class COglRenderer : public QQuickFramebufferObject::Renderer
{
public:
    COglRenderer();
    ~COglRenderer();

public:
    QOpenGLFramebufferObject* m_oglFBO;
    QOpenGLFramebufferObject* createFramebufferObject(const QSize &size);

    // render model
    void render();

public:
    void drawRect();
    void drawSphere(float r, int stack, int slice);

public:
    // view port width
    int m_ViewportWidth;
    // view port height
    int m_ViewportHeight;
    float m_fps;
    // update view port
    void resize(int width, int height);

    // 光照变量
public:
    // 全局环境光
    float globalAmbient[4];
    //材料的反射率（环境光和散射光）
    float matrialAmbientDiffuse[4];
    //材料的反射率（镜面光）
    float matrialSpecular[4];
    // 是否启用颜色追踪
    bool enableColorMatrial;

    // 是否启用光源0
    bool enableLight0;
    // 光源0 环境光
    float light0Ambient[4];
    // 光源0 散射光
    float light0Diffuse[4];
    // 光源0 镜面光
    float light0Specular[4];
    // 光源0 位置
    float light0Pos[4];
};

/************************************************************************/
/*                                                                      */
/************************************************************************/

#endif

/************************************************************************/
/*                                                                      */
/************************************************************************/
