#version 410 core

layout(location = 0) in float in_num0;
layout(location = 1) in float in_num1;

out float out_value;

void main()
{
	out_value = in_num0 + in_num1;
}