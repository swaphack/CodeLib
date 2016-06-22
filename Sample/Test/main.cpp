#include <string>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cassert>

#include "system.h"
#include "user.h"
#include "BLL/import.h"

using namespace user;
using namespace sys;

#define CREATE_STRUCT_BEGIN(NAME) \
struct NAME {

#define CREATE_STRUCT_MEMBER(MEMBERTYPE, MEMBER) \
	MEMBERTYPE MEMBER; 

#define CREATE_STRUCT_END() \
};

//////////////////////////////////////////////////////////////////////////
void init_user()
{
	(new user::BusinessGlobal())->init();

	(new test::AccountActionLogin(1))->doAction(true);
}

void test_packet()
{
	std::string data = "12345";

	StreamWriter* writer = new StreamWriter();
	writer->writeInt(124);
	writer->writeInt(data.size());
	writer->writeString(data.c_str());

	StreamReader* reader = new StreamReader(writer->getData(), writer->getLength());
	int a = reader->readInt();
	int len = reader->readInt();
	char* str = reader->readString(len);

	delete writer;

	delete reader;

}

void create_single_struct()
{
	std::vector<std::pair<int, std::string>> members;
	members[1].first = 1;
	members[1].second = "ha";

	std::string Name = "Hello";
	
	CREATE_STRUCT_BEGIN(Name)
	CREATE_STRUCT_MEMBER(int, HaHA);
	CREATE_STRUCT_END();
}



int main()
{
	//init_user();

	ASSERT(1);

	//create_single_struct();

	system("pause");

	return 0;
};