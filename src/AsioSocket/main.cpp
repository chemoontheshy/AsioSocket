
#include "transmission.h"
#include "windows.h"

static void RecvData(const uint8_t* data, const size_t length, void* pUser)
{
	std::cout << length << std::endl;
}


int main()
{
	auto factory = hs::net::CreateAsyncFactor();

	
	hs::net::AsyncParam asyncParam;
	asyncParam.DstIP = "127.0.0.1";
	asyncParam.Type = hs::net::NetType::UDP;
	asyncParam.Port = 30000;
	asyncParam.DstPort = 40000;
	asyncParam.MaxLength = 1500;
	auto asyncUDPsocket = factory->CreateAsyncBase(asyncParam, RecvData);
	hs::net::Packet packet;
	uint8_t data[5] = { 1,2,3,4,5 };
	packet.Data = &data[0];
	packet.Length = 5;
	while (true)
	{
		asyncUDPsocket->write(packet);
		Sleep(1000);
	}
	return 0;
}