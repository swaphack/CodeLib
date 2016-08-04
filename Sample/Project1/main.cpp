#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <ctime>

#define GET_STRING(x) (#x)

void setMember()
{
	printf("1\n");
}

void(*func)();

int main(int argc, char** argv)
{
	const char* a = GET_STRING(int);


	return 0;
}