#pragma once

#include "TestFuncNode.h"

class TestUtilityNode : public TestFuncNode
{
public:
	TestUtilityNode();
	virtual ~TestUtilityNode();
protected:
	virtual void testFunc();
private:
	void testString();

	void testMatrix();

	void testHttpDownload();
private:
	sys::ConcurrentFile* _concurFile = nullptr;
	sys::HttpDownload* _httpDownload = nullptr;
};