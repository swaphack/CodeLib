#include "GLSync.h"

using namespace render;

void GLSync::setClientWaitSync(GLsync sync, uint32_t flags, GLuint64 timeout)
{
	glClientWaitSync(sync, flags, timeout);
}

void GLSync::deleteSync(GLsync sync)
{
	glDeleteSync(sync);
}

void GLSync::fenceSync(uint32_t flags)
{
	glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, flags);
}

void GLSync::getSync(GLsync sync, SyncParameter pname, GLsizei bufSize, GLsizei *length, GLint *values)
{
	glGetSynciv(sync, (GLenum)pname, bufSize, length, values);
}

bool GLSync::isSync(GLsync sync)
{
	return glIsSync(sync) == GL_TRUE;
}

void GLSync::setTextureBarrier()
{
	glTextureBarrier();
}

void GLSync::waitSync(GLsync sync, uint32_t flags, GLuint64 timeout)
{
	glWaitSync(sync, flags, timeout);
}
