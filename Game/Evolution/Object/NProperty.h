#pragma once

#include "NMark.h"
#include <string>

namespace nature
{
	class NObject;
	class NProperty;
	typedef void (NObject::*NPropertyChanged)(NProperty* pProperty);

	// 属性
	class NProperty : public NMark
	{
	public:
		NProperty();
		~NProperty();
	public:
		// 当前属性值
		void setValue(int value);
		int getValue();
		// 属性最小值
		void setMinValue(int value);
		int getMinValue();
		// 属性最大值
		void setMaxValue(int value);
		int getMaxValue();

		// 注册监听
		void registerChangedHandler(NObject* pTarget, NPropertyChanged handler);
		// 注销监听
		void resetChangedHandler();
	protected:
		virtual void onRunChangedHand();
	private:
		int _value; // 当前值
		std::pair<int, int> _valueRange; // 值域[min,max]
		std::pair<NObject*, NPropertyChanged> _trigger; // 触发器
	};

}