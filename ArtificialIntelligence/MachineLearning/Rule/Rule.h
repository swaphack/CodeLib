#pragma once

namespace ml
{
	class RuleItem;
	class RuleCase;

	class Rule
	{
	public:
		void add(RuleItem* item);
		void remove(RuleItem* item);
		bool Match(const RuleCase* sample);
	protected:
	private:
	};
}