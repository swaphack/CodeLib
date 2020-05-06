#pragma once

#include "ShaderVariable.h"

namespace render
{
	class ShaderUniformBlock;
	class ShaderUniformBlockData : public ShaderVariable
	{
	public:
		ShaderUniformBlockData();
		virtual ~ShaderUniformBlockData();
	public:
		void setUniformBlock(ShaderUniformBlock* block);
		const ShaderUniformBlock* getUniformBlock() const;
	public:
		/**
		*	����ֵ
		*/
		void setValue(const std::string& name, const void* data);
	public:
		/**
		*	������
		*/
		void setBlockData(int size, const char* data);
		/**
		*	����
		*/
		const sys::MemoryData& getBlockData() const;
		/**
		*	���ڴ���������
		*/
		void setBlockIndicesData(int count, const uint32_t* indices, int* offsets, int* sizes, int* types);
	protected:
		void clearBlockData();
		void clearBlockIndicesData();
	private:
		sys::MemoryData _data;
		sys::MemoryData _indices;
		sys::MemoryData _offsets;
		sys::MemoryData _sizes;
		sys::MemoryData _types;

		ShaderUniformBlock* _uniformBlock = nullptr;
	};

	class ShaderUniformBlock : public ShaderVariable
	{
	public:
		ShaderUniformBlock();
		virtual ~ShaderUniformBlock();
	public:
		/**
		*	���ñ������
		*/
		void setUniformBlockID(uint32_t id);
		/**
		*	���Ա��
		*/
		uint32_t getUniformBlockID() const;
	public:
		/**
		*	��ȡ�ڴ�����
		*/
		bool getBlockData(ShaderUniformBlockData& data);
	private:
		uint32_t _uniformBlockID = 0;
	};
}