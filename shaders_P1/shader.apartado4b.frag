#version 330 core

out vec4 outColor;
in vec2 tc;

uniform sampler2D colorTex;




void main()
{
	//outColor = vec4 (tc, vec2(1.0));
	outColor = texture(colorTex,tc);
	float r = pow((tc.x - 0.5),2);
	float s = pow((tc.y - 0.5),2);
	if(r+s > 0.2) //esto me gustaria cambiarlo por lessThan
	{
		discard;
	}
}
