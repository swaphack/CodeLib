#pragma once

#include "Arithmetical/import.h"
#include "IO/import.h"
#include "Memory/import.h"
#include "Control/import.h"

namespace idea
{
	// 大脑
	class Brain
	{
	public:
		Brain();
		virtual ~Brain();
	public:
		// 输入设备
		Input* getInput();
		// 输出设备
		Output* getOutput();
		// 运算器
		Arithmetical* getArithmetical();
		// 存储
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