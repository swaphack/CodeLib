#pragma once


#include "HttpCommand.h"
#include "HttpDocument.h"

namespace sys
{
	class IResource;

	class HttpRespDocument : public HttpDocument
	{
	public:
		HttpRespDocument();
		virtual ~HttpRespDocument();
	public:
		// 解析字符串，是否是http请求文档
		bool parseResponse(const char* msg, int32_t len);
		// 版本
		const std::string& getHttpVersion() const;
		void setHttpVersion(const std::string& version);
		// 状态码
		const std::string& getResponseCode() const;
		void setResponseCode(const std::string& code);
		void setResponseCode(int32_t code);
		// 说明
		const std::string& getDescribe() const;
		void setDescribe(const std::string& desc);

		// 消息体文本格式
		void setContentType(const std::string& value);
		// 消息体文本长度
		void setContentLength(int32_t value);

		// 写入字符串
		void writeContentString(const std::string& value);
		// 写入文件
		void writeContentFile(const std::string& filename);

		// 设置资源管理
		void setResource(IResource* pResource);
		// 获取资源管理
		IResource* getResource() const;
	private:
		// 资源
		IResource* _resource = nullptr;
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
		inline void setChunkSize(int32_t size) { _chunkedSize = size; }
		// 获取分块长度
		inline int32_t getChunkSize() { return _chunkedSize; }
		// 生成消息
		virtual void makeMessage();
	private:
		HttpRespDocument* _document = nullptr;
		int32_t _chunkedSize = 0;
	};
}