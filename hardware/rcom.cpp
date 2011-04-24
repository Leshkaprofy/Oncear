#include "hardware/rcom.h"

using namespace hardware;

RCom::RCom()
{


}

RCom::~RCom()
{

}

void RCom::init(const char *address, bool isBlocking)
{
    this->setAddress(address);
    printf("connecting...\n");
    ((Com*)(this))->connect(isBlocking);
}

void RCom::destroy()
{

}

void RCom::errorEvent(Error error, const char *errorString)
{

}

void RCom::connectedEvent()
{

}

void RCom::connectionClosedEvent()
{

}
