#pragma once

#include "Relation.h"

namespace alg
{
	/**
	*	��ͼ��
	*/
	class MapNode : public Relation
	{
	public:
		MapNode();
		MapNode(const math::Vector2& position);
		MapNode(const math::Vector3& position);
		virtual ~MapNode();
	public:
		/**
		*	����
		*/
		void setPosition(const math::Vector2& pos);
		/**
		*	����
		*/
		void setPosition(const math::Vector3& pos);
		/**
		*	����
		*/
		const math::Vector3& getPosition() const;
	private:
		/**
		*	����
		*/
		math::Vector3 _position;
	};
}