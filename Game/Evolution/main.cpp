#include "Chemistry/ChemDocument.h"

using namespace nature;

int main(int argc, char** argv)
{
	const char* chemExpression = "Al(OH(CH3)2)2NH4";

	ChemDocument* pDoc = new ChemDocument();
	ChemNode* pNode = pDoc->loadMolecular(chemExpression);

	delete pNode;
	return 0;
}