#include "Script.h"

using namespace script;

int main(int argc, char** argv)
{
	const char* filepath = "Resource/main.script";

	Script::getInstance()->load(filepath);

	return 0;
}