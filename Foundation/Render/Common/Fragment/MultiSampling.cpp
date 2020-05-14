#include "MultiSampling.h"
#include "Graphic/import.h"

render::MultiSampling::MultiSampling()
{
	_sampleType = MultiSampleType::SAMPLE_MASK;
	_sampleConverage.t1 = 0;
	_sampleConverage.t2 = false;
}

render::MultiSampling::~MultiSampling()
{

}

void render::MultiSampling::setSampleType(MultiSampleType type)
{
	_sampleType = type;
}

void render::MultiSampling::setSampleCoverage(float value, bool invert)
{
	_sampleConverage.t1 = value;
	_sampleConverage.t2 = invert;
}

void render::MultiSampling::setSampleMask(uint32_t index, uint32_t mask)
{
	_sampleMask[index] = mask;
}

void render::MultiSampling::clearSampelMask()
{
	_sampleMask.clear();
}

void render::MultiSampling::startTest()
{
	GLState::enable((EnableModel)_sampleType);
}

void render::MultiSampling::test()
{
	if (_sampleType == MultiSampleType::SAMPLE_ALPHA_TO_COVERAGE
		|| _sampleType == MultiSampleType::SAMPLE_COVERAGE)
	{
		GLState::setSampleCoverage(_sampleConverage.t1, _sampleConverage.t2);
	}
	else if (_sampleType == MultiSampleType::SAMPLE_MASK)
	{
		for (auto item : _sampleMask)
		{
			GLState::setSampleMask(item.first, item.second);
		}
	}
}

void render::MultiSampling::endTest()
{
	GLState::disable((EnableModel)_sampleType);
}
