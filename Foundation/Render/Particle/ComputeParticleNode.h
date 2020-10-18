#pragma once

#include "PariticleNode.h"
#include "ParticleProtocol.h"
#include "Common/Shader/ShaderProgramDelegate.h"
namespace render
{
	class ComputeShaderProgram;
	class VertexFragmentShaderProgram;
	class ArrayBuffer;
	class UniformBuffer;
	class VertexArrayObject;
	class TextureBufferObject;

	/**
	*	ʹ�ü�����ɫ����������
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
		*	���ؼ�����ɫ���ļ�
		*/
		void loadComputeFile(const std::string& filepath, const ShaderProgramNFunc& updateFunc = nullptr);
		/**
		*	������Ⱦ��ɫ���ļ�
		*/
		void loadVertexAndFragmentFile(const std::string& vertex, const std::string& fragment, const ShaderProgramNFunc& updateFunc = nullptr);

		void setParticleGroupSize(int size);

		VertexArrayObject* getVAO() const;
	protected:
		virtual void draw();
	protected:
		// ����ʱ��
		virtual void update(float dt);
		// �����ı�
		virtual void updateParticleParameter();
	private:
		ComputeShaderProgram* _computeProgram = nullptr;

		ShaderProgramNFunc _computeUpdateFunc = nullptr;

		ShaderProgram* _renderProgram = nullptr;

		ShaderProgramNFunc _renderUpdateFunc = nullptr;

		VertexArrayObject* _renderVAO = nullptr;
		// ����λ��
		ArrayBuffer* _positionBuffer = nullptr;
		// �����ٶ�
		ArrayBuffer* _velocityBuffer = nullptr;

		TextureBufferObject* _positionTBO = nullptr;
		TextureBufferObject* _velocityTBO = nullptr;

		// ������λ�ú�����
		UniformBuffer* _attractorBuffer = nullptr;
		// ����
		float* _attractorMasses = nullptr;
		// ���С����shader�й�
		int _particleGroupSize = 512;
	};
}