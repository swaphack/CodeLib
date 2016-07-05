#pragma once

namespace web
{
	// 常量
	class HttpRequestConstant
	{
	public:
		// 请求获取Request-URI所标识的资源
		static const char* HTTP_GET/* = "GET"*/;
		// 在Request-URI所标识的资源后附加新的数据
		static const char* HTTP_POST/* = "POST"*/;
		// 请求获取由Request-URI所标识的资源的响应消息报头
		static const char* HTTP_HEAD/* = "HEAD"*/;
		// 请求服务器存储一个资源，并用Request-URI作为其标识
		static const char* HTTP_PUT/* = "PUT"*/;
		// 请求服务器删除Request-URI所标识的资源
		static const char* HTTP_DELETE/* = "DELETE"*/;
		// 请求服务器回送收到的请求信息，主要用于测试或诊断
		static const char* HTTP_TRACE/* = "TRACE"*/;
		// 保留将来使用
		static const char* HTTP_CONNECT/* = "CONNECT"*/;
		// 请求查询服务器的性能，或者查询与资源相关的选项和需求
		static const char* HTTP_OPTIONS/* = "OPTIONS"*/;
	};



	// 请求字段
	class HttpRequestField
	{
	public:
		//	能够接受的回应内容类型（Content-Types）。参见内容协商。
		static const char* ACCEPT/* = "Accept"*/;

		//	能够接受的字符集
		static const char* ACCEPT_CHARSET/* = "Accept-Charset"*/;

		//	能够接受的编码方式列表。参考 超文本传输协议压缩 
		static const char* ACCEPT_ENCODING/* = "Accept-Encoding"*/;

		//	能够接受的回应内容的自然语言列表。参考 内容协商 。
		static const char* ACCEPT_LANGUAGE/* = "Accept-Language"*/;

		//	能够接受的按照时间来表示的版本
		static const char* ACCEPT_DATETIME/* = "Accept-Datetime"*/;

		//	用于超文本传输协议的认证的认证信息
		static const char* AUTHORIZATION/* = "Authorization"*/;

		//	用来指定在这次的请求/回复链中的所有缓存机制 都必须 遵守的指令
		static const char* CACHE_CONTROL/* = "Cache-Control"*/;

		// 	该浏览器想要优先使用的连接类型
		static const char* CONNECTION/* = "Connection"*/;

		// 	之前由服务器通过 Set- Cookie （下文详述）发送的一个 超文本传输协议Cookie
		static const char* COOKIE/* = "Cookie"*/;

		// 	以 八位字节数组 （8位的字节）表示的请求体的长度
		static const char* CONTENT_LENGTH/* = "Content-Length"*/;

		// 	请求体的内容的二进制 MD5 散列值，以 Base64 编码的结果
		static const char* CONTENT_MD5/* = "Content-MD5"*/;

		// 	请求体的 多媒体类型 （用于POST和PUT请求中） 
		static const char* CONTENT_TYPE/* = "Content-Type"*/;

		//	发送该消息的日期和时间(按照 RFC 7231 中定义的"超文本传输协议日期"格式来发送)
		static const char* DATE/* = "Date"*/;

		// 	表明客户端要求服务器做出特定的行为 
		static const char* EXPECT/* = "Expect"*/;

		// 	发起此请求的用户的邮件地址
		static const char* FROM/* = "From"*/;

		// 	服务器的域名(用于 虚拟 主机 )，以及服务器所监听的 传输控制协议端口 号。如果所请求的端口是对应的服务的标准端口，则 端口 号可被省略。 
		//  自超文件传输协议版本1.1（HTTP / 1.1）开始便是必需字段。
		static const char* HOST/* = "Host"*/;

		// 	仅当客户端提供的实体与服务器上对应的实体相匹配时，才进行对应的操作。主要作用时，用作像 PUT 这样的方法中，仅当从用户上次更新某个资源以来，该资源未被修改的情况下，才更新该资源。 
		static const char* IF_MATCH/* = "If-Match"*/;

		// 	允许在对应的内容未被修改的情况下返回304未修改（ 304 Not Modified )
		static const char* IF_MODIFIED_SINCE/* = "If-Modified-Since"*/;

		// 	允许在对应的内容未被修改的情况下返回304未修改（ 304 Not Modified ），参考 超文本传输协议 的实体标记
		static const char* If_None_Match/* = "If-None-Match"*/;

