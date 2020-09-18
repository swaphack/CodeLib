#include "TessilationProtocol.h"
#include "Graphic/import.h"

render::TessilationProtocol::TessilationProtocol()
{
	for (size_t i = 0; i < 4; i++)
	{
		_tessOuterLevel[i] = 0;
	}

	for (size_t i = 0; i < 2; i++)
	{
		_tessInnerLevel[i] = 0;
	}
}

render::TessilationProtocol::~TessilationProtocol()
{
}

void render::TessilationProtocol::setEnableTessilation(bool bEnable)
{
	_bTessilationEnable = bEnable;
}

bool render::TessilationProtocol::isTessilationEnable() const
{
	return _bTessilationEnable;
}

void render::TessilationProtocol::setTessVerticeCount(int value)
{
	_tessVerticeCount = value;
}

int render::TessilationProtocol::getTessVerticeCount() const
{
	return _tessVerticeCount;
}

void render::TessilationProtocol::setTessOuterLevel(float value[4])
{
	for (size_t i = 0; i < 4; i++)
	{
		_tessOuterLevel[i] = value[i];
	}
}

const float* render::TessilationProtocol::getTessOuterLevel() const
{
	return _tessInnerLevel;
}

void render::TessilationProtocol::setTessInnerLevel(float value[2])
{
	for (size_t i = 0; i < 2; i++)
	{
		_tessInnerLevel[i] = value[i];
	}
}

const float* render::TessilationProtocol::getTessInnerLevel() const
{
	return _tessInnerLevel;
}

void render::TessilationProtocol::updateTessilation()
{
	GLBufferObjects::setPatchVertices(_tessVerticeCount);
	GLBufferObjects::setPatchTessOuterLevel(_tessOuterLevel);
	GLBufferObjects::setPatchTessInnerLevel(_tessInnerLevel);
}
