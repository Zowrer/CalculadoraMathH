
/************************************************
*	BENEMÉRITA UNIVERSIDAD AUTÓNOMA DE PUEBLA  	*
*	FACULTAD DE CIENCIAS DE LA COMPUTACIÓN   	*
*                                               *
*   Curso Intel-BuUAP                           *
*												*
*   Desarroladores:                             *
*                                               *
*	Yolanda Alvarez                         	*
*                                               *
*	Pedro Ambrosio                             	*
*                                               *
*	Raul Arias                                 	*
*                                               *
*	Monica Canizo                              	*
*                                               *
*	Ignacio Acevedo Carrera                  	*
*	zourer@gmail.com							*
*	                                        	*
************************************************/

/// Librerias
#include <stdio.h>
#include <math.h>
#include <libintl.h>
#include <locale.h>
#include <signal.h>
#include <unistd.h>

#include "my_lib.h"

///definiciones
#define _(cadena) gettext(cadena)

int main(int argc, char* argv[]){
    // declaracion de variables locales
    //variable para leer la categoria de funciones
    int categoria;

    //variable para leer la operacion elegida
    int operacion;

    //Cambio del manejo de señales, mensaje de error en caso de que no sea posible
	if (signal (SIGINT, myCatch) == SIG_ERR){
		perror ("No se puede cambiar SIGINT");
	}

    if (signal (SIGSEGV	, myCatch) == SIG_ERR){
		perror ("No se puede cambiar SIGTERM");
	}

    //Mensaje de bienvenida
    printf(_("\n\n¡Bienvenido, estas ejecutando una calculadora desarrollada por el equipo Icazas!\n\n"));

    //Ciclo principal
    do{
        //Desplegamos en pantalla el menu de categorias
        mostrarMenu ();

        //Leemos un digito en base 10 de maximo 2 caracteres
        categoria = readInt(10,2);

        //Si el valor leido es un numero evaluamos el menu
        //De lo contrario mostramos mensaje de error
        if (categoria != -2147483648) {
            //Si la opcion elegida no es salida
            //desplegamos en pantalla el submenu de operaciones seleccionadas
            //if (categoria != 10) {
            //    mostrarSubMenu (categoria);
            //}

            //Leemos un digito en base 10 de maximo 2 caracteres
            //operacion = readInt(10,2);

            //Si el valor leido es un numero evaluamos el submenu
            //De lo contrario mostramos mensaje de error
            //if (operacion != NULL){
                //Con la categoria y la operacion elegidas evaluamos la funcion adecuada
                switch (categoria) {
                    case 1:{
		    	suma();
			break;
                    }
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:{
		    	arcoseno();
			break;
		    }
                    case 9:{
                        printf(_("\n\nError: Lo lamento aún está en desarrollo :( \n"));
                        printf(_("\nEs culpa de Peter XD \n\n"));
                        break;
                    }
                    case 10:
                    case 11:
                    case 12:{
			coship();
			break;
		    }
                    case 13:{
			tanhip(); 
			break;
		    }
                    case 14:
                    case 15:
                    case 16:
                    case 17:
                    case 18:
                    case 19:{
			potencia();
			break;
		    }
                    case 20:
                    case 21:
                    case 22:
                    case 23:
                    case 24:{
			frexpre();
			break;
		    }
                    case 25:
                    case 26:
                    case 27:{
                        printf(_("\n\n¡Gracias por usar nuestra calculadora!\n"));
                        printf(_("¡Regresa Pronto!\n\n"));
                        break;
                    }

                    default:{
                        printf(_("\n\n¡Ingresaste una opcion no valida!\n"));
                        printf(_("¡Intenta de nuevo!\n\n"));
                        break;
                    }
                }
            /*}
            else{
                printf(_("\n\n¡Error: no ingresaste un número!\r\n"));
                printf(_("¡Intenta de nuevo!\r\n\n"));
            }*/
        }
        else{
            printf(_("\n\n¡Error: no ingresaste un número!\n"));
            printf(_("¡Intenta de nuevo!\n\n"));
        }


    }while (categoria != 27);
    return 0;
}
