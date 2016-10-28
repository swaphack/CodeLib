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
		RemoteResource();
		virtual ~RemoteResource();
	public:
		// 名称
		virtual const char* getName() { return "REMOTE"; }
		// 加载文件
		bool loadFileData(const char* filename, std::string& data);
	protected:
		// 获取完整路径
		std::string getFullPath(const char* filename);
		// 获取数据
		bool getCacheData(const char* fullpath, std::string& data);
		// 下载数据
		void onDownloadCallback(int tag, const char* data, int size);
	private:
		// 递增标识
		static int s_Tag;

		std::map<int, std::string> _downloadPath;
	};
}