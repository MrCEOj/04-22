//Ortiz Jakes Ludwin Marcelo | 1182866//
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

typedef struct{
    int matricula;
    int calif[4];
    int tareas;
    int proy;
    char nombre[40];
}chavos;

void registro(chavos[41] ,int *);
void consulta(chavos[41]);
void ordenar(chavos[41],int);
void imprime(chavos);

int main(){
    setlocale(LC_CTYPE, "Spanish");
    
    char opc;
    int i=0;
    chavos datos[41];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    
	printf(" ____  _                           _     _         \n");
	printf("|  _ \\(_)                         (_)   | |  ____  \n");
	printf("| |_) |_  ___ _ ____   _____ _ __  _  __| | / __ \\ \n");
	printf("|  _ <| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| |/ _` |/ / _` |\n");
	printf("| |_) | |  __/ | | \\ V /  __/ | | | | (_| | | (_| |\n");
	printf("|____/|_|\\___|_| |_|\\_/ \\___|_| |_|_|\\__,_|\\ \\__,_|\n");
	printf("                                            \\____/ \n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);                                                
	do{
	    puts("\n********************************");
	    puts("**** [a] Registro           ****");
	    puts("**** [b] Consulta           ****");
	    puts("**** [c] Ordenar por nombre ****");
	    puts("**** [d] Salir              ****");
	    puts("********************************");
	    printf("Opción: ");
	    opc=tolower(getchar());
	    getc(stdin);
		puts("");
	    switch(opc){
	        case 'a':
	            registro(datos,&i);
	        break;
	        case 'b':
	            consulta(datos);
	        break;
	        case 'c':
	            ordenar(datos,i);
	        break;
	        case 'd':
	            puts("\nBye bye.");
	        break;
	        default:
	            puts("\nOpción no válida.");
	    }
	}while(opc!='d');
}

void imprime(chavos datos){
	setlocale(LC_CTYPE, "Spanish");
    int j,suma=0;
    float prom;
    puts("**********************************\n");
    printf("— Matrícula: %d\n",datos.matricula);
    printf("— Nombre: %s\n",datos.nombre);
    for(j=0;j<3;j++){
        printf("— Calificación del examen del parcial %d: %d\n",j+1,datos.calif[j]);
    	suma+=datos.calif[j];
	}
    printf("— Calificación de tareas y participación: %d\n",datos.tareas);
    printf("— Calificación del proyecto final: %d\n",datos.proy);
    prom=datos.tareas*.2+datos.proy*.2+(suma/3)*.6;
    printf("— Promedio final: %.2f\n\n",prom);
    
}

void registro(chavos datos[41], int *i){
	setlocale(LC_CTYPE, "Spanish");
    char ask;
    int j,val=0;
    do{
    	printf("\t    Registro #%d\n",*i+1);
        puts("************************************\n");

        printf("— Nombre: ");
        gets(datos[*i].nombre);
        for(j=0;j<strlen(datos[*i].nombre);j++)
            datos[*i].nombre[j]=toupper(datos[*i].nombre[j]);
    	
		printf("— Matrícula: ");
        scanf("%d",&datos[*i].matricula);
        getc(stdin);
        
        for(j=0;j<3;j++){
            printf("— Calificación del examen del parcial %d: ",j+1);
            scanf("%d",&datos[*i].calif[j]);
            if(datos[*i].calif[j]<0 || datos[*i].calif[j]>100){
				puts("Esa calificación supera los límites.\n");
				j--;            	
			}
        }

        printf("— Calificación de tareas y participación: ");
        scanf("%d",&datos[*i].tareas);

        printf("— Calificación del proyecto final: ");
        scanf("%d",&datos[*i].proy);

        puts("\n************************************");

        (*i)++;

        do{
        	getc(stdin);
            printf("\n¿Registrar a otro alumno? [S]|[N]: ");
            ask=tolower(getchar());
            if(ask!='s' && ask!='n'){
                puts("Esa respuesta no vale.");
            }else
                val=1;
        }while(val==0);
        
		puts("");
		getc(stdin);
    }while(ask!='n');
}

void consulta(chavos datos[41]){
	setlocale(LC_CTYPE, "Spanish");
	char buscar[40];
	int j;
	
	printf("Ingresa el nombre a buscar: ");
	gets(buscar);
	for(j=0;j<40;j++){
		if(strcasecmp(buscar,datos[j].nombre)==0){
			imprime(datos[j]);
			break;
		}
	}
}

void ordenar(chavos datos[41],int i){
	setlocale(LC_CTYPE, "Spanish");
	chavos aux;
	int j,k;
	
    for(j=0;j<i;j++)
        for(k=0;k<i-1;k++)
            if(strcmp(datos[k].nombre,datos[k+1].nombre)>0){
                aux=datos[k];
                datos[k]=datos[k+1];
                datos[k+1]=aux;
            }
            
    for(j=0;j<i;j++)
    	imprime(datos[j]);
}

