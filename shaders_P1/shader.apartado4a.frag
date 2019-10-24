#version 330 core

out vec4 outColor;
in vec2 tc;

uniform sampler2D colorTex;




void main()
{
	//outColor = vec4 (tc, vec2(1.0));
	outColor = texture(colorTex, tc);

	if(outColor.rgb == vec3(0.0,0.0,0.0)) //esto me gustaria cambiarlo por lessThan
	{
		discard;
	}
}
