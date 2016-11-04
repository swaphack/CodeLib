#pragma once

#include "Identity.h"

namespace game
{
	class IField;
	/**
	*	������
	*/
	class IStadium
	{
	public:
		virtual ~IStadium() {}
	public:
		/**
		*	���
		*/
		virtual int getID() = 0;
		/**
		*	��������
		*/
		virtual const IField* getField() = 0;
		/**
		*	��λ��
		*/
		virtual int getSeatCount() = 0;
		/**
		*	��̨��
		*/
		virtual int getStandCount() = 0;
	};
}