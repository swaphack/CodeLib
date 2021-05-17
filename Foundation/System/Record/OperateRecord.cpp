#include "OperateRecord.h"

using namespace sys;

sys::OperateRecord::OperateRecord()
{
}

sys::OperateRecord::~OperateRecord()
{
}

void sys::OperateRecord::push(OperateProtocol* operate)
{
	if (operate == nullptr)
	{
		return;
	}

	_doRecord.push_back(operate);
}

void sys::OperateRecord::redo()
{
	if (_undoRecord.empty())
	{
		return;
	}

	OperateProtocol* operate = _undoRecord.front();
	operate->redo();
	_undoRecord.pop_front();

	_doRecord.push_back(operate);
}

void sys::OperateRecord::undo()
{
	if (_doRecord.empty())
	{
		return;
	}

	OperateProtocol* operate = _doRecord.back();
	operate->undo();
	_doRecord.pop_back();

	_undoRecord.push_front(operate);
}

void sys::OperateRecord::clean()
{
	while (!_doRecord.empty())
	{
		auto item = _doRecord.front();
		_doRecord.pop_front();
		delete item;
	}

	while (!_undoRecord.empty())
	{
		auto item = _undoRecord.front();
		_undoRecord.pop_front();
		delete item;
	}
}
