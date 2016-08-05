#pragma once

#include "system.h"

namespace web
{
	typedef void (*downloadCallback)(int tag, const char* data, int size);

	// http����
	class HttpDownload : public sys::Object
	{
	public:
		HttpDownload();
		~HttpDownload();
	public:
		bool download(const char* url, int port, const char* filepath, downloadCallback callback, int tag);
		// ���ͼ�����������
		void flushListenData(int id);
	protected:
		// �������ݻص�
		void onRecvHand(int id, sys::DataQueue& data);
		// ���һ�����ؼ���
		void addListen(sys::Client* client, downloadCallback callback, int tag);
		// �������
		void clear();
	private:
		// ��������
		std::map<int, sys::StreamWriter*> _downloadDatas;

		typedef std::map<int, sys::Tuple3<int, downloadCallback, sys::Client*> > DownloadCallback;
		// ���ػص�
		DownloadCallback _downloadCallbacks;
	};
}