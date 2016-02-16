/************************************************************************/
/*                                                                      */
/************************************************************************/

#ifndef OGLCONTAINER_H
#define OGLCONTAINER_H

/************************************************************************/
/*                                                                      */
/************************************************************************/
#include "OglRenderer.h"
#include <QQuickFramebufferObject>


/************************************************************************/
/*                                                                      */
/************************************************************************/

class COglContainer : public QQuickFramebufferObject
{
    Q_OBJECT

public:
    Q_PROPERTY(int viewPortWidth READ getViewPortWidth WRITE setViewPortWidth NOTIFY viewPortWidthChanged)
    Q_PROPERTY(int viewPortHeight READ getViewPortHeight WRITE setViewPortHeight NOTIFY viewPortHeightChanged)

public:
    COglContainer();
    ~COglContainer();

public:
    // create render in container
    Renderer *createRenderer() const;

public:
    // view port width
    int m_viewPortWidth;
    // view port height
    int m_viewPortHeight;
    // get view port width
    int getViewPortWidth() const {return m_viewPortWidth;}
    // set view port width
    void setViewPortWidth( const int &viewPortWidth);
    // get view port height
    int getViewPortHeight() const {return m_viewPortHeight;}
    // set view port height
    void setViewPortHeight( const int &viewPortHeight);

signals:
    // notify when view change
    void viewPortWidthChanged();
    // notify when view change
    void viewPortHeightChanged();

};

/************************************************************************/
/*                                                                      */
/************************************************************************/

#endif

/************************************************************************/
/*                                                                      */
/************************************************************************/
