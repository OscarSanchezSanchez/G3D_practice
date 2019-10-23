#include "BOX.h"
#include <IGL/IGlib.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


//Idenficadores de los objetos de la escena
int objId, objId_new =-1;

//Declaraci�n de CB
void resizeFunc(int width, int height);
void idleFunc();
void keyboardFunc(unsigned char key, int x, int y);
void mouseFunc(int button, int state, int x, int y);
void mouseMotionFunc(int x, int y);

//Matriz de vista
//Se ajusta la camara
//Si no se da valor se cogen valores por defecto
glm::mat4 view = glm::mat4(1.0f);

//Matriz de proyeccion
glm::mat4 proj = glm::mat4(0.0f);

//Velocidad de movimeinto
const float MOVEMENT_SPEED = 0.1f;


int main(int argc, char** argv)
{
	std::locale::global(std::locale("spanish"));// acentos ;)
	if (!IGlib::init("../shaders_P1/shader.v3.vert", "../shaders_P1/shader.v3.frag"))
		return -1;
   
	//CBs
	IGlib::setResizeCB(resizeFunc);
	IGlib::setIdleCB(idleFunc);
	IGlib::setKeyboardCB(keyboardFunc);
	IGlib::setMouseCB(mouseFunc);
  	IGlib::setMouseMoveCB(mouseMotionFunc);

	view[3].z = -20.0f;

	IGlib::setViewMat(view);

	float n = 1.0f;
	float f = 50.0f;

	proj[0].x = 1 / glm::tan(glm::radians(30.0f));
	proj[1].y = 1 / glm::tan(glm::radians(30.0f));
	proj[2].z = -(f + n) / (f - n);
	proj[3].z = -(2.0f * f * n) / (f - n);
	proj[2].w = -1.0f;

	IGlib::setProjMat(proj);


	//Creamos el objeto que vamos a visualizar
	objId = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex, 
			cubeVertexPos, cubeVertexColor, cubeVertexNormal,cubeVertexTexCoord, cubeVertexTangent);
		
	glm::mat4 modelMat = glm::mat4(2.0f);
	IGlib::setModelMat(objId, modelMat);
	//Incluir texturas aqu�.
	IGlib::addColorTex(objId, "../img/diamond_ore.png");
	
	//create second object
	objId_new = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex,
		cubeVertexPos, cubeVertexColor, cubeVertexNormal, cubeVertexTexCoord, cubeVertexTangent);
	IGlib::setModelMat(objId_new, modelMat);
	//Mainloop
	IGlib::mainLoop();
	IGlib::destroy();
	return 0;
}

void resizeFunc(int width, int height)
{
	float aspectRatio = (float)width / (float)height;

	proj[0].x = 1 / (glm::tan(glm::radians(30.0f)) * aspectRatio);

	IGlib::setProjMat(proj);
}

void idleFunc()
{
	static float ang = 0.0f;
	ang = (ang < 6.2830f) ? ang + 0.01f : 0.0f;

	glm::mat4 model(1.0f);
	model = glm::rotate(model, ang, glm::vec3(1, 1, 0));
	IGlib::setModelMat(objId, model);

	glm::mat4 model2(1.0f);
	model2 = glm::rotate(model2, ang, glm::vec3(4, 0, -0.01));
	IGlib::setModelMat(objId_new, model2);

	model2 = glm::translate(model2, glm::vec3(0, 3, 0));
	IGlib::setModelMat(objId_new, model2);

	model2 = glm::rotate(model2, ang, glm::vec3(1, 0, 0));
	IGlib::setModelMat(objId_new, model2);

}

void keyboardFunc(unsigned char key, int x, int y)
{
	std::cout << "Se ha pulsado la tecla " << key << std::endl << std::endl;
	switch (key)
	{
	case 'w': 
		view[3].z += MOVEMENT_SPEED;
		IGlib::setViewMat(view);
		break;
	case 's':
		view[3].z -= MOVEMENT_SPEED;
		IGlib::setViewMat(view);
		break;
	case 'a':
		view[3].x += MOVEMENT_SPEED;
		IGlib::setViewMat(view);
		break;
	case 'd':
		view[3].x -= MOVEMENT_SPEED;
		IGlib::setViewMat(view);
		break;
	case 'q':
		break;
	case 'e':
		break;
	}

}

void mouseFunc(int button, int state, int x, int y)
{
	if (state==0)
		std::cout << "Se ha pulsado el bot�n ";
	else
		std::cout << "Se ha soltado el bot�n ";
	
	if (button == 0) std::cout << "de la izquierda del rat�n " << std::endl;
	if (button == 1) std::cout << "central del rat�n " << std::endl;
	if (button == 2) std::cout << "de la derecha del rat�n " << std::endl;

	std::cout << "en la posici�n " << x << " " << y << std::endl << std::endl;
}

void mouseMotionFunc(int x, int y)
{
}
