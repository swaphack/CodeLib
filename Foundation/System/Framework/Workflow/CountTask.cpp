#include "CountTask.h"

using namespace sys;

CountTask::CountTask()
{
}

CountTask::CountTask(uint32_t nCount)
{
	this->setCount(nCount);
}

CountTask::~CountTask()
{

}

bool CountTask::isOver()const
{
	return m_nCount <= 0;
}

void CountTask::setCount(uint32_t nCount)
{
	m_nCount = nCount;
}

uint32_t CountTask::getCount() const
{
	return m_nCount;
}

sys::OnceTask::OnceTask()
{
	this->setCount(1);
}

sys::OnceTask::~OnceTask()
{
}
