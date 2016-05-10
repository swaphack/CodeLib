#include "system.h"

#include <vadefs.h>

#include <tuple>

using namespace  sys;

typedef void (Object::*find)(int id);
#define find_selector(FIND_SEL) static_cast<find>(&FIND_SEL)
typedef FuncHandler<Object*, find> Finder;


class Test : public Object
{
public:
	Test() {}
	virtual ~Test() {}
public:
	virtual void search(int id)
	{
		printf("search id %d", id);
	}
protected:
private:
};

int main(int argc, char** argv)
{
	Test* test = new Test();
}