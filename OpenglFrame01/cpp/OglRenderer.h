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
    // view port width
    int m_ViewportWidth;
    // view port height
    int m_ViewportHeight;
    float m_fps;
    // update view port
    void resize(int width, int height);
};

/************************************************************************/
/*                                                                      */
/************************************************************************/

#endif

/************************************************************************/
/*                                                                      */
/************************************************************************/
