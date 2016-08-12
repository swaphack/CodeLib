#pragma once

#include "macros.h"
#include "NMetabolismProtocol.h"
#include <queue>

namespace nature
{
	// 机体
	class NOrganism : public NObject, public NMetabolismProtocol, public NTimer
	{
	protected:
		// 处理对象
		struct TargetHandler
		{
			bool Finish;
			NObject* Target;

			TargetHandler()
				:Finish(false),
				Target(nullptr)
			{}
		};
	public:
		NOrganism();
		virtual ~NOrganism();
	public:
		// 更新，需重写
		virtual void update(float dt);
		// 输入，需重写
		virtual bool input(NObject* pObject);
		// 注册异化回调
		virtual void setOutputHandler(NObject* pTarget, OutputCallback callback);
	protected:
		// 判断是否可以添加同化物质,需重写
		virtual bool canAddInputTarget(NObject* pObject);
		// 异化处理
		void onOuputHandler(NObject* pObject);
	protected:
		// 同化物
		std::queue<TargetHandler*> _inputTargets;
		// 异化回调参数
		std::pair<NObject*, OutputCallback> _outputCallback;
	};
}