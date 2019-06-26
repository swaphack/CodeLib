#pragma once

#include "Base/import.h"
#include "PtrInfo.h"

namespace sys
{
	// 缓存
	class PtrCache : public Name
	{
		friend class Memory; 
	private:
		PtrCache(char* ptr, uint32 size);
		virtual ~PtrCache();
	public:
		// 获取用户自定义类型的缓存指针
		template<typename T>
		T* getPtr();
		// 获取用户自定义类型的缓存值
		template<typename T>
		T getValue();
		// 重置
		void reset();
	protected:
		// 分配空间
		char* alloctPtr(uint32 size);
	private:
		// PtrCache信息{指针， 大小}
		Tuple2<char*, uint32> _cacheInfo;
		// 当前游标位置
		uint32 _cursor;
		// 已分配的内存块
		std::map<uint32, PtrInfo> _alloctedPtrs;
	};

	template<typename T>
	T* PtrCache::getPtr()
	{
		uint32 size = sizeof(T);
		return (T*)alloctPtr(size);
	}

	template<typename T>
	T PtrCache::getValue()
	{
		uint32 size = sizeof(T);
		return *((T*)alloctPtr(size));
	}
}