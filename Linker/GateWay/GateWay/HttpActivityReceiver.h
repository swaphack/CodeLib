#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

namespace gw
{
	// http Ӧ��
	class HttpActivityReceiver : public web::HttpActivity
	{
	protected:
		// ����������
		virtual void doGet(sys::HttpRequest* request);
		// http ����
		virtual void doHttpGet(sys::HttpRequest* request);
	private:
		// ��ȡ�����ҳ��
		void handUrlMethod(sys::String& inString, std::string& outString);
		// ��ȡ�ϴ��Ĳ���
		// for url get param(?xx=xx)
		void handGetParamMethod(sys::String& inString, std::map<std::string, std::string>& outParams);
		// for url get param(?xx=xx)
		void handPostParamMethod(sys::String& inString, std::map<std::string, std::string>& outParams);
	};
}