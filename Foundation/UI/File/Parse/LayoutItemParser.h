#pragma once

#include "IElement.h"

namespace ui
{
	// ���ֽ�����
	class LayoutItemParser : public IElement
	{
	public:
		LayoutItemParser();
		virtual ~LayoutItemParser();
	protected:
		virtual void parseAttributes();
		virtual void saveAttributes();

		virtual LayoutItem* getLayoutItem();
	private:
	};
}