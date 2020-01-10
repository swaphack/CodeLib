#pragma once

#include "Resource.h"


namespace sys
{
	/**
	*	远程数据
	*	url： http://127.0.0.2:80;
	*/
	class RemoteResource : public Resource
	{
	public:
		// 下载任务
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
		// 名称
		virtual const char* getName() { return "REMOTE"; }
		// 加载文件
		bool loadFileData(const char* filename, GetDataCallback handler);
	protected:
		// 获取完整路径
		std::string getFullPath(const char* filename);
		// 获取数据
		bool getCacheData(const char* fullpath, std::string& data);
		// 下载数据
		void onDownloadCallback(int32_t tag, const char* data, int32_t size);
	private:
		// 递增标识
		static int32_t s_Tag;

		std::map<int32_t, DownloadTask> _downloadTasks;
	};
}