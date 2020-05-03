#pragma once

#include <cstdint>

namespace sys
{
	class Object
	{
	public:
		Object(uint64_t id = 0);
		virtual ~Object();
	public:
		// ��ñ��
		virtual uint64_t getID() const;
		// �������ô���
		void retain();
		// �������ô���
		void release();
		// ����
		void dispose();
		// �Զ��ͷţ���Ҫ����G_AUTORELEASEPOOL�Ĺ���
		void autoRelease();
	public:
		template<typename T, typename = std::enable_if<std::is_base_of<Object, T>::type, T>::value>
		bool is()
		{
			return dynamic_cast<T*>(this) != nullptr;
		}

		template<typename T, typename = std::enable_if<std::is_base_of<Object, T>::type, T>::value>
		bool as()
		{
			return dynamic_cast<T*>(this);
		}
	public:
		// ���ô���
		int32_t RetainCount;
		// ���ñ��
		void setID(uint64_t id);
	private:
		// ���
		uint64_t _id;
		// �Ƿ��Զ��ͷ�
		bool _bAutoRelease;
	};

#define CREATE_OBJECT(OBJECT_TYPE) sys::createObject<OBJECT_TYPE>()

	template<typename T>
	T* createObject()
	{
		T* temp = new T();
		if (!temp)
		{
			return nullptr;
		}

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}
}