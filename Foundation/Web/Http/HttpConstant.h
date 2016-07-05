#pragma once

namespace web
{
	// ����
	class HttpRequestConstant
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



	// �����ֶ�
	class HttpRequestField
	{
	public:
		//	�ܹ����ܵĻ�Ӧ�������ͣ�Content-Types�����μ�����Э�̡�
		static const char* ACCEPT/* = "Accept"*/;

		//	�ܹ����ܵ��ַ���
		static const char* ACCEPT_CHARSET/* = "Accept-Charset"*/;

		//	�ܹ����ܵı��뷽ʽ�б��ο� ���ı�����Э��ѹ�� 
		static const char* ACCEPT_ENCODING/* = "Accept-Encoding"*/;

		//	�ܹ����ܵĻ�Ӧ���ݵ���Ȼ�����б��ο� ����Э�� ��
		static const char* ACCEPT_LANGUAGE/* = "Accept-Language"*/;

		//	�ܹ����ܵİ���ʱ������ʾ�İ汾
		static const char* ACCEPT_DATETIME/* = "Accept-Datetime"*/;

		//	���ڳ��ı�����Э�����֤����֤��Ϣ
		static const char* AUTHORIZATION/* = "Authorization"*/;

		//	����ָ������ε�����/�ظ����е����л������ ������ ���ص�ָ��
		static const char* CACHE_CONTROL/* = "Cache-Control"*/;

		// 	���������Ҫ����ʹ�õ���������
		static const char* CONNECTION/* = "Connection"*/;

		// 	֮ǰ�ɷ�����ͨ�� Set- Cookie ���������������͵�һ�� ���ı�����Э��Cookie
		static const char* COOKIE/* = "Cookie"*/;

		// 	�� ��λ�ֽ����� ��8λ���ֽڣ���ʾ��������ĳ���
		static const char* CONTENT_LENGTH/* = "Content-Length"*/;

		// 	����������ݵĶ����� MD5 ɢ��ֵ���� Base64 ����Ľ��
		static const char* CONTENT_MD5/* = "Content-MD5"*/;

		// 	������� ��ý������ ������POST��PUT�����У� 
		static const char* CONTENT_TYPE/* = "Content-Type"*/;

		//	���͸���Ϣ�����ں�ʱ��(���� RFC 7231 �ж����"���ı�����Э������"��ʽ������)
		static const char* DATE/* = "Date"*/;

		// 	�����ͻ���Ҫ������������ض�����Ϊ 
		static const char* EXPECT/* = "Expect"*/;

		// 	�����������û����ʼ���ַ
		static const char* FROM/* = "From"*/;

		// 	������������(���� ���� ���� )���Լ��������������� �������Э��˿� �š����������Ķ˿��Ƕ�Ӧ�ķ���ı�׼�˿ڣ��� �˿� �ſɱ�ʡ�ԡ� 
		//  �Գ��ļ�����Э��汾1.1��HTTP / 1.1����ʼ���Ǳ����ֶΡ�
		static const char* HOST/* = "Host"*/;

		// 	�����ͻ����ṩ��ʵ����������϶�Ӧ��ʵ����ƥ��ʱ���Ž��ж�Ӧ�Ĳ�������Ҫ����ʱ�������� PUT �����ķ����У��������û��ϴθ���ĳ����Դ����������Դδ���޸ĵ�����£��Ÿ��¸���Դ�� 
		static const char* IF_MATCH/* = "If-Match"*/;

		// 	�����ڶ�Ӧ������δ���޸ĵ�����·���304δ�޸ģ� 304 Not Modified )
		static const char* IF_MODIFIED_SINCE/* = "If-Modified-Since"*/;

		// 	�����ڶ�Ӧ������δ���޸ĵ�����·���304δ�޸ģ� 304 Not Modified �����ο� ���ı�����Э�� ��ʵ����
		static const char* If_None_Match/* = "If-None-Match"*/;

		// 	�����ʵ��δ���޸Ĺ��������ҷ�������ȱ�ٵ���һ���������֣����򣬷��������µ�ʵ�� 
		static const char* IF_RANGE/* = "If-Range"*/;

		// 	������ʵ����ĳ���ض�ʱ������δ���޸ĵ�����£��ŷ��ͻ�Ӧ
		static const char* IF_UNMODIFIED_SINCE/* = "If-Unmodified-Since"*/;

		//	���Ƹ���Ϣ�ɱ���������ת���Ĵ���
		static const char* Max_Forwards/* = "Max-Forwards"*/;

		//	����һ����� ����Դ��Դ���� ������Ҫ��������ڻ�Ӧ�м���һ�������ʿ���-������Դ����'Access-Control-Allow-Origin'���ֶΣ��� 
		static const char* ORIGIN/* = "Origin"*/;

