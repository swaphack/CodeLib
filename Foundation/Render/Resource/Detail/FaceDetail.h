#pragma once

#include "system.h"
#include "Common/struct/pointer_common.h"

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
	protected:
		// 材质
		int _material = 0;
		// 顶点索引
		T_Indice _indices;
	};
}