#pragma once

#include "system.h"

namespace alg
{
	class PointSet;

	/**
	*	����ӿ�
	*/
	class MeshProtocol : public sys::Object
	{
	public:
		MeshProtocol();
		virtual ~MeshProtocol();
	public:
		/**
		*	�����㼯��
		*/
		void setPointSet(PointSet* pointSet);
		/**
		*	�����㼯��
		*/
		PointSet* getPointSet() const;
	protected:
		/**
		*	�����㼯��
		*/
		PointSet* _pointSet = nullptr;
	};
}
