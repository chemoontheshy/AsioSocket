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

		/// <summary>
		/// 异步基础类
		/// </summary>
		class AsyncBase
		{
		public:
			/// <summary>
			/// 析构函数
			/// </summary>
			virtual ~AsyncBase() = default;

			/// <summary>
			/// 发送
			/// </summary>
			/// <param name="packet">基础数据包</param>
			/// <returns>成功：返回发送的长度，失败返回0</returns>
			virtual size_t write(const Packet& packet) = 0;
		};

		/// <summary>
		/// 异步实例指针
		/// </summary>
		using AsyncBasePtr = std::shared_ptr<AsyncBase>;

		/// <summary>
		/// 异步工厂基础类
		/// </summary>
		class AsyncFactoryBase
		{
		public:
			/// <summary>
			/// 析构函数
			/// </summary>
			virtual ~AsyncFactoryBase() = default;

			/// <summary>
			/// 创建异步实例类
			/// </summary>
			/// <param name="asyncParam">soket参数</param>
			/// <param name="asyncUdpRecvData">回调函数</param>
			/// <returns>返回:成功,异步实例指针;失败,返回nullptr</returns>
			virtual AsyncBasePtr CreateAsyncBase(const AsyncParam& asyncParam, AsyncRecvData asyncUdpRecvData,void* pUser) = 0;
		};

		/// <summary>
		/// 异步工厂实例指针
		/// </summary>
		using AsyncFactoryBasePtr = std::shared_ptr<AsyncFactoryBase>;

		/// <summary>
		/// 创建异步工厂实例指针
		/// </summary>
		/// <returns>返回:成功,异步工厂实例指针;失败,返回nullptr</returns>
		AsyncFactoryBasePtr CreateAsyncFactor();
	}
}

#endif // !__HS_TRANSMISSION_H__
