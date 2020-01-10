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
		// ��������
		struct DownloadTask
		{
			int32_t tag = 0;
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
		void onDownloadCallback(int32_t tag, const char* data, int32_t size);
	private:
		// ������ʶ
		static int32_t s_Tag;

		std::map<int32_t, DownloadTask> _downloadTasks;
	};
}