#include<iostream>
#include<stdlib.h>

using namespace std;

void pedirDatos();
void mostrarMatriz(int **,int,int);
void mostrarMatrizz(int **,int,int);
void mostrarMatrizzz(int **,int,int);
void sumarMatrices(int **, int**,int**,int,int);
void showResultingMatrix(int **,int,int);

int **puntero_matriz1, **puntero_matriz2,**puntero_matriz3,nFilas,nCol;
clock_t start_total, end_total, forT[23][2] = {0}; 
int main(){
    double total_t;
    start_total = clock();
	pedirDatos();                                                                
	mostrarMatriz(puntero_matriz1,nFilas,nCol);                                  
	mostrarMatrizz(puntero_matriz2,nFilas,nCol);                                 
	mostrarMatrizzz(puntero_matriz3,nFilas,nCol);                                
	sumarMatrices(puntero_matriz1,puntero_matriz2,puntero_matriz3,nFilas,nCol);  
	showResultingMatrix(puntero_matriz1,nFilas,nCol);
	//Liberar la memoria utilizada en matriz3
	forT[0][0]= clock();//Calcula el tiempo que tarda el siguiente for
	for(int i=0;i<nFilas;i++){
		delete[] puntero_matriz3[i];
	}
	forT[0][1]=clock();
	delete[] puntero_matriz3;
	
	//Liberar la memoria utilizada en matriz2
	forT[1][0]= clock();//Calcula el tiempo que tarda el siguiente for
	for(int i=0;i<nFilas;i++){
		delete[] puntero_matriz2[i];
	}
	forT[1][1]=clock();//Calcula el tiempo que tarda el siguiente for
	delete[] puntero_matriz2;
	
	//Liberar la memoria utilizada en matriz1
	forT[2][0]= clock();//Calcula el tiempo que tarda el siguiente for
	for(int i=0;i<nFilas;i++){
		delete[] puntero_matriz1[i];
	}
	forT[2][1]=clock();//Calcula el tiempo que tarda el siguiente for
	delete[] puntero_matriz1;
	end_total = clock();
	total_t = (double)(end_total - start_total)/CLOCKS_PER_SEC;
	printf("\n\n\n\n");
	for (int i = 0; i < 14; i++) // Ciclo para imprimir los tiempos de cada for 
	{
	        if(i<3)
	        {
	            printf("MAIN:[%d]for: %f\n", i,(double)(forT[i][1] - forT[i][0])/CLOCKS_PER_SEC  );
	        }
	        else if (i<9)
	        {
	            printf("pedirDatos:[%d]for: %f\n", i,(double)(forT[i][1] - forT[i][0])/CLOCKS_PER_SEC  );
	        }else if(i<12)
	        {
	            printf("mostrarMatriz:[%d]for: %f\n", i,(double)(forT[i][1] - forT[i][0])/CLOCKS_PER_SEC  );
	        }else if (i<13)
	        {
	            printf("sumarMatrices:[%d]for: %f\n", i,(double)(forT[i][1] - forT[i][0])/CLOCKS_PER_SEC  );
	        }else
	        {
	            printf("showResultingMatrix:[%d]for: %f\n", i,(double)(forT[i][1] - forT[i][0])/CLOCKS_PER_SEC  );
	        }
	}
	printf("-------------------\nEl tiempo total es de: %f\n", total_t  );
	return 0;
}