		// 	如果该实体未被修改过，则向我发送我所缺少的那一个或多个部分；否则，发送整个新的实体 
		static const char* IF_RANGE/* = "If-Range"*/;

		// 	仅当该实体自某个特定时间已来未被修改的情况下，才发送回应
		static const char* IF_UNMODIFIED_SINCE/* = "If-Unmodified-Since"*/;

		//	限制该消息可被代理及网关转发的次数
		static const char* Max_Forwards/* = "Max-Forwards"*/;

		//	发起一个针对 跨来源资源共享 的请求（要求服务器在回应中加入一个‘访问控制-允许来源’（'Access-Control-Allow-Origin'）字段）。 
		static const char* ORIGIN/* = "Origin"*/;

		//	与具体的实现相关，这些字段可能在请求/回应链中的任何时候产生 多种效果。
		static const char* PRAGMA/* = "Pragma"*/;

		//	用来向代理进行认证的认证信息。
		static const char* PROXY_AUTHORIZATION/* = "Proxy-Authorization"*/;

		//	仅请求某个实体的一部分。字节偏移以0开始。参考 字节服务 。
		static const char* RANGE/* = "Range"*/;

		//	表示浏览器所访问的前一个页面，正是那个页面上的某个链接将浏览器带到了当前所请求的这个页面。(“引导者”（“referrer”）这个单词，在RFC 中被拼错了，因此在大部分的软件实现中也拼错了，以至于，错误的拼法成为了标准的用法，还被当成了正确的术语) 
		static const char* REFERER/* = "Referer"*/;

		//	浏览器预期接受的传输编码方式：可使用回应协议头Transfer-Encoding 字段中的那些值，另外还有一个值可用，"trailers"（与" 分 块 "传输方式相关），用来表明，浏览器希望在最后一个尺寸为0的块之后还接收到一些额外的字段。
		static const char* TE/* = "TE"*/;

		//	浏览器的浏览器身份标识字符串 
		static const char* USER_AGENT/* = "User-Agent"*/;

		//	要求服务器升级到另一个协议。
		static const char* UPGRADE/* = "Upgrade"*/;

		//	向服务器告知，这个请求是由哪些代理发出的。
		static const char* VIA/* = "Via"*/;

		//	一个一般性的警告，告知，在实体内容体中可能存在错误。
		static const char* WARNING/* = "Warning"*/;
	};


	class HttpResponeField
	{
	public:
		//	指定哪些网站可参与到 跨来源资源共享 过程中
		static const char* ACCESS_CONTROL_ALLOW_ORIGIN/* = "Access-Control-Allow-Origin"*/;

		//	Specifies which patch document formats this server supports
		static const char* ACCEPT_PATCH/* = "Accept-Patch"*/;

		//	这个服务器支持哪些种类的部分内容范围
		static const char* ACCEPT_RANGES/* = "Accept-Ranges"*/;

		//	这个对象在 代理缓存 中存在的时间，以秒为单位
		static const char* AGE/* = "Age"*/;

		//	对于特定资源有效的动作。针对405不允许该方法（ 405 Method not allowed ）而使用
		static const char* ALLOW/* = "Allow"*/;

		//	向从服务器直到客户端在内的所有缓存机制告知，它们是否可以缓存这个对象。其单位为秒 
		static const char* CACHE_CONTROL/* = "Cache-Control"*/;

		//	针对该连接所预期的选项
		static const char* CONNECTION/* = "Connection"*/;

		//	An opportunity to raise a "File Download" dialogue box for a known MIME type with binary format or suggest a filename for dynamic content. Quotes are necessary with special characters.
		static const char* CONTENT_DISPOSITION/* = "Content-Disposition"*/;

		//	在数据上使用的编码类型。参考 超文本传输协议压缩 
		static const char* CONTENT_ENCODING/* = "Content-Encoding"*/;

		//	内容所使用的语言
		static const char* CONTENT_LANGUAGE/* = "Content-Language"*/;

		//	回应消息体的长度，以 字节 （8位为一字节）为单位
		static const char* CONTENT_LENGTH/* = "Content-Length"*/;

		//	所返回的数据的一个候选位置
		static const char* CONTENT_LOCATION/* = "Content-Location"*/;

		//	回应内容的二进制 MD5 散列，以 Base64 方式编码
		static const char* CONTENT_MD5/* = "Content-MD5"*/;

		//	这条部分消息是属于某条完整消息的哪个部分
		static const char* CONTENT_RANGE/* = "Content-Range"*/;

