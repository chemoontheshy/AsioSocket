#ifndef __HS_ASYNC_FACTORY_H__
#define __HS_ASYNC_FACTORY_H__
#include "transmission.h"
#include <vector>

#include "asio.hpp"

namespace hs
{
	namespace net
	{
		
		class AsyncFactory final : public AsyncFactoryBase
		{
		public:
			AsyncFactory(const size_t count = std::thread::hardware_concurrency());

			~AsyncFactory();

			AsyncBasePtr CreateAsyncBase(const AsyncParam& __HS_IN asyncParam, AsyncRecvData asyncRecvData) override;

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
