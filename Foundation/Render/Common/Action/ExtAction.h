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
		static RepeateAction* create(int nCount, Action* action);

		int getCount()  const;
		void setCount(int count);

		void setAction(Action* action);
		virtual void setTarget(Node* target);
	protected:
		// 重置
		virtual void reset();
		// 反转
		virtual void reverse();

		virtual void update(float duration);
	private:
		int _count = 0;
		int _totalCount = 0;
		Action* _action = nullptr;
	};

	// 永远执行下去
	class RepeateForeverAction : public Action
	{
	public:
		RepeateForeverAction();
		virtual ~RepeateForeverAction();
	public:
		static RepeateForeverAction* create(Action* action);
	public:
		void setAction(Action* action);
		virtual void setTarget(Node* target);
	protected:
		// 重置
		virtual void reset();
		// 反转
		virtual void reverse();

		virtual void update(float duration);
	private:
		Action* _action = nullptr;
	};

	// 顺序执行动作
	class SequenceAction : public Action
	{
	public:
		SequenceAction();
		virtual ~SequenceAction();
	public:
		static SequenceAction* create(Action* action0, Action* action1);
		static SequenceAction* create(Action* action0, Action* action1, Action* action2);
		static SequenceAction* create(Action* action0, Action* action1, Action* action2, Action* action3);
	public:
		void addAction(Action* action);
		void removeAction(Action* action);
		void removeAllActions();
		virtual void setTarget(Node* target);
	protected:
		// 重置
		virtual void reset();
		// 反转
		virtual void reverse();

		virtual void update(float duration);
	private:
		std::list<Action*> _actions;
		std::list<Action*> _removeActions;
	};

	// 并行执行动作
	class SpawnAction : public Action
	{
	public:
		SpawnAction();
		virtual ~SpawnAction();
	public:
		static SpawnAction* create(Action* action0, Action* action1);
		static SpawnAction* create(Action* action0, Action* action1, Action* action2);
		static SpawnAction* create(Action* action0, Action* action1, Action* action2, Action* action3);
	public:
		void addAction(Action* action);
		void removeAction(Action* action);
		void removeAllActions();
		virtual void setTarget(Node* target);
	protected:
		// 重置
		virtual void reset();
		// 反转
		virtual void reverse();

		virtual void update(float duration);
	private:
		std::list<Action*> _actions;
		std::list<Action*> _removeActions;
	};

	// 无参数调用函数
	class CallFunc : public Action
	{
	public:
		CallFunc();
		virtual ~CallFunc();
	public:
		static CallFunc* create(const std::function<void()>& func);

		void setFunc(const std::function<void()>& func);
	protected:
		virtual void update(float duration);
	private:
		std::function<void()> _func = nullptr;
	};

	// 有参数调用函数
	class CallFuncN : public Action
	{
	public:
		CallFuncN();
		virtual ~CallFuncN();
	public:
		static CallFuncN* create(const std::function<void(Node*)>& func);

		void setFunc(const std::function<void(Node*)>& func);
	protected:
		virtual void update(float duration);
	private:
		std::function<void(Node*)> _func = nullptr;
	};
}