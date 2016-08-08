#pragma once

#include "../Base/import.h"
#include "PtrInfo.h"
#include <string>
#include <map>

namespace sys
{
	// ����
	class PtrCache : public sys::Name
	{
		friend class Memory; 
	private:
		PtrCache(char* ptr, uint size);
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
		char* alloctPtr(uint size);
	private:
		// PtrCache��Ϣ{ָ�룬 ��С}
		sys::Tuple2<char*, uint> _cacheInfo;

		// ��ǰ�α�λ��
		uint _cursor;
		// �ѷ�����ڴ��
		std::map<uint, PtrInfo> _alloctedPtrs;
	};

	template<typename T>
	T* PtrCache::getPtr()
	{
		uint size = sizeof(T);
		return (T*)alloctPtr(size);
	}

	template<typename T>
	T sys::PtrCache::getValue()
	{
		uint size = sizeof(T);
		return *((T*)alloctPtr(size));
	}
}