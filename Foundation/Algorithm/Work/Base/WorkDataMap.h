#pragma once
#include <string>
#include <map>
#include "WorkData.h"

namespace alg
{
	namespace work
	{
		class WorkDataMap
		{
		public:
			/**
			*	设置数据
			*/
			void setData(const std::string& name, void* data);
			/**
			*	设置计数器对象数据
			*/
			void setObjectData(const std::string& name, sys::Object* data);
			/**
			*	设置值类型数据
			*/
			template<typename T>
			void setValueData(const std::string& name, const T& data)
			{
				_data[name] = WorkData();
				_data[name]->setNewData(name, data);
			}
			/**
			*	获取数据
			*/
			void* getData(const std::string& name) const;
			/**
			*	获取值类型数据
			*/
			template<typename T>
			T getValueData(const std::string& name) const
			{
				T temp;
				auto pWorkData = getWorkData(name);
				if (pWorkData == nullptr) return temp;
				if (pWorkData->getDataType() != WorkDataType::Value) return temp;
				temp = *((T*)pWorkData->data);
				return temp;
			}
			/**
			*	获取计数器对象数据
			*/
			sys::Object* getObjectData(const std::string& name) const;

			/**
			*	移除数据
			*/
			void removeData(const std::string& name);
			/**
			*	清空
			*/
			void clear();
		protected:
			/**
			*	获取数据
			*/
			const WorkData* getWorkData(const std::string& name) const;
		private:
			std::map<std::string, alg::work::WorkData> _data;
		};
	}
}
