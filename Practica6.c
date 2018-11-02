/*
Universidad Autónoma de Aguascalientes
Ingeniería en Computación Inteligente
Estructuras Computacionales III (AVANZADAS)
ALUMNO: Pérez Velasco Alejandro, Gutiérrez Juárez Carlos Enrique.
PROFESOR: Dr. en C. Luis Fernando Gutiérrez Marfileño
Descripción:  calcula la distancia más corta entre el vértice A y H mediante el	algoritmo de Dijkstra.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
main(){
    int matrizPesos[8][8];
    int i,j,k;
    bool val;
    int recorrido[8];
    int numExp=0;
    int pesoDelRecorrido=0;
    int expansiones[4];
    char letras[8];
    int op1=0,min,minPeso,totalPeso;
    letras[0]='A';
    letras[1]='B';
    letras[2]='C';
    letras[3]='D';
    letras[4]='E';
    letras[5]='F';
    letras[6]='G';
    letras[7]='H';
    for(i=0;i<8;i++) for( j=0;j<8;j++) matrizPesos[i][j]=0;
    matrizPesos[0][1]=3;
    matrizPesos[0][2]=1;
    matrizPesos[1][0]=3;
    matrizPesos[2][0]=1;
    
    matrizPesos[1][3]=1;
    matrizPesos[1][6]=5;
    matrizPesos[3][1]=1;
    matrizPesos[6][1]=5;
    
    matrizPesos[2][5]=5;
    matrizPesos[2][3]=2;
    matrizPesos[5][2]=5;
    matrizPesos[3][2]=2;
    
    matrizPesos[3][5]=2;
    matrizPesos[3][4]=4;
    matrizPesos[5][3]=2;
    matrizPesos[4][3]=4;
    
    matrizPesos[4][7]=1;
    matrizPesos[4][6]=2;
    matrizPesos[7][4]=1;
    matrizPesos[6][4]=2;
    
    matrizPesos[5][7]=3;
    matrizPesos[7][5]=3;
    printf("   ");
     for(i=0;i<8;i++)printf("%3c",letras[i]);
     printf("\n");
    for(i=0;i<8;i++) 
    {
        printf(" %c ",letras[i]);
        for(j=0;j<8;j++){
            printf("%3d",matrizPesos[i][j]);
        }
        printf("\n");
    }
    
    
	for(i=0;i<8;i++){
		recorrido[i]=-1;
	} 
	recorrido[0]=0;
	totalPeso=0;
	
	printf("RECORRIDO        EXPANSIONES\n");
	for(i=0;i<7;i++){//se reestablecen contadores y auxiliares
		numExp=0;//contador de expansiones del nodo actual
		min=0;//guarda la posicion de la expansion con menos peso
    	minPeso=20;//guarda menor peso de las expansiones
    	printf("%1c                ",letras[recorrido[i]]);//imprimo letra actual del recorrido
        for(j=0;j<8;j++){
        	
        	val=false;
            if(matrizPesos[recorrido[i]][j]!=0&&j!=recorrido[i]){//evalua que sea una posible expansion
                for(k=0;k<8;k++){//evalua que no se repita dentro de las expansiones
                	if(j==recorrido[k]){
                		val=true;	
					}
                }
                if(val==false){//sino se repite entonces la guarda dentro de las posibles expansiones
                	expansiones[numExp]=j;
                	printf("%2c",letras[expansiones[numExp]]);//imprimimos la posible expansion
                	if(minPeso>matrizPesos[recorrido[i]][expansiones[numExp]]){//sirve para guardar la posicion de la expancion con menos peso que se asignará al recorrido
                		min=j;
						minPeso=matrizPesos[recorrido[i]][expansiones[numExp]];
					}
    				
                	numExp++;//se aumenta el contador de expansiones
				}
            }
            
        }
        
        recorrido[i+1]=min;//se añade la expansion con menos peso al recorrido
        totalPeso+=matrizPesos[recorrido[i]][recorrido[i+1]];//se acumula el peso total del recorrido
        
        printf("\n");
        if(min==7){//si llega al ultimo nodo se acaba el ciclo
        	min=i;//guarda el numero de letras en el recorrido
        	break;
		}
    }
	for(i=0;i<=min+1;i++)printf("%3c",letras[recorrido[i]]);//imprime el recorrido 
     printf("\nPeso total= %d\n",totalPeso); //imprime el peso del recorrido
    getchar();
    
}
