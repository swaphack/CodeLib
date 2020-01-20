#pragma once

#include "CacheIdentity.h"
#include "CacheMgr.h"

namespace sys
{
	class StreamBase;
	// 缓存组
	class CacheGroup : public CacheIdentity
	{
	private:
		CacheGroup();
	public:
		virtual ~CacheGroup();
	public:
		// 创建一个缓存组
		static CacheGroup* create(const std::string& name);
	public:
		// 添加键值对数据
		void set(const std::string& name, const std::string& value);
		// 获取数据
		bool get(const std::string& name, std::string& value);
		// 清空所有数据
		void clear();

		template<typename T>
		void setT(const std::string& name, T value);

		template<typename T>
		const T& getT(const std::string& name);
	private:
		std::map<std::string, StreamBase> _values;
	};

	template<typename T>
	const T& CacheGroup::getT(const std::string& name)
	{
		char* temp = get(name);
		if (temp == nullptr)
		{
			return nullptr;
		}

		return *(T*)(temp);
	}

	template<typename T>
	void CacheGroup::setT(const std::string& name, T value)
	{
		if (name == nullptr)
		{
			return;
		}
		int32_t size = sizeof(value);
		char* data = (char*)malloc(size);
		memcpy(data, &value, size);
		this->set(name, data);
		free(data);
	}

}