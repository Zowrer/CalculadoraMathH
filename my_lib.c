/*
* Includes del sistema
*/
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
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
    printf(_("El siguiente menu muestra las categorias de operaciones disponibles\n"));
    printf(_("Para seleccionar una categoria\n"));
    printf(_("¡Inserta el número correspondiente!\n\n"));
    printf(_("[0] Trigonometricas\n"));
    printf(_("[1] Hiperbolicas\n"));
    printf(_("[2] Exponenciales\n"));
    printf(_("[3] Potencia\n"));
    printf(_("[4] Error y Gama\n"));
    printf(_("[5] Redonde y Residuo\n"));
    printf(_("[6] Punto Flotante\n"));
    printf(_("[7] Minimos, Maximos y Diferencia\n"));
    printf(_("[8] Clasificacion y Comparacion\n"));
    printf(_("[9] Otras\n"));
    printf(_("[10] Salir\r\n\n"));
}

/*
* Despliega en pantalla un submenu con las opciones de funciones por categoria
*/
void mostrarSubMenu (int op){
    printf(_("\n\nEl siguiente menu muestra las operaciones disponibles en esta categoria\n"));
    printf(_("Para seleccionar una operacion\n"));
    printf(_("¡Inserta el número correspondiente!\n\n"));
    switch (op) {
        case 0:{
            printf(_("[0] Coseno\n"));
            break;
        }

        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        default:{
            printf(_("\nError: Lo lamento aún está en desarrollo :( \n"));
            break;
        }
    }
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
        return -2147483648;
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
        printf(_("\nLo lamento, nos puedes salir con la combinacion de teclas Crtl+C"));
        printf(_("\nIntenta con la opcion Predefinida\n\n"));
    }

    if (numS == SIGSEGV) {
        printf(_("\nError:"));
        printf(_("\nViolacion de segmentacion\n\n"));
    }
}
