#include "CtrlAudioSource3D.h"
#include "AudioManager.h"

using namespace render;


CtrlAudioSource3D::CtrlAudioSource3D()
{

}

CtrlAudioSource3D::~CtrlAudioSource3D()
{

}

bool CtrlAudioSource3D::init()
{
	if (!CtrlAudioSource::init())
	{
		return false;
	}

	_notify->addListen(ENP_SPACE, [&](){
		FMOD_VECTOR pos;
		FMOD_VECTOR vel;

		_3dSettings.position = this->getPosition();

		ConvertToFMODVector(_3dSettings.position, pos);
		ConvertToFMODVector(_3dSettings.velocity, vel);

		AUDIO_SET_FUNC(_channel, set3DAttributes, &pos, &vel);
	});

	return true;
}

void CtrlAudioSource3D::set3DAttributes(const Attribute3DSettings& setting)
{
	_3dSettings = setting;
}

Attribute3DSettings CtrlAudioSource3D::get3DAttributes()
{
	return _3dSettings;
}

void CtrlAudioSource3D::set3DMinMaxDistance(const sys::Range& distance)
{
	AUDIO_SET_FUNC(_channel, set3DMinMaxDistance, distance.min, distance.max);
}

sys::Range CtrlAudioSource3D::get3DMinMaxDistance()
{
	float min;
	float max;

	AUDIO_DO_FUNC(_channel, get3DMinMaxDistance, &min, &max);

	sys::Range range;
	range.min = min;
	range.max = max;

	return range;
}

void CtrlAudioSource3D::set3DConeSettings(const Cone3DSettings& setting)
{
	AUDIO_SET_FUNC(_channel, set3DConeSettings, setting.insideconeangle, setting.outsideconeangle, setting.outsidevolume);
}

Cone3DSettings CtrlAudioSource3D::get3DConeSettings()
{
	Cone3DSettings setting;
	if (_channel == nullptr)
	{
		return setting;
	}
	AUDIO_DO_FUNC(_channel, get3DConeSettings, &setting.insideconeangle, &setting.outsideconeangle, &setting.outsidevolume);

	return setting;
}

void CtrlAudioSource3D::set3DConeOrientation(const sys::Vector3& orientation)
{
	FMOD_VECTOR vector;
	ConvertToFMODVector(orientation, vector);
	AUDIO_SET_FUNC(_channel, set3DConeOrientation, &vector);
}

sys::Vector3 CtrlAudioSource3D::get3DConeOrientation()
{
	FMOD_VECTOR vector;
	AUDIO_DO_FUNC(_channel, get3DConeOrientation, &vector);

	sys::Vector3 dest;
	ConvertToSysVector(vector, dest);

	return dest;
}

void CtrlAudioSource3D::set3DCustomRolloff(const std::vector<sys::Vector3>& points)
{
	int count = points.size();
	if (count <= 0)
	{
		return;
	}

	FMOD_VECTOR* pVector = new FMOD_VECTOR[count];
	for (int i = 0; i < count; i++)
	{
		ConvertToFMODVector(points[i], pVector[i]);
	}

	AUDIO_SET_FUNC(_channel, set3DCustomRolloff, pVector, count);

	delete pVector;
}

std::vector<sys::Vector3> CtrlAudioSource3D::get3DCustomRolloff()
{
	FMOD_VECTOR* pVector;
	int count;

	AUDIO_DO_FUNC(_channel, get3DCustomRolloff, &pVector, &count);

	std::vector<sys::Vector3> data;
	for (int i = 0; i < count; i++)
	{
		sys::Vector3 dest;
		ConvertToSysVector(pVector[i], dest);
		data.push_back(dest);
	}

	return data;
}

void CtrlAudioSource3D::set3DOcclusion(const Occlusion3DSettings& setting)
{
	AUDIO_SET_FUNC(_channel, set3DOcclusion, setting.directocclusion, setting.reverbocclusion);
}

Occlusion3DSettings CtrlAudioSource3D::get3DOcclusion()
{
	Occlusion3DSettings setting;
	AUDIO_DO_FUNC(_channel, get3DOcclusion, &setting.directocclusion, &setting.reverbocclusion);

	return setting;
}

void CtrlAudioSource3D::set3DSpread(float angle)
{
	AUDIO_SET_FUNC(_channel, set3DSpread, angle);
}

float CtrlAudioSource3D::get3DSpread()
{
	AUDIO_GET_FUNC(_channel, get3DSpread, float);
}

void CtrlAudioSource3D::set3DLevel(float level)
{
	AUDIO_SET_FUNC(_channel, set3DSpread, level);
}

float CtrlAudioSource3D::get3DLevel()
{
	AUDIO_GET_FUNC(_channel, get3DLevel, float);
}

void CtrlAudioSource3D::set3DDopplerLevel(float level)
{
	AUDIO_SET_FUNC(_channel, set3DDopplerLevel, level);
}

float CtrlAudioSource3D::get3DDopplerLevel()
{
	AUDIO_GET_FUNC(_channel, get3DDopplerLevel, float);
}

void CtrlAudioSource3D::set3DDistanceFilter(const Distance3DFilterSettings& setting)
{
	AUDIO_SET_FUNC(_channel, set3DDistanceFilter, setting.custom, setting.customLevel, setting.centerFreq);
}

Distance3DFilterSettings CtrlAudioSource3D::get3DDistanceFilter()
{
	Distance3DFilterSettings setting;
	AUDIO_DO_FUNC(_channel, get3DDistanceFilter, &setting.custom, &setting.customLevel, &setting.centerFreq);
	return setting;
}

void CtrlAudioSource3D::setVelocity(const sys::Vector3& velocity)
{
	_3dSettings.velocity = velocity;
}

const sys::Vector3& CtrlAudioSource3D::getVelocity()
{
	return _3dSettings.velocity;
}

int CtrlAudioSource3D::getInitMode()
{
	return FMOD_3D;
}
