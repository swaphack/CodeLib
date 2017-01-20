#include "chem.h"

using namespace chem;

int main(int argc, char* argv[])
{
	const char* expression = "(NH4(OH)2)2CO";
	ChemDocument* document = new ChemDocument();
	ChemNode* node = document->getInstance()->loadMolecular(expression);
	node = document->getInstance()->loadMolecular(expression);

	return 0;
}