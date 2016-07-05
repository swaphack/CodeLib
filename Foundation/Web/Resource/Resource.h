#pragma once

#include "system.h"
#include "text.h"

namespace web
{
	class Resource
	{
	public:
		// �����ļ�
		const char* loadFile(const char* filename, ulong& size);
		// ����xml�ļ�
		tinyxml2::XMLDocument* loadXMLFile(const char* filename);
		// ����json�ļ�
		Json::Reader* loadJsonFile(const char* filename);
	protected:
	private:
	};
}