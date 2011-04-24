#include <QApplication>

#include "hardware/rcom.h"
#include "hardware/rcamera.h"
#include "GUI/rcamerawidget.h"
#include "hardware/devices/rcameradevice.h"

using namespace hardware::device;
using namespace GUI;
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    RCom *r = new RCom();

    //RCameraDevice *cam = new RCameraDevice(r->id());
    RCamera *cam = new RCamera(r->id());
    RCameraWidget *widget = new RCameraWidget(cam);
    //QObject::connect(cam, SIGNAL(imageReceived(QImage)), widget, SLOT(imageReived(QImage)) );
    r->init();
    widget->show();
    cam->setStreaming(true);
    return app.exec();
}
