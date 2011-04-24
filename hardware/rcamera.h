#ifndef RCAMERA_H
#define RCAMERA_H

#include <QThread>

#include <QImage>
#include <QMutex>
#include <QWaitCondition>

#include "rec/robotino/com/ComId.h"
#include "namespaces.h"

using namespace rec::robotino::com;

class hardware::RCamera: public QThread
{
    Q_OBJECT
public:
    RCamera(ComId &comId, QObject *parent = 0);
    ~RCamera();

    bool isStreaming() const;
    void setResolution(unsigned int width, unsigned int height);
    void resolution(unsigned int *width, unsigned int *height) const;

signals:
    void imageReceived(QImage iamge);

public slots:
    void setStreaming(bool streaming);

protected:
    void run();

    QMutex mutex;
    QWaitCondition condition;

    bool streaming;
    bool resized;
    ComId comId;
    unsigned int width, height;
};

#endif // RCAMERA_H
