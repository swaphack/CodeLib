#include "MultiSampling.h"
#include "Graphic/import.h"


bool render::MultiSampling::isSupport()
{
	int ret = 0;
	GLState::getInteger(GetTarget::SAMPLE_BUFFERS, &ret);
	return ret != 0;
}
