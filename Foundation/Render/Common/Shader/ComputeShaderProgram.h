#pragma once

#include "ShaderProgram.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class DispatchIndirectBuffer;
	/**
	*	������ɫ��
	*/
	class ComputeShaderProgram : public ShaderProgram
	{
	public:
		ComputeShaderProgram();
		virtual ~ComputeShaderProgram();
	public:
		/**
		*	�����ļ� cpath ����
		*/
		bool loadComputeShader(const std::string& cpath);
	public:
		/**
		*	�ѹ����鷢�͵����������
		*/
		void dispatchCompute(uint32_t groupXCount, uint32_t groupYCount, uint32_t groupZCount);
		/**
		*	�ѻ������ݷ��͵����������
		*/
		void dispatchBuffer(const DispatchIndirectBuffer* buffer);
		/**
		*	�����ڴ���������
		*/
		void setMemoryBarrier(MemoryBarrierBit barrier);
		/**
		*	�����ڴ���������
		*/
		void setMemoryBarrier(uint32_t barriers);
	public:
		/**
		*	�������
		*/
		static void getMaxWorkGroupSize(uint32_t& x, uint32_t& y, uint32_t& z);
		/**
		*	���shader shared�ֶ�
		*/
		static void getMaxSharedMemorySize(uint32_t& size);
	};
}