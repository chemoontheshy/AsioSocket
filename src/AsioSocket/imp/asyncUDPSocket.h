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
		/// �첽UDPʵ��ʵ��
		/// </summary>
		class AsyncUDPSocket final : public AsyncBase
		{
		public:
			/// <summary>
			/// ���캯��
			/// </summary>
			/// <param name="context">Ȩ��</param>
			/// <param name="asyncParam">socket����</param>
			/// <param name="asyncRecvData">�ص�����</param>
			AsyncUDPSocket(asio::io_context& context, const AsyncParam& asyncParam, AsyncRecvData asyncRecvData,void* pUser);

			~AsyncUDPSocket();
			/// <summary>
			/// ����
			/// </summary>
			/// <param name="packet">�������ݰ�</param>
			/// <returns></returns>
			size_t write(const Packet& __HS_IN packet) override;

		private:
			/// <summary>
			/// ������Ϣѭ��
			/// </summary>
			void doReadLoop();

			/// <summary>
			/// ���ڰ󶨵Ľ��ջص�����
			/// </summary>
			/// <param name="error">������</param>
			/// <param name="byte_transferred">���յ��ĳ���</param>
			void readHandle(const asio::error_code& error, std::size_t byte_transferred);

		private:
			/// <summary>�������ݰ������ڽ�����Ϣ�Ļ�����</summary>
			Packet                                   m_pPacket;
			/// <summary>������</summary>
			asio::error_code                         m_pErrorCode;
			/// <summary>����IP�Ͷ˿�</summary>
			asio::ip::udp::endpoint                  m_pLocalEndPoint;
			/// <summary>Զ��IP�Ͷ˿�</summary>
			asio::ip::udp::endpoint                  m_pRemoteEndPoint;
			/// <summary>UDPSocketȨ��</summary>
			std::shared_ptr<asio::ip::udp::socket>   m_pUDPSocket;
			/// <summary>�����ڴ������(ʵ�ʵ��ڴ�ռ�)</summary>
			std::vector<uint8_t>                     m_lstMemeoryUsed;
			/// <summary>�û��������Ļص�����</summary>
			AsyncRecvData                            m_pAsyncRecvData;
			/// <summary>�û�ָ��</summary>
			void*                                    m_pUser;
		};
	}
}

#endif // !__HS_ASYNC_UDP_SOCKET__

