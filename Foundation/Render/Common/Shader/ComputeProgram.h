#pragma once

#include "ShaderProgram.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class DispatchIndirectBuffer;
	/**
	*	计算着色器
	*/
	class ComputeProgram : public ShaderProgram
	{
	public:
		ComputeProgram();
		virtual ~ComputeProgram();
	public:
		/**
		*	添加文件 cpath 计算
		*/
		bool loadComputeShader(const std::string& cpath);
	public:
		/**
		*	把工作组发送到计算管线上
		*/
		void dispatchCompute(uint32_t groupXCount, uint32_t groupYCount, uint32_t groupZCount);
		/**
		*	把缓存数据发送到计算管线上
		*/
		void dispatchBuffer(const DispatchIndirectBuffer* buffer);

		void setMemoryBarrier(MemoryBarrierBit barrier);

		void setMemoryBarrier(uint32_t barriers);
	public:
		/**
		*	最大工作组
		*/
		static void getMaxWorkGroupSize(uint32_t& x, uint32_t& y, uint32_t& z);
		/**
		*	最大shader shared字段
		*/
		static void getMaxSharedMemorySize(uint32_t& size);
	};
}