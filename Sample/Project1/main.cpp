#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>

void test(char * format, ...)
{
	va_list args;
	int len = 1024;
	char * buffer;

	va_start(args, format);
	len = _vscprintf(format, args) + 1;  //怎么做这个类似功能

	buffer = (char*)malloc(len * sizeof(char));
	vsprintf(buffer, format, args);
	printf(buffer);

	va_end(args);
	free(buffer);
}

int main(int argc, char** argv)
{
	int len = 1;
	int offset = -1;
	const char* str = "hello world!";
	do 
	{
		char * dest = new char[len];
		memset(dest, 0, len);
		offset = _snprintf(dest, len, "%s", str);
		delete[] dest;
		len *= 2;
	} while (offset == -1);

	test("%s", str);

	return 0;
}