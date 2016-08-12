#pragma once

#include "NOrganism.h"
#include "NMetabolismProtocol.h"

namespace nature
{
	/**
	*	生物通性
	*　	1、生物体具有严整的结构。
	*	稍微解释一下什么叫严整的结构，也就是说细胞是生物体结构和功能的基本单位。
	*	2、生物体能进行新陈代谢。
	*	3、生物体能生长。
	*	4、生物体具有应激性。
	*	5、生物体能生殖和发育。
	*	6、生物体具有遗传和变异的特性。
	*	7、生物体能在一定程度上适应环境并影响环境。
	*/
	class NBioticProtocol 
	{
	public:
		NBioticProtocol() {}
		virtual ~NBioticProtocol() {}
	public:
		// 获取机体
		virtual const NOrganism* getOrganism() = 0;

		// 同化, 需重写
		virtual bool input(NObject* pObject) = 0;
		// 注册异化回调
		virtual void setOutputCallback(NObject* pTarget, OutputCallback callback) {};

		// 生长
		virtual void growing() = 0;

		// 应激
		virtual bool touch(NObject* pObject) = 0;
		// 注册应激反馈回调
		virtual void setFeedbackCallback(NObject* pTarget, OutputCallback callback) {};
	};
}