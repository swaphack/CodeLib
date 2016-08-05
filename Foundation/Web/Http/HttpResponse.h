#pragma once

#include <string>
#include "HttpCommand.h"
#include "system.h"

namespace web
{
	/*
	HTTP��Ӧ������������ɣ��ֱ��ǣ�״̬�С���Ϣ��ͷ����Ӧ����

	1��״̬�и�ʽ���£�
	HTTP-Version Status-Code Reason-Phrase CRLF
	���У�HTTP-Version��ʾ������HTTPЭ��İ汾��Status-Code��ʾ���������ص���Ӧ״̬���룻Reason-Phrase��ʾ״̬������ı�������
	״̬��������λ������ɣ���һ�����ֶ�������Ӧ������������ֿ���ȡֵ��
	1xx��ָʾ��Ϣ--��ʾ�����ѽ��գ���������
	2xx���ɹ�--��ʾ�����ѱ��ɹ����ա���⡢����
	3xx���ض���--Ҫ������������и���һ���Ĳ���
	4xx���ͻ��˴���--�������﷨����������޷�ʵ��
	5xx���������˴���--������δ��ʵ�ֺϷ�������
	����״̬���롢״̬������˵����
	200 OK      //�ͻ�������ɹ�
	400 Bad Request  //�ͻ����������﷨���󣬲��ܱ������������
	401 Unauthorized //����δ����Ȩ�����״̬��������WWW-Authenticate��ͷ��һ��ʹ��
	403 Forbidden  //�������յ����󣬵��Ǿܾ��ṩ����
	404 Not Found  //������Դ�����ڣ�eg�������˴����URL
	500 Internal Server Error //��������������Ԥ�ڵĴ���
	503 Server Unavailable  //��������ǰ���ܴ���ͻ��˵�����һ��ʱ�����ָܻ�����
	eg��HTTP/1.1 200 OK ��CRLF��

	2����Ӧ��ͷ����

	3����Ӧ���ľ��Ƿ��������ص���Դ������

	Sample:
	std::string respData = "Hello";
	HttpResponse response;
	response.setContentType("text/html");
	response.setDateHeader(HttpResponeField::DATE, now);
	response.setDateHeader(HttpResponeField::LAST_MODIFIED, now);
	response.setHeader(HttpResponeField::SERVER, "Windows");
	response.setHeader(HttpResponeField::CONNECTION, "close");
	response.setContentLength(respData.size());
	response.setBody(respData.c_str());
	*/
	class HttpResponse : public HttpCommand
	{
	public:
		// http �汾				
		static const char* HTTP_RESPONSE_VERSION/* = "VERSION"*/;
		// ״̬��
		static const char* HTTP_RESPONSE_STATUS/* = "STATUS"*/;
		// ˵��
		static const char* HTTP_RESPONSE_DESCRIBE/* = "DESCRIBE"*/;
	public:
		HttpResponse();
		virtual ~HttpResponse();
	public:
		// ״̬�в���
		void setResponse(const char* key, const char* value);
		// ��Ϣ���ı���ʽ
		void setContentType(const char* value);
		// ��Ϣ���ı�����
		void setContentLength(int value);
		// д���ַ���
		void writeString(const char* value);
		// д���ļ�
		void writeFile(const char* filename);
		// ������Ϣ
		virtual void makeMessage();
		// ������Ϣ,���ض�ȡ�����ĳ���
		virtual int tryParseMessage(const char* msg, int size);
	private:
		// ����������
		void parseResponse(const char* line);
	};
}