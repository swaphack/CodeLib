#pragma once

#include "system.h"

namespace alg
{
	/**
	*	对象信息
	*/
	class ObjectDetail : public sys::Object
	{
	public:
		ObjectDetail();
		virtual ~ObjectDetail();
	public:
		/**
		*	设置名字
		*/
		void setName(const std::string& name);
		/**
		*	获取名字
		*/
		const std::string& getName() const;
		/**
		*	设置标记
		*/
		void setTag(int tag);
		/**
		*	获取标记
		*/
		int getTag() const;
	protected:
		// 名字
		std::string _name;
		// 标记
		int _tag = 0;
	};
}