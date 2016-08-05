#pragma once

#include <map>
#include <string>

#include "macros.h"
#include "system.h"

namespace web
{
	// http����
	class HttpCommand : public Command
	{
	public:
		// http �������˳��
		enum HttpRequestParseOrder
		{
			EHRPO_BEGIN,	// ��ʼ
			EHRPO_REQUEST,	// ������
			EHRPO_HEADER,	// ͷ��Ϣ
			EHRPO_BODY,		// ��Ϣ��
			EHRPO_END,		// ����
		};
	public:
		HttpCommand();
		virtual ~HttpCommand();
	public:
		// ����session id
		void setSessionID(const char* id);
		// ��ȡsession id
		const char* getSessionID();
		// �Ƿ���http��ʽ
		bool isHttpFormat();
		// �����Ƿ���http��ʽ
		void setHttpFormat(bool status);

		// ��ȡ��ͷ����
		const char* getHeader(const char* key);
		// ���θ�ʽ��ͷ����
		bool getIntegerHeader(const char* key, int& value);

		// ���ñ�ͷ����
		void setHeader(const char* key, const char* value);
		// ʱ���ʽ��ͷ����
		void setDateHeader(const char* key, sys::Time* value);
		// ���θ�ʽ��ͷ����
		void setIntegerHeader(const char* key, int value);

		// ��ѡ����Ϣ��
		void setBody(const char* value, int size);
		// ��ѡ����Ϣ��
		const char* getBody();
		// ��ѡ��Ϣ�峤��
		int getBodySize();
		// ������Ϣ
		virtual void makeMessage();
		// ������Ϣ,���ض�ȡ�����ĳ���
		virtual int tryParseMessage(const char* msg, int size);
	protected:
		// ����
		void reset();
	protected:
		// ��һ�в���
		std::map<std::string, std::string> _firstHeader;
		// ��ͷ����
		std::map<std::string, std::string> _headParams;
		// ��ѡ����Ϣ��
		std::string _body;
	private:
		// Ŀ��id
		std::string _sessionID;
		// �Ƿ�http��ʽ
		bool _bHttpFormat;
	};
}