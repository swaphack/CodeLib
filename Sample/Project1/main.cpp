#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <ctime>

#include <map>

#define GET_STRING(x) (#x)

struct A;
class All
{
public:
	All() {}
	~All() {}
public: 
	void addA(int i, void* a)
	{
		_as[i] = a;
	}
	void removeA(int i, bool bDestory = false)
	{
		std::map<int, void*>::iterator iter = _as.find(i);
		if (iter == _as.end())
		{
			return;
		}

		A* second = static_cast<A*>(iter->second);
		_as.erase(iter);
		if (bDestory == true)
		{
			delete second;
		}
	}
	void destoryA(int i)
	{
		this->removeA(i, true);
	}
protected:
	std::map<int, void*> _as;
};

static All all;

struct A
{
public:
	int i;
public:
	A()
	{}
	~A()
	{
		all.removeA(1, false);
	}
};


int main(int argc, char** argv)
{
	
	for (int i = 0; i < 10; i ++)
	{
		all.addA(i, new A());
	}

	all.destoryA(1);

	while (true)
	{

	}

	return 0;
}