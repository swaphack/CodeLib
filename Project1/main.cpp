/*
#include <string>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cassert>

#include "system.h"
#include "db.h"

using namespace db;
using namespace sys;

#define STRUCT_HEAD "content.h"

#define STRUCT_TEXT "content.txt"
#define DATA_TEXT "data.txt"

void db_create_data_struct()
{
	DBTable t1;
	t1.setName("UserInfo");
	t1.addField("ID", EFT_UINT);
	t1.addField("Name", EFT_STRING, 50);
	t1.addField("BirthDay", EFT_STRING, 50);

	DBTable t2;
	t2.setName("Career");
	t2.addField("ID", EFT_STRING, 50);
	t2.addField("Age", EFT_UCHAR);
	t2.addField("Work", EFT_USHORT);

	DBContent dbContent;
	dbContent.addTable(t1);
	dbContent.addTable(t2);

	DBCode* dbCode = new DBCode();
	dbCode->createDataStruct(STRUCT_HEAD, &dbContent);
}

void db_load_table_struct()
{
	DBContent dbContent;
	DBCode* dbCode = new DBCode();
	dbCode->loadContent(STRUCT_TEXT, &dbContent);
}

struct A
{
	char a;
	int b;
	long long c;
};

struct B
{
	long long c;
	char a;
	int b;
};

struct C
{
	char data[100];
};

struct D
{
	char b;
	short c;
	int a;
	char data[50];
};

void test_struct_size()
{
	printf("size of A : %d\n", sizeof(A));
	printf("size of B : %d\n", sizeof(B));
	printf("size of C : %d\n", sizeof(C));

	A a;
	B b;
	C c;

	printf("size of a : %d\n", sizeof(a));
	printf("size of b : %d\n", sizeof(b));
	printf("size of c : %d\n", sizeof(c));

	D d;
	d.a = 1;
	d.b = 2;
	d.c = 3;
	memset(d.data, 1, 50);

	char* ptr = (char*)&d;
	int offset = 0;

	char bb = *(char*)(ptr + offset);
	offset += 2 * sizeof(char);

	short cc = *(short*)(ptr + offset);
	offset += sizeof(short);

	int aa = *(int*)(ptr + offset);
	offset += sizeof(int);

	

	std::string dd = std::string((ptr + offset), sizeof(D) - offset - 1);


	printf("size of aa : %d\n", aa);
	printf("size of bb : %d\n", bb);
	printf("size of dd : %s\n", dd.c_str());

	std::string str(10, 0);

	printf("string value : %s\n", str.c_str());
	printf("string size %d", str.size());
}

int main()
{
	return 0;
};
*/