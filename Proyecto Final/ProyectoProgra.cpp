//-------Proyecto final de la materia "Fundamentos de programación"-------
//-------Se realizó por:					   -------
//-------*Gómez Arizmendi José		 			   -------
//-------*Martínez Rosete Karol Joshua		 		   -------
//-------*Rivas Velázquez José Joaquín		  		   -------
//-------*Sandoval Rodríguez Rubén Ulises	  	 	   -------
//-------*Trinidad Barbero Jorge A. 		  		   -------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#define p printf 
char matriz [7][7] = {{' ',' ',' ',' ',' ',' '},{' ','A','B','C','D','E'},{' ','F','G','H','I','K'},{' ','L','M','N','O','P'},{' ','Q','R','S','T','U'},{' ','V','W','X','Y','Z'}};
char cadena[25];		//Arreglo para lectura del archivo de entrada sin espacio
char frase[25];			//Arreglo para lectura del archivo de entrada dado por el usuario
//seccion de funciones 
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void presentacion(void)//				Aqui se realiza la función que ejecuta la presentación del programa
{
	gotoxy(25,2);
	p("FACULTAD DE INGENIER%cA \n Proyecto realizado por:\n G%cmez Arizmendi Jos%c Luis \n Mart%cnez Rosete Karol Joshua \n",214,162,130,161);
	p(" Rivas Vel%czquez Jos%c Joaqu%cn \n Sandoval Rodr%cguez Ruben Ulises \n Trinidad Barbero Jorge Alfredo \n",160,130,161);
	p(" Para la materia de: Fundamentos de programaci%cn \n Profesora:Cintia Quezada Reyez \n Grupo: 01 \n",162);
}
char extraerEspacios(char cadena[25])
{
	int tamcad,i,e;
	p("Da la frase");
	fflush(stdin);
	gets(frase);
	tamcad=strlen(frase);
	e=0;
	for (i=0;i<=tamcad;i++)
	{
		if(cadena[i]!=' ')
		{
			cadena[e]=frase[i];
			e=e+1;			
		}		
	}			
}
void asignacion(char let[6])
{
	int col, ren;
	int i=0;
	for(col=1;col<=6;col++)
	{
		matriz[0][col]=let[i];
		i=i+1;
	}
	i=0;	
	for(ren=1;ren<=6;ren++)
	{
		matriz[ren][0]=let[i];
		i=i+1;
	}
}
int main()
{
	//Apuntuntadores para el manejo de archivos
	FILE *entrada;  //origen
	FILE *salida;  //Destino
	//variables a utilizar
	char nombreUsuario[25];		//Arreglo para el nombre del usuario
	char nombreArchivoIn[16];	//Arreglo para el nombre que se le dará al archivo de entrada
	char nombreArchivoOut[16];	//Arreglo para el nombre del archivo de salida
	char menu;			//Variable para la selección en el menú
	char letras5[6];			//Variable para asignación de las letras que introduce el usuario
	char escritura []=" ";		//Variable para cadena de escritura en archivo de salida
	char ext[5]=".txt";		//para posteriormente agregar extensión
	//Variables auxiliares
	int o = 0;						
	int l = 0;
	int u = 0;
	
	//Página de presentación
	presentacion();
	getchar();			//getchar();
	system("cls"); 			//limpiar pantalla
	//Página de datos del usuario	
	p("Por favor, ingrese su nombre (m%cximo 25 caracteres), al finalizar, presione enter \n",160);
	fflush(stdin);
    	gets(nombreUsuario);
    	p(" %cC%cmo se va a llamar tu archivo de entrada? (sin extensi%cn) \n",168,162,162);
    	fflush(stdin);
    	gets(nombreArchivoIn);
	strcat(nombreArchivoIn, ext);
    	entrada = fopen (nombreArchivoIn , "w");
    	if (entrada == NULL) 
		p("Error abriendo archivo");
   	else{
    	     fgets (string , 1000 , entrada) != NULL;
	     fclose(entrada);
	     do{
		string[l] = toupper(string[l]);
		l = l+1;
		}while(string[l] != NULL);
	     }
    	p("%cC%cmo se va a llamar tu archivo de salida? (sin extensi%cn) \n",168,162,162);
    	fflush(stdin);
   	gets(nombreArchivoOut);
	strcat(nombreArchivoOut, ext);
	system("cls"); 			//limpiar pantalla
	//Página de menú y repetición del mismo
	do{
	   p("Selecciona una opcion y presiona enter\n");
	   p("a) Modificacion del texto\n");
	   p("b) Obtencion del texto original\n");
	   p("Para salir presione 'c'\n");
	   menu = ' ';
	   scanf("%c",&menu);	
	   switch(menu){
			//Caso que modifica el texto		
			case 'a':
			   	//Sección que ingresa las letras para la codificación
				for(int i=1;i<=5;i++)
					{p("ingrese una letra\n");
					 scanf("%c", &letra);
					 scanf("%c", &letra);
					 letra = toupper (letra);
					 if(letra >=65 && letra <= 90)
							{matriz[0][i] = letra;
							 matriz[i][0] = letra;}
					 else{
					      puts("su letra no corresponde al alfabeto inglés");	
						}
					}
			   	//Sección que codifica el texto
				do{
				   for(int i=1;i<=5;i++){
					for(int j=1;j<=5;j++){
						if(string[o] ==32)
							{
							string[o]=NULL;
							o = o + 1;
							}
						else
						     {
						      if(string[o] == matriz[i][j])
								{
							 	 escritura[u] = matriz[i][0];
								 u = u+1;
								 escritura[u] = matriz[0][j];
								 string[o]=NULL;
								 o = o + 1;
								 u = u+1;
								 }
						      }
							    }	//Llave del segundo ciclo
							}	//Llave del primer ciclo
					}while(string[o]!= NULL);
				 p("El texto modificado es:");
				 p(escritura);
				 getchar();
				 getchar();
				 system("cls");
				 
			   	 //Sección  que crea y escribe en el archivo de salida
			   	 salida = freopen(nombreArchivoOut,"w",stdout);
				 p(nombreUsuario);
				 p("El texto modificado es: %s\n",escritura);
				 fclose ( salida );	
				 break;
			   
			case 'b':
					p("holi2");
					getchar();
					getchar();
					system("cls");
					break;		
			case 'c':
			   		p("usted ha decidido salir, adi%cs",162);
					getchar();
					getchar();
			   		system("cls");
			   		break;
			default:
					p("Opcion no valida, por favor ingrese una opcion valida");
					getchar();
					getchar();
					system("cls");
					break;
		}	//Llave del switch
	}while(menu != 'c');
	return 0;
}			//Llave del main
