#pragma once

namespace sys
{
	// ����
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

	// ��������
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