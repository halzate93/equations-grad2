// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <string>
#include <cstdlib> 
#include <iostream>
#include <sstream>
//using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	float a1,b1,c1,a2,b2,c2;
	int ini,fin;
	printf("Ingrese a1 \n");
	scanf("%f",&a1);
	printf("Ingrese b1 \n");
	scanf("%f",&b1);
	printf("Ingrese c1 \n");
	scanf("%f",&c1);
	printf("Ingrese a2 \n");
	scanf("%f",&a2);
	printf("Ingrese b2 \n");
	scanf("%f",&b2);
	printf("Ingrese c2 \n");
	scanf("%f",&c2);
	printf("Ingrese inicio del intervalo  \n");
	scanf("%d",&ini);
	printf("Ingrese fin del intervalo \n");
	scanf("%i",&fin);
	float inif = ((float)(ini));
	float finf = ((float)(fin));
	float y1,y2;
//	const char* args ;
	//string args;	
	//ostringstream osr;
		//inicia el ciclo (compara inif con finf si inif mayor termina la ejecucion saltando a end: http://www.website.masmforum.com/tutorials/fptute/fpuchap7.htm
		__asm{
			ciclo:
			fld inif	
			fcomp finf
			fstsw ax
			fwait
			sahf
			ja endciclo
		}
		//halla y1 con el x actual(inif)
		__asm{
				fld inif
				fld st(0)
				fmulp st(1),st(0)
				fld a1
				fmulp st(1),st(0)
				fld inif
				fld b1
				fmulp st(1),st(0)
				faddp st(1),st(0)
				fld c1
				faddp st(1),st(0)
				fstp y1
		};/*
		args += " ";
		osr<<args<<inif;
		args = osr.str();
		args += " ";
		osr<<args<<y1;
		args = osr.str();
		*/
		//halla y2 con el x actual(inif)
		__asm{
				fld inif
				fld st(0)
				fmulp st(1),st(0)
				fld a2
				fmulp st(1),st(0)
				fld inif
				fld b2
				fmulp st(1),st(0)
				faddp st(1),st(0)
				fld c2
				faddp st(1),st(0)
				fstp y2
		};
		/*
		args += " ";
		osr<<args<<inif;
		args = osr.str();
		args += " ";
		osr<<args<<y2;
		args = osr.str();
		*/
		printf("Ecuacion 1: x = %f , f(x) = %f \n",inif,y1);
		printf("Ecuacion 2: x = %f , f(x) = %f \n",inif,y2);
		// compara y1, y2 si son iguales salta impr: si no salta next:
		__asm{
			fld y1	
			fcomp y2
			fstsw ax
			fwait
			sahf
			jz impr
			jmp nextciclo
			impr:
		}
			printf("las curvas se cruzan en X = %f , Y = %f \n",inif,y2);
		__asm{
			nextciclo:
		}

		inif++;
		// salta al inicio del ciclo
		__asm{
			jmp ciclo
		}
	__asm {
		endciclo:
	}
	//string dir ="java -jar C:/Users/Mateo/Proyectos/Eafit/6/Organizacion/Ecuaciones2grado/p2/graficador/Graficador/dist/Graficador.jar ";
	//dir+=args;
	//const char* call = dir.c_str();
	char value;
	//printf(call);
	FILE* child = _popen("java -jar C:/Users/Mateo/Proyectos/Eafit/6/Organizacion/Ecuaciones2grado/p2/graficador/Graficador/dist/Graficador.jar 0 0 1 1 2 4 3 9","r"); // _popen("java -jar test.jar text1 text2", "r");
	if (fscanf(child, "%s", &value) == 1)
	{
		fprintf(stdout,"Got Value: %f\n", value);
	}
	system("pause"); 
	return 0;
}

