#include <iostream>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t>0){
		t=t-1;
		//cout<<"HOLA"<<endl;
		int n;
		cin>>n;
		int A[n];
		int B[n];
		int C[n];
		int D[n];
		for(int i=0;i<n;i++){
			cin>>A[i];
			C[i]=0;
		}
		for(int i=0;i<n;i++){
			cin>>B[i];
			D[i]=0;
		}
		int q;
		cin>>q;
		while(q>0){
			q=q-1;
			int x,y,z=-1;
			cin>>x;
			if(x==0){
				cin>>y>>z;
				//cout<<z<<endl;
				A[y]=z;
			}else if(x==1){
				cin>>y>>z;
				//cout<<z<<endl;
				B[y]=z;
			}else{
				cin>>y;
				//cout<<z<<endl
				int contIzqA=0;
				int contIzqB=0;
				int contDerA=0;
				int contDerB=0;
				int ax = A[y]-1;
				C[y]=A[y];
				int axy = y;
				while(ax>0 && axy>0){
					axy=axy-1;
					C[axy]=ax;
					ax=ax-1;
					contIzqA++;
				}
				ax = B[y]-1;
				D[y]=B[y];
				axy = y;
				while(ax>0 && axy>0){
					axy=axy-1;
					D[axy]=ax;
					ax=ax-1;
					contIzqB++;
				}
				
				
				
				ax = A[y]-1;
				axy = y+1;
				while(ax>0 && axy<n){
					
					C[axy]=ax;
					axy=axy+1;
					ax=ax-1;
					contDerA++;
				}
				ax = B[y]-1;
				axy = y+1;
				while(ax>0 && axy<n){
					
					D[axy]=ax;
					axy=axy+1;
					ax=ax-1;
					contDerB++;
				}
				
				int menorA=10000;
				int sumaA=0;
				int sumaB=0;
				
				for(int j=(y-contIzqA);j<(y+contDerA+1);j++){
					ax=A[j]-C[j];
					if(ax<menorA){
						menorA=ax;
					}
				}
				if(ax<0){
					for(int j=(y-contIzqA);j<(y+contDerA+1);j++){
						C[j]=C[j]+ax;
					}
				}
				
				for(int j=(y-contIzqA);j<(y+contDerA+1);j++){
					sumaA=sumaA+C[j];
				}
				
				menorA=10000;
				
				for(int j=(y-contIzqB);j<(y+contDerB+1);j++){
					ax=B[j]-D[j];
					if(ax<menorA){
						menorA=ax;
					}
				}
				if(ax<0){
					for(int j=(y-contIzqB);j<(y+contDerB+1);j++){
						D[j]=D[j]+ax;
					}
				}
				
				for(int j=(y-contIzqB);j<(y+contDerB+1);j++){
					sumaB=sumaB+D[j];
				}
				
				if(sumaA<=sumaB){
					cout<<sumaA<<endl;
				}else{
					cout<<sumaB<<endl;
				}
				
				
				
				
				
			}
			
		}
	}
	
	return 0;
}
