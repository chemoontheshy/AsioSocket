#include "transmission.h"
#include "imp/asyncFactory.h"

hs::net::AsyncFactoryBasePtr hs::net::CreateAsyncFactor()
{
	return AsyncFactoryBasePtr(new AsyncFactory());
}
