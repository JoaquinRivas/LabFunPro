//-------Proyecto final de la materia "Fundamentos de programaci�n"-------
//-------Se realiz� por:					  -------
//-------*G�mez Arizmendi Jos�		 		  -------
//-------*Mart�nez Rosete Karol Joshua		  -------
//-------*Rivas Vel�zquez Jos� Joaqu�n		  -------
//-------*Sandoval Rodr�guez Rub�n Ulises	  -------
//-------*Trinidad Barbero Jorge A. 		  -------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
//Apuntuntadores para el manejo de archivos
	FILE *entrada;  //origen
	FILE *salida;  //Destino
//variables a utilizar
	char nombreUsuario[]=" ";		//Apuntador para el nombre del usuario
	char nombreArchivoIn[]=" ";			//Apuntador para el nombre que se le dar� al archivo de entrada
	char nombreArchivoOut[]=" ";		//Apuntador para el nombre del archivo de salida
	char matriz [6][6] = {{NULL,'1','1','1','1','1'},{'1','A','B','C','D','E'},{'1','F','G','H','I','K'},{'1','L','M','N','O','P'},{'1','Q','R','S','T','U'},{'1','V','W','X','Y','Z'}};//Arreglo bidimensional para la matriz de transformaciones
	char menu;						//Variable para la elecci�n en el men�
	char string[]=" ";				//variable para lectura del archivo de entrada
	char letra;						//Variable para asignaci�n de las letras que introduce el usuario
	char escritura []=" ";			//Variable para cadena de escritura en archivo de salida
	//Variables auxiliares
	int o = 0;						
	int l = 0;
	int u = 0;
//P�gina de presentaci�n
	puts("Proyecto realizado por:\n");
	puts("Gomez Arizmendi Jose\n");
	puts("Martinez Rosete Karol Joshua\n");
	puts("Rivas Velazquez Jose Joaquin\n");
	puts("Sandoval Rodriguez Ruben Ulises\n");
	puts("Trinidad Barbero Jorge A.\n");
	puts("Para la materia de: Fundamentos de programacion\n");
	puts("Grupo: 01		Profesora: M.C. Cintia Quezada Reyes\n");
	getchar();
	//getchar();
	system("cls"); 			//limpiar pantalla
//P�gina de datos del usuario	
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
//P�gina de men� y repetici�n
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
							puts("su letra no corresponde al alfabeto ingl�s");	
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
