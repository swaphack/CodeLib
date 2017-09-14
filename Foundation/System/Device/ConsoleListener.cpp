#include "ConsoleListener.h"
#include "../Thread/Thread.h"
#include "Console.h"

using namespace sys;


ConsoleListener::ConsoleListener()
:_running(false)
,_receiveLineHandler(nullptr)
{

}

ConsoleListener::~ConsoleListener()
{

}

void ConsoleListener::setReceiveLineCallback(ReceiveLineCallback handler)
{
	_receiveLineHandler = handler;
}

void ConsoleListener::run()
{
	if (_receiveLineHandler == nullptr)
	{
		return;
	}
	_running = true;
	Thread th;
	th.start([this](){
		while (_running)
		{
			std::string line = G_CONSOLE->readLine();
			_receiveLineHandler(line);
		}
	});

	th.detach();
}

void ConsoleListener::stop()
{
	_running = false;
}
