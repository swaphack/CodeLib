#pragma once

#include <cstdint>

#include "Map/Base/MapModule.h"
#include "MultiState.h"

namespace alg
{
	/**
	*	��ͼ����
	*/
	template<const uint32_t SlotCount, const uint32_t PositionCount,
		typename M, typename = std::enable_if<std::is_base_of<MapModule, M>::value, M>::type>
	class MapGeneration
	{
	public:
		MapGeneration() {}
		virtual ~MapGeneration() {}
	public:
		void setSeed(uint32_t seed)
		{
			_seed = seed;
		}
	public:
		/**
		*	���ص�ͼ��Դ 
		*/
		void loadMapAssets(const MapAssets& assets)
		{
			const auto& rules = assets.getAllSlotRules();
			for (const auto& item : rules)
			{
				for (const auto& relation : item.second.getAllRelations())
				{
					_slotRelationTable.set(item.first, relation, true);
				}
			}

			_modulesID.removeAllStates();
			const auto& modules = assets.getAllModules();
			for (const auto& item : modules)
			{
				_modulesID.add(item.first);
			}

			for (uint32_t i = 0; i < PositionCount; i++)
			{
				_positionStatus[i] = state;
			}
		}
		/**
		*	���ȡ��һ��ģ��
		*/
		bool randomModule(uint32_t& moduleID) const
		{
			uint32_t count = _modulesID.getCount();
			if (count == 0)
			{
				return false;
			}
			uint32_t value = sys::Random::getNumber(count);
			moduleID = _modulesID.get(value);
			return true;
		}
	private:
		// ��۹�ϵ��
		RelationTable2D<SlotCount> _slotRelationTable;
		// λ��״̬��
		std::map<uint32_t, MultiState> _positionStatus;
		// ģ��
		MultiState _modulesID;
		// �������
		uint32_t _seed = 0;
	};
}
