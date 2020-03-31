#pragma once

#include <string>

namespace render
{
	/**
	*	�汾
	*/
	class GLVersion
	{
	public:
		/**
		*	opengl �汾
		*/
		static int getVersionID();
		/**
		*	opengl �汾
		*/
		static std::string getVersionDetail();
		/**
		*	��Ⱦ �汾
		*/
		static std::string getRendererDetail();
		/**
		*	���� �汾
		*/
		static std::string getVendorDetail();
		/**
		*	��ʾ�汾��Ϣ
		*/
		static void showDetail();
	protected:
	private:
	};
}