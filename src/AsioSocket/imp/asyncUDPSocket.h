#ifndef __HS_ASYNC_UDP_SOCKET__
#define __HS_ASYNC_UDP_SOCKET__
#include "../transmission.h"
#include "../structurer.h"

#include <asio.hpp>

namespace hs
{
	namespace net
	{
		/// <summary>
		/// 异步UDP实例实现
		/// </summary>
		class AsyncUDPSocket final : public AsyncBase
		{
		public:
			/// <summary>
			/// 构造函数
			/// </summary>
			/// <param name="context">权柄</param>
			/// <param name="asyncParam">socket参数</param>
			/// <param name="asyncRecvData">回调函数</param>
			AsyncUDPSocket(asio::io_context& context, const AsyncParam& asyncParam, AsyncRecvData asyncRecvData,void* pUser);

			~AsyncUDPSocket();
			/// <summary>
			/// 发送
			/// </summary>
			/// <param name="packet">基础数据包</param>
			/// <returns></returns>
			size_t write(const Packet& __HS_IN packet) override;

		private:
			/// <summary>
			/// 接收信息循环
			/// </summary>
			void doReadLoop();

			/// <summary>
			/// 用于绑定的接收回调函数
			/// </summary>
			/// <param name="error">错误码</param>
			/// <param name="byte_transferred">接收到的长度</param>
			void readHandle(const asio::error_code& error, std::size_t byte_transferred);

		private:
			/// <summary>基础数据包：用于接收信息的缓存区</summary>
			Packet                                   m_pPacket;
			/// <summary>错误码</summary>
			asio::error_code                         m_pErrorCode;
			/// <summary>本地IP和端口</summary>
			asio::ip::udp::endpoint                  m_pLocalEndPoint;
			/// <summary>远端IP和端口</summary>
			asio::ip::udp::endpoint                  m_pRemoteEndPoint;
			/// <summary>UDPSocket权柄</summary>
			std::shared_ptr<asio::ip::udp::socket>   m_pUDPSocket;
			/// <summary>申请内存的总数(实际的内存空间)</summary>
			std::vector<uint8_t>                     m_lstMemeoryUsed;
			/// <summary>用户传进来的回调函数</summary>
			AsyncRecvData                            m_pAsyncRecvData;
			/// <summary>用户指针</summary>
			void*                                    m_pUser;
		};
	}
}

#endif // !__HS_ASYNC_UDP_SOCKET__

