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
		// 控制器
		Control* _control;
		// 运算器
		Arithmetical* _arithmetical;
		// 输入设备
		Input* _input;
		// 输出设备
		Output* _output;
		// 存储
		Memory* _memory;
	};
}