void pedirDatos(){
	cout<<"Digite el tamaño de la matriz: ";
	cin>>nFilas;
	nCol=nFilas;
	cout << "El valor en memoria de nCol es:"<< sizeof(nCol);
	cout << "\nEl valor en memoria de nFilas es:"<< sizeof(nFilas);
	
	//Reservando memoria para la primera matriz
	forT[3][0] = clock();//Calcula el tiempo que tarda el siguiente for
	puntero_matriz1 = new int*[nFilas]; //Reservar memoria para las filas
	for(int i=0;i<nFilas;i++){
		puntero_matriz1[i] = new int[nCol]; //Reservar memoria para las columnas
	}
	forT[3][1] = clock();//Calcula el tiempo que tarda el siguiente for
	cout<<"\n\nDigite los elementos de la primera matriz: \n";
	forT[4][0] = clock();//Calcula el tiempo que tarda el siguiente for
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz1+i)+j); //puntero_matriz1[i][j]
		}
	}
	forT[4][1] = clock();//Calcula el tiempo que tarda el siguiente for
	cout<< "\nEl valor en memoria de matriz1 es: " << sizeof(puntero_matriz1);
	
	//Reservando memoria para la segunda matriz
	puntero_matriz2 = new int*[nFilas]; //Reservar memoria para las filas
	forT[5][0] = clock();//Calcula el tiempo que tarda el siguiente for//Calcula el tiempo que tarda el siguiente for
	for(int i=0;i<nFilas;i++){
		puntero_matriz2[i] = new int[nCol]; //Reservar memoria para las columnas
	}
	forT[5][1] = clock();//Calcula el tiempo que tarda el siguiente for
	cout<<"\n\nDigite los elementos de la segunda matriz: \n";
	forT[6][0] = clock();//Calcula el tiempo que tarda el siguiente for
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz2+i)+j); //puntero_matriz2[i][j]
		}
	
	}
	forT[6][1] = clock();//Calcula el tiempo que tarda el siguiente for

	cout<< "\nEl valor en memoria de la matriz2 es: " << sizeof(puntero_matriz2);
    
   //Reservando memoria para la tercera matriz
	puntero_matriz3 = new int*[nFilas]; //Reservar memoria para las filas
	forT[7][0] = clock();//Calcula el tiempo que tarda el siguiente for
	for(int i=0;i<nFilas;i++){
		puntero_matriz3[i] = new int[nCol]; //Reservar memoria para las columnas
	}
	forT[7][1] = clock();//Calcula el tiempo que tarda el siguiente for
	cout<<"\n\nDigite los elementos de la tercera matriz: \n";
	forT[8][0] = clock();//Calcula el tiempo que tarda el siguiente for
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz3+i)+j); //puntero_matriz3[i][j]
		}
	
	}
	forT[8][1] = clock();//Calcula el tiempo que tarda el siguiente for
	cout<< "\nEl valor en memoria de la matriz3 es: " << sizeof(puntero_matriz3);
	cout<<"\n\n\n";
}



void mostrarMatriz(int**puntero_matriz1,int nFilas,int nCol){
    forT[9][0] = clock();//Calcula el tiempo que tarda el siguiente for
    for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz1+i)+j)<<" "; //puntero_matriz1[i][j]
		}
		cout<<"\n";
	}
	forT[9][1] = clock();//Calcula el tiempo que tarda el siguiente for
	cout<<"\n+\n\n";
}
void mostrarMatrizz(int**puntero_matriz2,int nFilas,int nCol){
    forT[10][0] = clock();//Calcula el tiempo que tarda el siguiente for
    for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz2+i)+j)<<" "; //puntero_matriz1[i][j]
		}cout<<"\n";
	}
	forT[10][1] = clock();//Calcula el tiempo que tarda el siguiente for
	cout<<"\n+\n\n";
}
void mostrarMatrizzz(int**puntero_matriz3,int nFilas,int nCol){
    forT[11][0] = clock();//Calcula el tiempo que tarda el siguiente for
    for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz3+i)+j)<<" "; //puntero_matriz1[i][j]
		}
		cout<<"\n";
	}
	forT[11][1] = clock();//Calcula el tiempo que tarda el siguiente for
}
void sumarMatrices(int **puntero_matriz1, int **puntero_matriz2,int **puntero_matriz3, int nFilas,int nCol){
    forT[12][0] = clock();//Calcula el tiempo que tarda el siguiente for
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			*(*(puntero_matriz1+i)+j) += *(*(puntero_matriz2+i)+j)+= *(*(puntero_matriz3+i)+j); //almacenamos la suma en la primera para no tener que crear otra
		}
	}
	forT[12][1] = clock();//Calcula el tiempo que tarda el siguiente for
}

void showResultingMatrix(int **puntero,int nFilas, int nCol){
	cout<<"\nLa suma de las 3 matrices es: \n\n";
	forT[13][0] = clock();//Calcula el tiempo que tarda el siguiente for
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz1+i)+j)<<" "; //puntero_matriz1[i][j]
		}
		cout<<"\n";
	}
	forT[13][1] = clock();//Calcula el tiempo que tarda el siguiente for
}
