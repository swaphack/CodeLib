#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>

class IA
{
public:
	virtual ~IA()
	{
	}
protected:
private:
};

class A : public IA
{
public:
	A()
	{
	}
	virtual ~A()
	{
	}
public:
	virtual int getNumber() 
	{ 
		return 1; 
	}
};

class B : public A
{
public:
	B()
	{
	}
	virtual ~B()
	{
	}
protected:  
	virtual int getNumber() 
	{ 
		return 2; 
	}
};

int main(int argc, char** argv)
{
	A* a = new B();

	printf("%d", a->A::getNumber());
	printf("%d", a->getNumber());

	delete a;

	return 0;
}