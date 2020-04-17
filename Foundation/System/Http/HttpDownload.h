#pragma once

#include <string>
#include <cstdint>
#include <map>
#include <functional>
#include "Framework/Object.h"
#include "Net/DataQueue.h"

namespace sys
{
	class Client;
	class StreamWriter;

	// http���ػص�
	typedef void (Object::*downloadedCallback)(int32_t tag, const std::string& content);

	// http���ش���
	typedef std::pair<Object*, downloadedCallback> HttpDownloadedCallback;

	typedef std::function<void(int32_t tag, const std::string& content)> HttpDownloadedFunc;
	typedef std::function<void(int32_t tag, const char* data, int32_t len)> HttpDownloadingFunc;

	// http����
	class HttpDownload : public Object
	{
		struct DownloadSlot
		{
			int32_t id = 0;
			int32_t tag = 0;
			HttpDownloadedCallback handler;
			HttpDownloadedFunc func = nullptr;
			Client* client = nullptr;
			std::string localpath;

			void hand(const std::string& body);
		};
	public:
		HttpDownload();
		virtual ~HttpDownload();
	public:
		/**
		*   @brief �����ļ�
		*   @param url Զ��ip��ַ
		*   @param filepath �ļ�·��
		*   @param recvHander �������ݴ���
		*   @param callback ������ɻص�
		*   @param tag ��ʾ
		*/
		bool startTask(const std::string& url, const std::string& filepath, HttpDownloadedCallback callback, int32_t tag = 0);
		/**
		*   @brief �����ļ�
		*   @param url Զ��ip��ַ
		*   @param filepath �ļ�·��
		*   @param recvFunc �������ݴ���
		*   @param callback ������ɻص�
		*   @param tag ��ʾ
		*/
		bool startTask(const std::string& url, const std::string& filepath, HttpDownloadedFunc func, int32_t tag = 0);
		// ����ʱ�ص�
		void setDownloadingFunc(HttpDownloadingFunc func);
		// ���ͼ�����������
		void flushData(int32_t id);


		static void parseHttpURL(const std::string& url, std::string& ip, int32_t& port, std::string& filepath, std::string& values);
	protected:
		// ��ʼ���ͻ���
		Client* initClient(const std::string& url);
		// �������ݻص�
		void onRecvHandle(int32_t id, DataQueue& data);
		// ���һ�����ؼ���
		void addListen(Client* client, const std::string& localpath, HttpDownloadedCallback callback, HttpDownloadedFunc func, int32_t tag = 0);
		// �������
		void clear();
	private:
		// ��������
		std::map<int32_t, StreamWriter*> _downloadDatas;

		// ���ػص�
		std::map<int32_t, DownloadSlot > _downloadSlots;

		// ����ʱ�ص�
		HttpDownloadingFunc _downloadingFunc = nullptr;
	};
}