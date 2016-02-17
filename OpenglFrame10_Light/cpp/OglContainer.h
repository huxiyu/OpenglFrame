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
    Q_INVOKABLE void globalAmbientR(float v);
    Q_INVOKABLE void globalAmbientG(float v);
    Q_INVOKABLE void globalAmbientB(float v);

    Q_INVOKABLE void matrialAmbientDiffuseR(float v);
    Q_INVOKABLE void matrialAmbientDiffuseG(float v);
    Q_INVOKABLE void matrialAmbientDiffuseB(float v);

    Q_INVOKABLE void matrialSpecularR(float v);
    Q_INVOKABLE void matrialSpecularG(float v);
    Q_INVOKABLE void matrialSpecularB(float v);

    Q_INVOKABLE void enableLight0(bool v);
    Q_INVOKABLE void light0AmbientR(float v);
    Q_INVOKABLE void light0AmbientG(float v);
    Q_INVOKABLE void light0AmbientB(float v);
    Q_INVOKABLE void light0DiffuseR(float v);
    Q_INVOKABLE void light0DiffuseG(float v);
    Q_INVOKABLE void light0DiffuseB(float v);
    Q_INVOKABLE void light0SpecularR(float v);
    Q_INVOKABLE void light0SpecularG(float v);
    Q_INVOKABLE void light0SpecularB(float v);

    Q_INVOKABLE void light0PosX(float v);
    Q_INVOKABLE void light0PosY(float v);
    Q_INVOKABLE void light0PosZ(float v);



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
