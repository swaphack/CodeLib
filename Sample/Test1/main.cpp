#include "system.h"
#include <thread>
#include <chrono>

int main(int argc, char** argv)
{
	sys::ConcurrentFile* pFile = new sys::ConcurrentFile("F:/1.txt");

	int count1 = 1000;
	std::thread th1([&](){
		while (count1 > 0)
		{
			char* strText = "afdafdsss";
			pFile->write(strText, strlen(strText));
			printf("====WriteData : %s\n", strText);
			count1--;
		}
	});
	th1.detach();

	int offset = 0;
	int size = 0;
	int count2 = 1000;
	char strText[10] = { 0 };
	std::thread th2([&](){
		while (count2 > 0)
		{
			memset(strText, 0, sizeof(strText));
			pFile->read(strText, offset, 9, [&](const char* data, int length){
				printf("====ReadData : %s\n", strText);
			});			
			count2--;
		}
		pFile->finish();
	});
	th2.detach();

	std::thread th3([&](){
		while (true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));

			std::string line = G_CONSOLE->readLine();
			if (line == "exit")
			{
				break;
			}
		}
	});

	th3.join();

	return 0;
}