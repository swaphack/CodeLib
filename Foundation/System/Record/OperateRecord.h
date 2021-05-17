#pragma once

#include <deque>

namespace sys
{
	/**
	*	�����ӿ�
	*/ 
	class OperateProtocol
	{
	public:
		virtual ~OperateProtocol() {}
	public:
		/**
		*	����ִ��
		*/
		virtual void redo() = 0;
		/**
		*	����
		*/
		virtual void undo() = 0;
	private:

	};

	/**
	*	������¼
	*/
	class OperateRecord
	{
	public:
		OperateRecord();
		virtual ~OperateRecord();
	public:
		/**
		*	����ִ��
		*/
		void push(OperateProtocol* operate);
		/**
		*	����ִ��
		*/
		void redo();
		/**
		*	����
		*/
		void undo();
		/**
		*	��ղ���
		*/
		void clean();
	private:
		// ������¼
		std::deque<OperateProtocol*> _doRecord;
		// �س���¼
		std::deque<OperateProtocol*> _undoRecord;
	};
}