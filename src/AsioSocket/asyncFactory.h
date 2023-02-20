#ifndef __HS_ASYNC_FACTORY_H__
#define __HS_ASYNC_FACTORY_H__
#include "transmission.h"
#include <vector>

#include "asio.hpp"

namespace hs
{
	namespace net
	{
		
		/// <summary>
		/// �첽Socket������
		/// </summary>
		class AsyncFactory final : public AsyncFactoryBase
		{
		public:
			/// <summary>
			/// ���캯��
			/// </summary>
			/// <param name="count"></param>
			AsyncFactory(const size_t count = std::thread::hardware_concurrency());

			~AsyncFactory();

			AsyncBasePtr CreateAsyncBase(const AsyncParam& __HS_IN asyncParam, AsyncRecvData asyncRecvData,void* pUser) override;

		private:
			size_t                                               m_iIndex;
			std::vector<std::thread>                             m_lstThread;
			std::vector<asio::io_context>                        m_lstIoContext;

			/// <summary>
			/// ��ʱ��, ����ϣ������run()�󣬼�ʹû��io�¼�, Ҳ�����˳��¼�ѭ��, ����һֱ�ȴ�, 
			/// �������µ��첽io���õ�ʱ��, �����Լ���ʹ�ø�ѭ���� asio::io_context::work���Է�ֹio_context��û��io�¼������˳���
			/// </summary>
			std::vector<std::unique_ptr<asio::io_context::work>> m_lstWork;
		};
	}
}

#endif // !__HS_ASYNC_FACTORY_H__
