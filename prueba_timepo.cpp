#include <iostream>
#include <ctime> 

using namespace std;
 
 void potencia(long long int h){
	long long int poten=1;
	long long int auxi=2;
 	
	for(int j=0;j<h;j++){
		poten=poten*auxi;
		for(int k=0;k<j;k++){
			poten=poten-auxi;
			for(int h=0;h<k;h++){
				poten=poten+1;
			}
		}
		poten=poten+auxi;
	}
	cout<<"Resultado de 2 al "<<h<<" sera igual a: "<<poten<<endl;
 	
 }




int main(){
	
	int w;
	cin>>w;
	
	while(w>0){
		w=w-1;
		
		long long int n;
		cin>>n;
		
		
		long long int aux=2;
		long long int pot;
		
		unsigned t0, t1;
		t0=clock();
		
		
		
		pot=1;
		
		for(int i=0;i<n;i++){
			pot=pot*aux;
			for(int m=0;m<i;m++){
				pot=pot-aux;
				for(int n=0;n<m;n++){
					pot=pot+1;
				}
			}
			pot=pot+aux;
		}
		cout<<"Resultado de 2 al "<<n<<" sera igual a: "<<pot<<endl;;
		
		// Code to execute
		t1 = clock();
		 
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Execution Time dentro de todo: " << time << endl;
		
		t0=clock();
		
		potencia(n);
		
		t1 = clock();
		 
		time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Execution Time con funcion: " << time << endl;
		
		
		
		
	}
	
	
	
	
	return 0;
}
