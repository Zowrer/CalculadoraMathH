/*
* Includes del sistema
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <libintl.h>
#include <locale.h>
#include <signal.h>
#include <unistd.h>

///definiciones
#define _(cadena) gettext(cadena)

/*
* Despliega en pantalla un menu con las opciones de Categorias
*/
void mostrarMenu (){
    printf(_("The following menu displays the available operations\n"));
    printf(_("To select a category\n"));
    printf(_("Enter the corresponding number!\n\n"));
    printf(_("[1] Addition\n"));
    printf(_("[2] Subtraction\n"));
    printf(_("[3] Multiplication\n"));
    printf(_("[4] Division\n"));
    printf(_("[5] Sine\n"));
    printf(_("[6] Cosine\n"));
    printf(_("[7] Tangent\n"));
    printf(_("[8] Arc sine\n"));
    printf(_("[9] Arc cosine\n"));
    printf(_("[10] Arc tangent\n"));
    printf(_("[11] Hyperbolic sine\n"));
    printf(_("[12] Hyperbolic cosine\n"));
    printf(_("[13] Hyperbolic tangent\n"));
    printf(_("[14] Arc tangent y/x (atan2)\n"));
    printf(_("[15] Exponential\n"));
    printf(_("[16] Natural logarithm\n"));
    printf(_("[17] Decimal logarithm\n"));
    printf(_("[18] Square root\n"));
    printf(_("[19] Power\n"));
    printf(_("[20] Absolute value\n"));
    printf(_("[21] floating point remainder (fmod)\n"));
    printf(_("[22] Ceil function\n"));
    printf(_("[23] Floor function\n"));
    printf(_("[24] frexp\n"));
    printf(_("[25] ldexp\n"));
    printf(_("[26] modf\n"));
    printf(_("[27] Exit\n\n"));
}

int readInt(int base, int max){
    //Buffer para almacenar los digitos leidos
    static int* BUFFER = NULL;


    //la variable b funciona como base de multiplicacion
    //inicia como 0 porque en las unidades: base elevado a la 0 es igual a 1
    //Al ser de tipo char pueden moverse de 0 hasta maximo 255
    unsigned char b = 1;

    //Las variables i y j son para mover indices
    //la variable f funciona como factor (numero positivo o negativo)
    //son de tipo char porque es la unidad signed mas pequeña en C
    //la variable ch almacenara los caracteres sacados del buffer de teclado
    char i = 0, j = 0, f = 1, ch;

    //Variable para almacenar el resultado inicializada
    int result = 0;

    //Leemos el primer caracter en el buffer de teclado
    ch  = getchar();
    //Reservamos memoria para el numero de digitos a leer
    if(BUFFER == NULL){
        BUFFER = malloc(max * sizeof(int));
    }

    //Si el primer caracter es el signo "-" ponemos el factor negativo y leemos el siguiente caracter en el buffer
    if(ch == 45){
        f = -1;
        ch = getchar();
    }
    //Mientras el numero de caracteres leidos sea menor que el maximo requerido
    //el caracter leido sea diferente de nueva linea o Error
    // y sea un digito, almacenamos el caracter leido
    while( (i < max) && (ch != 10) && (ch != -1) && (ch >= 48 && ch <= 57) ){
        BUFFER[i++] = ch;
        ch = getchar();
    }
    //Si no se leyeron digitos retornamos ERROR,
    // antes limpiamos el buffer de teclado
    if( i == 0 || (ch != 10 && ch != -1)){
        while(ch != 10 && ch != -1){
            /* consumo lo que haya en el buffer para vaciarlo.*/
            ch = getchar();
        }
        //Retornamos el valor maximo negativo como codigo de error
        return myNaN ();
    }

    //Si leimos digitos transformamos el string en un entero según la base.
    // De atrás para adelante, multiplicando por la base y sumando.
    for( j = (i-1); j >= 0 ; j-- ){
        result += ( BUFFER[j] - 48 ) * b;
        b*= base;
    }

    /* aplico el signo*/
    result *= f;
    return result;
}

void myCatch (int numS){
    if (numS == SIGINT) {
        printf(_("\nSorry, you can not exit with the key combination Ctrl + C"));
        printf(_("\nTry the default setting\n\n"));
    }

    if (numS == SIGSEGV) {
        printf(_("\nError:"));
        printf(_("\nSegmentation fault\n\n"));
    }
}

int myNaN (){
    return (pow(2,(sizeof(int)*8))+2);
}

void suma (){
    int a,b,c;
    printf(_("\nAddition \n"));
    printf(_("\n1st Number: "));
    scanf("%d",&a);
    printf(_("\n2nd Number: "));
    scanf("%d",&b);
    c = a + b;
    printf(_("\nResult: "));
    printf("%d\n\n",c);
}

