#version 330 core
layout (location = 0) in vec3 aPos; // λ�ñ���������λ��ֵΪ0

out vec4 vertexColor; // ΪƬ����ɫ��ָ��һ����ɫ���

void main()
{
    gl_Position = vec4(aPos, 1.0); // ע��������ΰ�һ��vec3��Ϊvec4�Ĺ������Ĳ���
    vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // �������������Ϊ����ɫ
}