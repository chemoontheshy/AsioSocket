#include "transmission.h"
#include "asyncFactory.h"

std::shared_ptr<hs::net::AsyncFactoryBase> hs::net::CreateAsyncFactor()
{
	return AsyncFactoryBasePtr(new AsyncFactory());
}
