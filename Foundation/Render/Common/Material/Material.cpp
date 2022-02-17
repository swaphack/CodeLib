#include "Material.h"
#include "Common/Shader/import.h"
#include "Common/Node/Node.h"
#include "Graphic/import.h"
#include "MaterialSetting.h"
#include "Common/DrawNode/DrawCore.h"

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

void render::Material::setNode(Node* node)
{
	_node = node;
}

render::Node* render::Material::getNode()
{
	return _node;
}

void render::Material::setShaderProgram(ShaderProgram* shaderProgram)
{
	SAFE_RETAIN(shaderProgram);
	SAFE_RELEASE(_shaderProgram);
	_shaderProgram = shaderProgram;
	_materialSetting->setShaderProgram(shaderProgram);
}

render::ShaderProgram* render::Material::getShaderProgram() const
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
	if (_node) _node->notify(render::NodeNotifyType::Draw);
}

void render::Material::applyMaterial()
{
	if (_shaderProgram == nullptr)
	{
		return;
	}
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

bool render::Material::equals(const Material& material) const
{
	if (_shaderProgram != material.getShaderProgram())
	{
		return false;
	}
	if (!_detail->equals(*material.getMaterialDetail()))
	{
		return false;
	}
	return _materialSetting->equalsSelfDefinedUniforms(*material.getMaterialSetting());
}

#define CREATE_VALUE_TYPE(T,Type,name, value) \
uint32_t size = sizeof(T);\
T* data = (T*)malloc(size); \
if (data == nullptr) return; \
memcpy(data, &value, size); \
_materialSetting->addSelfDefineUniform(name, Type, size, data);\
if (_node) _node->notify(render::NodeNotifyType::Draw);


#define CREATE_FLOAT_ARRAY_TYPE(Type,name, value) \
if (value.getSize() == 0) return;\
uint32_t size = value.getSize();\
float* data = (float*)malloc(size);\
if (data == nullptr) return; \
memcpy(data, value.getValue(), size);\
_materialSetting->addSelfDefineUniform(name, Type, size, data); \
if (_node) _node->notify(render::NodeNotifyType::Draw);


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
	if (_shaderProgram == nullptr) return false;

	for (auto item : _shaderProgram->getShaderProperty()->getAttribs())
	{
		if (item.second == name) 
			return true;
	}

	return false;
}

bool render::Material::hasAttrib(const VertexDataType& type) const
{
	if (_shaderProgram == nullptr) return false;

	for (auto item : _shaderProgram->getShaderProperty()->getAttribs())
	{
		if ((VertexDataType)item.first == type)
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

