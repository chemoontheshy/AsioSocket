#ifndef __HS_STRUCTURER_H__
#define __HS_STRUCTURER_H__
#include "hs_utils.h"

namespace hs
{
	namespace net
	{
		/// <summary>
		/// 传输类型
		/// </summary>
		enum class NetType
		{
			/// <summary>TCP</summary>
			TCP,
			/// <summary>UDP</summary>
			UDP
		};

		/// <summary>
		/// soket参数
		/// </summary>
		struct AsyncParam
		{
			/// 传输类型
			NetType     Type;
			/// 本地端口 :为0时由系统分配，不为0则可指定
			uint16_t    Port;
			/// 目标IP
			std::string DstIP;
			/// 目标Port
			uint16_t    DstPort;
			/// 发送及接受最大长度
			size_t      MaxLength;
		};

		/// <summary>
		/// 统一回调函数
		/// </summary>
		typedef void(*AsyncRecvData)(const uint8_t* data, const size_t length, void* pUser);
	}
}

#endif // !__HS_STRUCTURER_H__

