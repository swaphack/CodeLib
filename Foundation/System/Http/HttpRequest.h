#pragma once

#include "Base/Types.h"
#include "HttpCommand.h"
#include "HttpDocument.h"

namespace sys
{
	/*
	http请求由三部分组成，分别是：请求行、消息报头、请求正文

	请求行以一个方法符号开头，以空格分开，后面跟着请求的URI和协议的版本，格式如下：Method Request-URI HTTP-Version CRLF

	其中 Method表示请求方法；Request-URI是一个统一资源标识符；HTTP-Version表示请求的HTTP协议版本；CRLF表示回车和换行（除了作为结尾的CRLF外，不允许出现单独的CR或LF字符）。

	请求方法（所有方法全为大写）有多种，各个方法的解释如下：
	GET     请求获取Request-URI所标识的资源
	POST    在Request-URI所标识的资源后附加新的数据
	HEAD    请求获取由Request-URI所标识的资源的响应消息报头
	PUT     请求服务器存储一个资源，并用Request-URI作为其标识
	DELETE  请求服务器删除Request-URI所标识的资源
	TRACE   请求服务器回送收到的请求信息，主要用于测试或诊断
	CONNECT 保留将来使用
	OPTIONS 请求查询服务器的性能，或者查询与资源相关的选项和需求

	应用举例：
	GET方法：在浏览器的地址栏中输入网址的方式访问网页时，浏览器采用GET方法向服务器获取资源，eg:GET /form.html HTTP/1.1 (CRLF)

	POST方法要求被请求服务器接受附在请求后面的数据，常用于提交表单。
	eg：POST /reg.jsp HTTP/ (CRLF)
	Accept:image/gif,image/x-xbit,... (CRLF)
	...
	HOST:www.guet.edu.cn (CRLF)
	Content-Length:22 (CRLF)
	Connection:Keep-Alive (CRLF)
	Cache-Control:no-cache (CRLF)
	(CRLF)         //该CRLF表示消息报头已经结束，在此之前为消息报头
	user=jeffrey&pwd=1234  //此行以下为提交的数据

	HEAD方法与GET方法几乎是一样的，对于HEAD请求的回应部分来说，它的HTTP头部中包含的信息与通过GET请求所得到的信息是相同的。利用这个方法，不必传输整个资源内容，就可以得到Request-URI所标识的资源的信息。该方法常用于测试超链接的有效性，是否可以访问，以及最近是否更新。
	2、请求报头后述
	3、请求正文(略)
	*/

	// http请求文档
	class HttpReqDocument : public HttpDocument
	{
	public:
		HttpReqDocument();
		virtual ~HttpReqDocument();
	public:
		// 解析字符串，是否是http请求文档
		bool parseRequest(const char* msg, int32_t size);
		// 请求方式
		const char* getMethod();
		void setMethod(const char* method);
		// 请求地址
		const char* getUrl();
		void setUrl(const char* url);
		// 版本
		const char* getHttpVersion();
		void setHttpVersion(const char* version);
	};


	// http 请求
	class HttpRequest : public HttpCommand
	{
	public:
		HttpRequest();
		virtual ~HttpRequest();
	public:
		HttpReqDocument* getDocument();
		void setDocument(HttpReqDocument* doc);
		// 生成消息
		virtual void makeMessage();
	private:
		HttpReqDocument* _document;
	};
}