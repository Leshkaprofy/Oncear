#ifndef RCAMERAWIDGET_H
#define RCAMERAWIDGET_H

#include <QWidget>


#include "namespaces.h"

using namespace hardware;
class QImage;


class GUI::RCameraWidget : public QWidget
{
    Q_OBJECT
public:
    RCameraWidget(RCamera *cam, QWidget *parent = 0);

    RCamera* getCamera() const;
    void setCamera(RCamera *cam);

signals: 

public slots:
    void imageReived(QImage image);

protected:
    void paintEvent(QPaintEvent *);

    QImage image;
    RCamera *cam;

};

#endif // RCAMERAWIDGET_H
