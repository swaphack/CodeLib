#pragma once

#include "system.h"

namespace alg
{
	class PointSet;

	/**
	*	网格接口
	*/
	class MeshProtocol : public sys::Object
	{
	public:
		MeshProtocol();
		virtual ~MeshProtocol();
	public:
		/**
		*	所属点集合
		*/
		void setPointSet(PointSet* pointSet);
		/**
		*	所属点集合
		*/
		PointSet* getPointSet() const;
	protected:
		/**
		*	所属点集合
		*/
		PointSet* _pointSet = nullptr;
	};
}
