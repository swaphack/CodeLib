#pragma once

namespace game
{
	class IAction;
	class IScene;

	/**
	*	思考
	*/
	class IMind
	{
	public:
		virtual ~IMind() {}
	public:
		/**
		*	获取下一步动作
		*/
		virtual IAction* getAction(IScene* pScene) = 0;
	};
}