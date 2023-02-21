#include "hkstreamobject.h"
#include <iostream>
#include <windows.h>
#include <thread>


HKStreamObject::HKStreamObject(const VideoParam &videoParam, AsyncFactoryBasePtr asyncFactory):m_iHKPort(0),m_pVideoParam(videoParam),m_bFlag(false),m_pRTP(nullptr),m_pRTCP(nullptr)
{
    m_pRTP = asyncFactory->CreateAsyncBase(videoParam.NetAsyncParam,RTPRecvData,this);
    AsyncParam rtcpParam;
    rtcpParam.DstIP     = videoParam.NetAsyncParam.DstIP;
    rtcpParam.DstPort   = videoParam.NetAsyncParam.DstPort+1;
    rtcpParam.Port      = videoParam.NetAsyncParam.Port+1;
    rtcpParam.MaxLength = videoParam.NetAsyncParam.MaxLength;
    rtcpParam.Type      = videoParam.NetAsyncParam.Type;
    m_pRTCP = asyncFactory->CreateAsyncBase(rtcpParam,RTCPRecvData,this);
}

HKStreamObject::~HKStreamObject()
{

}

void HKStreamObject::Start()
{
    m_bFlag =true;

}

void HKStreamObject::Close()
{
  
}


void HKStreamObject::RTPRecvData(uint8_t *data, const size_t length, void *pUser)
{

//    if (length > 12) {
//        HKStreamObject* pHKStreamObject = reinterpret_cast<HKStreamObject*>(pUser);
//        PlayM4_InputData(reinterpret_cast<HKStreamObject*>(pUser)->getHKPort(), reinterpret_cast<BYTE*>(data+12), static_cast<DWORD>(length - 12));
//    }
    std::cout<<"rtp:"<<length<<std::endl;
}

void HKStreamObject::RTCPRecvData(uint8_t *data, const size_t length, void *pUser)
{
    std::cout<<"rtcp:"<<length<<std::endl;
}

void HKStreamObject::sendRTCP(const Packet &packet)
{
    m_pRTCP->write(packet);
}
