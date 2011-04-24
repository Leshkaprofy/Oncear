#ifndef RCOM_H
#define RCOM_H

#include <QObject>
#include "rec/robotino/com/Com.h"

#include <string>

#include "namespaces.h"

using namespace rec::robotino::com;
using namespace std;

class hardware::RCom: public QObject, public Com
{
    Q_OBJECT
public:
    RCom();
    ~RCom();

    void init(const char *address = "127.0.0.1:8080",bool isBlocking = false);
    void destroy();

    virtual void errorEvent (Error error, const char *errorString);
    virtual void connectedEvent();
    virtual void connectionClosedEvent();

signals:
    void errorEventSignal(string description);
    void connectedEventSignal();
    void connectionClosedSignal();
};

#endif // RCOM_H
