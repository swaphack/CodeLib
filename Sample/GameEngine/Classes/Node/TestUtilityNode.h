#pragma once

#include "TestNode.h"

class TestUtilityNode : public TestNode
{
public:
	TestUtilityNode();
	virtual ~TestUtilityNode();
protected:
	virtual void initNodes();
private:
	void testString();

	void testMatrix();

	void testHttpDownload();
private:
	sys::ConcurrentFile* _concurFile = nullptr;
	sys::HttpDownload* _httpDownload = nullptr;
};