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
		*	显示版本信息
		*/
		static void showDetail();
	protected:
	private:
	};
}