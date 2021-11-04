#pragma once

#include "../Env/TestNode.h"

class TestTexturePack : public TestNode
{
public:
	TestTexturePack();
	virtual ~TestTexturePack();
protected:
	virtual void initNodes();
private:
	void packImageTexture();

	void packEnglishTexture();

	void packChineseTexture();
};