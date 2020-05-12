#include "GLState.h"
#include "macros.h"

using namespace render;

void GLState::enable(EnableModel capability)
{
	glEnable((GLenum)capability);
}

void GLState::disable(EnableModel capability)
{
	glDisable((GLenum)capability);
}

bool GLState::isEnabled(EnableModel capability)
{
	return glIsEnabled((GLenum)capability) != 0;
}

void GLState::getBoolean(GetTarget pname, uint8_t* value)
{
	return glGetBooleanv((GLenum)pname, value);
}

void GLState::getDouble(GetTarget pname, double* value)
{
	return glGetDoublev((GLenum)pname, value);
}

void GLState::getFloat(GetTarget pname, float* value)
{
	return glGetFloatv((GLenum)pname, value);
}

void GLState::getInt(GetTarget pname, int* value)
{
	return glGetIntegerv((GLenum)pname, value);
}

void render::GLState::getInt(uint32_t pname, int* value)
{
	return glGetIntegerv(pname, value);
}

void render::GLState::setColorMask(uint32_t buffer, bool red, bool green, bool blue, bool alpha)
{
	glColorMaski(buffer, 
		red ? GL_TRUE : GL_FALSE, 
		green ? GL_TRUE : GL_FALSE,
		blue ? GL_TRUE : GL_FALSE,
		alpha ? GL_TRUE : GL_FALSE);
}

void render::GLState::getBoolean(uint32_t pname, uint8_t* value)
{
	return glGetBooleanv(pname, value);
}

void render::GLState::getDouble(uint32_t pname, double* value)
{
	return glGetDoublev(pname, value);
}

void render::GLState::getFloat(uint32_t pname, float* value)
{
	return glGetFloatv(pname, value);
}

void GLState::getTexImage(TextureTarget target, int level, TexImageInternalFormat internalFormat, TexImageDataType pixelType, void* data)
{
	glGetTexImage((GLenum)target, level, (GLenum)internalFormat, (GLenum)pixelType, data);
}

void GLState::getTexLevelParameter(TextureTarget target, int level, GetTextureParameter parameter, float* value)
{
	glGetTexLevelParameterfv((GLenum)target, level, (GLenum)parameter, value);
}



void GLState::getTexParameter(TextureTarget target, GetTextureParameter parameter, int* value)
{
	glGetTexParameteriv((GLenum)target, (GLenum)parameter, value);
}

void GLState::getTexParameter(TextureTarget target, GetTextureParameter parameter, float* value)
{
	glGetTexParameterfv((GLenum)target, (GLenum)parameter, value);
}





void GLState::getPointer(GetPointerTarget target, void** value)
{
	glGetPointerv((GLenum)target, value);
}

void GLState::setBlendColor(const sys::Color4F& color)
{
	glBlendColor(color.red, color.green, color.blue, color.alpha);
}

void GLState::setBlendEquation(BlendEquationMode mode)
{
	glBlendEquation((GLenum)mode);
}

void GLState::setBlendEquation(uint32_t buf, BlendEquationMode mode)
{
	glBlendEquationi(buf, (GLenum)mode);
}

void GLState::setBlendEquationSeparate(BlendEquationMode rgb, BlendEquationMode alpha)
{
	glBlendEquationSeparate((GLenum)rgb, (GLenum)alpha);
}

void GLState::setBlendEquationSeparate(uint32_t buf, BlendEquationMode rgb, BlendEquationMode alpha)
{
	glBlendEquationSeparatei(buf, (GLenum)rgb, (GLenum)alpha);
}

void GLState::setBlendFunc(BlendingFactorSrc src, BlendingFactorDest dest)
{
	glBlendFunc((GLenum)src, (GLenum)dest);
}

void GLState::setBlendFunc(uint32_t buf, BlendingFactorSrc src, BlendingFactorDest dest)
{
	glBlendFunci(buf,(GLenum)src, (GLenum)dest);
}

void GLState::setBlendFuncSeparate(BlendEquationMode srcRGB, BlendEquationMode destRGB, BlendEquationMode srcAlpha, BlendEquationMode destAlpha)
{
	glBlendFuncSeparate((GLenum)srcRGB, (GLenum)destRGB, (GLenum)srcAlpha, (GLenum)destAlpha);
}

void GLState::setBlendFuncSeparate(uint32_t buf, BlendEquationMode srcRGB, BlendEquationMode destRGB, BlendEquationMode srcAlpha, BlendEquationMode destAlpha)
{
	glBlendFuncSeparatei(buf, (GLenum)srcRGB, (GLenum)destRGB, (GLenum)srcAlpha, (GLenum)destAlpha);
}

void GLState::setClampColor(bool clamp)
{
	glClampColor(GL_CLAMP_READ_COLOR, clamp ? GL_TRUE : GL_FALSE);
}

void GLState::setClipControl(ClipControlOrigin origin, ClipControlDepth depth)
{
	glClipControl((GLenum)origin, (GLenum)depth);
}

