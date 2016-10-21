struct A 
{
	int a;
	int b;

	A()
	{
		a = 1;
		b = 2;
	}
};

struct B : public A
{
	int c;

	B()
	{
		c = 3;
	}
};

int main(int argc, char** argv)
{
	B b;

	A a = b;

	A* p = &a;

	return 0;
}
