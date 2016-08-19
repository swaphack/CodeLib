#pragma once

#include <string>
#include "HttpCommand.h"
#include "HttpDocument.h"
#include "../Resource/import.h"

namespace sys
{
	/*
	HTTP响应由三个部分组成，分别是：状态行、消息报头、响应正文

	1、状态行格式如下：
	HTTP-Version Status-Code Reason-Phrase CRLF
	其中，HTTP-Version表示服务器HTTP协议的版本；Status-Code表示服务器发回的响应状态代码；Reason-Phrase表示状态代码的文本描述。
	状态代码有三位数字组成，第一个数字定义了响应的类别，且有五种可能取值：
	1xx：指示信息--表示请求已接收，继续处理
	2xx：成功--表示请求已被成功接收、理解、接受
	3xx：重定向--要完成请求必须进行更进一步的操作
	4xx：客户端错误--请求有语法错误或请求无法实现
	5xx：服务器端错误--服务器未能实现合法的请求
	常见状态代码、状态描述、说明：
	200 OK      //客户端请求成功
	400 Bad Request  //客户端请求有语法错误，不能被服务器所理解
	401 Unauthorized //请求未经授权，这个状态代码必须和WWW-Authenticate报头域一起使用
	403 Forbidden  //服务器收到请求，但是拒绝提供服务
	404 Not Found  //请求资源不存在，eg：输入了错误的URL
	500 Internal Server Error //服务器发生不可预期的错误
	503 Server Unavailable  //服务器当前不能处理客户端的请求，一段时间后可能恢复正常
	eg：HTTP/1.1 200 OK （CRLF）

	2、响应报头后述

	3、响应正文就是服务器返回的资源的内容

	Sample:
	std::string respData = "Hello";
	HttpResponse response;
	response.setContentType("text/html");
	response.setDateHeader(HttpResponeField::DATE, now);
	response.setDateHeader(HttpResponeField::LAST_MODIFIED, now);
	response.setHeader(HttpResponeField::SERVER, "Windows");
	response.setHeader(HttpResponeField::CONNECTION, "close");
	response.setContentLength(respData.size());
	response.setBody(respData.c_str());
	*/

	class HttpRespDocument : public HttpDocument
	{
	public:
		HttpRespDocument();
		virtual ~HttpRespDocument();
	public:
		// 解析字符串，是否是http请求文档
		bool parseResponse(const char* msg, int size);
		// 版本
		const char* getHttpVersion();
		void setHttpVersion(const char* version);
		// 状态码
		const char* getResponseCode();
		void setResponseCode(const char* code);
		// 说明
		const char* getDescribe();
		void setDescribe(const char* desc);

		// 消息体文本格式
		void setContentType(const char* value);
		// 消息体文本长度
		void setContentLength(int value);

		// 写入字符串
		void writeString(const char* value);
		// 写入文件
		void writeFile(const char* filename);

		// 设置资源管理
		void setResource(IResource* pResource);
		// 获取资源管理
		IResource* getResource();
	private:
		// 资源
		IResource* _resource;
	};


	// http 反馈
	class HttpResponse : public HttpCommand
	{
	public:
		HttpResponse();
		virtual ~HttpResponse();
	public:
		HttpRespDocument* getDocument();
		void setDocument(HttpRespDocument* doc);
		// 生成消息
		virtual void makeMessage();
	private:
		HttpRespDocument* _document;
	};
}