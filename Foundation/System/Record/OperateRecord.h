#pragma once

#include <deque>

namespace sys
{
	/**
	*	操作接口
	*/ 
	class OperateProtocol
	{
	public:
		virtual ~OperateProtocol() {}
	public:
		/**
		*	重新执行
		*/
		virtual void redo() = 0;
		/**
		*	撤销
		*/
		virtual void undo() = 0;
	private:

	};

	/**
	*	操作记录
	*/
	class OperateRecord
	{
	public:
		OperateRecord();
		virtual ~OperateRecord();
	public:
		/**
		*	重新执行
		*/
		void push(OperateProtocol* operate);
		/**
		*	重新执行
		*/
		void redo();
		/**
		*	撤销
		*/
		void undo();
		/**
		*	清空操作
		*/
		void clean();
	private:
		// 操作记录
		std::deque<OperateProtocol*> _doRecord;
		// 回撤记录
		std::deque<OperateProtocol*> _undoRecord;
	};
}