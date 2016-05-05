#pragma once

#include "macros.h"

namespace render
{
	// 3d模型
	class CtrlModel : public ColorNode
	{
	public:
		CtrlModel();
		virtual ~CtrlModel();
	public:
		virtual void draw();
		// 设置模型材质
		void setMatrial(Material* material);
		// 获取模型材质
		Material* getMatrial();
		// 设置单面的纹理帧
		void setFaceFrame(ModelFace face, TexFrame* frame);
		// 设置所有面的纹理帧
		void setAllFacesFrame(TexFrame* frame);
	protected:
		virtual void initSelf();
		// 获取面的纹理
		TextureRect* getTextureRect(ModelFace face);
	protected:
		// 模型材质
		Material* _material;
		// 纹理
		TexFrame* _faceFrames[6];
		// 法线
		sys::Vector _normal[6];
		// 纹理坐标
		TextureCube _texCube;
	};
}