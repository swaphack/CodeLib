#pragma once

#include "Action.h"
#include <list>

namespace render
{
	class IntervalAction;

	// �ظ�ִ�м���
	class RepeateAction : public Action
	{
	public:
		RepeateAction();
		virtual ~RepeateAction();
	public:
		int getCount();
		void setCount(int count);

		void setAction(Action* action);
		virtual void setTarget(Node* target);
	protected:
		// ����
		virtual void reset();
		// ��ת
		virtual void reverse();

		virtual void update(float duration);
	private:
		int _count;
		int _totalCount;
		Action* _action;
	};

	// ��Զִ����ȥ
	class RepeateForeverAction : public Action
	{
	public:
		RepeateForeverAction();
		virtual ~RepeateForeverAction();
	public:
		void setAction(Action* action);
		virtual void setTarget(Node* target);
		
	protected:
		// ����
		virtual void reset();
		// ��ת
		virtual void reverse();

		virtual void update(float duration);
	private:
		Action* _action;
	};

	// ˳��ִ�ж���
	class SequenceAction : public Action
	{
	public:
		SequenceAction();
		virtual ~SequenceAction();
	public:
		void addAction(Action* action);
		void removeAction(Action* action);
		void removeAllActions();
		virtual void setTarget(Node* target);
	protected:
		// ����
		virtual void reset();
		// ��ת
		virtual void reverse();

		virtual void update(float duration);
	private:
		std::list<Action*> _actions;
		std::list<Action*> _removeActions;
	};

	// ����ִ�ж���
	class SpawnAction : public Action
	{
	public:
		SpawnAction();
		virtual ~SpawnAction();
	public:
		void addAction(Action* action);
		void removeAction(Action* action);
		void removeAllActions();
		virtual void setTarget(Node* target);
	protected:
		// ����
		virtual void reset();
		// ��ת
		virtual void reverse();

		virtual void update(float duration);
	private:
		std::list<Action*> _actions;
		std::list<Action*> _removeActions;
	};

	// �޲������ú���
	class CallFunc : public Action
	{
	public:
		CallFunc();
		virtual ~CallFunc();
	public:
		void setFunc(const std::function<void()>& func);
	protected:
		virtual void update(float duration);
	private:
		std::function<void()> _func;
	};

	// �в������ú���
	class CallFuncN : public Action
	{
	public:
		CallFuncN();
		virtual ~CallFuncN();
	public:
		void setFunc(const std::function<void(Node*)>& func);
	protected:
		virtual void update(float duration);
	private:
		std::function<void(Node*)> _func;
	};
}