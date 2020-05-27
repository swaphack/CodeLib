#include "CtrlAudioGeometry.h"
#include "AudioManager.h"
#include "Common/DrawNode/PrimitiveNode.h"
#include "Common/Tool/Tool.h"

#define MAX_POLYGON_COUNT 1
#define POLYGON_INDEX 0

using namespace render;

CtrlAudioGeometry::CtrlAudioGeometry()
	:_geometry(nullptr)
	, _maxPolygonCount(0)
	, _maxVerticesCount(0)
{
	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		_polygons[i] = nullptr;
	}
}

CtrlAudioGeometry::~CtrlAudioGeometry()
{
	if (_geometry)
	{
		_geometry->release();
	}
}

bool CtrlAudioGeometry::init()
{
	if (!Node::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::SPACE, [this](){
		_geometryBody.position = this->getPosition();
		_geometryBody.scale = this->getScale();
		onGeometryChange();
		onPolygonsChange();
	});

	_notify->addListen(NodeNotifyType::AUDIO, [this](){
		onGeometryChange();
	});

	return true;
}
bool CtrlAudioGeometry::load(const GeometryData* data)
{
	if (data == nullptr)
	{
		return false;
	}

	if (_geometry != nullptr)
	{
		_geometry->release();
		_geometry = nullptr;
	}

	_maxPolygonCount = 0;
	_maxVerticesCount = 0;

	if (G_AUDIO->getSystem() == nullptr)
	{
		return false;
	}
	FMOD_RESULT result = G_AUDIO->getSystem()->loadGeometry(data->data, data->datasize, &_geometry);
	if (result == FMOD_OK)
	{
		_maxPolygonCount = 0;
		_maxVerticesCount = 0;
		AUDIO_DO_FUNC(_geometry, getMaxPolygons, &_maxPolygonCount, &_maxVerticesCount);
	}
	return result == FMOD_OK;
}

bool CtrlAudioGeometry::save(GeometryData* data)
{
	if (data == nullptr)
	{
		return false;
	}

	if (_geometry == nullptr)
	{
		return false;
	}

	_geometry->save(data->data, &data->datasize);

	return true;
}

bool CtrlAudioGeometry::init(int maxpolygons, int maxvertices)
{
	if (_geometry != nullptr)
	{
		_geometry->release();
		_geometry = nullptr;
	}
	_maxPolygonCount = 0;
	_maxVerticesCount = 0;

	if (G_AUDIO->getSystem() == nullptr)
	{
		return false;
	}
	FMOD_RESULT result = G_AUDIO->getSystem()->createGeometry(maxpolygons, maxvertices, &_geometry);
	if (result == FMOD_OK)
	{
		_maxPolygonCount = maxpolygons;
		_maxVerticesCount = maxvertices;
	}
	return result == FMOD_OK;
}

void CtrlAudioGeometry::setActive(bool active)
{
	AUDIO_SET_FUNC(_geometry, setActive, active);
}

bool CtrlAudioGeometry::getActive()
{
	AUDIO_GET_FUNC(_geometry, getActive, bool);
}

void CtrlAudioGeometry::setForward(const math::Vector3& forward)
{
	_geometryBody.forward = forward;
	this->notify(NodeNotifyType::AUDIO);
}

const math::Vector3& CtrlAudioGeometry::getForward()
{
	return _geometryBody.forward;
}

void CtrlAudioGeometry::setUp(const math::Vector3& up)
{
	_geometryBody.up = up;
	this->notify(NodeNotifyType::AUDIO);
}

const math::Vector3& CtrlAudioGeometry::getUp()
{
	return _geometryBody.up;
}

int CtrlAudioGeometry::getMaxPolygons()
{
	return _maxPolygonCount;
}

int CtrlAudioGeometry::getMaxVertices()
{
	return _maxVerticesCount;
}

int CtrlAudioGeometry::getPolygonsCount()
{
	AUDIO_GET_FUNC(_geometry, getNumPolygons, int);
}

int CtrlAudioGeometry::getVerticesCount()
{
	int count = getPolygonsCount();
	int totalvertice = 0;
	int numvertices = 0;
	for (int i = 0; i < count; i++)
	{
		AUDIO_DO_FUNC(_geometry, getPolygonNumVertices, i, &numvertices);
		totalvertice += numvertices;
	}

	return totalvertice;
}

