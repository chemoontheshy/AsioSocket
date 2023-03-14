#ifndef __HS_ASYNC_FACTORY_H__
#define __HS_ASYNC_FACTORY_H__
#include "../transmission.h"
#include <vector>

#include "asio.hpp"

namespace hs
{
	namespace net
	{
		
		/// <summary>
		/// 异步Socket产生器
		/// </summary>
		class AsyncFactory final : public AsyncFactoryBase
		{
		public:
			/// <summary>
			/// 构造函数
			/// </summary>
			/// <param name="count"></param>
			AsyncFactory(const size_t count = std::thread::hardware_concurrency());

			/// <summary>
			/// 析构函数
			/// </summary>
			~AsyncFactory();

			/// <summary>
			/// 创建Socket
			/// </summary>
			/// <param name="asyncParam">参数</param>
			/// <param name="asyncRecvData">回到函数</param>
			/// <param name="pUser">传入指针</param>
			/// <returns></returns>
			AsyncBasePtr CreateAsyncBase(const AsyncParam& __HS_IN asyncParam, AsyncRecvData asyncRecvData,void* pUser) override;

		private:
			/// <summary>支持并发的最大数量</summary>
			size_t                                               m_iIndex;
			/// <summary>线程池</summary>
			std::vector<std::thread>                             m_lstThread;
			/// <summary>权柄池</summary>
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
