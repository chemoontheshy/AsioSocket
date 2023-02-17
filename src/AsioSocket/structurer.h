#ifndef __HS_STRUCTURER_H__
#define __HS_STRUCTURER_H__
#include "hs_utils.h"

namespace hs
{
	namespace net
	{
		/// <summary>
		/// ��������
		/// </summary>
		enum class NetType
		{
			/// <summary>TCP</summary>
			TCP,
			/// <summary>UDP</summary>
			UDP
		};

		/// <summary>
		/// soket����
		/// </summary>
		struct AsyncParam
		{
			/// ��������
			NetType     Type;
			/// ���ض˿� :Ϊ0ʱ��ϵͳ���䣬��Ϊ0���ָ��
			uint16_t    Port;
			/// Ŀ��IP
			std::string DstIP;
			/// Ŀ��Port
			uint16_t    DstPort;
			/// ���ͼ�������󳤶�
			size_t      MaxLength;
		};

		/// <summary>
		/// ͳһ�ص�����
		/// </summary>
		typedef void(*AsyncRecvData)(const uint8_t* data, const size_t length, void* pUser);
	}
}

#endif // !__HS_STRUCTURER_H__

