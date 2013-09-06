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

	while(inif<finf){
		//halla y1 con el x actual(inif)
		 __asm{
			fld inif
			fld st(0)
			fld a1
			fmul
			fmul
			fld inif
			fld b1
			fmul
			fadd
			fld c1
			fadd
			fst y1
		};
		 __asm{
			fld inif
			fld st(0)
			fld a2
			fmul
			fmul
			fld inif
			fld b2
			fmul
			fadd
			fld c2
			fadd
			fst y2
		};
		if(y1==y2){
			printf("las curvas se cruzan en X = %f , Y = %f ",inif,y1);
		}
		inif++;
	}
	
		 /*
        int y1 = a*x*x + b*x + c;
        int y2 = d*x*x + e*x + f;
            
        if(y1 == y2){   //Found an interception
            cont++;
            System.out.println("("+x+", "+y1+")");
            g.addPoint(x, y2, true);
        }else{
            g.addPoint(x, y1, false);
            g.addPoint(x, y2, false);
        }*/
	system("pause"); 
	return 0;
}

