#pragma once

#include "Stream/import.h"

#include <string>
#include <cstdint>
#include <vector>
#include <map>
#include "DateTime/Time.h"

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
	500 int32ernal Server Error //��������������Ԥ�ڵĴ���
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
		bool parse(const std::string& msg);
		// ����http�ַ���
		bool save(std::string& msg);

		// ��ȡ״̬����
		std::string getStatus(int32_t index);
		// ����״̬����
		void setStatus(int32_t index, const std::string& value);

		// ��ȡ��ͷ����
		std::string getHeader(const std::string& key);
		// ���θ�ʽ��ͷ����
		bool getIntegerHeader(const std::string& key, int32_t& value);

		// �Ƴ���ͷ����
		void removeHeader(const std::string& key);
		// ���ñ�ͷ����
		void setHeader(const std::string& key, const std::string& value);
		// ʱ���ʽ��ͷ����
		void setDateHeader(const std::string& key, Time* value);
		// ���θ�ʽ��ͷ����
		void setIntegerHeader(const std::string& key, int32_t value);

		// ��ѡ����Ϣ��
		void setBody(const std::string& value);
		// ��ѡ����Ϣ��
		const std::string& getBody();
		// ��ѡ��Ϣ�峤��
		int32_t getBodySize();
		// ��ȡ������
		int32_t getStreamSize();
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