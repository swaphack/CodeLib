#pragma once

#include "Resource.h"

namespace sys
{
	// ��������
	class LocalResource : public Resource
	{
	public:
		LocalResource();
		virtual ~LocalResource();
	public:
		// ����
		virtual const char* getName() { return "LOCAL"; }
		// �����ļ�
		virtual bool loadFileData(const char* filename, GetDataCallback handler);
	protected:
		// ��ȡ����·��
		std::string getFullPath(const char* filename);
		// ��ȡ����
		bool getCacheData(const char* fullpath, std::string& data);
	};
}