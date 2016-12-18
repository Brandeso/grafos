#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *ap;
	if((ap = fopen("grafo.txt", "w+")) == NULL)
	{
		fprintf(stderr, "Error al abrir el archivo");
		exit(1);
	}
	
	printf("Introduzca la matriz de adyacencia por renglones, separando cada número por una coma.\n");
	
//	char matriz[15][30];
	char cadena[30];
	int a = 0, b = 1, c = 0, d = 0;
	
	printf("Introduzca el renglón #1: ");
	fflush(stdin);
	scanf("%s", cadena);
	
	for(a = 0; a < 30; a++)
	{
		if(cadena[a] != '\0')
		{
			b = b+1;
		}
		if((cadena[a] == '1') || (cadena[a] == '0'))
		{
			c = c+1;
		}
	}
	
	char matriz[c][b];
	
	for(a = 0; a < b; a++)
	{
		matriz[0][a] = cadena[a];
	}
	a = 1;
	for(a = 1; a < c; a++)
	{
		printf("Introduzca el renglón #%d: ", a+1);
		fflush(stdin);
		scanf("%s", matriz[a]);
	}
	
	printf("La matriz de adyacencia es: \n");
	
	for(a = 0; a < c; a++)
	{
		for(d = 0; d < b; d++)
		{
			if(matriz[a][d] == ',')
			{
				printf(" ");
			}
			if((matriz[a][d] == '0') || (matriz[a][d] == '1'))
			{
				printf("%c", matriz[a][d]);
			}
			
		}
		printf("\n");
	}
	
	for(a = 0; a < c; a++)
	{
		for(d = 0; d < b; d++)
		{
			fprintf(ap, "%c", matriz[a][d]);
		}
		if((a+1) != c)
			fprintf(ap, "\n");
	}
	
	fclose(ap);
	
	printf("Largo: %d\nVertices: %d\n", b, c);
}