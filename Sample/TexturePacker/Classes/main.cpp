#include "system.h"
#include "algorithm.h"

int main(int argc, char** argv)
{
	alg::BinPacking2D bin2D;
	bin2D.addItem(0, 10, 10);
	bin2D.addItem(1, 10, 10);
	bin2D.addItem(2, 3, 5);
	bin2D.addItem(3, 6, 7);
	bin2D.addItem(4, 6, 8);
	return 1;
}