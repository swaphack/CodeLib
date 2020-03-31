#pragma once

namespace render
{
	/**
	*	µ˜ ‘
	*/
	class GLDebug
	{
	public:
		/**
		*	œ‘ æ¥ÌŒÛ
		*/
		static void showError();
	};

#define SHOW_OPENGL_ERROR_MESSAGE() GLDebug::showError();
}