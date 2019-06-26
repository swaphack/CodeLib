#include "Maths/Set.h"

void printSet(maths::Set<int>& data)
{
	for (int i = 0; i < data.count(); i++)
	{
		printf("%d ", data.item(i));
	}
	printf("\n");
}

int main(int argc, char** argv)
{
	maths::Set<int> set0;
	set0.append(1);
	set0.append(2);
	set0.append(3);
	set0.append(10);

	maths::Set<int> set1;
	set1.append(3);
	set1.append(4);
	set1.append(5);
	set1.append(10);

	maths::Set<int> set2 = set0.intersectSet(set1);
	maths::Set<int> set3 = set0.unionSet(set1);

	printSet(set0);
	printSet(set1);
	printSet(set2);
	printSet(set3);

	set3.remove(4);
	printSet(set3);

	return 0;
}