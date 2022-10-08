#include <iostream>

using namespace std;

/*
	POSIBLE SOLUCION PROPUESTA
	TERMINADO
*/



int main(){
	int n;
	cin>>n;
	const int digitos = 100;
	const int mayorNueve = 13;
	const int numerosOcho[8] = {1,2,6,24,20,20,40,20};
	while(n>0){
		n-=1;
		int x;
		cin>>x;
		int aux=1;
		
		if(x>=9){
			//int aux=2;
			for(int i=0;i<x;i++){
				aux=(aux*mayorNueve)%digitos;
			}
			cout<<aux<<endl;
		}else{
			int suma=0;
			for(int i=0;i<x;i++){
				suma+=numerosOcho[i];
			}
			suma=suma%100;
			
			
			for(int i=0;i<x;i++){
				aux=(aux*suma)%digitos;
			}
			cout<<aux<<endl;
			
		}
	}
	return 0;
}
