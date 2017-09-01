#include "BattleSimulator.h"

int main(int argc, char** argv)
{
	BattleSimulator* pSimulator = new BattleSimulator();
	pSimulator->Init();
	pSimulator->Run();
	delete pSimulator;

	return 0;
}