#version 410 core

layout(location = 0) in float in_num0;
layout(location = 1) in float in_num1;

out float out_addValue;
out float out_subValue;

void main()
{
	out_addValue = in_num0 + in_num1;

	out_subValue = in_num0 - in_num1;
}