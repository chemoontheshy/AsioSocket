#include "asyncFactory.h"
#include "asyncUDPSocket.h"
using namespace hs::net;


hs::net::AsyncFactory::AsyncFactory(const size_t count) :m_iIndex(0),
	m_lstIoContext(count), m_lstWork(count)
{
	std::cout << "count" << std::endl;
	for (size_t i = 0; i < count; i++)
	{
		m_lstWork[i] = std::unique_ptr<asio::io_context::work>(new asio::io_context::work(m_lstIoContext[i]));
		m_lstThread.emplace_back([this, i]() {
			this->m_lstIoContext[i].run();
			});
	}
}

AsyncFactory::~AsyncFactory()
{
	for(auto& ioContext : m_lstIoContext)
	{
		ioContext.stop();
	}

	for (auto& thread : m_lstThread)
	{
		thread.join();
	}
}

AsyncBasePtr hs::net::AsyncFactory::CreateAsyncBase(const AsyncParam& __HS_IN asyncParam, AsyncRecvData asyncRecvData, void* pUser)
{
	m_iIndex = (++m_iIndex) % (m_lstIoContext.size());
	switch (asyncParam.Type)
	{
	case NetType::UDP:
	{
		return AsyncBasePtr(new AsyncUDPSocket(m_lstIoContext.at(m_iIndex), asyncParam, asyncRecvData,pUser));
	}
	break;
	case NetType::TCP:
	{
		//To需要新建一个TCP实例
	}
	break;
	default:
		break;
	}
	return AsyncBasePtr();
}
