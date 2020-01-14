#pragma once

#include <set>
#include <vector>

namespace math
{
	class CompoundProposition;
	class Proposition;
	class EquivalenceSample;

	/**
	*	�ȼ۹���
	*/
	class EquivalenceRule
	{
	public:
		EquivalenceRule();
		virtual ~EquivalenceRule();
	public:
		void init();
		/**
		*	��ȡ�ȼ�����
		*	���ȴ��ӽڵ㿪ʼ����
		*/
		Proposition* getEquivalenceProposition(CompoundProposition* proposition);
	protected:
		/**
		*	��ȡ�ȼ�����
		*/
		std::vector<Proposition*> getEquivalence(CompoundProposition* proposition);
	public:
		/**
		*	�����ڵ�
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<EquivalenceSample, T>::value, T>::type>
		void addEquivalenceSample()
		{
			T* t = new T();
			this->addEquivalenceSample(t);
		}
		/**
		*	��ӵȼ�ʵ��
		*/
		void addEquivalenceSample(EquivalenceSample* sample);
		/**
		*	�Ƴ��ȼ�ʵ��
		*/
		void removeEquivalenceSample(EquivalenceSample* sample);
		/**
		*	�Ƴ����еȼ�ʵ��
		*/
		void removeAllEquivalenceSamples();
	private:
		std::set<EquivalenceSample*> _equivalenceSamples;
	};
}