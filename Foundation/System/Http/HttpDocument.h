#pragma once

#include "Stream/import.h"

#include <string>
#include <vector>
#include <map>

namespace sys
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
	HttpDocument doc;
	doc.setContentType("text/html");
	doc.setDateHeader(HttpResponeField::DATE, now);
	doc.setDateHeader(HttpResponeField::LAST_MODIFIED, now);
	doc.setHeader(HttpResponeField::SERVER, "Windows");
	doc.setHeader(HttpResponeField::CONNECTION, "close");
	doc.setContentLength(respData.size());
	doc.setBody(respData.c_str());
	*/
	class HttpDocument
	{
	public:
		HttpDocument();
		virtual ~HttpDocument();
	public:
		// �����ַ������Ƿ���http�ĵ�
		bool parse(const char* msg, int size);
		// ����http�ַ���
		bool save(std::string& msg);

		// ��ȡ״̬����
		const char* getStatus(int index);
		// ����״̬����
		void setStatus(int index, const char* value);

		// ��ȡ��ͷ����
		const char* getHeader(const char* key);
		// ���θ�ʽ��ͷ����
		bool getIntegerHeader(const char* key, int& value);

		// �Ƴ���ͷ����
		void removeHeader(const char* key);
		// ���ñ�ͷ����
		void setHeader(const char* key, const char* value);
		// ʱ���ʽ��ͷ����
		void setDateHeader(const char* key, Time* value);
		// ���θ�ʽ��ͷ����
		void setIntegerHeader(const char* key, int value);

		// ��ѡ����Ϣ��
		void setBody(const char* value, int size);
		// ��ѡ����Ϣ��
		const char* getBody();
		// ��ѡ��Ϣ�峤��
		int getBodySize();
		// ��ȡ������
		int getStreamSize();
	protected:
		// ����״̬��
		bool readStatusSection();
		// ����ͷ��
		bool readHeaderSection();
		// ����������
		bool readBodySection();
		// ����״̬��
		void resetStatusSection();
	private:
		StringStream* _stream;
		// ״̬��
		std::vector<std::string> _statusSection;
		// ��ͷ��
		std::map<std::string, std::string> _headerSection;
		// �����
		std::string _bodySection;
	};
}