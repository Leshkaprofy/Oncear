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

signals:
    void imageReceived(QImage iamge);
    void setStream(bool streaming);
    void sendMessage(const QString &message);

public slots:
    void setStreaming(bool streaming);

protected:
    void run();

    ComId comId;
};

#endif // RCAMERA_H
