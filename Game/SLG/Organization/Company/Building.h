#pragma once

#include "../macros.h"

namespace slg
{
	// 建筑
	class Building : public Target
	{
	public:
		Building();
		virtual ~Building();
	public:
		// 容量
		int getCapacity();
		void setCapacity(int capacity);

		// 已分配
		int getAllocated();
		void setAllocated(int allocated);
	protected:
	private:
		// 容量
		int _capacity;
		// 已分配
		int _allocated;
	};
}