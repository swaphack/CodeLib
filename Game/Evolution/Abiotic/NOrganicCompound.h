#pragma once

#include "macros.h"
#include "NAbiotic.h"

namespace nature
{
	/**
	*	有机化合物
	*
	*	狭义上的有机化合物主要是由碳元素、氢元素组成，是一定含碳的化合物，但是不包括碳的氧化物（一氧化碳、二氧化碳）、碳酸，碳酸盐、氰化物、硫氰化物、氰酸盐、金属碳化物、部分简单含碳化合物（如SiC）等物质。
	*	但广义有机化合物可以不含碳元素。
	*	有机物是生命产生的物质基础，所有的生命体都含有机化合物。
	*	脂肪、氨基酸、蛋白质、糖、血红素、叶绿素、酶、激素等。
	*	生物体内的新陈代谢和生物的遗传现象，都涉及到有机化合物的转变。
	*	此外，许多与人类生活有密切相关的物质，如石油、天然气、棉花、染料、化纤、塑料、有机玻璃、天然和合成药物等，均与有机化合物有着密切联系。
	*
	*	有机物是含碳化合物（一氧化碳、二氧化碳、碳酸、碳酸盐、碳酸氢盐、金属碳化物、氰化物、硫氰化物等氧化物除外）或碳氢化合物及其衍生物的总称。有机物是生命产生的物质基础。
	*	无机化合物通常指不含碳元素的化合物，但少数含碳元素的化合物，如二氧化碳、碳酸、一氧化碳、碳酸盐等不具有有机物的性质，因此这类物质也属于无机物。
	*	有机化合物除含碳元素外，还可能含有氢、氧、氮、氯、磷和硫等元素。
	*	总之，有机化合物都是含碳化合物，但是含碳化合物不一定是有机化合物。
	*/
	class NOrganicCompound : public NAbiotic
	{
	public:
		NOrganicCompound();
		virtual ~NOrganicCompound();
	public:

	protected:
	private:
	};
}