#pragma once

namespace sys
{
	// 方程
	class Equation
	{
	public:
		Equation();
		virtual ~Equation();
	public:
		virtual void setExpression(const char* expression);
	protected:
	private:
	};

	// 向量方程
	class VectorEquation : public Equation
	{
	public:
		VectorEquation();
		virtual ~VectorEquation();
	public:
		virtual void setExpression(const char* expression);

		float getX(float* params);
		float getY(float* params);
		float getZ(float* params);
	protected:
	private:
	};
}