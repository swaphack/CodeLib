#pragma once

#include "../Stream/import.h"

#include <string>
#include <vector>
#include <map>

namespace sys
{
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