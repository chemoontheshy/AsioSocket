#ifndef __HS_TRANSMISSION_H__
#define __HS_TRANSMISSION_H__
#include "structurer.h"


namespace hs
{
	namespace net
	{
		/// <summary>
		/// ʹ��ͳһ���ݰ�
		/// </summary>
		using Packet = hs::stucture::Packet;

		/// <summary>
		/// �첽������
		/// </summary>
		class AsyncBase
		{
		public:
			/// <summary>
			/// ��������
			/// </summary>
			virtual ~AsyncBase() = default;

			/// <summary>
			/// ����
			/// </summary>
			/// <param name="packet">�������ݰ�</param>
			/// <returns>�ɹ������ط��͵ĳ��ȣ�ʧ�ܷ���0</returns>
			virtual size_t write(const Packet& packet) = 0;
		};

		/// <summary>
		/// �첽ʵ��ָ��
		/// </summary>
		using AsyncBasePtr = std::shared_ptr<AsyncBase>;

		/// <summary>
		/// �첽����������
		/// </summary>
		class AsyncFactoryBase
		{
		public:
			/// <summary>
			/// ��������
			/// </summary>
			virtual ~AsyncFactoryBase() = default;

			/// <summary>
			/// �����첽ʵ����
			/// </summary>
			/// <param name="asyncParam">soket����</param>
			/// <param name="asyncUdpRecvData">�ص�����</param>
			/// <returns>����:�ɹ�,�첽ʵ��ָ��;ʧ��,����nullptr</returns>
			virtual AsyncBasePtr CreateAsyncBase(const AsyncParam& asyncParam, AsyncRecvData asyncUdpRecvData,void* pUser) = 0;
		};

		/// <summary>
		/// �첽����ʵ��ָ��
		/// </summary>
		using AsyncFactoryBasePtr = std::shared_ptr<AsyncFactoryBase>;

		/// <summary>
		/// �����첽����ʵ��ָ��
		/// </summary>
		/// <returns>����:�ɹ�,�첽����ʵ��ָ��;ʧ��,����nullptr</returns>
		AsyncFactoryBasePtr CreateAsyncFactor();
	}
}

#endif // !__HS_TRANSMISSION_H__
