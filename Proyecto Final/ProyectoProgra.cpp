//-------Proyecto final de la materia "Fundamentos de programación"-------
//-------Se realizó por:					  -------
//-------*Gómez Arizmendi José		 		  -------
//-------*Martínez Rosete Karol Joshua		  -------
//-------*Rivas Velázquez José Joaquín		  -------
//-------*Sandoval Rodríguez Rubén Ulises	  -------
//-------*Trinidad Barbero Jorge A. 		  -------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#define p printf 
//seccion de funciones 
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void presentacion(void)
	{//				Aqui se realiza la función que ejecuta la presentación del programa
		gotoxy(25,2);
		p("FACULTAD DE INGENIER%cA \n Proyecto realizado por:\n G%cmez Arizmendi Jos%c Luis \n Mart%cnez Rosete Karol Joshua \n",214,162,130,161);
		p(" Rivas Vel%czquez Jos%c Joaqu%cn \n Sandoval Rodr%cguez Ruben Ulises \n Trinidad Barbero Jorge Alfredo \n",160,130,161);
		p(" Para la materia de: Fundamentos de programaci%cn \n Profesora:Cintia Quezada Reyez \n Grupo: 01 \n",162);
	}
int main(){
//Apuntuntadores para el manejo de archivos
	FILE *entrada;  //origen
	FILE *salida;  //Destino
//variables a utilizar
	char nombreUsuario[]=" ";		//Apuntador para el nombre del usuario
	char nombreArchivoIn[]=" ";			//Apuntador para el nombre que se le dará al archivo de entrada
	char nombreArchivoOut[]=" ";		//Apuntador para el nombre del archivo de salida
	char matriz [6][6] = {{NULL,'1','1','1','1','1'},{'1','A','B','C','D','E'},{'1','F','G','H','I','K'},{'1','L','M','N','O','P'},{'1','Q','R','S','T','U'},{'1','V','W','X','Y','Z'}};//Arreglo bidimensional para la matriz de transformaciones
	char menu;						//Variable para la elección en el menú
	char string[]=" ";				//variable para lectura del archivo de entrada
	char letra;						//Variable para asignación de las letras que introduce el usuario
	char escritura []=" ";			//Variable para cadena de escritura en archivo de salida
	char ext[5]=".txt";			//para posteriormente agregar extensión
	//Variables auxiliares
	int o = 0;						
	int l = 0;
	int u = 0;
//Página de presentación
	presentacion();
	getchar();
	//getchar();
	system("cls"); 			//limpiar pantalla
//Página de datos del usuario	
	p("Por favor, ingrese su nombre (m%cximo 25 caracteres), al finalizar, presione enter \n",160);
	fflush(stdin);
    scanf("%[^\n]s",nombreUsuario);
    p(" %cC%cmo se va a llamar tu archivo de entrada? (sin extensi%cn) \n",168,162,162);
    fflush(stdin);
    gets(nombreArchivoIn);
	strcat(nombreArchivoIn, ext);
    entrada = fopen (nombreArchivoIn , "r");
    if (entrada == NULL) 
		p("Error abriendo archivo");
   	else {
    	fgets (string , 1000 , entrada) != NULL;
		fclose(entrada);
		do{
			string[l] = toupper(string[l]);
			l = l+1;
			}while(string[l] != NULL);
    	}
    ps("%cC%cmo se va a llamar tu archivo de salida? (sin extensi%cn) \n",168,162,162);
    fflush(stdin);
   	gets(nombreArchivoOut);
	strcat(nombreArchivoOut, ext);
	system("cls"); 			//limpiar pantalla
//Página de menú y repetición
	while(1){
		p("Selecciona una opcion y presiona enter");
		p("a) Modificacion del texto");
		p("b) Obtencion del texto original");
		p("Para salir presione 'ctrl+c'");
		menu = ' ';
		scanf("%c",&menu);	
		switch(menu){
			case 'a':
					for(int i=1;i<=5;i++){
						p("ingrese una letra\n");
						scanf("%c", &letra);
						scanf("%c", &letra);
						letra = toupper (letra);
						if(letra >=65 && letra <= 90){
							matriz[0][i] = letra;
							matriz[i][0] = letra;}
						else{
							puts("su letra no corresponde al alfabeto inglés");	
							}
									}
					do{
						for(int i=1;i<=5;i++){
							for(int j=1;j<=5;j++){
								if(string[o] ==32){
									string[o]=NULL;
									o = o + 1;
								}
								else{
									if(string[o] == matriz[i][j]){
										escritura[u] = matriz[i][0];
										u = u+1;
										escritura[u] = matriz[0][j];
										string[o]=NULL;
										o = o + 1;
										u = u+1;
										}
									}
								}
						}
					}while(string[o]!= NULL);
					p("El texto modificado es:");
					p(escritura);
					getchar();
					getchar();
					system("cls");
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
			default:
					p("Opcion no valida, por favor ingrese una opcion valida");
					getchar();
					getchar();
					system("cls");
					break;
		}
			}
	printf("usted ha decidido salir, adios");
	getchar();
	getchar();
	return 0;
}
