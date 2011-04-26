#include "rcamera.h"

#include <QTime>

#include "hardware/devices/rcameradevice.h"

using namespace hardware;
using namespace hardware::device;

RCamera::RCamera(ComId &comId, QObject *parent) :
    QThread(parent)
{
    this->comId = comId;
}

RCamera::~RCamera()
{
    emit setStream(false);
    wait();
}

void RCamera::setStreaming(bool streaming)
{
    emit setStream(streaming);
    emit sendMessage(QString("%1\t Camera is %2 streaming now.").arg(QTime::currentTime().toString()).arg((streaming)?"":"not"));
}

void RCamera::run()
{
    RCameraDevice *camera = new RCameraDevice(comId);
    emit sendMessage(QString("%1\t Camera is connected").arg(QTime::currentTime().toString()));
    connect(camera, SIGNAL(imageReceived(QImage)), SIGNAL(imageReceived(QImage)));
    connect(this, SIGNAL(setStream(bool)), camera, SLOT(setStream(bool)));
    exec();
}

