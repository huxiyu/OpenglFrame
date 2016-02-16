/************************************************************************/
/*                                                                      */
/************************************************************************/

#include "OglContainer.h"

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
