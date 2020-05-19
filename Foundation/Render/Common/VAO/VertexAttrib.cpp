#include "VertexAttrib.h"

#include "Graphic/import.h"
#include "VertexArrayObject.h"

using namespace render;


VertexAttrib::VertexAttrib(uint32_t index, VertexArrayObject* obj)
	:VAOAttrib(index, obj)
{

}

VertexAttrib::~VertexAttrib()
{

}

void render::VertexAttrib::setValue(double v0)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0);
}

void render::VertexAttrib::setValueL(double v0)
{
	GLBufferObjects::setVertexAttribL(getIndex(), v0);
}

void render::VertexAttrib::setValueArray1(const double* v)
{
	GLBufferObjects::setVertexAttribArray1(getIndex(), v);
}

void render::VertexAttrib::setValueArray2(const uint32_t* v)
{
	GLBufferObjects::setVertexAttribArray2(getIndex(), v);
}

void render::VertexAttrib::setValueArray3(const uint32_t* v)
{
	GLBufferObjects::setVertexAttribArray3(getIndex(), v);
}

void render::VertexAttrib::setValueArray2(const int* v)
{
	GLBufferObjects::setVertexAttribArray2(getIndex(), v);
}

void render::VertexAttrib::setValueArray3(const int* v)
{
	GLBufferObjects::setVertexAttribArray3(getIndex(), v);
}

void render::VertexAttrib::setValueArray2(const int16_t* v)
{
	GLBufferObjects::setVertexAttribArray2(getIndex(), v);
}

void render::VertexAttrib::setValueArray3(const int16_t* v)
{
	GLBufferObjects::setVertexAttribArray3(getIndex(), v);
}

void render::VertexAttrib::setValueArray2(const float* v)
{
	GLBufferObjects::setVertexAttribArray2(getIndex(), v);
}

void render::VertexAttrib::setValueArray3(const float* v)
{
	GLBufferObjects::setVertexAttribArray3(getIndex(), v);
}

void render::VertexAttrib::setValueArray2(const double* v)
{
	GLBufferObjects::setVertexAttribArray2(getIndex(), v);
}

void render::VertexAttrib::setValueArray3(const double* v)
{
	GLBufferObjects::setVertexAttribArray3(getIndex(), v);
}

void render::VertexAttrib::setValueArray4(const double* v)
{
	GLBufferObjects::setVertexAttribArray4(getIndex(), v);
}

void render::VertexAttrib::setValue4N(const int8_t* v)
{
	GLBufferObjects::setVertexAttrib4N(getIndex(), v);
}

void render::VertexAttrib::setValueI4(const int8_t* value)
{
	GLBufferObjects::setVertexAttribI4(getIndex(), value);
}

void render::VertexAttrib::setValueL1(const double* value)
{
	GLBufferObjects::setVertexAttribL1(getIndex(), value);
}

void render::VertexAttrib::setValueL2(const double* value)
{
	GLBufferObjects::setVertexAttribL2(getIndex(), value);
}

void render::VertexAttrib::setValueL3(const double* value)
{
	GLBufferObjects::setVertexAttribL3(getIndex(), value);
}

void render::VertexAttrib::setValueL4(const double* value)
{
	GLBufferObjects::setVertexAttribL4(getIndex(), value);
}

void render::VertexAttrib::setValueP1(VertexAttribPackType type, bool normalized, uint32_t value)
{
	GLBufferObjects::setVertexAttribP1(getIndex(), type, normalized, value);
}

void render::VertexAttrib::setValueP2(VertexAttribPackType type, bool normalized, uint32_t value)
{
	GLBufferObjects::setVertexAttribP2(getIndex(), type, normalized, value);
}

void render::VertexAttrib::setValueP3(VertexAttribPackType type, bool normalized, uint32_t value)
{
	GLBufferObjects::setVertexAttribP3(getIndex(), type, normalized, value);
}

void render::VertexAttrib::setValueP4(VertexAttribPackType type, bool normalized, uint32_t value)
{
	GLBufferObjects::setVertexAttribP4(getIndex(), type, normalized, value);
}

void render::VertexAttrib::setDivisor(uint32_t divisor)
{
	GLBufferObjects::setVertexAttribDivisor(getIndex(), divisor);
}

void render::VertexAttrib::setValueI4(const uint32_t* value)
{
	GLBufferObjects::setVertexAttribI4(getIndex(), value);
}

void render::VertexAttrib::setValueI4(const int32_t* value)
{
	GLBufferObjects::setVertexAttribI4(getIndex(), value);
}

void render::VertexAttrib::setValueI4(const uint16_t* value)
{
	GLBufferObjects::setVertexAttribI4(getIndex(), value);
}

void render::VertexAttrib::setValueI4(const int16_t* value)
{
	GLBufferObjects::setVertexAttribI4(getIndex(), value);
}

