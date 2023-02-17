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

#define __HS_IN     // �������
#define __HS_OUT    // �������
#define __HS_IN_OUT // �����������


#endif // !

#define VSNC_MAX(a,b)          ((a)>(b)?(a):(b))
#define VSNC_MIN(a,b)          ((a)<(b)?(a):(b))

namespace hs
{
	/// <summary>
	/// ���ýṹ��
	/// </summary>
	namespace stucture
	{
		/// <summary>�����Э��ö��</summary>
		enum  class CodecID :int { H264, HEVC };

		/// <summary>
		/// ���ݰ�
		/// </summary>
		struct Packet
		{
			/// <summary>ָ��ͷ </summary>
			uint8_t* Data;
			/// <summary>���� </summary>
			size_t   Length;
		};
	}

	namespace utils
	{
		template <typename _Ty>
		inline void __zero_mem(_Ty&& var) noexcept { memset(&var, 0, sizeof(_Ty)); }

		/// <summary>
		/// ��ȡ�Ժ���Ϊ��λ��UTCʱ��
		/// </summary>
		/// <returns>�Ժ���Ϊ��λ��UTCʱ��</returns>
		inline int64_t     __utc() noexcept { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }

		/// <summary>
		/// ��ǰ�߳�����Ϊ��λ��ʱ
		/// </summary>
		/// <param name="val">�ӳٵ�����</param>
		inline void        __sleep_seconds(const int val) noexcept { std::this_thread::sleep_for(std::chrono::seconds(val)); }

		/// <summary>
		/// ��ǰ�߳��Ժ���Ϊ��λ��ʱ
		/// </summary>
		/// <param name="val">�ӳٵĺ�����</param>
		inline void        __sleep_milliseconds(const int val) noexcept { std::this_thread::sleep_for(std::chrono::milliseconds(val)); }
	}

}



#endif // !__HS_UTILS_H_
