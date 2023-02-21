#ifndef __VIDEO_OBJECT_H__
#define __VIDEO_OBJECT_H__
#include "windows.h"
#include "../AsioSocket/transmission.h"

using namespace hs::net;


enum class FactoryType : int
{
    HK,
    DH
};

enum class PayloadType : int
{
    PS,
    ES,
    H264,
    H265,
};

struct VideoParam
{
    FactoryType         Factory;
    PayloadType         Payload;
    HWND                WinId;
    AsyncParam          NetAsyncParam;
};

class QVideoObject
{
public:
    virtual ~QVideoObject() = default;
    virtual void Start(){}
    virtual void Close(){}
};

using QVideoObjectPtr = std::shared_ptr<QVideoObject>;

QVideoObjectPtr CreateVideoObject(const VideoParam& videoParam,AsyncFactoryBasePtr asyncFactory);

#endif
