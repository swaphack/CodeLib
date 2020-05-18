#include "FragmentSample.h"
#include "Graphic/import.h"

render::FragmentSample::FragmentSample()
{
	_fragmentType = FragmentType::SAMPLE;

	_sampleType = FragmentSampleType::SAMPLE_MASK;
	_sampleConverage.t1 = 0;
	_sampleConverage.t2 = false;
}

render::FragmentSample::~FragmentSample()
{

}

void render::FragmentSample::setSampleType(FragmentSampleType type)
{
	_sampleType = type;
}

void render::FragmentSample::setSampleCoverage(float value, bool invert)
{
	_sampleConverage.t1 = value;
	_sampleConverage.t2 = invert;
}

void render::FragmentSample::setSampleMask(uint32_t index, uint32_t mask)
{
	_sampleMask[index] = mask;
}

void render::FragmentSample::clearSampelMask()
{
	_sampleMask.clear();
}

void render::FragmentSample::begin()
{
	GLState::enable((EnableModel)_sampleType);
}

void render::FragmentSample::update()
{
	if (_sampleType == FragmentSampleType::SAMPLE_ALPHA_TO_COVERAGE
		|| _sampleType == FragmentSampleType::SAMPLE_COVERAGE)
	{
		GLState::setSampleCoverage(_sampleConverage.t1, _sampleConverage.t2);
	}
	else if (_sampleType == FragmentSampleType::SAMPLE_MASK)
	{
		for (auto item : _sampleMask)
		{
			GLState::setSampleMask(item.first, item.second);
		}
	}
}

void render::FragmentSample::end()
{
	GLState::disable((EnableModel)_sampleType);
}
