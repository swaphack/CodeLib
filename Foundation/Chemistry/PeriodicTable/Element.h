#pragma once

#include <string>
#include <map>

namespace chem
{
	// 元素信息
	struct Element
	{
		// 编号
		int ID;
		// 符号
		std::string Symbol;
		// 名称
		std::string Name;
		// 原子数
		int AtomicNumber;
		// 相对原子质量
		float RelativeAtomicMass;

		Element()
		{
			ID = 0;
			Symbol = "";
			Name = "";
			AtomicNumber = 0;
			RelativeAtomicMass = 0;
		}
	};
}