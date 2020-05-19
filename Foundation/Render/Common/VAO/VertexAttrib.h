#pragma once
#include "Graphic/GLAPI/macros.h"
#include "VAOAttrib.h"

namespace render
{
	class VertexAttrib : public VAOAttrib
	{
	public:
		VertexAttrib(uint32_t index, VertexArrayObject* obj);
		virtual~VertexAttrib();
	public:
	public:
		void setValue(double v0);
		void setValue(double v0, double v1);
		void setValue(double v0, double v1, double v2);
		void setValue(double v0, double v1, double v2, double v3);

		void setValue(float v0);
		void setValue(float v0, float v1);
		void setValue(float v0, float v1, float v2);
		void setValue(float v0, float v1, float v2, float v3);


		void setValue(int16_t v0);
		void setValue(int16_t v0, int16_t v1);
		void setValue(int16_t v0, int16_t v1, int16_t v2);
		void setValue(int16_t v0, int16_t v1, int16_t v2, int16_t v3);

		void setValue(int v0);
		void setValue(int v0, int v1);
		void setValue(int v0, int v1, int v2);
		void setValue(int v0, int v1, int v2, int v3);


		void setValue(uint32_t v0);
		void setValue(uint32_t v0, uint32_t v1);
		void setValue(uint32_t v0, uint32_t v1, uint32_t v2);
		void setValue(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3);

		void setValue(uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3);
	public:
		void setValueL(double v0);
		void setValueL(double v0, double v1);
		void setValueL(double v0, double v1, double v2);
		void setValueL(double v0, double v1, double v2, double v3);
	public:
		void setValueArray1(const double* v);
		void setValueArray2(const double* v);
		void setValueArray3(const double* v);
		void setValueArray4(const double* v);

		void setValueArray1(const float* v);
		void setValueArray2(const float* v);
		void setValueArray3(const float* v);
		void setValueArray4(const float* v);

		void setValueArray1(const int16_t* v);
		void setValueArray2(const int16_t* v);
		void setValueArray3(const int16_t* v);
		void setValueArray4(const int16_t* v);

		void setValueArray1(const int* v);
		void setValueArray2(const int* v);
		void setValueArray3(const int* v);
		void setValueArray4(const int* v);

		void setValueArray1(const uint32_t* v);
		void setValueArray2(const uint32_t* v);
		void setValueArray3(const uint32_t* v);
		void setValueArray4(const uint32_t* v);

		void setValueArray4(const int8_t* v);
		void setValueArray4(const uint8_t* v);
		void setValueArray4(const uint16_t* v);
	public:
		void setValue4N(const int8_t* v);
		void setValue4N(const int16_t* v);
		void setValue4N(const int32_t* v);
		void setValue4N(const uint8_t* v);
		void setValue4N(const uint16_t* v);
		void setValue4N(const uint32_t* v);
	public:
		void setValueI4(const int8_t* value);
		void setValueI4(const uint8_t* value);
		void setValueI4(const int16_t* value);
		void setValueI4(const uint16_t* value);
		void setValueI4(const int32_t* value);
		void setValueI4(const uint32_t* value);
	public:
		void setValueL1(const double* value);
		void setValueL2(const double* value);
		void setValueL3(const double* value);
		void setValueL4(const double* value);
	public:
		void setValueP1(VertexAttribPackType type, bool normalized, uint32_t value);
		void setValueP2(VertexAttribPackType type, bool normalized, uint32_t value);
		void setValueP3(VertexAttribPackType type, bool normalized, uint32_t value);
		void setValueP4(VertexAttribPackType type, bool normalized, uint32_t value);
	public:
		void setDivisor(uint32_t divisor);
	protected:
	private:
	};
}