void GLState::setColorMask(bool red, bool green, bool blue, bool alpha)
{
	glColorMask(
		red ? GL_TRUE : GL_FALSE,
		green ? GL_TRUE : GL_FALSE,
		blue ? GL_TRUE : GL_FALSE,
		alpha ? GL_TRUE : GL_FALSE);
}

void GLState::setCullFace(FaceType mode)
{
	glCullFace((GLenum)mode);
}

void GLState::setDepthFunc(DepthFunction func)
{
	glDepthFunc((GLenum)func);
}

void GLState::setDepthMask(bool flag)
{
	glDepthMask(flag ? GL_TRUE : GL_FALSE);
}

void GLState::setDepthRange(float zNear, float zFar)
{
	glDepthRange(zNear, zFar);
}

void GLState::setDepthRangeArray(uint32_t first, int count, const double* v)
{
	glDepthRangeArrayv(first, count, v);
}

void GLState::setDepthRangeIndexed(uint32_t index, float zNear, float zFar)
{
	glDepthRangeIndexed(index, zNear, zFar);
}

void GLState::setFrontFace(FrontFaceDirection mode)
{
	glFrontFace((GLenum)mode);
}
void GLState::setFogHint(HintMode type)
{
	glHint(GL_FOG_HINT, (GLenum)type);
}

void GLState::setFragmentShaderDerivativeHint(HintMode type)
{
	glHint(GL_FRAGMENT_SHADER_DERIVATIVE_HINT, (GLenum)type);
}

void GLState::setGenerateMipMapHint(HintMode type)
{
	glHint(GL_GENERATE_MIPMAP_HINT, (GLenum)type);
}

void GLState::setLineSmoothHint(HintMode type)
{
	glHint(GL_LINE_SMOOTH_HINT, (GLenum)type);
}

void GLState::setPerspectiveCorrectionHint(HintMode type)
{
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, (GLenum)type);
}

void GLState::setPointSmoothHint(HintMode type)
{
	glHint(GL_POINT_SMOOTH_HINT, (GLenum)type);
}

void GLState::setPolygonSmoothHint(HintMode type)
{
	glHint(GL_POLYGON_SMOOTH_HINT, (GLenum)type);
}

void GLState::setTextureCompressionHint(HintMode type)
{
	glHint(GL_TEXTURE_COMPRESSION_HINT, (GLenum)type);
}

void GLState::setPointSize(float size)
{
	glPointSize(size);
}

void GLState::setLineWidth(float width)
{
	glLineWidth(width);
}

void GLState::setPolygonOffset(float factor, float units)
{
	glPolygonOffset(factor, units);
}

void GLState::setPolygonMode(FaceType mode, PolygonMode type)
{
	glPolygonMode((GLenum)mode, (GLenum)type);
}

void GLState::setLogicOp(LogicOp op)
{
	glLogicOp((GLenum)op);
}

void GLState::setPixelStore(PixelStore name, float value)
{
	glPixelStoref((GLenum)name, value);
}

void GLState::setPointParameter(PointParameter pname, const float* value)
{
	glPointParameterfv((GLenum)pname, value);
}

void GLState::setSampleCoverage(float value, bool invert)
{
	glSampleCoverage(value, invert ? GL_TRUE : GL_FALSE);
}

void GLState::setScissor(int x, int y, int width, int height)
{
	glScissor(x, y, width, height);
}

void GLState::setScissorArray(uint32_t first, int count, const int* v)
{
	glScissorArrayv(first, count, v);
}

void GLState::setScissorIndexed(uint32_t index, float x, float y, float width, float height)
{
	glScissorIndexed(index, x, y, width, height);
}

void GLState::setStencilFunc(StencilFunction func, int ref, uint32_t mask)
{
	glStencilFunc((GLenum)func, ref, mask);
}

void GLState::setStencilFuncSeparate(FaceType type, StencilFunction func, int ref, uint32_t mask)
{
	glStencilFuncSeparate((GLenum)type,(GLenum)func, ref, mask);
}

void GLState::setStencilMask(uint32_t mask)
{
	glStencilMask(mask);
}

void GLState::setStencilMaskSeparate(FaceType type, uint32_t mask)
{
	glStencilMaskSeparate((GLenum)type, mask);
}

void GLState::setStencilOp(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass)
{
	glStencilOp((GLenum)stencilFail, (GLenum)depthFail, (GLenum)depthPass);
}

void GLState::setStencilOpSeparate(FaceType type, StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass)
{
	glStencilOpSeparate((GLenum)type, (GLenum)stencilFail, (GLenum)depthFail, (GLenum)depthPass);
}

void GLState::setViewport(float x, float y, float width, float height)
{
	glViewport(x, y, width, height);
}

void GLState::setViewportArray(uint32_t first, int count, const float* v)
{
	glViewportArrayv(first, count, v);
}

void GLState::setViewportIndexed(uint32_t index, float x, float y, float width, float height)
{
	glViewportIndexedf(index, x, y, width, height);
}

