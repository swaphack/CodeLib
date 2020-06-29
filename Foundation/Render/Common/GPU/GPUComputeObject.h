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
		*	加载计算着色器
		*/
		void loadComputeProgram(const std::string& computeFilepath);
		/**
		*	设置计算组大小
		*/
		void setGroupSize(uint32_t groupXCount, uint32_t groupYCount = 1, uint32_t groupZCount = 1);
		/**
		*	计算组x大小
		*/
		uint32_t getGroupXCount() const;
		/**
		*	计算组y大小
		*/
		uint32_t getGroupYCount() const;
		/**
		*	计算组z大小
		*/
		uint32_t getGroupZCount() const;
		/**
		*	设置屏蔽类型
		*/
		void setMemoryBarrier(MemoryBarrierBit bit);
		/**
		*	屏蔽类型
		*/
		MemoryBarrierBit getMemoryBarrier() const;
		/**
		*	设置着色器处理函数
		*/
		void setShaderProgramFunc(const ShaderProgramFunc& func);
		/**
		*	着色器处理函数
		*/
		ShaderProgramFunc getShaderProgramFunc() const;
	public:
		bool run();
	private:
		/**
		*	计算着色器程序
		*/
		ComputeShaderProgram* _computeProgram = nullptr;
		/**
		*	计算组大小
		*/
		GroupSize _groupSize;
		/**
		*	屏蔽类型
		*/
		MemoryBarrierBit _memoryBarrierBit = MemoryBarrierBit::UNIFORM_BARRIER_BIT;
		/**
		*	着色器处理函数
		*/
		ShaderProgramFunc _shaderProgramFunc = nullptr;
	};
}