void arcoseno(){
    double a,b;
    printf(_("\nArc sine \n"));
    printf(_("\nNumber: "));
    scanf("%lf",&a);
    b=asin(a);
    printf(_("\nResult: "));
    printf("%lf\n\n",b);
}

void coship(){
    double a,b;
    printf(_("\nHyperbolic cosine \n"));
    printf(_("\nNumber: "));
    scanf("%lf",&a);
    b=cosh(a);
    printf(_("\nResult: "));
    printf("%lf\n\n",b);
}

void frexpre(){
    double a,c;
    int b;
    printf(_("\nfrexp \n"));
    printf(_("\nNumber: "));
    scanf("%lf",&a);
    printf(_("\nExponent: "));
    scanf("%d",&b);
    c=frexp(a,&b);
    printf(_("\nResult: "));
    printf("%lf\n\n",c);
}

void potencia(){
    double a,b,c;
    printf(_("\nPower \n"));
    printf(_("\nNumber: "));
    scanf("%lf",&a);
    printf(_("\nPower: "));
    scanf("%lf",&b);
    c=pow(a,b);
    printf(_("\nResult: "));
    printf("%lf\n\n",c);
}

void tanhip(){
    double a,b;
    printf(_("\nHyperbolic tangent \n"));
    printf(_("\nNumber: "));
    scanf("%lf",&a);
    b=tanh(a);
    printf(_("\nResult: "));
    printf("%lf\n\n",b);
}

/*Other*/

void multiplicacion (){
    int a,b;
    printf(_("\nMultiplication \n"));
    printf(_("\n1st Number: "));
    scanf("%d", &a);
    printf(_("\n2nd Number: "));
    scanf("%d", &b);
    printf(_("\nResult: "));
    printf("%d\n\n", a*b);
}

/*void tangHiper (){
  double a;
  printf(_("\nHyperbolic tangent \n"));
  printf(_("\n1st Number: "));
	scanf("%lf", &a);
  printf(_("\nResult: "));
  printf("%lf\n\n", tanh(a));
}*/

void raizCuadrada (){
  double a;
  printf(_("\nSquare root \n"));
  printf(_("\n1st Number: "));
	scanf ("%lf", &a);
  printf(_("\nResult: "));
  printf("%lf\n\n", sqrt(a));
}

void funcionPiso (){
  double a;
  printf(_("\nFloor function \n"));
  printf(_("\n1st Number: "));
  scanf("%lf", &a);
  printf(_("\nResult: "));
  printf("%lf\n\n", floor(a));
}

void atanDos (){
  double a, b;
  printf(_("\nArc Tangent Two (atan2) \n"));
  printf(_("\n1st Number: "));
	scanf("%lf",&a);
	printf(_("\n2nd Number: "));
	scanf("%lf",&b);
  printf(_("\nResult: "));
  printf("%lf\n\n", atan2(a, b));
}

void valorAbsoluto (){
  double a;
  printf(_("\nAbsolute value \n"));
  printf(_("\n1st Number: "));
  scanf ("%lf", &a);
  printf(_("\nResult: "));
  printf("%lf\n\n", fabs(a));
}

void logaritmoNatural (){
  double a;
  printf(_("\nNatural logarithm \n"));
  printf(_("\n1st Number: "));
	scanf ("%lf", &a);
  printf(_("\nResult: "));
  printf("%lf\n\n", log(a));
}

void senoHiper (){
  double a;
  printf(_("\nHyperbolic sine \n"));
  printf(_("\n1st Number: "));
	scanf("%lf", &a);
  printf(_("\nResult: "));
  printf("%lf\n\n", sinh(a));
}

 void arcoCoseno(){
    double x,y;
    printf(_("\nArco Coseno \n"));
    printf(_("\nNúmero: "));
    scanf("%lf",&x);
    y=acos(x);
    printf(_("\nResultado en Radianes: "));
    printf("%lf\n\n",y);
}

void coseno(){
    double x,y;
    printf(_("\nCoseno \n"));
    printf(_("\nNúmero: "));
    scanf("%lf",&x);
    y=cos(x);
    printf(_("\nResultado en Radianes: "));
    printf("%lf\n\n",y);
}


void fmod(){
    double x,y;
    printf("\nModulo de 2 números \n");
    printf("\n1er Número: ");
    scanf("%lf",&x);
    printf("\n2do Número: ");
    scanf("%lf",&y);
    printf("\nEl Módulo de %lf entre %lf es:", x, y);
}

void tan(){

    double x,y;
    printf(_("\nTangente en Radianes \n"));
    printf(_("\nNúmero: "));
    scanf("%lf",&x);
    y=tan(x);
    printf(_("\nResultado en Radianes: "));
    printf("%lf\n\n",y);
}



