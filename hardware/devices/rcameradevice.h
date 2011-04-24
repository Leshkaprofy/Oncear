#ifndef RCAMERADEVICE_H
#define RCAMERADEVICE_H

#include <QObject>
#include <QImage>

#include "rec/robotino/com/Camera.h"
#include "rec/robotino/com/ComId.h"

#include "namespaces.h"

using namespace rec::robotino::com;

class hardware::device::RCameraDevice : public QObject, public Camera
{
    Q_OBJECT
public:
    RCameraDevice(ComId &comId);

    virtual void imageReceivedEvent( const unsigned char* data,unsigned int dataSize,
                                     unsigned int width,unsigned int height,unsigned int numChannels,
                                     unsigned int bytesPerChannel,unsigned int step );
signals:
    void imageReceived(QImage image);

};

#endif // RCAMERADEVICE_H
