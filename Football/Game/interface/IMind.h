#pragma once

namespace game
{
	class IAction;
	class IScene;

	/**
	*	˼��
	*/
	class IMind
	{
	public:
		virtual ~IMind() {}
	public:
		/**
		*	��ȡ��һ������
		*/
		virtual IAction* getAction(IScene* pScene) = 0;
	};
}