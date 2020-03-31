#pragma once

#include "system.h"
#include "Common/struct/pointer_common.h"
#include "mathlib.h"

namespace render
{
	class MaterialDetail;

	// ������
	class FaceDetail : public sys::Object
	{
	public:
		FaceDetail();
		virtual ~FaceDetail();
	public:
		/**
		*	���ò���
		*/
		void setMaterial(int mat);
		/**
		*	��ȡ����
		*/
		int getMaterial();
		/**
		*	��������������
		*/
		void setIndices(int size, uint16_t* indices);
		/**
		*	��ȡ����������
		*/
		const T_Indice& getIndices();
		/**
		*	�仯����
		*/
		void setMatrix(const math::Matrix44& mat);
		/**
		*	�仯����
		*/
		const math::Matrix44& getMatrix();
	protected:
		// ����
		int _material = 0;
		// ��������
		T_Indice _indices;
		// �仯��Ϣ
		math::Matrix44 _matrix;
	};
}