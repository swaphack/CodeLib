#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <ctime>

int main(int argc, char** argv)
{
	
	time_t now = 0;
	struct tm* stm = new struct tm();

	time(&now);
	localtime_s(stm, &now);

	delete stm;
	
	char* strTime = ctime(&now);

	printf("%s\n", strTime);

	return 0;
}