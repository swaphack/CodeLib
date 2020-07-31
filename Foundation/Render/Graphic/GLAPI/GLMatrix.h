#pragma once
#include "mathlib.h"
#include "macros.h"

namespace render
{
	/**
	*	¾ØÕó²Ù×÷Ïà¹Ø
	*/
	class GLMatrix
	{
	public:
		static void setMatrixMode(MatrixMode mode);
		static void applyModelView();
		static void applyProjection();
		static void applyTexture();
	public:
		static void loadMatrix(const float* value);
		static void loadMatrix(const math::Matrix4x4& value);
		static void loadIdentity();
	public:
		static void pushMatrix();
		static void popMatrix();
	public:
		static void multMatrix(const float* value);
		static void multMatrix(const math::Matrix4x4& value);
	public:
		static void rotate(float angle, float x, float y, float z);
		static void rotate(float angle, const math::Vector3& value);
		static void rotate(const math::Vector3& value);
		static void translate(float x, float y, float z);
		static void translate(const math::Vector3& value);
		static void scale(float x, float y, float z);
		static void scale(const math::Vector3& value);
	public:
		static void getProjectionMatrix(float* value);
		static void getModelViewMatrix(float* value);
		static void getTextureMatrix(float* value);
	public:
		static void loadFrustum(float left, float right, float bottom, float top, float zNear, float zFar);
		static void loadOrtho(float left, float right, float bottom, float top, float zNear, float zFar);
	public:
		static void loadTransposeMatrix(float* value);
		static void multTransposeMatrix(float* value);
	};
}