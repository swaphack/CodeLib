#pragma once

#include "Common/import.h"

#include "3d/Common/Model.h"

namespace render
{
	// 3d模型基础，球
	/*
	        z (θ)
			|   P
			|  /
			| /
		  O |/_______ y
		   / \ 
		  /   \
		 x (φ)M
	
	角xOM  φ
	角zOP  θ

	假设P（x，y，z）为空间内一点，则点P也可用这样三个有次序的数(r，θ，φ)来确定，
	其中r为原点O与点P间的距离；θ为有向线段OP与z轴正向的夹角；φ为从正z轴来看自x轴按逆时针方向转到OM所转过的角，这里M为点P在xOy面上的投影；。
	这样的三个数r，θ，φ叫做点P的球面坐标，显然，这里r，θ，φ的变化范围为r∈[0,+∞)，θ∈[0, π]， φ∈[0,2π]
	当r,θ或φ分别为常数时,可以表示如下特殊曲面:
		r = 常数，即以原点为心的球面；
		θ= 常数，即以原点为顶点、z轴为轴的圆锥面；
		φ= 常数，即过z轴的半平面。

	球坐标系(r,θ,φ)与直角坐标系(x,y,z)的转换关系:
	x=rsinθcosφ
	y=rsinθsinφ
	z=rcosθ

	直角坐标系(x,y,z)与球坐标系(r,θ,φ)的转换关系为:
	r = sqrt(x^2 + y^2 + z^2);
	θ = arccos(z/r)
	φ = arctan(y/x)

	*/
	class SphereModel : public Model // 还有问题
	{
	public:
		SphereModel();
		virtual ~SphereModel();
	public:
		virtual bool init();
	public:
		// 设置球半径
		void setRadius(float radius);
		// 获取球半径
		float getRadius();
	protected:
		math::Vector3 getPoint(const math::Vector2& uv);
		math::Vector3 getPoint(float u, float v);

		void updateSphere();
	protected:
		virtual void onDraw();
		virtual void initBufferObject();
		virtual void updateBufferData();
	private:
		// 球半径
		float _radius = 1;
	};
}