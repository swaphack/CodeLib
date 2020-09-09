#pragma once

#include "CurvilinearCoordinatesSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	�ѿ�������ϵ
	*	ֱ������ϵ
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
	*	��ά�ѿ�������ϵ
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
		*	��������ϵ
		*/
		void loadIdentity();
	};

	/**
	*	��ά�ѿ�������ϵ
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
		*	��������ϵ
		*/
		void loadIdentity();
	public:
		/**
		*	����3d����ϵ���㣬�ᣬ������
		*/
		static CartesianCoordinatesSystem3D create(const Vector3& point, Axis3D eAxis, const Vector3& vector);
	};

	/**
	*	��ά�ѿ�������ϵ
	*/
	class CartesianCoordinatesSystem4D : public CartesianCoordinatesSystem<4>
	{
	public:
		CartesianCoordinatesSystem4D();
		virtual ~CartesianCoordinatesSystem4D();
	public:
		/**
		*	��������ϵ
		*/
		void loadIdentity();
	};
}