#ifndef __HS_TRANSMISSION_H__
#define __HS_TRANSMISSION_H__
#include "structurer.h"


namespace hs
{
	namespace net
	{
		/// <summary>
		/// 使用统一数据包
		/// </summary>
		using Packet = hs::stucture::Packet;

		/**/
		class AsyncBase
		{
		public:
			virtual ~AsyncBase() = default;

			virtual size_t write(const Packet& packet) = 0;
		};

		using AsyncBasePtr = std::shared_ptr<AsyncBase>;

		class AsyncFactoryBase
		{
		public:
			virtual ~AsyncFactoryBase() = default;
			virtual AsyncBasePtr CreateAsyncBase(const AsyncParam& asyncParam, AsyncRecvData asyncUdpRecvData) = 0;
		};

		std::shared_ptr<AsyncFactoryBase> CreateAsyncFactor();
	}
}

#endif // !__HS_TRANSMISSION_H__
