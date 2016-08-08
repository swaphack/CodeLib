#pragma once

#include "system.h"

#include <string>

namespace web
{
	// 缓存身份
	class CacheIdentity : public sys::Name
	{
	public:
		CacheIdentity();
		virtual ~CacheIdentity();
	public:
		// 标识id
		int getID();
		// 缓存管理
		void setInControl(bool status);
		bool isInControl();
	protected:
		// 生成id，由cachemgr生成
		void makeID();
	private:
		// 标识id
		int _id;
		// 是否在缓存管理中
		bool _bInCacheControl;
	};
}