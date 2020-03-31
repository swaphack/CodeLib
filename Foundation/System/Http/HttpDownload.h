#pragma once

#include <string>
#include <cstdint>
#include <map>
#include "Framework/Object.h"
#include "Net/DataQueue.h"

namespace sys
{
	class Client;
	class StreamWriter;

	// http���ػص�
	typedef void (Object::*downloadCallback)(int32_t tag, const std::string& content);

	// http���ش���
	typedef std::pair<Object*, downloadCallback> HttpDownloadCallback;

	// http����
	class HttpDownload : public Object
	{
		struct DownloadSlot
		{
			int32_t id = 0;
			int32_t tag = 0;
			HttpDownloadCallback handler;
			Client* client = nullptr;
		};
	public:
		HttpDownload();
		~HttpDownload();
	public:
		/**
		*   @brief �����ļ�
		*   @param url Զ��ip��ַ
		*   @param port �˿ں�
		*   @param filepath �ļ�·��
		*   @param callback ������ɻص�
		*   @param tag ��ʾ
		*/
		bool download(const std::string& url, int32_t port, const std::string& filepath, HttpDownloadCallback callback, int32_t tag);

		// ���ͼ�����������
		void flushListenData(int32_t id);
	protected:
		// �������ݻص�
		void onRecvHandle(int32_t id, DataQueue& data);
		// ���һ�����ؼ���
		void addListen(Client* client, HttpDownloadCallback callback, int32_t tag);
		// �������
		void clear();
	private:
		// ��������
		std::map<int32_t, StreamWriter*> _downloadDatas;

		// ���ػص�
		std::map<int32_t, DownloadSlot > _downloadSlots;
	};
}