		//	当前内容的MIME类型 
		static const char* CONTENT_TYPE/* = "Content-Type"*/;

		//	此条消息被发送时的日期和时间(按照 RFC 7231 中定义的“超文本传输协议日期”格式来表示)
		static const char* DATE/* = "Date"*/;

		//	对于某个资源的某个特定版本的一个标识符，通常是一个 消息散列
		static const char* ETAG/* = "ETag"*/;

		//	指定一个日期/时间，超过该时间则认为此回应已经过期
		static const char* EXPIRES/* = "Expires"*/;

		//	所请求的对象的最后修改日期(按照 RFC 7231 中定义的“超文本传输协议日期”格式来表示)
		static const char* LAST_MODIFIED/* = "Last-Modified"*/;

		//	用来表达与另一个资源之间的类型关系，此处所说的类型关系是在 RFC 5988 中定义的
		static const char* LINK/* = "Link"*/;

		//	用来 进行 重定向 ，或者在创建了某个新资源时使用
		static const char* LOCATION/* = "Location"*/;

		//	This field is supposed to set P3P policy, in the form of P3P:CP="your_compact_policy". However, P3P did not take off,[28] most browsers have never fully implemented it, a lot of websites set this field with fake policy text, that was enough to fool browsers the existence of P3P policy and grant permissions for third party cookies.
		static const char* P3P/* = "P3P"*/;

		//	与具体的实现相关，这些字段可能在请求/回应链中的任何时候产生多种效果。
		static const char* PRAGMA/* = "Pragma"*/;

		//	要求在访问代理时提供身份认证信息
		static const char* PROXY_AUTHENTICATE/* = "Proxy-Authenticate"*/;

		//	用于缓解 中间人攻击 ，声明网站的认证用的 传输 层安全协议 证书的散列值
		static const char* PUBLIC_KEY_PINS/* = "Public-Key-Pins"*/;

		//	Used in redirection, or when a new resource has been created. This refresh redirects after 5 seconds.
		static const char* REFRESH/* = "Refresh"*/;

		//	如果某个实体临时不可用，则，此协议头用来告知客户端日后重试。其值可以是一个特定的时间段(以秒为单位)或一个超文本传输协议日期
		static const char* RETRY_AFTER/* = "Retry-After"*/;

		//	服务器的名字
		static const char* SERVER/* = "Server"*/;

		//	HTTP cookie
		static const char* SET_COOKIE/* = "Set-Cookie"*/;

		//	通用网关接口 协议头字段，用来说明当前这个超文本传输协议回应的 状态 。普通的超文本传输协议回应，会使用单独的“状态行”（"Status-Line"）作为替代，这一点是在 RFC 7230 中定义的。
		static const char* STATUS/* = "Status"*/;

		//	A HSTS Policy informing the HTTP client how long to cache the HTTPS only policy and whether this applies to subdomains.
		static const char* STRICT_TRANSPORT_SECURITY/* = "Strict-Transport-Security"*/;

		//	The Trailer general field value indicates that the given set of header fields is present in the trailer of a message encoded with chunked transfer coding.
		static const char* TRAILER/* = "Trailer"*/;

		//	用来将实体安全地传输给用户的编码形式。 当前定义 的方法 包括： 分 块(chunked) 、压缩（compress）、缩小（deflate）、压缩（gzip）、实体（identity）。 
		static const char* Transfer_Encoding/* = "Transfer-Encoding"*/;

		//	要求客户端升级到另一个协议。
		static const char* UPGRADE/* = "Upgrade"*/;

		//	告知下游的代理服务器，应当如何对未来的请求协议头进行匹配，以决定是否可使用已缓存的回应内容而不是重新从原始服务器请求新的内容。 
		static const char* VARY/* = "Vary"*/;

		//	告知代理服务器的客户端，当前回应是通过什么途径发送的。
		static const char* VIA/* = "Via"*/;

		//	一般性的警告，告知在实体内容体中可能存在错误。
		static const char* WARNING/* = "Warning"*/;

		//	表明在请求获取这个实体时应当使用的认证模式。
		static const char* WWW_AUTHENTICATE/* = "WWW-Authenticate"*/;

		//	Clickjacking protection: deny - no rendering within a frame, sameorigin - no rendering if origin mismatch, allow-from - allow from specified location, allowall - non-standard, allow from any location
		static const char* X_FRAME_OPTIONS/* = "X-Frame-Options"*/;
	};
}