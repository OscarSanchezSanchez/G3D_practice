#version 330 core

out vec4 outColor;
in vec3 colorv;

void main()
{
	outColor = colorv.xyzz;
}
