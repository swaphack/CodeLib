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
			*	��������
			*/
			void setData(const std::string& name, void* data);
			/**
			*	���ü�������������
			*/
			void setObjectData(const std::string& name, sys::Object* data);
			/**
			*	����ֵ��������
			*/
			template<typename T>
			void setValueData(const std::string& name, const T& data)
			{
				_data[name] = WorkData();
				_data[name]->setNewData(name, data);
			}
			/**
			*	��ȡ����
			*/
			void* getData(const std::string& name) const;
			/**
			*	��ȡֵ��������
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
			*	��ȡ��������������
			*/
			sys::Object* getObjectData(const std::string& name) const;

			/**
			*	�Ƴ�����
			*/
			void removeData(const std::string& name);
			/**
			*	���
			*/
			void clear();
		protected:
			/**
			*	��ȡ����
			*/
			const WorkData* getWorkData(const std::string& name) const;
		private:
			std::map<std::string, alg::work::WorkData> _data;
		};
	}
}
