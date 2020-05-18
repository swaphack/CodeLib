#pragma once

#include <set>
#include "Common/Fragment/FragmentHandle.h"

namespace render
{
	/**
	*	ƬԪ����
	*	˳��: ���ǰ��Ĳ��Ի��߲�����ͬͨ���Ļ�������Ĳ�ִ��
	*	1.�ü�����
	*	2.���ز�������
	*	3.ģ�����
	*	4.��Ȳ���
	*	5.���
	*	6.�߼�����
	*/
	class FragmentOperator : public sys::Object
	{
	public:
		FragmentOperator();
		virtual ~FragmentOperator();
	public:
		template<typename T, typename = std::enable_if<std::is_base_of<FragmentHandle, T>::value, T>::type>
		T* getHandle()
		{
			for (auto item : _handles)
			{
				if (item.second->is<T>())
				{
					return item.second->as<T>();
				}
			}

			auto t = CREATE_OBJECT(T);
			auto type = t->getFragmentType();
			this->removeHandle(type);
			this->addHandle(t);
			return t;
		}
		void removeHandle(FragmentType fragType);
		void addHandle(FragmentHandle* handle);
		void removeAllHandles();
	public:
		void begin();
		void update();
		void end();
	private:
		std::map<FragmentType, FragmentHandle*> _handles;
	};
}
