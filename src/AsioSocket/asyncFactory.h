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
			/// 有时候, 我们希望调用run()后，即使没有io事件, 也不会退出事件循环, 而是一直等待, 
			/// 当有了新的异步io调用的时候, 还可以继续使用该循环。 asio::io_context::work可以防止io_context在没有io事件的情退出。
			/// </summary>
			std::vector<std::unique_ptr<asio::io_context::work>> m_lstWork;
		};
	}
}

#endif // !__HS_ASYNC_FACTORY_H__
