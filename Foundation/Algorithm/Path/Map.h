#pragma once

#include "mathlib.h"

#include <map>
#include <string>

namespace alg
{
	class MapNode;
	class Relation;

	// 地图
	class Map
	{
	public:
		Map();
		virtual ~Map();
	public:
		/**
		*	添加节点
		*/
		void addNode(const math::Vector3& point);
		/**
		*	获取节点
		*/
		const math::Vector3* getNode(const math::Vector3& point);
		/**
		*	移除所有节点
		*/
		void removeAllNodes();
	public:
		void addRelative(const math::Vector3& src, const math::Vector3& dest);

		void removeRelative(const math::Vector3& src, const math::Vector3& dest);
		
		float getDistance(const math::Vector3& src, const math::Vector3& dest);
	protected:
		std::map<std::string, MapNode*> _nodes;
		std::map<std::string, float>
	};
}

