#pragma once

#include "macros.h"

namespace render
{
	class GLSync
	{
	public:
		static void setClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
		static void deleteSync(GLsync sync);
		static void fenceSync(GLbitfield flags);
		static void getSync(GLsync sync, SyncParameter pname, GLsizei bufSize, GLsizei *length, GLint *values);
		static bool isSync(GLsync sync);
		static void setTextureBarrier();
		static void waitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
	};
}