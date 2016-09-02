#pragma once

namespace game
{
	class ITeam;
	class IRule;
	class IField;
	class IFieldSide;

	/**
	*	������
	*/
	class IMatchPart
	{
	public:
		virtual ~IMatchPart() {}
	public:
		/**
		*	����ʱ��
		*/
		virtual float getNormalTime() const = 0;
		/**
		*	��ʱʱ��
		*/
		virtual float getAllowanceTime() const = 0;
		/**
		*	�����Ƿ����
		*/
		virtual bool isMatchOver() const = 0;
		/**
		*	��������
		*/
		virtual const IRule* getRule() const = 0;
		/**
		*	��������
		*/
		virtual const IField* getField() const = 0;
	};
}