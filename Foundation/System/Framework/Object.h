#pragma once

#include "Base/Types.h"

namespace sys
{
	class Object
	{
	public:
		Object(int64 id = 0);
		virtual ~Object();
	public:
		// 获得编号
		virtual int64 getID() const;
		// 增加引用次数
		void retain();
		// 减少引用次数
		void release();
		// 销毁
		void dispose();
		// 自动释放，需要调用G_AUTORELEASEPOOL的管理
		void autoRelease();
	public:
		// 引用次数
		int32 RetainCount;
	protected:
		// 设置编号
		void setID(int32 id);
	private:
		// 编号
		int64 _id;
		// 是否自动释放
		bool _bAutoRelease;
	};
}