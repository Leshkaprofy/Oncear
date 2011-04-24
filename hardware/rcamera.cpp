#include "rcamera.h"

#include "hardware/devices/rcameradevice.h"

using namespace hardware;
using namespace hardware::device;

RCamera::RCamera(ComId &comId, QObject *parent) :
    QThread(parent),
    streaming(false),
    resized(false)
{
    this->comId = comId;
}

RCamera::~RCamera()
{
    setStreaming(false);
    wait();
}

bool RCamera::isStreaming() const
{
    return streaming;
}

void RCamera::setResolution(unsigned int width, unsigned int height)
{
    mutex.lock();
    this->width = width;
    this->height = height;
    resized = true;
    mutex.lock();
}

void RCamera::resolution(unsigned int *width, unsigned int *height) const
{
    *width = this->width;
    *height = this->height;
}

void RCamera::setStreaming(bool streaming)
{
    mutex.lock();/*
    if (streaming && !this->streaming)  {
        this->streaming = true;
        condition.wakeOne();
    } else {
        this->streaming = streaming;
    }*/
    this->streaming = true;
    condition.wakeOne();
    mutex.unlock();
}

void RCamera::run()
{
    RCameraDevice *camera = new RCameraDevice(comId);
    camera->setStreaming(false);
    connect(camera, SIGNAL(imageReceived(QImage)), SIGNAL(imageReceived(QImage)));
    forever {
        mutex.lock();
        if (!streaming) {
            camera->setStreaming(false);
            condition.wait(&mutex);
            camera->setStreaming(true);
        }/*
        if (resized)    {
            camera->setResolution(width, height);
        }*/
        mutex.unlock();
    }
}

