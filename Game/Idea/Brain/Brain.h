#pragma once

#include "Arithmetical.h"
#include "Input.h"
#include "Output.h"
#include "Memory.h"
#include "Control.h"

namespace idea
{
	class Brain
	{
	public:
		Brain();
		~Brain();
	public:
		Input* getInput();
		Output* getOutput();
		Arithmetical* getArithmetical();
		Memory* getMemory();

		void update();
	protected:
		// ������
		Control* _control;
		// ������
		Arithmetical* _arithmetical;
		// �����豸
		Input* _input;
		// ����豸
		Output* _output;
		// �洢
		Memory* _memory;
	};
}