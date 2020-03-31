#pragma once

#include "system.h"
#include "Common/struct/pointer_common.h"
#include "mathlib.h"

namespace render
{
	class MaterialDetail;

	// 纹理面
	class FaceDetail : public sys::Object
	{
	public:
		FaceDetail();
		virtual ~FaceDetail();
	public:
		/**
		*	设置材质
		*/
		void setMaterial(int mat);
		/**
		*	获取材质
		*/
		int getMaterial();
		/**
		*	设置三角形索引
		*/
		void setIndices(int size, uint16_t* indices);
		/**
		*	获取三角形索引
		*/
		const T_Indice& getIndices();
		/**
		*	变化矩阵
		*/
		void setMatrix(const math::Matrix44& mat);
		/**
		*	变化矩阵
		*/
		const math::Matrix44& getMatrix();
	protected:
		// 材质
		int _material = 0;
		// 顶点索引
		T_Indice _indices;
		// 变化信息
		math::Matrix44 _matrix;
	};
}