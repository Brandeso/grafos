#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *ap;
	if((ap = fopen("grafo2.txt", "w+")) == NULL)
	{
		fprintf(stderr, "Error al abrir el archivo");
		exit(1);
	}
	
	char cadena[30];
	
	printf("Introduzca el primer renglón de la matriz: ");
	fflush(stdin);
	scanf("%s", cadena);
	
	
}