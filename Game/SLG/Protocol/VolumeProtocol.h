#pragma once

#include "system.h"

namespace slg
{
	// ���
	class VolumeProtocol
	{
	public:
		VolumeProtocol();
		virtual ~VolumeProtocol();
	public:
		void setWidth(int width);
		int getWidth();

		void setHeight(int height);
		int getHeight();

		void setDeep(int deep);
		int getDeep();
	protected:
	private:
		sys::Volume _volume;
	};
}