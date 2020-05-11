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
		// 获得编号
		virtual uint64_t getID() const;
		// 增加引用次数
		void retain();
		// 减少引用次数
		void release();
		// 销毁
		void dispose();
		// 自动释放，需要调用G_AUTORELEASEPOOL的管理
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
		// 引用次数
		int32_t RetainCount;
		// 设置编号
		void setID(uint64_t id);
	private:
		// 编号
		uint64_t _id = 0;
		// 是否自动释放
		bool _bAutoRelease = false;
	};

#define CREATE_OBJECT(OBJECT_TYPE) sys::createObject<OBJECT_TYPE>()

	template<typename T, typename=std::enable_if<std::is_base_of<Object, T>::value, T>::type>
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