#pragma once

#include <set>
#include "Common/Fragment/FragmentHandle.h"

namespace render
{
	/**
	*	片元操作
	*	顺序: 如果前面的测试或者操作不同通过的话，后面的不执行
	*	1.裁剪测试
	*	2.多重采样操作
	*	3.模板测试
	*	4.深度测试
	*	5.混合
	*	6.逻辑操作
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
