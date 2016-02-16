/************************************************************************/
/*                                                                      */
/************************************************************************/

#include "OglContainer.h"
#include <QDebug>

/************************************************************************/
/*                                                                      */
/************************************************************************/

// container renderer
COglRenderer* g_renderer = NULL;

/************************************************************************/
/*                                                                      */
/************************************************************************/

COglContainer::COglContainer()
{
    //    setAntialiasing(true);
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

COglContainer::~COglContainer()
{

}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::globalAmbientR(float v)
{
    if (g_renderer != NULL)
    {
        qDebug("globalAmbientR = %f", v);
        g_renderer->globalAmbient[0] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::globalAmbientG(float v)
{
    if (g_renderer != NULL)
    {
        qDebug("globalAmbientG = %f", v);
        g_renderer->globalAmbient[1] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::globalAmbientB(float v)
{
    if (g_renderer != NULL)
    {
        qDebug("globalAmbientB = %f", v);
        g_renderer->globalAmbient[2] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::matrialAmbientDiffuseR(float v)
{
    if (g_renderer != NULL)
    {
        qDebug("matrialAmbientDiffuseR = %f", v);
        g_renderer->matrialAmbientDiffuse[0] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::matrialAmbientDiffuseG(float v)
{
    if (g_renderer != NULL)
    {
        qDebug("matrialAmbientDiffuseG = %f", v);
        g_renderer->matrialAmbientDiffuse[1] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::matrialAmbientDiffuseB(float v)
{
    if (g_renderer != NULL)
    {
        qDebug("matrialAmbientDiffuseB = %f", v);
        g_renderer->matrialAmbientDiffuse[2] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
void COglContainer::enableLight0(bool v)
{
    if (g_renderer != NULL)
    {
        g_renderer->enableLight0 = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::light0AmbientR(float v)
{
    if (g_renderer != NULL)
    {
        g_renderer->light0Ambient[0] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::light0AmbientG(float v)
{
    if (g_renderer != NULL)
    {
        g_renderer->light0Ambient[1] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::light0AmbientB(float v)
{
    if (g_renderer != NULL)
    {
        g_renderer->light0Ambient[2] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::light0DiffuseR(float v)
{
    if (g_renderer != NULL)
    {
        g_renderer->light0Diffuse[0] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::light0DiffuseG(float v)
{
    if (g_renderer != NULL)
    {
        g_renderer->light0Diffuse[1] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::light0DiffuseB(float v)
{
    if (g_renderer != NULL)
    {
        g_renderer->light0Diffuse[2] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::light0PosX(float v)
{
    if (g_renderer != NULL)
    {
        g_renderer->light0Pos[0] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::light0PosY(float v)
{
    if (g_renderer != NULL)
    {
        g_renderer->light0Pos[1] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::light0PosZ(float v)
{
    if (g_renderer != NULL)
    {
        g_renderer->light0Pos[2] = v;
    }
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

QQuickFramebufferObject::Renderer* COglContainer::createRenderer() const
{
    // create render
    g_renderer = new COglRenderer();
    g_renderer->resize(m_viewPortWidth, m_viewPortHeight);

    return g_renderer;
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::setViewPortWidth(const int &viewPortWidth)
{
    m_viewPortWidth = viewPortWidth;
    if (g_renderer != NULL)
    {
        g_renderer->m_ViewportWidth = m_viewPortWidth;
    }
    emit viewPortWidthChanged();
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

void COglContainer::setViewPortHeight(const int &viewPortHeight)
{
    m_viewPortHeight = viewPortHeight;
    if (g_renderer != NULL)
    {
        g_renderer->m_ViewportHeight = m_viewPortHeight;
    }
    emit viewPortHeightChanged();
}
