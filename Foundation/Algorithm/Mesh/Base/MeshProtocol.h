#pragma once

#include "system.h"

namespace alg
{
	namespace mesh
	{
		class PointSet;

		/**
		*	网格接口
		*/
		class MeshProtocol : public sys::Object
		{
		public:
			MeshProtocol() {}
			virtual ~MeshProtocol() {}
		public:
			/**
			*	点集合
			*/
			inline PointSet* getPointSet() const { return  _pointSet; }
			/**
			*	点集合
			*/
			inline void setPointSet(PointSet* pointSet) { _pointSet = pointSet; }
			/**
			*	关键值
			*/
			inline void setKey(const std::string& key) { _key = key; }
			/**
			*	关键值
			*/
			inline const std::string& getKey() const { return _key; }
		protected:
			/**
			*	点集合
			*/
			PointSet* _pointSet = nullptr;
			/**
			*	关键值
			*/
			std::string _key;
		};
	}
}
