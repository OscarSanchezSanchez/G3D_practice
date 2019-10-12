#version 330 core

out vec4 outColor;


void main()
{
	vec2 c = vec2(1,0);	
	
	outColor = (mod(gl_PrimitiveID, 2)==0) ? c.xxxx: c.yyxx;
	
	//outColor = c.xyyy;   
}
