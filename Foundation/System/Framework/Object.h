#pragma once

#include <cstdint>
#include <functional>

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

		void startThread(const std::function<void()>& func);
	public:
		template<typename T>
		bool is()
		{
			return dynamic_cast<T*>(this) != nullptr;
		}

		template<typename T>
		T* as()
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
		uint64_t _id = 0;
		// �Ƿ��Զ��ͷ�
		bool _bAutoRelease = false;
	};

#define AUTO_RELEASE_OBJECT(object) { if(object) { object->autoRelease(); } }
#define SAFE_RETAIN(x) { if(x) { (x)->retain(); } }
#define SAFE_RELEASE(x) { if(x) { (x)->release(); } }

	template<typename T, typename = std::enable_if<std::is_base_of<sys::Object, T>::value, T>::type>
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

#define CREATE_OBJECT(OBJECT_TYPE) sys::createObject<OBJECT_TYPE>()
}