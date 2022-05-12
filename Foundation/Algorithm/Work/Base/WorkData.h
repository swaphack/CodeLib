#pragma once

#include "Work/Task/Task.h"
#include <list>
#include <string>
#include <map>

namespace alg
{
	namespace work
	{
		// ��������
		enum class WorkDataType
		{
			// ��
			None,
			// ֵ����
			Value,
			// ������
			Object,
		};
		//  ����
		struct WorkData
		{
		public:
			// ����
			std::string name;
			// ����
			void* data = nullptr;
		public:
			WorkData();
			~WorkData();
		public:
			/**
			*	��������
			*/
			void setData(const std::string& key, void* value);
			/**
			*	���ô��м�����������
			*/
			void setObjectData(const std::string& key, sys::Object* value);
			/**
			*	����ֵ�������ݣ��½�����
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
			*	�������ݣ��½�����
			*/
			WorkDataType getDataType() const;
		private:
			// �Ƿ�Ҫ�ͷ�
			WorkDataType _releaseType = WorkDataType::None;
		};
	}
}