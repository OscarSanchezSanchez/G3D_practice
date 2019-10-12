#version 330 core

in vec3 inPos;	
in vec3 inColor;	
uniform mat4 modelViewProj;
out vec3 colorv;

void main()
{
	colorv = inColor;
	gl_Position = modelViewProj*vec4(inPos,1.0);
}
