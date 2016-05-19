#include "matrix_common.h"

using namespace render;


Matrix::Matrix()
{
	this->reset();
}

Matrix::~Matrix()
{

}

void Matrix::reset()
{
	Position = sys::Vector(0, 0, 0);
	Scale = sys::Vector(1, 1, 1);
	Rotation = sys::Vector(0, 0, 0);

	matrix[0] = 1.0f;
	matrix[1] = 0.0f;
	matrix[2] = 0.0f;
	matrix[3] = 0.0f;

	matrix[4] = 0.0f;
	matrix[5] = 1.0f;
	matrix[6] = 0.0f;
	matrix[7] = 0.0f;

	matrix[8] = 0.0f;
	matrix[9] = 0.0f;
	matrix[10] = 1.0f;
	matrix[11] = 0.0f;

	matrix[12] = 0.0f;
	matrix[13] = 0.0f;
	matrix[14] = 0.0f;
	matrix[15] = 1.0f;
}

void Matrix::make()
{
	matrix[0] = Scale.x;
	matrix[1] = 0.0f;
	matrix[2] = 0.0f;
	matrix[3] = Rotation.x;

	matrix[4] = 0.0f;
	matrix[5] = Scale.y;
	matrix[6] = 0.0f;
	matrix[7] = Rotation.y;

	matrix[8] = 0.0f;
	matrix[9] = 0.0f;
	matrix[10] = Scale.z;
	matrix[11] = Rotation.z;

	matrix[12] = Position.x;
	matrix[13] = Position.y;
	matrix[14] = Position.z;
	matrix[15] = 1.0f;
}