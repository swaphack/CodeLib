#pragma once

#include <string>

namespace render
{
	/**
	*	版本
	*/
	class GLVersion
	{
	public:
		/**
		*	opengl 版本
		*/
		static int getVersionID();
		/**
		*	opengl 版本
		*/
		static std::string getVersionDetail();
		/**
		*	渲染 版本
		*/
		static std::string getRendererDetail();
		/**
		*	销售 版本
		*/
		static std::string getVendorDetail();
		/**
		*	着色器语言 版本
		*/
		static std::string getShadingLanguageVersion();
		/**
		*	扩展
		*/
		static std::string getExtensions();
		/**
		*	显示版本信息
		*/
		static void showDetail();
	};
}