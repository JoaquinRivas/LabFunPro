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
		printf("FACULTAD DE INGENIER%cA \n Proyecto realizado por:\n G%cmez Arizmendi Jos%c Luis \n Mart%cnez Rosete Karol Joshua \n",214,162,130,161);
		printf(" Rivas Vel%czquez Jos%c Joaqu%cn \n Sandoval Rodr%cguez Ruben Ulises \n Trinidad Barbero Jorge Alfredo \n",160,130,161);
		printf(" Para la materia de: Fundamentos de programaci%cn \n Profesora:Cintia Quezada Reyez \n Grupo: 01 \n",162);
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
	puts("Por favor, ingresa tu nombre:\n");
	fflush(stdin);
    scanf("%[^\n]s",nombreUsuario);
    puts("Ingresa el nombre del archivo a utilizar(entrada)\n");
    fflush(stdin);
    scanf("%[^\n]s",nombreArchivoIn);
    entrada = fopen (nombreArchivoIn , "r");
    if (entrada == NULL) 
		perror ("Error abriendo archivo");
   	else {
    	fgets (string , 1000 , entrada) != NULL;
		fclose(entrada);
		do{
			string[l] = toupper(string[l]);
			l = l+1;
			}while(string[l] != NULL);
    	}
    puts("Ingresa el nombre del archivo a de salida, recuerda poner '.txt' al final del nombre\n");
    fflush(stdin);
   	scanf("%[^\n]s",nombreArchivoOut);
	system("cls"); 			//limpiar pantalla
//Página de menú y repetición
	while(1){
		puts("Selecciona una opcion y presiona enter");
		puts("a) Modificacion del texto");
		puts("b) Obtencion del texto original");
		puts("Para salir presione 'ctrl+c'");
		menu = ' ';
		scanf("%c",&menu);	
		switch(menu){
			case 'a':
					for(int i=1;i<=5;i++){
						puts("ingrese una letra\n");
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
					puts("El texto modificado es:");
					printf(escritura);
					getchar();
					getchar();
					system("cls");
					salida = freopen(nombreArchivoOut,"w",stdout);
					printf(nombreUsuario);
					printf("El texto modificado es: %s\n",escritura);
					fclose ( salida );	
					break;
			case 'b':
					puts("holi2");
					getchar();
					getchar();
					system("cls");
					break;		
			default:
					puts("Opcion no valida, por favor ingrese una opcion valida");
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
