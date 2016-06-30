#pragma once

#include <string>
#include "HttpCommand.h"

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
		HttpResponse();
		~HttpResponse();
	public:
		// ����Ŀ��id
		void setDestID(int id);
		// ��ȡĿ��id
		int getDestID();
	public:
		// ����Ҫ���͵��ַ���
		void setPostString(const char* data);
	protected:
	private:
		int _destID;

	};
}