void render::VertexAttrib::setValueI4(const uint8_t* value)
{
	GLBufferObjects::setVertexAttribI4(getIndex(), value);
}

void render::VertexAttrib::setValue4N(const uint32_t* v)
{
	GLBufferObjects::setVertexAttrib4N(getIndex(), v);
}

void render::VertexAttrib::setValue4N(const uint16_t* v)
{
	GLBufferObjects::setVertexAttrib4N(getIndex(), v);
}

void render::VertexAttrib::setValue4N(const uint8_t* v)
{
	GLBufferObjects::setVertexAttrib4N(getIndex(), v);
}

void render::VertexAttrib::setValue4N(const int32_t* v)
{
	GLBufferObjects::setVertexAttrib4N(getIndex(), v);
}

void render::VertexAttrib::setValue4N(const int16_t* v)
{
	GLBufferObjects::setVertexAttrib4N(getIndex(), v);
}

void render::VertexAttrib::setValueArray4(const uint16_t* v)
{
	GLBufferObjects::setVertexAttribArray4(getIndex(), v);
}

void render::VertexAttrib::setValueArray4(const uint8_t* v)
{
	GLBufferObjects::setVertexAttribArray4(getIndex(), v);
}

void render::VertexAttrib::setValueArray4(const int8_t* v)
{
	GLBufferObjects::setVertexAttribArray4(getIndex(), v);
}

void render::VertexAttrib::setValueArray4(const uint32_t* v)
{
	GLBufferObjects::setVertexAttribArray4(getIndex(), v);
}

void render::VertexAttrib::setValueArray1(const uint32_t* v)
{
	GLBufferObjects::setVertexAttribArray1(getIndex(), v);
}

void render::VertexAttrib::setValueArray4(const int* v)
{
	GLBufferObjects::setVertexAttribArray4(getIndex(), v);
}

void render::VertexAttrib::setValueArray1(const int* v)
{
	GLBufferObjects::setVertexAttribArray1(getIndex(), v);
}

void render::VertexAttrib::setValueArray4(const int16_t* v)
{
	GLBufferObjects::setVertexAttribArray4(getIndex(), v);
}

void render::VertexAttrib::setValueArray1(const int16_t* v)
{
	GLBufferObjects::setVertexAttribArray1(getIndex(), v);
}

void render::VertexAttrib::setValueArray4(const float* v)
{
	GLBufferObjects::setVertexAttribArray4(getIndex(), v);
}

void render::VertexAttrib::setValueArray1(const float* v)
{
	GLBufferObjects::setVertexAttribArray1(getIndex(), v);
}

void render::VertexAttrib::setValueL(double v0, double v1, double v2, double v3)
{
	GLBufferObjects::setVertexAttribL(getIndex(), v0, v1, v2, v3);
}

void render::VertexAttrib::setValueL(double v0, double v1, double v2)
{
	GLBufferObjects::setVertexAttribL(getIndex(), v0, v1, v2);
}

void render::VertexAttrib::setValueL(double v0, double v1)
{
	GLBufferObjects::setVertexAttribL(getIndex(), v0, v1);
}

void render::VertexAttrib::setValue(uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2, v3);
}

void render::VertexAttrib::setValue(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2, v3);
}

void render::VertexAttrib::setValue(uint32_t v0, uint32_t v1, uint32_t v2)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2);
}

void render::VertexAttrib::setValue(uint32_t v0, uint32_t v1)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1);
}

void render::VertexAttrib::setValue(uint32_t v0)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0);
}

void render::VertexAttrib::setValue(int v0, int v1, int v2, int v3)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2, v3);
}

void render::VertexAttrib::setValue(int v0, int v1, int v2)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2);
}

void render::VertexAttrib::setValue(int v0, int v1)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1);
}

void render::VertexAttrib::setValue(int v0)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0);
}

void render::VertexAttrib::setValue(int16_t v0, int16_t v1, int16_t v2, int16_t v3)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2, v3);
}

void render::VertexAttrib::setValue(int16_t v0, int16_t v1, int16_t v2)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2);
}

void render::VertexAttrib::setValue(int16_t v0, int16_t v1)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1);
}

void render::VertexAttrib::setValue(int16_t v0)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0);
}

void render::VertexAttrib::setValue(float v0, float v1, float v2, float v3)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2, v3);
}

void render::VertexAttrib::setValue(float v0, float v1, float v2)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2);
}

void render::VertexAttrib::setValue(float v0, float v1)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1);
}

void render::VertexAttrib::setValue(float v0)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0);
}

void render::VertexAttrib::setValue(double v0, double v1, double v2, double v3)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2, v3);
}

void render::VertexAttrib::setValue(double v0, double v1, double v2)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1, v2);
}

void render::VertexAttrib::setValue(double v0, double v1)
{
	GLBufferObjects::setVertexAttrib(getIndex(), v0, v1);
}