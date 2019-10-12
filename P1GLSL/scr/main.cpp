#include "BOX.h"
#include <IGL/IGlib.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


//Idenficadores de los objetos de la escena
int objId =-1;

//Declaración de CB
void resizeFunc(int width, int height);
void idleFunc();
void keyboardFunc(unsigned char key, int x, int y);
void mouseFunc(int button, int state, int x, int y);
void mouseMotionFunc(int x, int y);


int main(int argc, char** argv)
{
	std::locale::global(std::locale("spanish"));// acentos ;)
	if (!IGlib::init("../shaders_P1/shader.v4.vert", "../shaders_P1/shader.v4.frag"))
		return -1;
   
	//CBs
	IGlib::setResizeCB(resizeFunc);
	IGlib::setIdleCB(idleFunc);
	IGlib::setKeyboardCB(keyboardFunc);
	IGlib::setMouseCB(mouseFunc);
  	IGlib::setMouseMoveCB(mouseMotionFunc);

	//Se ajusta la cámara
	//Si no se da valor se cojen valores por defecto
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(0.0f);

	view[3].z = -6.0f;

	float n = 1.0f;
	float f = 10.0f;

	proj[0].x = 1 / glm::tan(glm::radians(30.0f));
	proj[1].y = 1 / glm::tan(glm::radians(30.0f));
	proj[2].z = -(f + n) / (f - n);
	proj[3].z = -(2.0f * f * n) / (f - n);
	proj[2].w = -1.0f;

	IGlib::setProjMat(proj);
	IGlib::setViewMat(view);



	//Creamos el objeto que vamos a visualizar
	objId = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex, 
			cubeVertexPos, cubeVertexColor, cubeVertexNormal,cubeVertexTexCoord, cubeVertexTangent);
		
	glm::mat4 modelMat = glm::mat4(1.0f);
	IGlib::setModelMat(objId, modelMat);
	//Incluir texturas aquí.
	IGlib::addColorTex(objId, "../img/color.png");
	

	
	//Mainloop
	IGlib::mainLoop();
	IGlib::destroy();
	return 0;
}

void resizeFunc(int width, int height)
{
	//Ajusta el aspect ratio al tamaño de la venta
}

void idleFunc()
{
	static float ang = 0.0f;
	ang = (ang < 6.2830f) ? ang + 0.01f : 0.0f;

	glm::mat4 model(1.0f);
	model = glm::rotate(model, ang, glm::vec3(1, 1, 0));
	IGlib::setModelMat(objId, model);


}

void keyboardFunc(unsigned char key, int x, int y)
{
	std::cout << "Se ha pulsado la tecla " << key << std::endl << std::endl;
}

void mouseFunc(int button, int state, int x, int y)
{
	if (state==0)
		std::cout << "Se ha pulsado el botón ";
	else
		std::cout << "Se ha soltado el botón ";
	
	if (button == 0) std::cout << "de la izquierda del ratón " << std::endl;
	if (button == 1) std::cout << "central del ratón " << std::endl;
	if (button == 2) std::cout << "de la derecha del ratón " << std::endl;

	std::cout << "en la posición " << x << " " << y << std::endl << std::endl;
}

void mouseMotionFunc(int x, int y)
{
}
