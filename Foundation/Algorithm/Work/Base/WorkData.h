#pragma once

#include "Work/Task/Task.h"
#include <list>
#include <string>
#include <map>

namespace alg
{
	namespace work
	{
		// 数据类型
		enum class WorkDataType
		{
			// 无
			None,
			// 值类型
			Value,
			// 计数器
			Object,
		};
		//  数据
		struct WorkData
		{
		public:
			// 名称
			std::string name;
			// 数据
			void* data = nullptr;
		public:
			WorkData();
			~WorkData();
		public:
			/**
			*	设置数据
			*/
			void setData(const std::string& key, void* value);
			/**
			*	设置带有计数器的数据
			*/
			void setObjectData(const std::string& key, sys::Object* value);
			/**
			*	设置值类型数据，新建对象
			*/
			template<typename T>
			void setNewData(const std::string& key, const T& value)
			{
				T* ptr = new T();
				*ptr = value;
				this->name = key;
				this->data = ptr;
				_releaseType = WorkDataType::Delete;
			}
			/**
			*	设置数据，新建对象
			*/
			WorkDataType getDataType() const;
		private:
			// 是否要释放
			WorkDataType _releaseType = WorkDataType::None;
		};
	}
}