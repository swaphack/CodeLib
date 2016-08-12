#pragma once

#include "macros.h"
#include "NBioticProtocol.h"
#include "NOrganism.h"

namespace nature
{
	/**
	*	生物
	*/
	class NBiotic : public NObject, public NBioticProtocol, public NTimer
	{
	public:
		NBiotic();
		virtual ~NBiotic();
	public:
		// 初始化
		virtual bool init();
		// 更新，需重写
		virtual void update(float dt);

		// 获取机体
		virtual const NOrganism* getOrganism();

		// 同化，需重写
		virtual bool input(NObject* pObject);
		// 注册异化回调
		virtual void setOutputHandler(NObject* pTarget, OutputCallback callback);

		// 生长
		virtual void growing();

		// 应激
		virtual bool touch(NObject* pObject);
		// 注册应激反馈回调
		virtual void setFeedbackCallback(NObject* pTarget, OutputCallback callback);
	protected:
		// 设置机体
		void setOrganism(NOrganism* pOrganism);
		// 异化处理
		void onOuputHandler(NObject* pObject);
		// 反馈处理
		void onFeedbackHandler(NObject* pObject);
	private:
		// 机体
		NOrganism* _organism;
		// 异化回调参数
		std::pair<NObject*, OutputCallback> _outputCallback;
		// 反馈回调参数
		std::pair<NObject*, OutputCallback> _feedbackCallback;
	};
}