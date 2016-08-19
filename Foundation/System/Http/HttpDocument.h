#pragma once

#include "../Stream/import.h"

#include <string>
#include <vector>
#include <map>

namespace sys
{
	class HttpDocument
	{
	public:
		HttpDocument();
		virtual ~HttpDocument();
	public:
		// 解析字符串，是否是http文档
		bool parse(const char* msg, int size);
		// 生成http字符串
		bool save(std::string& msg);

		// 获取状态参数
		const char* getStatus(int index);
		// 设置状态参数
		void setStatus(int index, const char* value);

		// 获取报头参数
		const char* getHeader(const char* key);
		// 整形格式报头参数
		bool getIntegerHeader(const char* key, int& value);

		// 设置报头参数
		void setHeader(const char* key, const char* value);
		// 时间格式报头参数
		void setDateHeader(const char* key, Time* value);
		// 整形格式报头参数
		void setIntegerHeader(const char* key, int value);

		// 可选的消息体
		void setBody(const char* value, int size);
		// 可选的消息体
		const char* getBody();
		// 可选消息体长度
		int getBodySize();
		// 获取流长度
		int getStreamSize();
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