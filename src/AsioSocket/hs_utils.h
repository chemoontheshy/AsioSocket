#ifndef __HS_UTILS_H_
#define __HS_UTILS_H_

#include <chrono>
#include <thread> // std::this_thread
#include <iostream>


#ifdef _WIN32
#ifdef _WINDLL
#define __VSNC_PORT __declspec(dllexport)
#else
#define __VSNC_PORT __declspec(dllimport)
#endif // WIN32_DLL

#define __HS_IN     // 输入参数
#define __HS_OUT    // 输出参数
#define __HS_IN_OUT // 输入输出参数


#endif // !

#define VSNC_MAX(a,b)          ((a)>(b)?(a):(b))
#define VSNC_MIN(a,b)          ((a)<(b)?(a):(b))

namespace hs
{
	/// <summary>
	/// 常用结构体
	/// </summary>
	namespace stucture
	{
		/// <summary>编解码协议枚举</summary>
		enum  class CodecID :int { H264, HEVC };

		/// <summary>
		/// 数据包
		/// </summary>
		struct Packet
		{
			/// <summary>指针头 </summary>
			uint8_t* Data;
			/// <summary>长度 </summary>
			size_t   Length;
		};
	}

	namespace utils
	{
		template <typename _Ty>
		inline void __zero_mem(_Ty&& var) noexcept { memset(&var, 0, sizeof(_Ty)); }

		/// <summary>
		/// 获取以毫秒为单位的UTC时间
		/// </summary>
		/// <returns>以毫秒为单位的UTC时间</returns>
		inline int64_t     __utc() noexcept { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }

		/// <summary>
		/// 当前线程以秒为单位延时
		/// </summary>
		/// <param name="val">延迟的秒数</param>
		inline void        __sleep_seconds(const int val) noexcept { std::this_thread::sleep_for(std::chrono::seconds(val)); }

		/// <summary>
		/// 当前线程以毫秒为单位延时
		/// </summary>
		/// <param name="val">延迟的毫秒数</param>
		inline void        __sleep_milliseconds(const int val) noexcept { std::this_thread::sleep_for(std::chrono::milliseconds(val)); }
	}

}



#endif // !__HS_UTILS_H_
