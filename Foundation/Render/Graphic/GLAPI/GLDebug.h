#pragma once

namespace render
{
	/**
	*	����
	*/
	class GLDebug
	{
	public:
		/**
		*	��ʾ����
		*/
		static void showError();
	};

#define SHOW_OPENGL_ERROR_MESSAGE() GLDebug::showError();
}