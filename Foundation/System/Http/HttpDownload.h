#pragma once

#include <string>
#include <cstdint>
#include <map>
#include <functional>
#include "Framework/Object.h"
#include "Net/DataQueue.h"

namespace sys
{
	class TCPClient;
	class StreamWriter;

	typedef std::function<void(int32_t tag, const std::string& content)> HttpDownloadedFunc;
	typedef std::function<void(int32_t tag, const char* data, int32_t len)> HttpDownloadingFunc;

	struct HttpDownloadListener
	{
		// http下载回调
		typedef void (Object::* DownloadedCallback)(int32_t tag, const std::string& content);

		Object* first = nullptr;
		DownloadedCallback second = nullptr;

		HttpDownloadListener()
		{

		}

		HttpDownloadListener(Object* obj, DownloadedCallback handler)
			:first(obj), second(handler)
		{

		}
	};

	// http下载
	class HttpDownload : public Object
	{
		struct DownloadSlot
		{
			int32_t id = 0;
			int32_t tag = 0;
			HttpDownloadListener handler;
			HttpDownloadedFunc func = nullptr;
			TCPClient* client = nullptr;
			std::string localpath;

			void hand(const std::string& body);
		};
	public:
		HttpDownload();
		virtual ~HttpDownload();
	public:
		/**
		*   @brief 下载文件
		*   @param url 远程ip地址
		*   @param filepath 文件路径
		*   @param recvHander 接收数据处理
		*   @param callback 下载完成回调
		*   @param tag 标示
		*/
		bool startTask(const std::string& url, const std::string& filepath, const HttpDownloadListener& callback, int32_t tag = 0);
		/**
		*   @brief 下载文件
		*   @param url 远程ip地址
		*   @param filepath 文件路径
		*   @param recvFunc 接收数据处理
		*   @param callback 下载完成回调
		*   @param tag 标示
		*/
		bool startTask(const std::string& url, const std::string& filepath, HttpDownloadedFunc func, int32_t tag = 0);
		// 下载时回调
		void setDownloadingFunc(HttpDownloadingFunc func);
		// 推送监听到的数据
		void flushData(int32_t id);


		static void parseHttpURL(const std::string& url, std::string& ip, int32_t& port, std::string& filepath, std::string& values);
	protected:
		// 初始化客户端
		TCPClient* initClient(const std::string& url);
		// 接收数据回调
		void onRecvHandle(int32_t id, DataQueue& data);
		// 添加一个下载监听
		void addListen(TCPClient* client, const std::string& localpath, const HttpDownloadListener& callback, HttpDownloadedFunc func, int32_t tag = 0);
		// 清空数据
		void clear();
	private:
		// 下载数据
		std::map<int32_t, StreamWriter*> _downloadDatas;

		// 下载回调
		std::map<int32_t, DownloadSlot > _downloadSlots;

		// 下载时回调
		HttpDownloadingFunc _downloadingFunc = nullptr;
	};
}