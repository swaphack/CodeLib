#include "instance/World.h"

using namespace game;

int main(int argc, char** argv)
{
	while (true)
	{
		World::getInstance()->update();
	}
	return 0;
}