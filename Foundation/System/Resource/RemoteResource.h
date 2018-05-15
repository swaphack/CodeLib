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

		struct DownloadTask
		{
			int tag = 0;
			std::string path = "";
			GetDataCallback handler = nullptr;
		};
	public:
		RemoteResource();
		virtual ~RemoteResource();
	public:
		// ����
		virtual const char* getName() { return "REMOTE"; }
		// �����ļ�
		bool loadFileData(const char* filename, GetDataCallback handler);
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

		std::map<int, DownloadTask> _downloadTasks;
	};
}