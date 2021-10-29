#pragma once
#include "Resource/Image/ImageDetail.h"

namespace sys
{
	// 每个字符存储的数据
	class FontCharDetail : public ImageDetail
	{
	public:
		FontCharDetail();
		~FontCharDetail();
	public:
		void setAdvance(float x, float y);
		void setAdvanceX(float x);
		void setAdvanceY(float y);
		int getAdvanceX() const;
		int getAdvanceY() const;
	public:
		//字形原点(0,0)到字形位图最左边象素的距离
		void setDelta(float x, float y);
		//字形原点(0, 0)到字形位图最左边象素的距离x
		void setDeltaX(float x);
		//字形原点(0, 0)到字形位图最左边象素的距离y
		void setDeltaY(float y);
		int getDeltaX() const;
		int getDeltaY() const;
	protected:
		// 实际标准面积-步进,宽度
		int _advX = 0;
		int _advY = 0;

		// 字形原点(0,0)到字形位图最左边象素的水平距离.它以整数象素的形式表示。 
		int _deltaX = 0;
		int _deltaY = 0;
	};
}