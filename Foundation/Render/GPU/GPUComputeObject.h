#pragma once

#include "system.h"

#include "Common/Shader/ShaderProgramDelegate.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class ComputeShaderProgram;

	class GPUComputeObject : public sys::Object
	{
		struct GroupSize
		{
			uint32_t x = 1;
			uint32_t y = 1;
			uint32_t z = 1;
		};
	public:
		GPUComputeObject();
		virtual ~GPUComputeObject();
	public:
		/**
		*	���ؼ�����ɫ��
		*/
		void loadComputeProgram(const std::string& computeFilepath);
		/**
		*	���ü������С
		*/
		void setGroupSize(uint32_t groupXCount, uint32_t groupYCount = 1, uint32_t groupZCount = 1);
		/**
		*	������x��С
		*/
		uint32_t getGroupXCount() const;
		/**
		*	������y��С
		*/
		uint32_t getGroupYCount() const;
		/**
		*	������z��С
		*/
		uint32_t getGroupZCount() const;
		/**
		*	������������
		*/
		void setMemoryBarrier(MemoryBarrierBit bit);
		/**
		*	��������
		*/
		MemoryBarrierBit getMemoryBarrier() const;
		/**
		*	������ɫ��������
		*/
		void setShaderProgramFunc(const ShaderProgramFunc& func);
		/**
		*	��ɫ��������
		*/
		ShaderProgramFunc getShaderProgramFunc() const;
	public:
		bool run();
	private:
		/**
		*	������ɫ������
		*/
		ComputeShaderProgram* _computeProgram = nullptr;
		/**
		*	�������С
		*/
		GroupSize _groupSize;
		/**
		*	��������
		*/
		MemoryBarrierBit _memoryBarrierBit = MemoryBarrierBit::UNIFORM_BARRIER_BIT;
		/**
		*	��ɫ��������
		*/
		ShaderProgramFunc _shaderProgramFunc = nullptr;
	};
}
