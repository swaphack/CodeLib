#pragma once

#include "mathlib.h"

#include <map>
#include <string>

namespace alg
{
	class MapNode;
	class Relation;

	// ��ͼ
	class Map
	{
	public:
		Map();
		virtual ~Map();
	public:
		/**
		*	��ӽڵ�
		*/
		void addNode(const math::Vector3& point);
		/**
		*	��ȡ�ڵ�
		*/
		const math::Vector3* getNode(const math::Vector3& point);
		/**
		*	�Ƴ����нڵ�
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

