#pragma once

#include "PariticleNode.h"
#include "ParticleProtocol.h"
#include "Common/Shader/ShaderProgramDelegate.h"
namespace render
{
	class ComputeProgram;
	class VertexFragmentProgram;
	class ArrayBuffer;
	class UniformBuffer;
	class VertexArrayObject;
	class TextureBufferObject;

	/**
	*	使用计算着色器计算粒子
	*/
	class ComputeParticleNode : 
		public PariticleNode
	{
	public:
		ComputeParticleNode();
		virtual ~ComputeParticleNode();
	public:
		virtual bool init();
		/**
		*	加载计算着色器文件
		*/
		void loadComputeFile(const std::string& filepath, const ShaderProgramNFunc& updateFunc = nullptr);
		/**
		*	加载渲染着色器文件
		*/
		void loadVertexAndFragmentFile(const std::string& vertex, const std::string& fragment, const ShaderProgramNFunc& updateFunc = nullptr);
	protected:
		virtual void draw();
	protected:
		// 更新时间
		virtual void updateTime(float dt);
		// 参数改变
		virtual void updateParticleParameter();
	private:
		ComputeProgram* _computeProgram = nullptr;

		ShaderProgramNFunc _computeUpdateFunc = nullptr;

		VertexFragmentProgram* _renderProgram = nullptr;

		ShaderProgramNFunc _renderUpdateFunc = nullptr;

		VertexArrayObject* _renderVAO = nullptr;
		// 粒子位置
		ArrayBuffer* _positionBuffer = nullptr;
		// 粒子速度
		ArrayBuffer* _velocityBuffer = nullptr;

		TextureBufferObject* _positionTBO = nullptr;
		TextureBufferObject* _velocityTBO = nullptr;

		// 引力器位置和质量
		UniformBuffer* _attractorBuffer = nullptr;
		// 质量
		float* _attractorMasses = nullptr;
	};
}
