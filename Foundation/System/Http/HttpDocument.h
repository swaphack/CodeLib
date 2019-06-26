#pragma once

#include "Stream/import.h"

#include "Base/Types.h"

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
	500 int32ernal Server Error //服务器发生不可预期的错误
	503 Server Unavailable  //服务器当前不能处理客户端的请求，一段时间后可能恢复正常
	eg：HTTP/1.1 200 OK （CRLF）

	2、响应报头后述

	3、响应正文就是服务器返回的资源的内容

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
		// 解析字符串，是否是http文档
		bool parse(const char* msg, int32 size);
		// 生成http字符串
		bool save(std::string& msg);

		// 获取状态参数
		const char* getStatus(int32 index);
		// 设置状态参数
		void setStatus(int32 index, const char* value);

		// 获取报头参数
		const char* getHeader(const char* key);
		// 整形格式报头参数
		bool getint32egerHeader(const char* key, int32& value);

		// 移除报头参数
		void removeHeader(const char* key);
		// 设置报头参数
		void setHeader(const char* key, const char* value);
		// 时间格式报头参数
		void setDateHeader(const char* key, Time* value);
		// 整形格式报头参数
		void setint32egerHeader(const char* key, int32 value);

		// 可选的消息体
		void setBody(const char* value, int32 size);
		// 可选的消息体
		const char* getBody();
		// 可选消息体长度
		int32 getBodySize();
		// 获取流长度
		int32 getStreamSize();
	protected:
		// 解析状态行
		bool readStatusSection();
		// 解析头行
		bool readHeaderSection();
		// 解析身体行
		bool readBodySection();
		// 重置状态行
		void resetStatusSection();
	private:
		StringStream* _stream;
		// 状态段
		std::vector<std::string> _statusSection;
		// 报头段
		std::map<std::string, std::string> _headerSection;
		// 报体段
		std::string _bodySection;
	};
}