		//	������ʵ����أ���Щ�ֶο���������/��Ӧ���е��κ�ʱ����� ����Ч����
		static const char* PRAGMA/* = "Pragma"*/;

		//	��������������֤����֤��Ϣ��
		static const char* PROXY_AUTHORIZATION/* = "Proxy-Authorization"*/;

		//	������ĳ��ʵ���һ���֡��ֽ�ƫ����0��ʼ���ο� �ֽڷ��� ��
		static const char* RANGE/* = "Range"*/;

		//	��ʾ����������ʵ�ǰһ��ҳ�棬�����Ǹ�ҳ���ϵ�ĳ�����ӽ�����������˵�ǰ����������ҳ�档(�������ߡ�����referrer����������ʣ���RFC �б�ƴ���ˣ�����ڴ󲿷ֵ����ʵ����Ҳƴ���ˣ������ڣ������ƴ����Ϊ�˱�׼���÷���������������ȷ������) 
		static const char* REFERER/* = "Referer"*/;

		//	�����Ԥ�ڽ��ܵĴ�����뷽ʽ����ʹ�û�ӦЭ��ͷTransfer-Encoding �ֶ��е���Щֵ�����⻹��һ��ֵ���ã�"trailers"����" �� �� "���䷽ʽ��أ������������������ϣ�������һ���ߴ�Ϊ0�Ŀ�֮�󻹽��յ�һЩ������ֶΡ�
		static const char* TE/* = "TE"*/;

		//	��������������ݱ�ʶ�ַ��� 
		static const char* USER_AGENT/* = "User-Agent"*/;

		//	Ҫ���������������һ��Э�顣
		static const char* UPGRADE/* = "Upgrade"*/;

		//	���������֪���������������Щ�������ġ�
		static const char* VIA/* = "Via"*/;

		//	һ��һ���Եľ��棬��֪����ʵ���������п��ܴ��ڴ���
		static const char* WARNING/* = "Warning"*/;
	};


	class HttpResponeField
	{
	public:
		//	ָ����Щ��վ�ɲ��뵽 ����Դ��Դ���� ������
		static const char* ACCESS_CONTROL_ALLOW_ORIGIN/* = "Access-Control-Allow-Origin"*/;

		//	Specifies which patch document formats this server supports
		static const char* ACCEPT_PATCH/* = "Accept-Patch"*/;

		//	���������֧����Щ����Ĳ������ݷ�Χ
		static const char* ACCEPT_RANGES/* = "Accept-Ranges"*/;

		//	��������� ������ �д��ڵ�ʱ�䣬����Ϊ��λ
		static const char* AGE/* = "Age"*/;

		//	�����ض���Դ��Ч�Ķ��������405������÷����� 405 Method not allowed ����ʹ��
		static const char* ALLOW/* = "Allow"*/;

		//	��ӷ�����ֱ���ͻ������ڵ����л�����Ƹ�֪�������Ƿ���Ի�����������䵥λΪ�� 
		static const char* CACHE_CONTROL/* = "Cache-Control"*/;

		//	��Ը�������Ԥ�ڵ�ѡ��
		static const char* CONNECTION/* = "Connection"*/;

		//	An opportunity to raise a "File Download" dialogue box for a known MIME type with binary format or suggest a filename for dynamic content. Quotes are necessary with special characters.
		static const char* CONTENT_DISPOSITION/* = "Content-Disposition"*/;

		//	��������ʹ�õı������͡��ο� ���ı�����Э��ѹ�� 
		static const char* CONTENT_ENCODING/* = "Content-Encoding"*/;

		//	������ʹ�õ�����
		static const char* CONTENT_LANGUAGE/* = "Content-Language"*/;

		//	��Ӧ��Ϣ��ĳ��ȣ��� �ֽ� ��8λΪһ�ֽڣ�Ϊ��λ
		static const char* CONTENT_LENGTH/* = "Content-Length"*/;

		//	�����ص����ݵ�һ����ѡλ��
		static const char* CONTENT_LOCATION/* = "Content-Location"*/;

		//	��Ӧ���ݵĶ����� MD5 ɢ�У��� Base64 ��ʽ����
		static const char* CONTENT_MD5/* = "Content-MD5"*/;

		//	����������Ϣ������ĳ��������Ϣ���ĸ�����
		static const char* CONTENT_RANGE/* = "Content-Range"*/;

		//	��ǰ���ݵ�MIME���� 
		static const char* CONTENT_TYPE/* = "Content-Type"*/;

		//	������Ϣ������ʱ�����ں�ʱ��(���� RFC 7231 �ж���ġ����ı�����Э�����ڡ���ʽ����ʾ)
		static const char* DATE/* = "Date"*/;

