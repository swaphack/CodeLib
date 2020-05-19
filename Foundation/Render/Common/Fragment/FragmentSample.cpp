#include "FragmentSample.h"
#include "Graphic/import.h"

render::FragmentSample::FragmentSample()
	:FragmentHandle(FragmentType::SAMPLE, (EnableMode)FragmentSampleType::SAMPLE_MASK)
{
	_sampleConverage.t1 = 0;
	_sampleConverage.t2 = false;
}

render::FragmentSample::~FragmentSample()
{

}

void render::FragmentSample::setSampleType(FragmentSampleType type)
{
	setEnableMode((EnableMode)type);
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

void render::FragmentSample::update()
{
	FragmentSampleType sampleType = (FragmentSampleType)getEnableMode();
	if (sampleType == FragmentSampleType::SAMPLE_ALPHA_TO_COVERAGE
		|| sampleType == FragmentSampleType::SAMPLE_COVERAGE)
	{
		GLState::setSampleCoverage(_sampleConverage.t1, _sampleConverage.t2);
	}
	else if (sampleType == FragmentSampleType::SAMPLE_MASK)
	{
		for (auto item : _sampleMask)
		{
			GLState::setSampleMask(item.first, item.second);
		}
	}
}
