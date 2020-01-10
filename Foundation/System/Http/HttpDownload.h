#pragma once

#include "Framework/Object.h"
#include "Net/import.h"
#include "Stream/import.h"

namespace sys
{
	// http���ػص�
	typedef void (Object::*downloadCallback)(int32_t tag, const char* data, int32_t size);

	// http���ش���
	typedef std::pair<Object*, downloadCallback> OnHttpDownloadCallback;

	// http����
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
		@brief �����ļ�
		@param url Զ��ip��ַ
		@param port �˿ں�
		@param filepath �ļ�·��
		@param callback ������ɻص�
		@param tag ��ʾ
		*/
		bool download(const char* url, int32_t port, const char* filepath, OnHttpDownloadCallback callback, int32_t tag);

		// ���ͼ�����������
		void flushListenData(int32_t id);
	protected:
		// �������ݻص�
		void onRecvHandle(int32_t id, DataQueue& data);
		// ���һ�����ؼ���
		void addListen(Client* client, OnHttpDownloadCallback callback, int32_t tag);
		// �������
		void clear();
	private:
		// ��������
		std::map<int32_t, StreamWriter*> _downloadDatas;

		// ���ػص�
		std::map<int32_t, DownloadSlot > _downloadSlots;
	};
}