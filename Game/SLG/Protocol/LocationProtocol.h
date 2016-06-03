#pragma once
#include "system.h"

namespace slg
{
	// ��λ
	class LocationProtocol
	{
	public:
		LocationProtocol();
		virtual ~LocationProtocol();
	public:
		// x������
		int getPositionX();
		void setPositionX(int x);
		// y������
		int getPositionY();
		void setPositionY(int y);
		// z������
		int getPositionZ();
		void setPositionZ(int z);
	protected:
	private:
		// λ��
		sys::Vector _position;
	};
}