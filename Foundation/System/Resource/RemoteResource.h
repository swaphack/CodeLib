#pragma once

#include "Resource.h"

namespace sys
{
	/**
	*	Զ������
	*	url�� http://www.baidu.com:80;
	*/
	class RemoteResource : public Resource
	{
	public:
		RemoteResource();
		virtual ~RemoteResource();
	public:
		// ����
		virtual const char* getName() { return "REMOTE"; }
		// �����ļ�
		bool loadFileData(const char* filename, std::string& data);
	protected:
		// ��ȡ����·��
		std::string getFullPath(const char* filename);
		// ��ȡ����
		bool getCacheData(const char* fullpath, std::string& data);
	};
}