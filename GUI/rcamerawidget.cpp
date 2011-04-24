#include "rcamerawidget.h"

#include <QPainter>

#include "hardware/rcamera.h"
#include "namespaces.h"
#include <QLabel>
using namespace GUI;
using namespace hardware;

RCameraWidget::RCameraWidget(RCamera *cam, QWidget *parent) :
    QWidget(parent)
{
    this->cam = cam;
    connect(cam, SIGNAL(imageReceived(QImage)), SLOT(imageReived(QImage)));
    if (!cam->isRunning())  {
        cam->start();
    }
}

void RCameraWidget::paintEvent(QPaintEvent *)
{
    QPainter painter( this );
    painter.drawImage( rect(), image);
}

RCamera* RCameraWidget::getCamera() const
{
    return cam;
}

void RCameraWidget::setCamera(RCamera *cam)
{
    if (this->cam != NULL)  {
        this->cam->setStreaming(false);
    }
    this->cam = cam;
}

void GUI::RCameraWidget::imageReived(QImage image)
{
    this->image = image;
    update();
}
