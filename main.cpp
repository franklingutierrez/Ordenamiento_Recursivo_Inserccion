// RECURSIVIDAD CON INSERCCION
#include<iostream>

using namespace std;
//int comparaciones=0;

int for2(int inicio, int tamanio, int numeros[]){
    int aux;

    if(inicio>tamanio){
        return 1;
    }

    if(numeros[inicio-1] > numeros[inicio]){
        aux = numeros[inicio-1];
        numeros[inicio-1] = numeros[inicio];
        numeros[inicio] = aux;
    }
    //comparaciones ++;

    inicio++;

    for2(inicio,tamanio,numeros);

    return 1;

}

int for1(int inicio, int tamanio, int numeros[]){

    if(inicio>tamanio){
        return 1;
    }
    //para ahorrar tiempo puede empezar en for2(inicio,tamanio,numeros);
    for2(0,tamanio,numeros);
    inicio++;
    for1(inicio,tamanio,numeros);

    return 1;
}

int main(){

    int tamanio;
	int numeros[] = {4,100,2,30,5,10,7,1};
	int i;

	tamanio = ((sizeof numeros / sizeof *numeros))-1;
	//tamanio = 7

    for1(0,tamanio,numeros);

    //cout<<comparaciones<<"\n";

	cout<<"Orden Ascendente: ";
	for(i=0;i<=tamanio;i++){
		cout<<numeros[i]<<",";
	}
	cout<<"\nOrden Descendente: ";

	for(i=tamanio;i>=0;i--){
		cout<<numeros[i]<<",";
	}

}