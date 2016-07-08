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
		// ��ͷ����
		void setHeader(const char* key, const char* value);
		// ʱ���ʽ��ͷ����
		void setDateHeader(const char* key, sys::Time* value);
		// ���θ�ʽ��ͷ����
		void setIntegerHeader(const char* key, int value);
		// ��Ϣ���ı���ʽ
		void setContentType(const char* value);
		// ��Ϣ���ı�����
		void setContentLength(int value);
		// ��ѡ����Ϣ��
		void setBody(const char* value);
		// ������Ϣ
		void makeMessage();
	private:
		// �����в���
		std::map<std::string, std::string> _responseParams;
		// ��ͷ����
		std::map<std::string, std::string> _headParams;
		// ��ѡ����Ϣ��
		std::string _body;
	};
}