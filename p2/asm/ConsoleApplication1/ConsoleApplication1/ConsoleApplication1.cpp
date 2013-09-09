// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <cstdlib> 


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

	while(inif<=finf){
		//halla y1 con el x actual(inif)
		float temp;
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
		};
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
		printf("Ecuacion 1: x = %f , f(x) = %f \n",inif,y1);
		printf("Ecuacion 2: x = %f , f(x) = %f \n",inif,y2);
		if(y1==y2){
			printf("las curvas se cruzan en X = %f , Y = %f \n",inif,y2);
		}
		inif++;
	}
	system("pause"); 
	return 0;
}

