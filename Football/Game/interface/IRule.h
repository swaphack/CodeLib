#pragma once

namespace game
{
	class IAction;
	class IScene;
	class IBall;
	class IPlayer;
	class IField;
	class ITeam;
	/**
	*	��������
	*/
	class IRule
	{
	public:
		virtual ~IRule() {}
	public:
		/**
		*	�����Ƿ񷸹�
		*	@param action ��������
		*	@param action ��������
		*/
		virtual bool isBreakRule(const IScene* pScene, int& nBreakRule) const = 0;
		/**
		*	������������Ƿ��㹻
		*	@param ITeam ����
		*/
		virtual bool isEnoughLineUpPlayer(const ITeam* pTeam) const = 0;
		/**
		*	��������
		*	@param pBall ��
		*	@param pField ��������
		*	@param pLastPlayer ���Ӵ������Ա
		*/
		virtual bool isOutByLine(const IBall* pBall, const IField* pField, const IPlayer* pLastPlayer) const = 0;
		/**
		*	��������
		*	@param pBall ��
		*	@param pField ��������
		*	@param pLastPlayer ���Ӵ������Ա
		*/
		virtual bool isOutEndLine(const IBall* pBall, const IField* pField, const IPlayer* pLastPlayer) const = 0;
		/**
		*	Խλ
		*	@param pBall ��
		*	@param pField ��������
		*	@param pLastPlayer ���Ӵ������Ա
		*/
		virtual bool isOffSide(const IBall* pBall, const IField* pField, const IPlayer* pLastPlayer) const = 0;
		/**
		*	����
		*	@param pBall ��
		*	@param pField ��������
		*	@param pLastPlayer ���Ӵ������Ա
		*/
		virtual bool isGoal(const IBall* pBall, const IField* pField, const IPlayer* pLastPlayer) const = 0;
	};
}