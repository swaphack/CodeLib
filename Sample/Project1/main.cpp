#include "system.h"
using namespace sys;

int bb = 2;

void show(int a)
{
	do 
	{
		bb = a;
		printf("value  is %d \n", bb);
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
		printf("value  is %d \n", bb);
	} while (0);
}

void test_asyn()
{
	for (int i = 0; i < 100; i++)
	{
		int data = i;
		AsynchronousResult* asynResult = Asynchronous::beginInvoke([](AsynchronousResult* pResult){
			if (pResult->finish == true)
			{
				int cc = *((int*)pResult->object);
				printf("Finish  is %d \n", cc);
			}
		}, show_asyn, &data);

		if (asynResult->finish == true)
		{
			int a = 1;
		}
	}
}

int main(int argc, char** argv)
{
	test_asyn();

	getchar();

	return 0;
}
