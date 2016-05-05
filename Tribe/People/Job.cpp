#include "Job.h"

using namespace tribe;


Job::Job()
:_profession(0)
, _beginTime(0)
, _endTime(0)
{
	_property = new Property();
}

Job::~Job()
{
	if (_property)
	{
		
	}
}
