#pragma once

#include "macros.h"

namespace nature
{
	class NCell;
	typedef NCell* (NObject::*CreateCellHandler)();
	/**
	*	细胞 （英文名：cell）并没有统一的定义，比较普遍的提法是：细胞是生物体基本的结构和功能单位。
	*	已知除病毒之外的所有生物均由细胞所组成，但病毒生命活动也必须在细胞中才能体现。
	*
	*	一般来说，细菌等绝大部分微生物以及原生动物由一个细胞组成，即单细胞生物，高等植物与高等动物则是多细胞生物。
	*	细胞可分为原核细胞、真核细胞两类，但也有人提出应分为三类，即把原属于原核细胞的古核细胞独立出来作为与之并列的一类。
	*	研究细胞的学科称为细胞生物学。
	*	细胞体形极微，在显微镜下始能窥见，形状多种多样。
	*	主要由细胞核与细胞质构成，表面有细胞膜。
	*	高等植物细胞膜外有细胞壁，细胞质中常有质体，体内有叶绿体和液泡，还有线粒体。
	*	动物细胞无细胞壁，细胞质中常有中心体，而高等植物细胞中则无。
	*	细胞有运动、营养和繁殖等机能。
	*/
	class NCell : public NOrganism
	{
	public:
		NCell();
		virtual ~NCell();
	public:
		// 细胞分裂，需重写
		virtual NCell* division();
		// 更新，需重写
		virtual void update(float dt);
	protected:
		// 判断是否可以同化物质,需重写
		virtual bool canAddInputTarget(NObject* pObject);
		// 同化物质
		virtual NObject* handInputTarget(TargetHandler* handler);
	};
}