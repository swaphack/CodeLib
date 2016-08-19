#pragma once

#include <string>

#include "CacheIdentity.h"
#include "CacheMgr.h"

namespace sys
{
	class StreamBase;
	// ������
	class CacheGroup : public CacheIdentity
	{
	private:
		CacheGroup();
	public:
		virtual ~CacheGroup();
	public:
		// ����һ��������
		static CacheGroup* create(const char* name);
	public:
		// ��Ӽ�ֵ������
		void set(const std::string& name, const std::string& value);
		// ��ȡ����
		bool get(const std::string& name, std::string& value);
		// �����������
		void clear();

		template<typename T>
		void setT(const char* name, T value);

		template<typename T>
		const T& getT(const char* name);
	private:
		std::map<std::string, StreamBase> _values;
	};

	template<typename T>
	const T& CacheGroup::getT(const char* name)
	{
		char* temp = get(name);
		if (temp == nullptr)
		{
			return nullptr;
		}

		return *(T*)(temp);
	}

	template<typename T>
	void CacheGroup::setT(const char* name, T value)
	{
		if (name == nullptr)
		{
			return;
		}
		int size = sizeof(value);
		char* data = (char*)malloc(size);
		memcpy(data, &value, size);
		this->set(name, data);
		free(data);
	}

}