#pragma once

#include "system.h"
#include "Common/struct/pointer_common.h"

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
	protected:
		// ����
		int _material = 0;
		// ��������
		T_Indice _indices;
	};
}