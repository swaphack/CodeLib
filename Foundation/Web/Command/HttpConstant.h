#pragma once

namespace web
{
	// ����
	class HttpConstant
	{
	public:
		// �����ȡRequest-URI����ʶ����Դ
		static const char* HTTP_GET/* = "GET"*/;
		// ��Request-URI����ʶ����Դ�󸽼��µ�����
		static const char* HTTP_POST/* = "POST"*/;
		// �����ȡ��Request-URI����ʶ����Դ����Ӧ��Ϣ��ͷ
		static const char* HTTP_HEAD/* = "HEAD"*/;
		// ����������洢һ����Դ������Request-URI��Ϊ���ʶ
		static const char* HTTP_PUT/* = "PUT"*/;
		// ���������ɾ��Request-URI����ʶ����Դ
		static const char* HTTP_DELETE/* = "DELETE"*/;
		// ��������������յ���������Ϣ����Ҫ���ڲ��Ի����
		static const char* HTTP_TRACE/* = "TRACE"*/;
		// ��������ʹ��
		static const char* HTTP_CONNECT/* = "CONNECT"*/;
		// �����ѯ�����������ܣ����߲�ѯ����Դ��ص�ѡ�������
		static const char* HTTP_OPTIONS/* = "OPTIONS"*/;
	};
}