		//	����ĳ����Դ��ĳ���ض��汾��һ����ʶ����ͨ����һ�� ��Ϣɢ��
		static const char* ETAG/* = "ETag"*/;

		//	ָ��һ������/ʱ�䣬������ʱ������Ϊ�˻�Ӧ�Ѿ�����
		static const char* EXPIRES/* = "Expires"*/;

		//	������Ķ��������޸�����(���� RFC 7231 �ж���ġ����ı�����Э�����ڡ���ʽ����ʾ)
		static const char* LAST_MODIFIED/* = "Last-Modified"*/;

		//	�����������һ����Դ֮������͹�ϵ���˴���˵�����͹�ϵ���� RFC 5988 �ж����
		static const char* LINK/* = "Link"*/;

		//	���� ���� �ض��� �������ڴ�����ĳ������Դʱʹ��
		static const char* LOCATION/* = "Location"*/;

		//	This field is supposed to set P3P policy, in the form of P3P:CP="your_compact_policy". However, P3P did not take off,[28] most browsers have never fully implemented it, a lot of websites set this field with fake policy text, that was enough to fool browsers the existence of P3P policy and grant permissions for third party cookies.
		static const char* P3P/* = "P3P"*/;

		//	������ʵ����أ���Щ�ֶο���������/��Ӧ���е��κ�ʱ���������Ч����
		static const char* PRAGMA/* = "Pragma"*/;

		//	Ҫ���ڷ��ʴ���ʱ�ṩ�����֤��Ϣ
		static const char* PROXY_AUTHENTICATE/* = "Proxy-Authenticate"*/;

		//	���ڻ��� �м��˹��� ��������վ����֤�õ� ���� �㰲ȫЭ�� ֤���ɢ��ֵ
		static const char* PUBLIC_KEY_PINS/* = "Public-Key-Pins"*/;

		//	Used in redirection, or when a new resource has been created. This refresh redirects after 5 seconds.
		static const char* REFRESH/* = "Refresh"*/;

		//	���ĳ��ʵ����ʱ�����ã��򣬴�Э��ͷ������֪�ͻ����պ����ԡ���ֵ������һ���ض���ʱ���(����Ϊ��λ)��һ�����ı�����Э������
		static const char* RETRY_AFTER/* = "Retry-After"*/;

		//	������������
		static const char* SERVER/* = "Server"*/;

		//	HTTP cookie
		static const char* SET_COOKIE/* = "Set-Cookie"*/;

		//	ͨ�����ؽӿ� Э��ͷ�ֶΣ�����˵����ǰ������ı�����Э���Ӧ�� ״̬ ����ͨ�ĳ��ı�����Э���Ӧ����ʹ�õ����ġ�״̬�С���"Status-Line"����Ϊ�������һ������ RFC 7230 �ж���ġ�
		static const char* STATUS/* = "Status"*/;

		//	A HSTS Policy informing the HTTP client how long to cache the HTTPS only policy and whether this applies to subdomains.
		static const char* STRICT_TRANSPORT_SECURITY/* = "Strict-Transport-Security"*/;

		//	The Trailer general field value indicates that the given set of header fields is present in the trailer of a message encoded with chunked transfer coding.
		static const char* TRAILER/* = "Trailer"*/;

		//	������ʵ�尲ȫ�ش�����û��ı�����ʽ�� ��ǰ���� �ķ��� ������ �� ��(chunked) ��ѹ����compress������С��deflate����ѹ����gzip����ʵ�壨identity���� 
		static const char* Transfer_Encoding/* = "Transfer-Encoding"*/;

		//	Ҫ��ͻ�����������һ��Э�顣
		static const char* UPGRADE/* = "Upgrade"*/;

		//	��֪���εĴ����������Ӧ����ζ�δ��������Э��ͷ����ƥ�䣬�Ծ����Ƿ��ʹ���ѻ���Ļ�Ӧ���ݶ��������´�ԭʼ�����������µ����ݡ� 
		static const char* VARY/* = "Vary"*/;

		//	��֪����������Ŀͻ��ˣ���ǰ��Ӧ��ͨ��ʲô;�����͵ġ�
		static const char* VIA/* = "Via"*/;

		//	һ���Եľ��棬��֪��ʵ���������п��ܴ��ڴ���
		static const char* WARNING/* = "Warning"*/;

		//	�����������ȡ���ʵ��ʱӦ��ʹ�õ���֤ģʽ��
		static const char* WWW_AUTHENTICATE/* = "WWW-Authenticate"*/;

		//	Clickjacking protection: deny - no rendering within a frame, sameorigin - no rendering if origin mismatch, allow-from - allow from specified location, allowall - non-standard, allow from any location
		static const char* X_FRAME_OPTIONS/* = "X-Frame-Options"*/;
	};
}