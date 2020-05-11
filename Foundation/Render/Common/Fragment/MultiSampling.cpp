#include "MultiSampling.h"
#include "Graphic/import.h"

void render::MultiSampling::enableSampleAlphaToCoverage()
{
	GLState::enable(EnableModel::SAMPLE_ALPHA_TO_COVERAGE);
}

void render::MultiSampling::enableSampleAlphaToOne()
{
	GLState::enable(EnableModel::SAMPLE_ALPHA_TO_ONE);
}

void render::MultiSampling::enableSampleCoverage()
{
	GLState::enable(EnableModel::SAMPLE_COVERAGE);
}

void render::MultiSampling::disableSampleAlphaToCoverage()
{
	GLState::disable(EnableModel::SAMPLE_ALPHA_TO_COVERAGE);
}

void render::MultiSampling::disableSampleAlphaToOne()
{
	GLState::disable(EnableModel::SAMPLE_ALPHA_TO_ONE);
}

void render::MultiSampling::disableSampleCoverage()
{
	GLState::disable(EnableModel::SAMPLE_COVERAGE);
}

void render::MultiSampling::setSampleCoverage(float value, bool invert)
{
	GLState::setSampleCoverage(value, invert);
}

void render::MultiSampling::setSampleMask(uint32_t index, uint32_t mask)
{
	GLFrameBuffer::setSampleMask(index, mask);
}
