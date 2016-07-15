#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <ctime>

class A
{
public:
	int getNumber() { return 1; }
	virtual int getCount() { return 2; }
protected:
private:
};

class B : public A
{
public:
	int getNumber() { return A::getNumber(); }
	virtual int getCount() { return A::getCount(); }
protected:
private:
};

int main(int argc, char** argv)
{
	B b;

	int num = b.getNumber();
	int count = b.getCount();

	return 0;
}