#include "asyncUDPSocket.h"
using namespace hs::net;

hs::net::AsyncUDPSocket::AsyncUDPSocket(asio::io_context& context, const AsyncParam& asyncParam, AsyncRecvData asyncRecvData, void* pUser):
	m_pLocalEndPoint(asio::ip::udp::v4(), asyncParam.Port),
	m_pRemoteEndPoint(asio::ip::address_v4::from_string(asyncParam.DstIP), asyncParam.DstPort),
	m_pUDPSocket(nullptr), m_pAsyncRecvData(asyncRecvData)
{
	m_lstMemeoryUsed.resize(asyncParam.MaxLength);
	m_pPacket.Data = m_lstMemeoryUsed.data();
	m_pPacket.Length = asyncParam.MaxLength;
	try
	{
		m_pUDPSocket = std::make_shared<asio::ip::udp::socket>(context, m_pLocalEndPoint);
		asio::socket_base::receive_buffer_size sbs(static_cast<int>(asyncParam.MaxLength));
		m_pUDPSocket->set_option(sbs);
	}
	catch (...)
	{
		std::cout << "create socket ip:127.0.0.1:" + std::to_string(asyncParam.Port) + " failed!!!" << std::endl;
	}
	doReadLoop();
}

size_t AsyncUDPSocket::write(const Packet& __HS_IN packet)
{
	if (m_pUDPSocket && packet.Data && packet.Length > 0)
	{
		return m_pUDPSocket->send_to(asio::buffer(packet.Data, packet.Length),
									m_pRemoteEndPoint, 0, m_pErrorCode);
	}
	return 0;
}



void hs::net::AsyncUDPSocket::doReadLoop()
{
	if (m_pUDPSocket)
	{
		m_pUDPSocket->async_receive_from(asio::buffer(m_pPacket.Data, m_pPacket.Length),
			m_pLocalEndPoint, std::bind(&AsyncUDPSocket::readHandle, this, std::placeholders::_1, std::placeholders::_2));
	}
}

void AsyncUDPSocket::readHandle(const asio::error_code& error, std::size_t byte_transferred)
{
	m_pAsyncRecvData(m_pPacket.Data, byte_transferred, nullptr);
	doReadLoop();
}