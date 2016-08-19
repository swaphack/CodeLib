#pragma once

#include "../Framework/Object.h"
#include "../Net/import.h"
#include "../Stream/import.h"

namespace sys
{
	typedef void (Object::*downloadCallback)(int tag, const char* data, int size);

	// http下载
	class HttpDownload : public Object
	{
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
		bool download(const char* url, int port, const char* filepath, Object* pTarget, downloadCallback callback, int tag);
		// 推送监听到的数据
		void flushListenData(int id);
	protected:
		// 接收数据回调
		void onRecvHand(int id, DataQueue& data);
		// 添加一个下载监听
		void addListen(Client* client, Object* pTarget, downloadCallback callback, int tag);
		// 清空数据
		void clear();
	private:
		// 下载数据
		std::map<int, StreamWriter*> _downloadDatas;

		typedef std::map<int, Tuple3<int, std::pair<Object*, downloadCallback>, Client*> > DownloadCallback;
		// 下载回调
		DownloadCallback _downloadCallbacks;
	};
}