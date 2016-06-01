#pragma once

#include "../macros.h"

namespace slg
{
	// ����
	class Building : public Target
	{
	public:
		Building();
		virtual ~Building();
	public:
		// ����
		int getCapacity();
		void setCapacity(int capacity);

		// �ѷ���
		int getAllocated();
		void setAllocated(int allocated);
	protected:
	private:
		// ����
		int _capacity;
		// �ѷ���
		int _allocated;
	};
}