#include "system.h"
using namespace sys;

volatile int bb = 2;

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

void show_asyn(int a)
{
	do
	{
		bb = a;

		printf("asyn data %d\n", bb);
	} while (true);
}

#define ARY_LENGTH 64
int data[ARY_LENGTH] = { 0 };
volatile int cc = 0;

void test_asyn()
{
	for (int i = 0; i < ARY_LENGTH; i++)
	{
		data[i] = i;
	}
	for (int i = 0; i < ARY_LENGTH; i++)
	{
		AsynchronousResult* asynResult = Asynchronous::beginInvoke([](AsynchronousResult* pResult){
			if (pResult->completed == true)
			{
				cc = *((int*)pResult->object);
				delete pResult->object;
				pResult->object = nullptr;
				printf("finish data %d\n", cc);
			}
		}, show_asyn, data[i]);

		int* value = new int(data[i]);
		asynResult->object = value;

		if (!asynResult->completed)
		{
			Asynchronous::endInvoke(asynResult);
		}
	}
}

void test_struct()
{
#pragma pack(1)
	typedef struct Header
	{
		unsigned int i : 1;
		unsigned int j : 2;
		unsigned int k : 29;
		int d;
	};
#pragma  pack()

	typedef struct Header2
	{
		int d;
		union
		{
			char i;
			char j;
			char k;
			char s;
		}a;
	};

	printf("Header size is %d\n", sizeof(Header));

	Header header;
	header.i = 1;
	header.j = 2;
	header.k = 4;
	header.d = 5;

	printf("Header2 size is %d\n", sizeof(Header2));

	Header2 header2;
	header2.d = 15;

	int a = 1;
}

int main(int argc, char** argv)
{
	test_asyn();

	getchar();

	return 0;
}
