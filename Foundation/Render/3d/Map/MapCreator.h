#pragma once

#include "common.h"

namespace render
{
	class TreeData;

	class MapCreator
	{
	public:
		MapCreator();
		~MapCreator();
	public:
		// ���ɵ�������
		TerrianData* generateTerrian();
		// ����������
		TreeData* generateTree();
	private:

	};
}