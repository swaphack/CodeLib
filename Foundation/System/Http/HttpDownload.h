#pragma once

#include "Framework/Object.h"
#include "Net/import.h"
#include "Stream/import.h"

namespace sys
{
	// http下载回调
	typedef void (Object::*downloadCallback)(int32_t tag, const char* data, int32_t size);

	// http下载处理
	typedef std::pair<Object*, downloadCallback> OnHttpDownloadCallback;

	// http下载
	class HttpDownload : public Object
	{
		struct DownloadSlot
		{
			int32_t id = 0;
			int32_t tag = 0;
			OnHttpDownloadCallback handler;
			Client* client = nullptr;
		};
	public:
		HttpDownload();
		~HttpDownload();
	public:
		/*
		@brief 下载文件
		@param url 远程ip地址
		@param port 端口号
		@param filepath 文件路径
		@param callback 下载完成回调
		@param tag 标示
		*/
		bool download(const char* url, int32_t port, const char* filepath, OnHttpDownloadCallback callback, int32_t tag);

		// 推送监听到的数据
		void flushListenData(int32_t id);
	protected:
		// 接收数据回调
		void onRecvHandle(int32_t id, DataQueue& data);
		// 添加一个下载监听
		void addListen(Client* client, OnHttpDownloadCallback callback, int32_t tag);
		// 清空数据
		void clear();
	private:
		// 下载数据
		std::map<int32_t, StreamWriter*> _downloadDatas;

		// 下载回调
		std::map<int32_t, DownloadSlot > _downloadSlots;
	};
}