#pragma once

#include "Basic/Array.h"

namespace math
{
	// �㼯��
	template<typename T, const int Length>
	struct Points : public Array<T, Length>
	{
		typedef Array<T, Length> base;
	public:
		Points(){}
		Points(const T* value)
		{
			this->assign(value);
		}
		virtual ~Points() {}
	public:
		/**
		*	��������
		*/
		bool hasVertex(const T& value) const
		{
			for (int i = 0; i < Length; i++)
			{
				if (base::getValue(i) == value)
				{
					return true;
				}
			}

			return false;
		}
	};

}
