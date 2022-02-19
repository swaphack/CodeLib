#pragma once

#include "system.h"

namespace alg
{
	namespace mesh
	{
		class PointSet;

		/**
		*	����ӿ�
		*/
		class MeshProtocol : public sys::Object
		{
		public:
			MeshProtocol() {}
			virtual ~MeshProtocol() {}
		public:
			/**
			*	�㼯��
			*/
			inline PointSet* getPointSet() const { return  _pointSet; }
			/**
			*	�㼯��
			*/
			inline void setPointSet(PointSet* pointSet) { _pointSet = pointSet; }
			/**
			*	�ؼ�ֵ
			*/
			inline void setKey(const std::string& key) { _key = key; }
			/**
			*	�ؼ�ֵ
			*/
			inline const std::string& getKey() const { return _key; }
		protected:
			/**
			*	�㼯��
			*/
			PointSet* _pointSet = nullptr;
			/**
			*	�ؼ�ֵ
			*/
			std::string _key;
		};
	}
}
