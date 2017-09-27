#pragma once

#include "Framework/Object.h"
#include "Net/import.h"
#include "Stream/import.h"

namespace sys
{
	// http���ػص�
	typedef void (Object::*downloadCallback)(int tag, const char* data, int size);

	// http���ش���
	typedef std::pair<Object*, downloadCallback> OnHttpDownloadCallback;

	// http����
	class HttpDownload : public Object
	{
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
		bool download(const char* url, int port, const char* filepath, OnHttpDownloadCallback callback, int tag);
		// ���ͼ�����������
		void flushListenData(int id);
	protected:
		// �������ݻص�
		void onRecvHandle(int id, DataQueue& data);
		// ���һ�����ؼ���
		void addListen(Client* client, OnHttpDownloadCallback callback, int tag);
		// �������
		void clear();
	private:
		// ��������
		std::map<int, StreamWriter*> _downloadDatas;

		typedef std::map<int, Tuple3<int, OnHttpDownloadCallback, Client*> > DownloadCallback;
		// ���ػص�
		DownloadCallback _downloadCallbacks;
	};
}