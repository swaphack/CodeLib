#pragma once

#include "CurvilinearCoordinatesSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	笛卡尔坐标系
	*	直角坐标系
	*/
	template<const int Count>
	class CartesianCoordinatesSystem : public CurvilinearCoordinatesSystem<Count>
	{
	public:
		CartesianCoordinatesSystem()
		{}
		virtual ~CartesianCoordinatesSystem()
		{}
	public:

	protected:
	private:
	};

	/**
	*	二维笛卡尔坐标系
	*/
	class CartesianCoordinatesSystem2D : public CartesianCoordinatesSystem<2>
	{
	public:
		enum Axis2D
		{
			X,
			Y
		};
	public:
		CartesianCoordinatesSystem2D();
		virtual ~CartesianCoordinatesSystem2D();
	public:
		/**
		*	基本坐标系
		*/
		void loadIdentity();
	};

	/**
	*	三维笛卡尔坐标系
	*/
	class CartesianCoordinatesSystem3D : public CartesianCoordinatesSystem<3>
	{
	public:
		enum Axis3D
		{
			X,
			Y,
			Z,
		};
	public:
		CartesianCoordinatesSystem3D();
		virtual ~CartesianCoordinatesSystem3D();
	public:
		/**
		*	基本坐标系
		*/
		void loadIdentity();
	public:
		/**
		*	创建3d坐标系，点，轴，轴向量
		*/
		static CartesianCoordinatesSystem3D create(const Vector3& point, Axis3D eAxis, const Vector3& vector);
	};

	/**
	*	四维笛卡尔坐标系
	*/
	class CartesianCoordinatesSystem4D : public CartesianCoordinatesSystem<4>
	{
	public:
		CartesianCoordinatesSystem4D();
		virtual ~CartesianCoordinatesSystem4D();
	public:
		/**
		*	基本坐标系
		*/
		void loadIdentity();
	};
}