#version 330 core

out vec4 outColor;
in vec2 tc;

uniform sampler2D colorTex;




void main()
{
	//outColor = vec4 (tc, vec2(1.0));
	outColor = texture(colorTex,tc);

}
