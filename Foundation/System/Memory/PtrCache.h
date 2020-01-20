#pragma once

#include "Base/macros.h"
#include "PtrInfo.h"

#include <map>
#include <cstdint>

namespace sys
{
	// ����
	class PtrCache : public Name
	{
		friend class Memory; 
	private:
		PtrCache(char* ptr, uint32_t size);
		virtual ~PtrCache();
	public:
		// ��ȡ�û��Զ������͵Ļ���ָ��
		template<typename T>
		T* getPtr();
		// ��ȡ�û��Զ������͵Ļ���ֵ
		template<typename T>
		T getValue();
		// ����
		void reset();
	protected:
		// ����ռ�
		char* alloctPtr(uint32_t size);
	private:
		// PtrCache��Ϣ{ָ�룬 ��С}
		Tuple2<char*, uint32_t> _cacheInfo;
		// ��ǰ�α�λ��
		uint32_t _cursor;
		// �ѷ�����ڴ��
		std::map<uint32_t, PtrInfo> _alloctedPtrs;
	};

	template<typename T>
	T* PtrCache::getPtr()
	{
		uint32_t size = sizeof(T);
		return (T*)alloctPtr(size);
	}

	template<typename T>
	T PtrCache::getValue()
	{
		uint32_t size = sizeof(T);
		return *((T*)alloctPtr(size));
	}
}