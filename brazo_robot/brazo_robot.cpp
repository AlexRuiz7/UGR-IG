//**************************************************************************
// Práctica 1
//
// Domingo Martin Perandres 2013-2016
//
// GPL
//**************************************************************************

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <math.h>
#include "robot.h"

// Tamaño de los ejes
const int AXIS_SIZE=5000;

// Variables que definen la posición de la cámara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// Variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width, Window_height, Front_plane, Back_plane;

// Variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50, UI_window_pos_y=50, UI_window_width=500, UI_window_height=500;

//**************************************************************************
//
//***************************************************************************

void clear_window(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
	//  Front_plane>0  Back_plane>PlanoDelantero)
	glFrustum(-Window_width, Window_width, -Window_height, Window_height, Front_plane, Back_plane);
}

//**************************************************************************
// Función para definir la transformación de vista (posicionar la cámara)
//***************************************************************************

void change_observer(){

	// Posición del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-Observer_distance);
	glRotatef(Observer_angle_x,1,0,0);
	glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Función que dibuja los ejes utilizando la primitiva gráfica de lineas
//***************************************************************************

void draw_axis(){
	glBegin(GL_LINES);
	// eje X, color rojo
	glColor3f(1,0,0);
	glVertex3f(-AXIS_SIZE,0,0);
	glVertex3f(AXIS_SIZE,0,0);
	// eje Y, color verde
	glColor3f(0,1,0);
	glVertex3f(0,-AXIS_SIZE,0);
	glVertex3f(0,AXIS_SIZE,0);
	// eje Z, color azul
	glColor3f(0,0,1);
	glVertex3f(0,0,-AXIS_SIZE);
	glVertex3f(0,0,AXIS_SIZE);
	glEnd();
}


//**************************************************************************
// Función que dibuja los objetos
//***************************************************************************

// Objetos
//Cube cubo;
//Dedo dedo;
//Pinza pinza;
//Brazo1 brazo1;
//Brazo2 brazo2;
Robot robot;

/* Entero que representa el modo de visualización del objeto:
		0: Puntos
		1: Aristas
		2: Sólido
		3: Ajedrez (sólido o aristas, según modo previo)
*/
unsigned short mode = 0;

float p=0, r1=0, r2=0, r3=0;

void draw_objects(){
	//robot.brazo2.brazo1.pinza.setPinza(p);
	robot.setPinza(p);
	robot.setBrazo1(r1);
	robot.setBrazo2(r2, r3);
	robot.draw(mode);

	glutPostRedisplay();
}

//**************************************************************************
//
//***************************************************************************

void draw_scene(void){
	clear_window();
	change_observer();
	draw_axis();
	draw_objects();
	glutSwapBuffers();
}


//***************************************************************************
// Función llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1, int Alto1){
	change_projection();
	glViewport(0, 0, Ancho1, Alto1);
	glutPostRedisplay();
}

//***************************************************************************
// Función llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// código de la tecla
// posición x del raton
// posición y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1, int x, int y){

		Tecla1 = toupper(Tecla1);

		switch(Tecla1){
			case 'P':
				mode = 0;
				break;
			case 'A':
				mode = 1;
				break;
			case 'S':
				mode = 2;
				break;
			case 'C':
				mode = 3;
				break;
			case 27:
				exit(0);
			case 'T':
				mode = 4;
				break;
			case '+':
				if(p<1.5)
					p+=0.1;
				break;
			case '-':
				if(p>0.1)
					p-=0.1;
				break;
			case 'H':
				r1++;
				break;
			case 'J':
				r1--;
				break;
			case 'B':
				r2++;
				break;
			case 'N':
				r2--;
				break;
			case 'M':
				r3++;
				break;
			case 'V':
				r3--;
				break;
		}

		glutPostRedisplay();
}

//***************************************************************************
// Función llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// código de la tecla
// posición x del raton
// posición y del raton

//***************************************************************************

void special_keys(int Tecla1, int x, int y){

switch (Tecla1){
	case GLUT_KEY_LEFT:
		Observer_angle_y--;
		break;
	case GLUT_KEY_RIGHT:
		Observer_angle_y++;
		break;
	case GLUT_KEY_UP:
		Observer_angle_x--;
		break;
	case GLUT_KEY_DOWN:
		Observer_angle_x++;
		break;
	case GLUT_KEY_PAGE_UP:
		Observer_distance*=1.2;
		break;
	case GLUT_KEY_PAGE_DOWN:
		Observer_distance/=1.2;
		break;
	}
	glutPostRedisplay();
}

//***************************************************************************
// Función de incialización
//***************************************************************************

void initialize(void){
	// se inicalizan la ventana y los planos de corte
	Window_width=5;
	Window_height=5;
	Front_plane=10;
	Back_plane=1000;

	// se inicia la posicion del observador, en el eje z
	Observer_distance=2*Front_plane;
	Observer_angle_x=0;
	Observer_angle_y=0;

	// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
	// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
	glClearColor(1,1,1,1);

	// se habilita el z-bufer
	glEnable(GL_DEPTH_TEST);
	change_projection();
	glViewport(0, 0, UI_window_width, UI_window_height);
}

//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv){

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("Práctica 1");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);

// función de inicialización
initialize();

// inicio del bucle de eventos
glutMainLoop();
return 0;
}
