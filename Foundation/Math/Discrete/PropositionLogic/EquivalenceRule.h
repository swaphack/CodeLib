#pragma once

#include <set>
#include <vector>

namespace math
{
	class CompoundProposition;
	class Proposition;
	class EquivalenceSample;

	/**
	*	等价规则
	*/
	class EquivalenceRule
	{
	public:
		EquivalenceRule();
		virtual ~EquivalenceRule();
	public:
		void init();
		/**
		*	获取等价命题
		*	优先从子节点开始处理
		*/
		Proposition* getEquivalenceProposition(CompoundProposition* proposition);
	protected:
		/**
		*	获取等价命题
		*/
		std::vector<Proposition*> getEquivalence(CompoundProposition* proposition);
	public:
		/**
		*	创建节点
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<EquivalenceSample, T>::value, T>::type>
		void addEquivalenceSample()
		{
			T* t = new T();
			this->addEquivalenceSample(t);
		}
		/**
		*	添加等价实例
		*/
		void addEquivalenceSample(EquivalenceSample* sample);
		/**
		*	移除等价实例
		*/
		void removeEquivalenceSample(EquivalenceSample* sample);
		/**
		*	移除所有等价实例
		*/
		void removeAllEquivalenceSamples();
	private:
		std::set<EquivalenceSample*> _equivalenceSamples;
	};
}