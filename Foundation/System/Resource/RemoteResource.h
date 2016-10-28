#pragma once

#include "Resource.h"

namespace sys
{
	/**
	*	Զ������
	*	url�� http://127.0.0.2:80;
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
		// ��������
		void onDownloadCallback(int tag, const char* data, int size);
	private:
		// ������ʶ
		static int s_Tag;

		std::map<int, std::string> _downloadPath;
	};
}