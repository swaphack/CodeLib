#version 330 core

// 位置
layout(location = 0) in vec3 in_position;
// 方向加速度
layout(location = 1) in vec3 in_speedAcceleration;
// 角速度
layout(location = 2) in vec3 in_angleAcceleration;

// 寿命
uniform float lifeTime;
// 间隔时间
uniform float deltaTime;
// 最大时间
uniform float maxTime;

// 输出位置
out vec3 out_Position;

void main()
{
	/*
	if (lifeTime > maxTime)
	{
		out_Position = vec3(0,0,0);
		return;
	}
	*/

	vec3 speed = normal(in_position);

	out_Position = in_position + deltaTime * speed; 

	out_Position = in_position + vec3(deltaTime, deltaTime, deltaTime);

	out_Position = vec3(out_Position.x, out_Position.y, 0);
	//out_Position = vec3(1,1,1);
}