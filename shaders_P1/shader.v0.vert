#version 330 core

in vec3 inPos;		

void main()
{
	mat4 view = mat4(1.0);
	mat4 proj = mat4(0.0);

	view[3].z=-3.0;

	float n =1;
	float f = 5;

	proj[0].x = 1/tan(radians(30.0));
	proj[1].y = 1/tan(radians(30.0));
	proj[2].z = -(f+n)/(f-n);
	proj[3].z = -(2.0*f*n)/(f-n);
	proj[2].w = -1.0;
	
	gl_Position = proj*view*vec4(inPos,1.0);
}