CtrlAudioGeometryPolygon* CtrlAudioGeometry::addPolygon(const std::vector<math::Vector3>& vertexes)
{
	if (vertexes.size() == 0)
	{
		return nullptr;
	}

	if (_geometry == nullptr)
	{
		return nullptr;
	}

	int maxPolygons = getMaxPolygons();
	int curPolygons = getPolygonsCount();
	if (curPolygons >= maxPolygons)
	{
		return false;
	}

	CtrlAudioGeometryPolygon* polygon = CREATE_NODE(CtrlAudioGeometryPolygon);
	polygon->setGeometry(_geometry);
	polygon->setVertexes(vertexes);

	this->addChild(polygon);

	return polygon;
}

CtrlAudioGeometryPolygon* CtrlAudioGeometry::addPolygon(const RectVectices& vertexes)
{
	if (_geometry == nullptr)
	{
		return nullptr;
	}

	int maxPolygons = getMaxPolygons();
	int curPolygons = getPolygonsCount();
	if (curPolygons >= maxPolygons)
	{
		return false;
	}

	CtrlAudioGeometryPolygon* polygon = CREATE_NODE(CtrlAudioGeometryPolygon);
	polygon->setGeometry(_geometry);
	polygon->setVertexes(vertexes);
	polygon->setDoubleSided(true);
	polygon->setDirectOcclusion(1.0f);
	polygon->setReverbOcclusion(1.0f);

	this->addChild(polygon);

	return polygon;
}

CtrlAudioGeometryPolygon* CtrlAudioGeometry::getPolygon(CubeFace index)
{
	return _polygons[(uint8_t)index];
}

void CtrlAudioGeometry::onGeometryChange()
{
	FMOD_VECTOR forward;
	FMOD_VECTOR up;
	FMOD_VECTOR pos;
	FMOD_VECTOR scale;

	ConvertToFMODVector(_geometryBody.forward, &forward);
	ConvertToFMODVector(_geometryBody.up, &up);
	ConvertToFMODVector(_geometryBody.position, &pos);
	ConvertToFMODVector(_geometryBody.scale, &scale);

	AUDIO_SET_FUNC(_geometry, setRotation, &forward, &up);
	AUDIO_SET_FUNC(_geometry, setPosition, &pos);
	AUDIO_SET_FUNC(_geometry, setScale, &scale);
}

void CtrlAudioGeometry::onPolygonsChange()
{
	math::Matrix44 mat = this->getWorldMatrix();
	math::Vector3 position = mat.getPosition();
	math::Volume volume = this->getVolume();
	Tool::calCube(position, volume, getAnchorPoint(), _cubeVertex);
	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		CtrlAudioGeometryPolygon* polygon = getPolygon((CubeFace)i);
		RectVectices rectVertex = getRectVertex(i);
		if (polygon == nullptr)
		{
			this->addPolygon(rectVertex);
		}
		else
		{
			polygon->setVertexes(rectVertex);
		}
	}
}

const RectVectices& CtrlAudioGeometry::getRectVertex(int i)
{
	if (i < 0 || i >= (int)CubeFace::MAX)
	{
		return _cubeVertex.front;
	}
	CubeFace face = (CubeFace)i;
	switch (face)
	{
	case render::CubeFace::FRONT:
		return _cubeVertex.front;
		break;
	case render::CubeFace::BACK:
		return _cubeVertex.back;
		break;
	case render::CubeFace::LEFT:
		return _cubeVertex.left;
		break;
	case render::CubeFace::RIGHT:
		return _cubeVertex.right;
		break;
	case render::CubeFace::TOP:
		return _cubeVertex.top;
		break;
	case render::CubeFace::BOTTOM:
		return _cubeVertex.bottom;
		break;
	default:
		break;
	}

	return _cubeVertex.front;
}


//////////////////////////////////////////////////////////////////////////

CtrlAudioGeometryPolygon::CtrlAudioGeometryPolygon()
	:_index(-1)
	, _geometry(nullptr)
	, _realVertexes(nullptr)
	, _realVerticeCount(0)
{

}

CtrlAudioGeometryPolygon::~CtrlAudioGeometryPolygon()
{
	if (_realVertexes)
	{
		delete[] _realVertexes;
	}
}

bool CtrlAudioGeometryPolygon::init()
{
	if (!Node::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::SPACE, [this](){
		this->onPolygonChange();
	});

	_notify->addListen(NodeNotifyType::AUDIO, [this](){
		this->onAttributeChange();
	});

	_notify->addListen(NodeNotifyType::GEOMETRY, [this](){
		this->onPolygonChange();
	});

	return true;
}

void CtrlAudioGeometryPolygon::setGeometry(FMOD::Geometry* geometry)
{
	_geometry = geometry;
}

