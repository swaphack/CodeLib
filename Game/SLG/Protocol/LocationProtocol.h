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
		// ��ȡλ������
		int getPositionX();
		int getPositionY();
		int getPositionY();
		sys::Vector getPosition();

		// ����λ��
		void setPositionX(int x);
		void setPositionY(int y);
		void setPositionZ(int z);
		void setPosition(float x, float y, float z = 0);
	protected:
	private:
		// λ��
		int _positionX;
		int _positionY;
		int _positionZ;
	};
}