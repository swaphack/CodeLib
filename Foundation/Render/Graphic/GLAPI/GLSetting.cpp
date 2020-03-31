#include "GLSetting.h"
#include "macros.h"

using namespace render;

void GLSetting::setFogHint(HintMode type)
{
	glHint(GL_FOG_HINT, (GLenum)type);
}

void GLSetting::setFragmentShaderDerivativeHint(HintMode type)
{
	glHint(GL_FRAGMENT_SHADER_DERIVATIVE_HINT, (GLenum)type);
}

void GLSetting::setGenerateMipMapHint(HintMode type)
{
	glHint(GL_GENERATE_MIPMAP_HINT, (GLenum)type);
}

void GLSetting::setLineSmoothHint(HintMode type)
{
	glHint(GL_LINE_SMOOTH_HINT, (GLenum)type);
}

void GLSetting::setPerspectiveCorrectionHint(HintMode type)
{
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, (GLenum)type);
}

void GLSetting::setPointSmoothHint(HintMode type)
{
	glHint(GL_POINT_SMOOTH_HINT, (GLenum)type);
}

void GLSetting::setPolygonSmoothHint(HintMode type)
{
	glHint(GL_POLYGON_SMOOTH_HINT, (GLenum)type);
}

void GLSetting::setTextureCompressionHint(HintMode type)
{
	glHint(GL_TEXTURE_COMPRESSION_HINT, (GLenum)type);
}

void GLSetting::setShadeModel(ShadingModel model)
{
	glShadeModel((GLenum)model);
}

void GLSetting::setPolygonMode(PolygonFaceMode mode, PolygonMode type)
{
	glPolygonMode((GLenum)mode, (GLenum)type);
}

