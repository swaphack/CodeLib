#include "WorkObject.h"

void alg::work::WorkObject::start()
{
	_bPlaying = true;
	_workState = WorkState::Running;
	this->onStart();
}

void alg::work::WorkObject::update(float dt)
{
	if (_workState == WorkState::None)
	{// 未启动
		this->start();
	}
	else if (_workState == WorkState::Running)
	{// 运行中
		if (isPlaying())
		{
			onUpdate(dt);
		}
	}
	else if (_workState == WorkState::End)
	{// 结束
		this->onFinish();
	}
	
}

void alg::work::WorkObject::pause()
{
	_bPlaying = false;
}

void alg::work::WorkObject::resume()
{
	_bPlaying = true;
}

void alg::work::WorkObject::finish()
{
	_bPlaying = false;
	_workState = WorkState::End;
}

bool alg::work::WorkObject::isPlaying() const
{
	return _bPlaying;
}

bool alg::work::WorkObject::isOver() const
{
	return _workState == WorkState::End;
}

void alg::work::WorkObject::reset()
{
	_bPlaying = false;
	_workState = WorkState::None;
	onReset();
}

void alg::work::WorkObject::onStart()
{
}

void alg::work::WorkObject::onUpdate(float dt)
{

}

void alg::work::WorkObject::onFinish()
{
}

void alg::work::WorkObject::onReset()
{
}
