#pragma once


#include "HttpCommand.h"
#include "HttpDocument.h"

namespace sys
{
	class IResource;

	class HttpRespDocument : public HttpDocument
	{
	public:
		HttpRespDocument();
		virtual ~HttpRespDocument();
	public:
		// �����ַ������Ƿ���http�����ĵ�
		bool parseResponse(const char* msg, int32_t len);
		// �汾
		const std::string& getHttpVersion() const;
		void setHttpVersion(const std::string& version);
		// ״̬��
		const std::string& getResponseCode() const;
		void setResponseCode(const std::string& code);
		void setResponseCode(int32_t code);
		// ˵��
		const std::string& getDescribe() const;
		void setDescribe(const std::string& desc);

		// ��Ϣ���ı���ʽ
		void setContentType(const std::string& value);
		// ��Ϣ���ı�����
		void setContentLength(int32_t value);

		// д���ַ���
		void writeContentString(const std::string& value);
		// д���ļ�
		void writeContentFile(const std::string& filename);

		// ������Դ����
		void setResource(IResource* pResource);
		// ��ȡ��Դ����
		IResource* getResource() const;
	private:
		// ��Դ
		IResource* _resource = nullptr;
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
		inline void setChunkSize(int32_t size) { _chunkedSize = size; }
		// ��ȡ�ֿ鳤��
		inline int32_t getChunkSize() { return _chunkedSize; }
		// ������Ϣ
		virtual void makeMessage();
	private:
		HttpRespDocument* _document = nullptr;
		int32_t _chunkedSize = 0;
	};
}