#include "rcamera.h"

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
}

void RCamera::run()
{
    RCameraDevice *camera = new RCameraDevice(comId);
    connect(camera, SIGNAL(imageReceived(QImage)), SIGNAL(imageReceived(QImage)));
    connect(this, SIGNAL(setStream(bool)), camera, SLOT(setStream(bool)));
    exec();
}

