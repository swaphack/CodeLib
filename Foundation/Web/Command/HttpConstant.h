#pragma once

namespace web
{
	// 常量
	class HttpConstant
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
}