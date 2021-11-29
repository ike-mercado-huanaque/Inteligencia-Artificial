#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRE_ARCHIVO "DOM.TXT"
#define NOMBRE_VAR "VAR.TXT"
#define LONG_MAX_CADENA 1000



int main(){
	FILE * flujo = fopen(NOMBRE_ARCHIVO,"r");
	FILE * vartxt = fopen(NOMBRE_VAR, "r");
	FILE * vartxt2 = fopen(NOMBRE_VAR,"r");
	
	if (flujo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}
	
	char linea[LONG_MAX_CADENA];
	char linea2[LONG_MAX_CADENA];
	char linea3[LONG_MAX_CADENA];
	char sep[] = " \n";
	char *token;
	int num,varnum,domnum,allfreqnum;
	int antena[varnum]; //asignacion de frecuencia a las antenas
	int dominio[domnum][allfreqnum];
	int maxdom[domnum];
	int domvar[varnum];
	int cont;
	int nlinea;
	
	varnum = 0;
	domnum = 0;
	allfreqnum = 0;
	
	while(fgets(linea2,LONG_MAX_CADENA,vartxt)){
		token = strtok(linea2,sep);
		cont = 0;
		while(token != NULL){
			if(cont == 1){
				if(atoi(token) > domnum){
				domnum++;
				}
			}
			token = strtok(NULL,sep);
			cont++;
		}
		varnum++;
	}
	printf("\n");
	printf("Numero de variables = %i\n",varnum);
	printf("Numero de dominios = %i\n",domnum);
	
	fclose(vartxt);
	vartxt2 = fopen(NOMBRE_VAR, "r");
	
	nlinea = 0;
	while(fgets(linea3,LONG_MAX_CADENA,vartxt2)){
		token = strtok(linea3,sep);
		while(token != NULL){
			if(cont == 1){
				domvar[nlinea] = atoi(token);
			}
			token = strtok(NULL,sep);
			cont++;
		}
		varnum++;
		nlinea++;
	}
	fclose(vartxt2);
	
	nlinea = 0;	
	while(fgets(linea,LONG_MAX_CADENA,flujo)){	
		token = strtok(linea,sep);
		cont = 0;
		while(token != NULL){
			num = atoi(token);
			printf("%i ",num);
			if(nlinea == 0){
				allfreqnum++;	
			}
					
			else{
				if(cont == 1){
					maxdom[nlinea] = num;
				}
				if(cont > 1) {
					dominio[nlinea][cont-2] = num;
				}
			}
			
			token = strtok(NULL,sep);
			cont++;
		}
		if(cont == 0){
				allfreqnum = allfreqnum - 1;
			}
		nlinea++;
	}
	fclose(flujo);
	printf(" Se leyo correctamente el archivo\n");	
	
	return 0;
}
