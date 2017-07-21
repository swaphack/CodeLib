#pragma once

#include <string>
#include "HttpCommand.h"
#include "HttpDocument.h"
#include "../Resource/import.h"

namespace sys
{
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
		void setResponseCode(int code);
		// 说明
		const char* getDescribe();
		void setDescribe(const char* desc);

		// 消息体文本格式
		void setContentType(const char* value);
		// 消息体文本长度
		void setContentLength(int value);

		// 写入字符串
		void writeContentString(const std::string& value);
		// 写入文件
		void writeContentFile(const char* filename);

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

		// 设置分块长度
		inline void setChunkSize(int size) { _chunkedSize = size; }
		// 获取分块长度
		inline int getChunkSize() { return _chunkedSize; }
		// 生成消息
		virtual void makeMessage();
	private:
		HttpRespDocument* _document;
		int _chunkedSize;
	};
}