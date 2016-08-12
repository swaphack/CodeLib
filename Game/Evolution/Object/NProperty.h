#pragma once

#include "NMark.h"
#include <string>

namespace nature
{
	class NObject;
	class NProperty;
	typedef void (NObject::*NPropertyChanged)(NProperty* pProperty);

	// ����
	class NProperty : public NMark
	{
	public:
		NProperty();
		~NProperty();
	public:
		// ��ǰ����ֵ
		void setValue(int value);
		int getValue();
		// ������Сֵ
		void setMinValue(int value);
		int getMinValue();
		// �������ֵ
		void setMaxValue(int value);
		int getMaxValue();

		// ע�����
		void registerChangedHandler(NObject* pTarget, NPropertyChanged handler);
		// ע������
		void resetChangedHandler();
	protected:
		virtual void onRunChangedHand();
	private:
		int _value; // ��ǰֵ
		std::pair<int, int> _valueRange; // ֵ��[min,max]
		std::pair<NObject*, NPropertyChanged> _trigger; // ������
	};

}