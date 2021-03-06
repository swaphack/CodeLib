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
		*	设置值
		*/
		void setValue(const std::string& name, const void* data);
	public:
		/**
		*	绑定数据
		*/
		void setBlockData(int size, const char* data);
		/**
		*	数据
		*/
		const sys::MemoryData& getBlockData() const;
		/**
		*	绑定内存索引数据
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
		*	设置变量编号
		*/
		void setUniformBlockID(uint32_t id);
		/**
		*	属性编号
		*/
		uint32_t getUniformBlockID() const;
	public:
		/**
		*	获取内存数据
		*/
		bool getBlockData(ShaderUniformBlockData& data);
	private:
		uint32_t _uniformBlockID = 0;
	};
}