int CtrlAudioGeometryPolygon::getIndex()
{
	return _index;
}

void CtrlAudioGeometryPolygon::setDirectOcclusion(float value)
{
	_geometrySettings.directocclusion = value;
	this->notify(NodeNotifyType::AUDIO);
}

float CtrlAudioGeometryPolygon::getDirectOcclusion()
{
	return _geometrySettings.directocclusion;
}

void CtrlAudioGeometryPolygon::setReverbOcclusion(float value)
{
	_geometrySettings.reverbocclusion = value;
	this->notify(NodeNotifyType::AUDIO);
}

float CtrlAudioGeometryPolygon::getReverbOcclusion()
{
	return _geometrySettings.reverbocclusion;
}

void CtrlAudioGeometryPolygon::setDoubleSided(bool value)
{
	_geometrySettings.doublesided = value;
	this->notify(NodeNotifyType::AUDIO);
}

bool CtrlAudioGeometryPolygon::isDoubleSided()
{
	return _geometrySettings.doublesided;
}

bool CtrlAudioGeometryPolygon::setVertexes(const math::Vector3* vertexes, int numvertices)
{
	if (vertexes == nullptr || numvertices <= 0)
	{
		return false;
	}

	if (_realVertexes != nullptr && numvertices != _realVerticeCount)
	{
		return false;
	}

	_vertexes.clear();
	for (int i = 0; i < numvertices; i++)
	{
		_vertexes.push_back(vertexes[i]);
	}

	this->notify(NodeNotifyType::GEOMETRY);

	return true;
}

bool CtrlAudioGeometryPolygon::setVertexes(const std::vector<math::Vector3>& vertexes)
{
	int count = vertexes.size();

	if (count <= 0)
	{
		return false;
	}

	if (_realVertexes != nullptr && count != _realVerticeCount)
	{
		return false;
	}

	_vertexes.clear();
	for (int i = 0; i < count; i++)
	{
		_vertexes.push_back(vertexes[i]);
	}

	this->notify(NodeNotifyType::GEOMETRY);
	return true;
}

bool CtrlAudioGeometryPolygon::setVertexes(const RectVectices& vertexes)
{
	_vertexes.clear();
	_vertexes.push_back(vertexes.leftDown);
	_vertexes.push_back(vertexes.rightDown);
	_vertexes.push_back(vertexes.rightUp);
	_vertexes.push_back(vertexes.leftUp);
	this->notify(NodeNotifyType::GEOMETRY);
	return true;
}

bool CtrlAudioGeometryPolygon::updateVertex(int index, const math::Vector3& vertex)
{
	int count = _vertexes.size();
	if (count == 0)
	{
		return false;
	}
	if (index < 0 || index >= count)
	{
		return false;
	}

	_vertexes[index] = vertex;

	this->notify(NodeNotifyType::GEOMETRY);
	return true;
}

void CtrlAudioGeometryPolygon::onPolygonChange()
{
	if (_geometry == nullptr)
	{
		return;
	}

	int count = _vertexes.size();
	if (count == 0)
	{
		return;
	}

	if (_realVertexes == nullptr)
	{

		math::Matrix44 mat = this->getWorldMatrix();
		math::Vector3 position = mat.getPosition();

		_realVertexes = new FMOD_VECTOR[count];
		_realVerticeCount = count;
		for (int i = 0; i < count; i++)
		{
			ConvertToFMODVector(_vertexes[i] + position, &_realVertexes[i]);
		}

		FMOD_RESULT result = _geometry->addPolygon(_geometrySettings.directocclusion, _geometrySettings.reverbocclusion, _geometrySettings.doublesided,
			count, _realVertexes, &_index);
		if (result != FMOD_OK)
		{
			return;
		}
	}
	else
	{
		math::Matrix44 mat = this->getWorldMatrix();
		math::Vector3 position = mat.getPosition();
		for (int i = 0; i < count; i++)
		{
			FMOD_VECTOR pos;
			ConvertToFMODVector(_vertexes[i] + position, &pos);
			_geometry->setPolygonVertex(_index, i, &pos);
		}
	}

	onAttributeChange();
}

void CtrlAudioGeometryPolygon::onAttributeChange()
{
	if (_realVertexes == nullptr)
	{
		return;
	}
	AUDIO_SET_FUNC(_geometry, setPolygonAttributes, _index, _geometrySettings.directocclusion, 	_geometrySettings.reverbocclusion, _geometrySettings.doublesided);
}
