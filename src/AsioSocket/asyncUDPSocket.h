#ifndef __HS_ASYNC_UDP_SOCKET__
#define __HS_ASYNC_UDP_SOCKET__
#include "transmission.h"
#include "structurer.h"

#include <asio.hpp>

namespace hs
{
	namespace net
	{
		class AsyncUDPSocket final : public AsyncBase
		{
		public:
			AsyncUDPSocket(asio::io_context& context, const AsyncParam& asyncParam, AsyncRecvData asyncRecvData);
			size_t write(const Packet& __HS_IN packet) override;

		private:
			void doReadLoop();
			void readHaddle(const asio::error_code& error, std::size_t byte_transferred);

		private:
			Packet                                   m_pPacket;
			asio::error_code                         m_pErrorCode;
			asio::ip::udp::endpoint                  m_pLocalEndPoint;
			asio::ip::udp::endpoint                  m_pRemoteEndPoint;
			std::shared_ptr<asio::ip::udp::socket>   m_pUDPSocket;
			/// <summary>申请内存的总数(实际的内存空间)</summary>
			std::vector<uint8_t>                     m_lstMemeoryUsed;
			AsyncRecvData                            m_pAsyncRecvData;
		};
	}
}

#endif // !__HS_ASYNC_UDP_SOCKET__

