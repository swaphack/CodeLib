#include "CtrlAudioGeometry.h"
#include "AudioManager.h"
#include "Common/DrawNode/DrawNode.h"

#define MAX_POLYGON_COUNT 1
#define POLYGON_INDEX 0

using namespace render;

CtrlAudioGeometry::CtrlAudioGeometry()
	:_geometry(nullptr)
	, _maxPolygonCount(0)
	, _maxVerticesCount(0)
{
	for (int i = 0; i < EMF_MAX; i++)
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

	_notify->addListen(ENP_SPACE, [this](){
		_geometryBody.position = this->getPosition();
		_geometryBody.scale = this->getScale();
		onGeometryChange();
		onPolygonsChange();
	});

	_notify->addListen(ENP_AUDIO, [this](){
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
	_notify->addMark(ENP_AUDIO);
	setDirty(true);
}

const math::Vector3& CtrlAudioGeometry::getForward()
{
	return _geometryBody.forward;
}

void CtrlAudioGeometry::setUp(const math::Vector3& up)
{
	_geometryBody.up = up;
	_notify->addMark(ENP_AUDIO);
	setDirty(true);
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

CtrlAudioGeometryPolygon* CtrlAudioGeometry::addPolygon(const RectVertex& vertexes)
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

CtrlAudioGeometryPolygon* CtrlAudioGeometry::getPolygon(ModelFace index)
{
	if (index < 0 || index >= EMF_MAX)
	{
		return nullptr;
	}

	return _polygons[index];
}

void CtrlAudioGeometry::onGeometryChange()
{
	FMOD_VECTOR forward;
	FMOD_VECTOR up;
	FMOD_VECTOR pos;
	FMOD_VECTOR scale;

	ConvertToFMODVector(_geometryBody.forward, forward);
	ConvertToFMODVector(_geometryBody.up, up);
	ConvertToFMODVector(_geometryBody.position, pos);
	ConvertToFMODVector(_geometryBody.scale, scale);

	AUDIO_SET_FUNC(_geometry, setRotation, &forward, &up);
	AUDIO_SET_FUNC(_geometry, setPosition, &pos);
	AUDIO_SET_FUNC(_geometry, setScale, &scale);
}

void CtrlAudioGeometry::onPolygonsChange()
{
	Tool::calRealCube(_realBodySpace.position, _realBodySpace.volume, getAnchorPoint(), _cubeVertex);
	for (int i = 0; i < EMF_MAX; i++)
	{
		CtrlAudioGeometryPolygon* polygon = getPolygon((ModelFace)i);
		RectVertex rectVertex = getRectVertex(i);
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

const RectVertex& CtrlAudioGeometry::getRectVertex(int i)
{
	if (i < 0 || i >= EMF_MAX)
	{
		return _cubeVertex.front;
	}
	ModelFace face = (ModelFace)i;
	switch (face)
	{
	case render::EMF_FRONT:
		return _cubeVertex.front;
		break;
	case render::EMF_BACK:
		return _cubeVertex.back;
		break;
	case render::EMF_LEFT:
		return _cubeVertex.left;
		break;
	case render::EMF_RIGHT:
		return _cubeVertex.right;
		break;
	case render::EMF_TOP:
		return _cubeVertex.top;
		break;
	case render::EMF_BOTTOM:
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

}

bool CtrlAudioGeometryPolygon::init()
{
	if (!Node::init())
	{
		return false;
	}

	_notify->addListen(ENP_SPACE, [this](){
		this->onPolygonChange();
	});

	_notify->addListen(ENP_AUDIO, [this](){
		this->onAttributeChange();
	});

	_notify->addListen(ENP_GEOMETRY, [this](){
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
	_notify->addMark(ENP_AUDIO);
	this->setDirty(true);
}

float CtrlAudioGeometryPolygon::getDirectOcclusion()
{
	return _geometrySettings.directocclusion;
}

void CtrlAudioGeometryPolygon::setReverbOcclusion(float value)
{
	_geometrySettings.reverbocclusion = value;
	_notify->addMark(ENP_AUDIO);
	this->setDirty(true);
}

float CtrlAudioGeometryPolygon::getReverbOcclusion()
{
	return _geometrySettings.reverbocclusion;
}

void CtrlAudioGeometryPolygon::setDoubleSided(bool value)
{
	_geometrySettings.doublesided = value;
	_notify->addMark(ENP_AUDIO);
	this->setDirty(true);
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

	_notify->addMark(ENP_GEOMETRY);

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

	_notify->addMark(ENP_GEOMETRY);
	this->setDirty(true);
	return true;
}

bool CtrlAudioGeometryPolygon::setVertexes(const RectVertex& vertexes)
{
	_vertexes.clear();
	_vertexes.push_back(vertexes.leftDown);
	_vertexes.push_back(vertexes.rightDown);
	_vertexes.push_back(vertexes.rightUp);
	_vertexes.push_back(vertexes.leftUp);
	_notify->addMark(ENP_GEOMETRY);
	this->setDirty(true);
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

	_notify->addMark(ENP_GEOMETRY);
	this->setDirty(true);
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
		SAFE_DELETE(_realVertexes);

		_realVertexes = new FMOD_VECTOR[count];
		_realVerticeCount = count;
		for (int i = 0; i < count; i++)
		{
			ConvertToFMODVector(_vertexes[i] + _realBodySpace.position, _realVertexes[i]);
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
		for (int i = 0; i < count; i++)
		{
			FMOD_VECTOR pos;
			ConvertToFMODVector(_vertexes[i] + _realBodySpace.position, pos);
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
