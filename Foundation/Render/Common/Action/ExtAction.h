#pragma once

#include "Action.h"
#include <list>

namespace render
{
	class IntervalAction;

	// 重复执行几次
	class RepeateAction : public Action
	{
	public:
		RepeateAction();
		virtual ~RepeateAction();
	public:
		int getCount();
		void setCount(int count);
		void setAction(IntervalAction* action);
	protected:
		virtual void update(float duration);
	private:
		int _count;
		int _totalCount;
		IntervalAction* _action;
	};

	// 永远执行下去
	class RepeateForeverAction : public Action
	{
	public:
		RepeateForeverAction();
		virtual ~RepeateForeverAction();
	public:
		void setAction(IntervalAction* action);
	protected:
		virtual void update(float duration);
	private:
		IntervalAction* _action;
	};

	// 顺序执行动作
	class SequenceAction : public Action
	{
	public:
		SequenceAction();
		virtual ~SequenceAction();
	public:
		void addAction(Action* action);
		void removeAction(Action* action);
		void removeAllActions();
	protected:
		virtual void update(float duration);
	private:
		std::list<Action*> _actions;
	};

	// 并行执行动作
	class SpawnAction : public Action
	{
	public:
		SpawnAction();
		virtual ~SpawnAction();
	public:
		void addAction(Action* action);
		void removeAction(Action* action);
		void removeAllActions();
	protected:
		virtual void update(float duration);
	private:
		std::list<Action*> _actions;
	};

	// 无参数调用函数
	class CallFunc : public Action
	{
	public:
		CallFunc();
		virtual ~CallFunc();
	public:
		void setFunc(std::function<void()> func);
	protected:
		virtual void update(float duration);
	private:
		std::function<void()> _func;
	};

	// 有参数调用函数
	class CallFuncN : public Action
	{
	public:
		CallFuncN();
		virtual ~CallFuncN();
	public:
		void setFunc(std::function<void(sys::Object*)> func);
	protected:
		virtual void update(float duration);
	private:
		std::function<void(sys::Object*)> _func;
	};
}