#include <QApplication>

#include "hardware/rcom.h"
#include "hardware/rcamera.h"
#include "GUI/rcamerawidget.h"
#include "GUI/rlogwidget.h"
#include "hardware/devices/rcameradevice.h"

using namespace hardware::device;
using namespace GUI;
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    RCom *r = new RCom();

    RLogWidget *log = new RLogWidget();
    //RCameraDevice *cam = new RCameraDevice(r->id());
    RCamera *cam = new RCamera(r->id());
    QObject::connect(cam,SIGNAL(sendMessage(QString)), log, SLOT(appendPlainText(QString)));
    RCameraWidget *widget = new RCameraWidget(cam);
    //QObject::connect(cam, SIGNAL(imageReceived(QImage)), widget, SLOT(imageReived(QImage)) );
    log->show();
    widget->show();
    r->init();
    cam->setStreaming(true);
    return app.exec();
}
