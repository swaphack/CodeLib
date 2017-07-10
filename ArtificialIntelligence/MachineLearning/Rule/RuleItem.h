#pragma once

namespace ml
{
	class RuleCase;

	class RuleItem
	{
	public:
		virtual bool Match(const RuleCase* sample);
	};
}
