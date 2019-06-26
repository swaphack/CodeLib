#pragma once

#include "Framework/Object.h"
#include "Net/import.h"
#include "Stream/import.h"

namespace sys
{
	// http���ػص�
	typedef void (Object::*downloadCallback)(int32 tag, const char* data, int32 size);

	// http���ش���
	typedef std::pair<Object*, downloadCallback> OnHttpDownloadCallback;

	// http����
	class HttpDownload : public Object
	{
		struct DownloadSlot
		{
			int32 id = 0;
			int32 tag = 0;
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
		bool download(const char* url, int32 port, const char* filepath, OnHttpDownloadCallback callback, int32 tag);

		// ���ͼ�����������
		void flushListenData(int32 id);
	protected:
		// �������ݻص�
		void onRecvHandle(int32 id, DataQueue& data);
		// ���һ�����ؼ���
		void addListen(Client* client, OnHttpDownloadCallback callback, int32 tag);
		// �������
		void clear();
	private:
		// ��������
		std::map<int32, StreamWriter*> _downloadDatas;

		// ���ػص�
		std::map<int32, DownloadSlot > _downloadSlots;
	};
}