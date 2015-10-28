
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

    //Cambio del manejo de señales, mensaje de error en caso de que no sea posible
	if (signal (SIGINT, myCatch) == SIG_ERR){
		perror ("SIGINT can not change");
	}

    if (signal (SIGSEGV	, myCatch) == SIG_ERR){
		perror ("SIGTERM can not change");
	}

    //Mensaje de bienvenida
    printf(_("\n\nWelcome, you are running a calculator developed by the team Icazas!\n\n"));

    //Ciclo principal
    do{
        //Desplegamos en pantalla el menu de categorias
        mostrarMenu ();

        //Leemos un digito en base 10 de maximo 2 caracteres
        categoria = readInt(10,2);

        //Si el valor leido es un numero evaluamos el menu
        //De lo contrario mostramos mensaje de error
        if (categoria != myNaN ()) {

                //Con la categoria y la operacion elegidas evaluamos la funcion adecuada
                switch (categoria) {
<<<<<<< HEAD
                    case 1:{
                        suma();
                        break;
                    }
                    case 2:
                    case 3:
                    case 4:
                    case 5:{
                        arcoCoseno();
                        break;
                    }
                    case 6:
                    case 7:
                    case 8:{
                        arcoseno();
                        break;
                    }
                    case 9:{
                        break;
                    }
                    case 10:{
                        coseno();
                    }
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
                    case 15:{
                        fmod();
                        break:
                    }
                    case 16:
                    case 17:
                    case 18:
                    case 19:{ potencia();
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
                    case 25:{
                        tan();
                        break;
                    }
                    case 26:
                    case 27:{
                        printf(_("\n\nThank you for using our calculator!\n"));
                        printf(_("Come back soon!\n\n"));
                        break;
                    }

                    default:{
                        printf(_("\n\nYou entered an invalid option!\n"));
                        printf(_("Try again!\n\n"));
                        break;
                    }
                }            
=======
                  case 1: { suma(); break; }
                  case 2:
                  case 3: { multiplicacion(); break; }
                  case 4:
                  case 5:
                  case 6:
                  case 7:
                  case 8: { arcoseno(); break; }
                  case 9: { break; }
                  case 10:
                  case 11: { senoHiper(); break; }
                  case 12: { coship(); break; }
                  case 13: { tanhip(); break; }
                  case 14: { atanDos(); break; }
                  case 15:
                  case 16: { logaritmoNatural(); break; }
                  case 17:
                  case 18: { raizCuadrada(); break; }
                  case 19: { potencia(); break; }
                  case 20: { valorAbsoluto(); break; }
                  case 21:
                  case 22:
                  case 23: { funcionPiso(); break; }
                  case 24: { frexpre(); break; }
                  case 25:
                  case 26:
                  case 27:{
                      printf(_("\n\nThank you for using our calculator!\n"));
                      printf(_("Come back soon!\n\n"));
                      break;
                  }
                  default:{
                      printf(_("\n\nYou entered an invalid option!\n"));
                      printf(_("Try again!\n\n"));
                      break;
                  }
              }            
>>>>>>> fa9790e345d02ae2f5adaa359344ddc614e37219
        }
        else{
            printf(_("\n\nError: It is not a number!\n"));
            printf(_("Try again!\n\n"));
        }
    }while (categoria != 27);
    return 0;
}
