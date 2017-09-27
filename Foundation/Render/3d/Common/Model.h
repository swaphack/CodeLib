#pragma once

#include "../macros.h"

namespace render
{
	// 模型
	class Model : public ColorNode
	{
	public:
		Model();
		virtual ~Model();
	public:
		virtual void draw();
		// 设置模型材质 
		void setMatrial(const Material* material);
		// 获取模型材质
		const Material* getMatrial() const;
		// 获取模型材质
		Material* getMatrial();
		// 获取模型纹理格子
		const Mesh* getMesh() const;
		// 获取模型纹理格子
		Mesh* getMesh();
		
		// 设置所有面的纹理帧
		void setTexFrame(const TexFrame* frame);
	protected:
		// 模型材质
		Material* _material;
		// 纹理
		TexFrame* _texFrame;
		// 纹理网格
		Mesh* _mesh;
	};
}