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
		virtual std::string getName() { return "LOCAL"; }
		// �����ļ�
		virtual bool loadFileData(const std::string& filename, GetDataCallback handler);
	protected:
		// ��ȡ����·��
		std::string getFullPath(const std::string& filename);
		// ��ȡ����
		bool getCacheData(const std::string& fullpath, std::string& data);
	};
}