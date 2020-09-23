#pragma once

#include <cstdint>
#include <map>
#include "MultiState.h"

namespace alg
{
	namespace map
	{
		class CreateMapProtocol;
		class MapProtocol;
		class Module;
		/**
		*	波函数坍塌算法
		*
		*
		确定要生成的图的大小，然后对于每一个固定大小的小区域，考虑每一种“局部信息”的是否可能出现。这些概率称为这个小区域的“波函数”。
		将每个小区域的“波函数”初始化。一开始，所有图案都有可能在任何位置出现。
		进行以下的循环：
			选择熵最小的，未确定的小区域（有多个的话，随机取一个），对它进行“观测”，根据可能的图案的频率随机确定它使用的图案（“波函数”发生了“坍缩”）。



			如果所有的小区域都确定了，跳出循环。
			如果有一个格子没有任何的可能的状态，生成失败。


			根据新的观测结果为周围的小区域们排除不合法的图案（影响到了周围格子的“波函数”）。

			在这个过程中可能有新的小区域的图案被完全确定。

		根据小区域使用的图案得到整张图片。
		*/
		class WFCAlgorithm
		{
		public:
			WFCAlgorithm();
			virtual ~WFCAlgorithm();
		public:
			void initMap(uint32_t pointCount, const MultiState& states);

			bool autoFillMap(MapProtocol* map, CreateMapProtocol* creator);
		protected:
			/**
			*	随机方法，尽可能填充
			*/
			bool randomFillPoint(MapProtocol* map, CreateMapProtocol* creator);

			/**
			*	绕指定目标周围开始填充
			*/
			bool roundFillPoint(uint32_t nIndex, MapProtocol* map, CreateMapProtocol* creator);

			/**
			*	设置点信息
			*/
			void setPoint(MapProtocol* map, uint32_t index, uint32_t moduleID);
			/**
			*	重置点信息
			*/
			void resetPoint(MapProtocol* map, uint32_t index);
			/**
			*	是否全部已设置
			*/
			bool isFinish();

			/**
			*	随机获取一个未填充点
			*/
			bool getRandomUnFillPoint(uint32_t& index);
			/**
			*	随机获取一个已填充点,熵值最小
			*/
			bool getRandomFilledPoint(uint32_t& index);

			/**
			*	获取指定位置的模块编号
			*/
			const Module* getModule(CreateMapProtocol* creator, uint32_t index) const;

			/**
			*	获取指定位置的模块编号
			*/
			bool getModuleID(uint32_t index, uint32_t& moduleID) const;
		protected:
			// 地图点数
			uint32_t _pointCount = 0;
			// 地图点 {点， 模块}
			std::map<uint32_t, uint32_t> _mapPoint;
			// 未设置点
			std::set<uint32_t> _unFillPoint;
			// 已设置点
			std::set<uint32_t> _filledPoint;
			// 位置状态表
			std::map<uint32_t, MultiState> _pointModules;
			// 状态
			MultiState _moduleStates;
		};
	}
}
