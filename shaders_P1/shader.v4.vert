#version 330 core

in vec3 inPos;	
in vec3 inNormal;

uniform mat4 modelViewProj;
uniform mat4 normal;

out vec3 nv;

void main()
{
	nv = (normal*vec4(inNormal,0)).xyz;
	gl_Position = modelViewProj *
		vec4(inPos,1.0);
}
