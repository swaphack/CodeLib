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
		virtual int getID() const = 0;
		/**
		*	��������
		*/
		virtual const IField* getField() const = 0;
		/**
		*	��λ��
		*/
		virtual int getSeatCount() const = 0;
		/**
		*	��̨��
		*/
		virtual int getStandCount() const = 0;
	};
}