#pragma once

#include "Base/Types.h"
#include "IStreamBase.h"
#include "StreamHelper.h"

namespace sys
{
	// 流数据基础，深度拷贝
	class StreamBase : public IStreamBase
	{
	public:
		StreamBase();
		virtual ~StreamBase();
	
	public:
		// 设置数据内容
		virtual void setData(const char* data, ss_t size);
		// 获取数据内容
		const char* getData() const;
		// 获取数据长度
		int32 getLength() const;
		// 设置数据长度
		void setLength(int32 length);
		// 释放流数据
		void freeStream();
	protected:
		// 数据长度
		ss_t _length;
		// 数据内容
		char* _data;
	};

	// 流数据引用基础，浅拷贝
	class StreamBaseRef : public IStreamBase
	{
	public:
		StreamBaseRef();
		virtual ~StreamBaseRef();
	public:
		// 设置数据内容
		virtual void setData(const char* data, ss_t size);
		// 获取数据内容
		const char* getData() const;
		// 获取数据长度
		int32 getLength() const;
		// 设置数据长度
		void setLength(int32 length);
		// 释放流数据
		void freeStream();
	protected:
		// 数据长度
		ss_t _length;
		// 数据内容
		char* _data;
	};

}