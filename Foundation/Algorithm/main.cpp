#include "Sort/Sort.h"
#include <vector>

using namespace alg;


int main(int argc, char** argv)
{
	int ary[] = { 1, 12, 8, 20, 5, 3, 6, 55 };

	Sort<int>::MergeSort(ary, 8, [](const int& a, const int& b)->int {
		return a > b ? 1 : a == b ? 0 : -1;
	});

	return 0;
}