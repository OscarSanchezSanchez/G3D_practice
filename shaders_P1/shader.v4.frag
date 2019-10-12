#version 330 core

out vec4 outColor;
in vec3 nv;

uniform sampler2D colorTex;



void main()
{
	
	outColor = nv.xyzz;
}
