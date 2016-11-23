#pragma once

#include "../macros.h"

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
		void setMatrial(const Material* material);
		// 获取模型材质
		const Material* getMatrial() const;
		// 获取模型材质
		Material* getMatrial();
		
		// 设置所有面的纹理帧
		virtual void setTexFrame(const TexFrame* frame);
	protected:
		virtual void initSelf();
	protected:
		// 模型材质
		Material* _material;
		// 纹理
		TexFrame* _texFrame;
	};
}