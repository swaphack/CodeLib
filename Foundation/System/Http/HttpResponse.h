#pragma once

#include <string>
#include "HttpCommand.h"
#include "HttpDocument.h"
#include "../Resource/import.h"

namespace sys
{
	class HttpRespDocument : public HttpDocument
	{
	public:
		HttpRespDocument();
		virtual ~HttpRespDocument();
	public:
		// �����ַ������Ƿ���http�����ĵ�
		bool parseResponse(const char* msg, int size);
		// �汾
		const char* getHttpVersion();
		void setHttpVersion(const char* version);
		// ״̬��
		const char* getResponseCode();
		void setResponseCode(const char* code);
		void setResponseCode(int code);
		// ˵��
		const char* getDescribe();
		void setDescribe(const char* desc);

		// ��Ϣ���ı���ʽ
		void setContentType(const char* value);
		// ��Ϣ���ı�����
		void setContentLength(int value);

		// д���ַ���
		void writeContentString(const std::string& value);
		// д���ļ�
		void writeContentFile(const char* filename);

		// ������Դ����
		void setResource(IResource* pResource);
		// ��ȡ��Դ����
		IResource* getResource();
	private:
		// ��Դ
		IResource* _resource;
	};


	// http ����
	class HttpResponse : public HttpCommand
	{
	public:
		HttpResponse();
		virtual ~HttpResponse();
	public:
		HttpRespDocument* getDocument();
		void setDocument(HttpRespDocument* doc);

		// ���÷ֿ鳤��
		inline void setChunkSize(int size) { _chunkedSize = size; }
		// ��ȡ�ֿ鳤��
		inline int getChunkSize() { return _chunkedSize; }
		// ������Ϣ
		virtual void makeMessage();
	private:
		HttpRespDocument* _document;
		int _chunkedSize;
	};
}