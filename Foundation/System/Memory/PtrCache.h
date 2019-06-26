#pragma once

#include "Base/import.h"
#include "PtrInfo.h"

namespace sys
{
	// ����
	class PtrCache : public Name
	{
		friend class Memory; 
	private:
		PtrCache(char* ptr, uint32 size);
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
		char* alloctPtr(uint32 size);
	private:
		// PtrCache��Ϣ{ָ�룬 ��С}
		Tuple2<char*, uint32> _cacheInfo;
		// ��ǰ�α�λ��
		uint32 _cursor;
		// �ѷ�����ڴ��
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