#include "TaskCountLimit.h"
#include "Task.h"

alg::work::TaskCountLimit::TaskCountLimit()
{
	this->setCount(1);
}

alg::work::TaskCountLimit::TaskCountLimit(uint32_t nCount)
{
	this->setCount(nCount);
}

alg::work::TaskCountLimit::~TaskCountLimit()
{

}

void alg::work::TaskCountLimit::setCount(uint32_t nCount)
{
	m_nTotalCount = nCount;
	m_nCurrentCount = 0;
}

uint32_t alg::work::TaskCountLimit::getCurrentCount() const
{
	return m_nCurrentCount;
}

uint32_t alg::work::TaskCountLimit::getTotalCount() const
{
	return m_nTotalCount;
}

void alg::work::TaskCountLimit::onUpdate(float dt)
{
	if (m_nCurrentCount >= m_nTotalCount) return;
	if (_task != nullptr)
	{
		if (_task->isOver())
		{// 任务结束
			m_nCurrentCount += 1;
			if (m_nCurrentCount >= m_nTotalCount)
			{// 次数用完
				this->setTrigger(true);
			}
			else
			{// 重置任务
				_task->reset();
			}
		}
	}
}

void alg::work::TaskCountLimit::onReset()
{
	TaskLimit::onReset();

	this->setCount(m_nTotalCount);
}
