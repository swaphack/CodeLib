#include "Material.h"
#include "Common/Shader/import.h"
#include "Common/Node/import.h"
#include "Graphic/import.h"
#include "MaterialSetting.h"

render::Material::Material()
{
	_materialSetting = new MaterialSetting();
}

render::Material::~Material()
{
	SAFE_RELEASE(_detail);
	SAFE_RELEASE(_shaderProgram);

	SAFE_DELETE(_materialSetting);
}

void render::Material::setShaderProgram(ShaderProgram* shaderProgram)
{
	SAFE_RELEASE(_shaderProgram);
	SAFE_RETAIN(shaderProgram);

	_shaderProgram = shaderProgram;
	_materialSetting->setShaderProgram(shaderProgram);
}

render::ShaderProgram* render::Material::getShaderProgram()
{
	return _shaderProgram;
}

void render::Material::setMaterialDetail(sys::MaterialDetail* detail)
{
	SAFE_RELEASE(_detail);
	SAFE_RETAIN(detail);

	_detail = detail;
}

sys::MaterialDetail* render::Material::getMaterialDetail() const
{
	return _detail;
}

render::MaterialSetting* render::Material::getMaterialSetting() const
{
	return _materialSetting;
}

void render::Material::setProgramFunc(const ShaderProgramFunc& func)
{
	_programFunc = func;
}

void render::Material::applyMaterial()
{
	if (_detail)
	{
		GLMaterial::setMaterialAmbient(FaceType::FRONT, _detail->getAmbient());
		GLMaterial::setMaterialDiffuse(FaceType::FRONT, _detail->getDiffuse());
		GLMaterial::setMaterialSpecular(FaceType::FRONT, _detail->getSpecular());
		GLMaterial::setMaterialShininess(FaceType::FRONT, _detail->getSpecularShiness());
		GLMaterial::setMaterialEmission(FaceType::FRONT, _detail->getEmission());
		GLDebug::showError();
	}
	else
	{
		static float matrialAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		static float matrialDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
		static float matrialSpecular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		static float matrialShiness = 0.0f;
		static float matrialEmission[] = { 0.0f, 0.0f, 0.0f, 1.0f };

		GLMaterial::setMaterialAmbient(FaceType::FRONT, matrialAmbient);
		GLMaterial::setMaterialDiffuse(FaceType::FRONT, matrialDiffuse);
		GLMaterial::setMaterialSpecular(FaceType::FRONT, matrialSpecular);
		GLMaterial::setMaterialShininess(FaceType::FRONT, matrialShiness);
		GLMaterial::setMaterialEmission(FaceType::FRONT, matrialEmission);
		GLDebug::showError();
	}
}

#define CREATE_VALUE_TYPE(T,Type,name, value) \
T* data = (T*)malloc(sizeof(T)); \
if (data == nullptr) return; \
memcpy(data, &value, sizeof(T)); \
_materialSetting->addSelfDefineUniform(name, Type, data);

#define CREATE_FLOAT_ARRAY_TYPE(Type,name, value) \
if (value.getSize() == 0) return;\
float* data = (float*)malloc(value.getSize());\
if (data == nullptr) return; \
memcpy(data, value.getValue(), value.getSize());\
_materialSetting->addSelfDefineUniform(name, Type, data);

void render::Material::setUniform(const std::string& name, int value)
{
	CREATE_VALUE_TYPE(int, MaterialSetting::UniformType::Integer, name, value);
}

void render::Material::setUniform(const std::string& name, float value)
{
	CREATE_VALUE_TYPE(int, MaterialSetting::UniformType::Float, name, value);
}

void render::Material::setUniform(const std::string& name, const math::Vector2& value)
{
	CREATE_FLOAT_ARRAY_TYPE(MaterialSetting::UniformType::Vec2, name, value);
}

void render::Material::setUniform(const std::string& name, const math::Vector3& value)
{
	CREATE_FLOAT_ARRAY_TYPE(MaterialSetting::UniformType::Vec3, name, value);
}

void render::Material::setUniform(const std::string& name, const math::Vector4& value)
{
	CREATE_FLOAT_ARRAY_TYPE(MaterialSetting::UniformType::Vec4, name, value);
}

void render::Material::setUniform(const std::string& name, const math::Matrix2x2& value)
{
	CREATE_FLOAT_ARRAY_TYPE(MaterialSetting::UniformType::Mat2x2, name, value);
}

void render::Material::setUniform(const std::string& name, const math::Matrix3x3& value)
{
	CREATE_FLOAT_ARRAY_TYPE(MaterialSetting::UniformType::Mat3x3, name, value);
}

void render::Material::setUniform(const std::string& name, const math::Matrix4x4& value)
{
	CREATE_FLOAT_ARRAY_TYPE(MaterialSetting::UniformType::Mat4x4, name, value);
}

bool render::Material::hasAttrib(const std::string& name) const
{
	if (_materialSetting == nullptr) return false;

	for (auto item : _materialSetting->getAttribs())
	{
		if (item.second == name) 
			return true;
	}

	return false;
}

bool render::Material::hasAttrib(const VertexDataType& type) const
{
	if (_materialSetting == nullptr) return false;

	for (auto item : _materialSetting->getAttribs())
	{
		if (item.first == type)
			return true;
	}

	return false;
}

void render::Material::runProgramFunc()
{
	if (_programFunc != nullptr && _shaderProgram != nullptr)
	{
		_programFunc(_shaderProgram);
	}
}

