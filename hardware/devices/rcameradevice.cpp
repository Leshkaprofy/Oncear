#include "hardware/devices/rcameradevice.h"
#include <QWidget>
#include <QPainter>
using namespace hardware::device;

RCameraDevice::RCameraDevice(ComId &comId)
{
    setComId(comId);
    //setStreaming(true);
}

void RCameraDevice::imageReceivedEvent(const unsigned char *data, unsigned int dataSize,
                                       unsigned int width, unsigned int height, unsigned int numChannels,
                                       unsigned int bytesPerChannel, unsigned int step)
{
    QImage image( data, width, height, QImage::Format_RGB888 );
    emit imageReceived(image);
}
