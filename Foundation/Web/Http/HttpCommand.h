#pragma once

#include <map>
#include <string>

#include "macros.h"
#include "system.h"

namespace web
{
	// http命令
	class HttpCommand : public Command
	{
	public:
		// http 请求解析顺序
		enum HttpRequestParseOrder
		{
			EHRPO_BEGIN,	// 开始
			EHRPO_REQUEST,	// 请求行
			EHRPO_HEADER,	// 头信息
			EHRPO_BODY,		// 消息体
			EHRPO_END,		// 结束
		};
	public:
		HttpCommand();
		virtual ~HttpCommand();
	public:
		// 设置session id
		void setSessionID(const char* id);
		// 获取session id
		const char* getSessionID();
		// 是否是http格式
		bool isHttpFormat();
		// 设置是否是http格式
		void setHttpFormat(bool status);

		// 获取报头参数
		const char* getHeader(const char* key);
		// 整形格式报头参数
		bool getIntegerHeader(const char* key, int& value);

		// 设置报头参数
		void setHeader(const char* key, const char* value);
		// 时间格式报头参数
		void setDateHeader(const char* key, sys::Time* value);
		// 整形格式报头参数
		void setIntegerHeader(const char* key, int value);

		// 可选的消息体
		void setBody(const char* value, int size);
		// 可选的消息体
		const char* getBody();
		// 可选消息体长度
		int getBodySize();
		// 生成消息
		virtual void makeMessage();
		// 解析消息,返回读取解析的长度
		virtual int tryParseMessage(const char* msg, int size);
	protected:
		// 重置
		void reset();
	protected:
		// 第一行参数
		std::map<std::string, std::string> _firstHeader;
		// 报头参数
		std::map<std::string, std::string> _headParams;
		// 可选的消息体
		std::string _body;
	private:
		// 目标id
		std::string _sessionID;
		// 是否http格式
		bool _bHttpFormat;
	};
}