#include<stdio.h>
int i=0;
main(){
	FILE* archivo=fopen("pruebanombre.txt","r");
	int cont=0;
	char space[30];
	while(!feof(archivo)){
		int c=fgetc(archivo);
		cont++;
		if(c==' '){
			space[i]=cont;
			i++;
			printf("%i ", cont);
		}
	}
	fclose(archivo);
	printf("%s", space);
	FILE* espacios=fopen("espacios.txt","w");
	fputs(space, espacios);
	fclose(espacios);
	getchar();
}
