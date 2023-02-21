#ifndef HKSTREAMOBJECT_H
#define HKSTREAMOBJECT_H
#include "videoobject.h"

class HKStreamObject final : public QVideoObject
{

public:
    HKStreamObject(const VideoParam& videoParam,AsyncFactoryBasePtr asyncFactory);
    ~HKStreamObject();
    void Start() override;
    void Close() override;
    long getHKPort() { return m_iHKPort; }

private:
    static void RTPRecvData(uint8_t* data, const size_t length, void* pUser);
    static void RTCPRecvData(uint8_t* data, const size_t length, void* pUser);

private:
    void sendRTCP(const Packet& packet);
private:
    long         m_iHKPort;
    VideoParam   m_pVideoParam;
    bool         m_bFlag;
    AsyncBasePtr m_pRTP;
    AsyncBasePtr m_pRTCP;

};

#endif // HKSTREAMOBJECT_H
