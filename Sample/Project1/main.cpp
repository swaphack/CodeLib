#include "system.h"
using namespace sys;

int bb = 2;

void show(int a)
{
	do 
	{
		bb = a;
	} while (true);
}

void test_thread()
{
	for (int i = 0; i < 100; i++)
	{
		Thread* pThread = ThreadPool::getInstance()->createThreadWithParams(show, i);

		pThread->detach();
	}
}

void show_asyn(void* a)
{
	do
	{
		bb = *((int*)a);
	} while (0);
}

void test_asyn()
{
	for (int i = 0; i < 100; i++)
	{
		int data = i;
		AsynchronousResult* asynResult = Asynchronous::beginInvoke([](AsynchronousResult* pResult){
			if (pResult->completed == true)
			{
				int cc = *((int*)pResult->object);
			}
		}, show_asyn, &data);

		if (!asynResult->completed)
		{
			Asynchronous::endInvoke(asynResult);
		}
	}
}

int main(int argc, char** argv)
{
	test_thread();

	getchar();

	return 0;
}
