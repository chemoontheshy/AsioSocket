#include "videoobject.h"
#include "hkstreamobject.h"


QVideoObjectPtr CreateVideoObject(const VideoParam &videoParam, AsyncFactoryBasePtr asyncFactory)
{
    switch (videoParam.Factory) {
    case FactoryType::HK:
        {
            return QVideoObjectPtr(new HKStreamObject(videoParam,asyncFactory));
        }
        break;
    case FactoryType::DH:
        {

        }
        break;
    default:
        break;
    }
    return nullptr;
}
