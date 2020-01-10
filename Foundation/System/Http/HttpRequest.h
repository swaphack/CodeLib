#pragma once

#include "Base/Types.h"
#include "HttpCommand.h"
#include "HttpDocument.h"

namespace sys
{
	/*
	http��������������ɣ��ֱ��ǣ������С���Ϣ��ͷ����������

	��������һ���������ſ�ͷ���Կո�ֿ���������������URI��Э��İ汾����ʽ���£�Method Request-URI HTTP-Version CRLF

	���� Method��ʾ���󷽷���Request-URI��һ��ͳһ��Դ��ʶ����HTTP-Version��ʾ�����HTTPЭ��汾��CRLF��ʾ�س��ͻ��У�������Ϊ��β��CRLF�⣬��������ֵ�����CR��LF�ַ�����

	���󷽷������з���ȫΪ��д���ж��֣����������Ľ������£�
	GET     �����ȡRequest-URI����ʶ����Դ
	POST    ��Request-URI����ʶ����Դ�󸽼��µ�����
	HEAD    �����ȡ��Request-URI����ʶ����Դ����Ӧ��Ϣ��ͷ
	PUT     ����������洢һ����Դ������Request-URI��Ϊ���ʶ
	DELETE  ���������ɾ��Request-URI����ʶ����Դ
	TRACE   ��������������յ���������Ϣ����Ҫ���ڲ��Ի����
	CONNECT ��������ʹ��
	OPTIONS �����ѯ�����������ܣ����߲�ѯ����Դ��ص�ѡ�������

	Ӧ�þ�����
	GET��������������ĵ�ַ����������ַ�ķ�ʽ������ҳʱ�����������GET�������������ȡ��Դ��eg:GET /form.html HTTP/1.1 (CRLF)

	POST����Ҫ��������������ܸ��������������ݣ��������ύ����
	eg��POST /reg.jsp HTTP/ (CRLF)
	Accept:image/gif,image/x-xbit,... (CRLF)
	...
	HOST:www.guet.edu.cn (CRLF)
	Content-Length:22 (CRLF)
	Connection:Keep-Alive (CRLF)
	Cache-Control:no-cache (CRLF)
	(CRLF)         //��CRLF��ʾ��Ϣ��ͷ�Ѿ��������ڴ�֮ǰΪ��Ϣ��ͷ
	user=jeffrey&pwd=1234  //��������Ϊ�ύ������

	HEAD������GET����������һ���ģ�����HEAD����Ļ�Ӧ������˵������HTTPͷ���а�������Ϣ��ͨ��GET�������õ�����Ϣ����ͬ�ġ�����������������ش���������Դ���ݣ��Ϳ��Եõ�Request-URI����ʶ����Դ����Ϣ���÷��������ڲ��Գ����ӵ���Ч�ԣ��Ƿ���Է��ʣ��Լ�����Ƿ���¡�
	2������ͷ����
	3����������(��)
	*/

	// http�����ĵ�
	class HttpReqDocument : public HttpDocument
	{
	public:
		HttpReqDocument();
		virtual ~HttpReqDocument();
	public:
		// �����ַ������Ƿ���http�����ĵ�
		bool parseRequest(const char* msg, int32_t size);
		// ����ʽ
		const char* getMethod();
		void setMethod(const char* method);
		// �����ַ
		const char* getUrl();
		void setUrl(const char* url);
		// �汾
		const char* getHttpVersion();
		void setHttpVersion(const char* version);
	};


	// http ����
	class HttpRequest : public HttpCommand
	{
	public:
		HttpRequest();
		virtual ~HttpRequest();
	public:
		HttpReqDocument* getDocument();
		void setDocument(HttpReqDocument* doc);
		// ������Ϣ
		virtual void makeMessage();
	private:
		HttpReqDocument* _document;
	};
}