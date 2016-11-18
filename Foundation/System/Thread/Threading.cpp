#include "Threading.h"

#include <thread>
#include <chrono>

using namespace sys;

void Threading::sleep(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Threading::sleepUntil(int seconds)
{
	std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(seconds));
}
