#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

double calcularF(double ax,double ay,double cx,double cy){
	double res;
	res = (ay*(cx-ax))/(ay-cy);
	res = res + ax;
	return res; 
	
}

int main(){
	int n,l;
	cin>>n>>l;// cantidad de dominos y longitud de la mesa
	int esq[n];//vector de las esquinas inferior izquierda donde empieza el domino
	int h[n];//vector de las alturas de los dominos
	int w[n];//vector de las anchuras de los dominos
	for(int i=0;i<n;i++){
		cin>>esq[i]>>h[i]>>w[i];
	}
	int q;
	cin>>q;//cantidad de consultas con los soles
	
	for(int i=0;i<q;i++){
		int x;//vector de ubicaciones en x del sol
		int y;//vector de ubicaciones en y del sol
		cin>>x>>y;
		unsigned t0, t1;
 
		t0=clock();
		// Code to execute
		
		
		double f[n+1];
		double faux=0;
		double seg[n+1][2];
		bool flag=false;
		int aux=n;
		
		for(int j=0;j<aux;j++){
			if(esq[j]<x && (esq[j]+w[j])<=x){
				
				
				f[j]=calcularF(x,y,esq[j],h[j]);
				if(f[j]<0){
					f[j]=0;
				}
				seg[j][1]=esq[j]+w[j];
				seg[j][0]=f[j];
				faux++;
				//cout<<f[j]<<endl;
				//cout<<"["<<j+1<<"]--> "<<"A1:  "<<seg[j][0]<<endl;
				//cout<<"["<<j+1<<"]--> "<<"A2:  "<<seg[j][1]<<endl;
			}else if(esq[j]>=x && (esq[j]+w[j])>x){
				f[j]=calcularF(x,y,esq[j]+w[j],h[j]);
				if(f[j]>l){
					f[j]=l;
				}
				seg[j][0]=esq[j];
				seg[j][1]=f[j];
				//cout<<f[j]<<endl;
				//cout<<"["<<j+1<<"]--> "<<"A1:  "<<seg[j][0]<<endl;
				//cout<<"["<<j+1<<"]--> "<<"A2:  "<<seg[j][1]<<endl;
			}else{
				flag=true;
				aux=aux+1;
				f[j]=calcularF(x,y,esq[j],h[j]);
				if(f[j]<0){
					f[j]=0;
				}
				seg[j][1]=esq[j]+w[j];
				seg[j][0]=f[j];
				f[j+1]=calcularF(x,y,esq[j]+w[j],h[j]);
				if(f[j+1]>l){
					f[j+1]=l;
				}
				seg[j+1][0]=esq[j];
				seg[j+1][1]=f[j+1];
				//cout<<"["<<j+1<<"]--> "<<"A1:  "<<seg[j][0]<<endl;
				//cout<<"["<<j+1<<"]--> "<<"A2:  "<<seg[j][1]<<endl;
				//cout<<f[j]<<endl;
				//cout<<f[j+1]<<endl;
				j=j+1;
				//cout<<"["<<j+1<<"]--> "<<"A1:  "<<seg[j][0]<<endl;
				//cout<<"["<<j+1<<"]--> "<<"A2:  "<<seg[j][1]<<endl;
				faux++;
				
			}
		}
		
		double intervalos[aux][2];
		intervalos[0][0]=seg[0][0];
		intervalos[0][1]=seg[0][1];
		
		int aux2=0;
		
		for(int j=1;j<faux;j++){
			if(seg[j][0]<intervalos[aux2][0]){
				intervalos[aux2][0]=seg[j][0];
				intervalos[aux2][1]=seg[j][1];
			}else if(seg[j][0]<intervalos[aux2][1]){
				intervalos[aux2][1]=seg[j][1];
			}else{
				aux2++;
				intervalos[aux2][0]=seg[j][0];
				intervalos[aux2][1]=seg[j][1];
			}
		}
		
		for(int j=faux;j<aux;j++){
			if(seg[j][1]<intervalos[aux2][1]){
				
			}else if(seg[j][0]<intervalos[aux2][1]){
				intervalos[aux2][1]=seg[j][1];
			}else{
				aux2++;
				intervalos[aux2][0]=seg[j][0];
				intervalos[aux2][1]=seg[j][1];
			}
		}
		
		double suma=0;
		for(int j=0;j<=aux2;j++){
			suma+=(intervalos[j][1]-intervalos[j][0]);
		}
		
		double iluminado = l-suma;
		
		cout<<fixed<<setprecision(4)<<iluminado<<endl;
		
		t1 = clock();
		 
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Execution Time: " << time << endl;
		
		
		
	}
	
	
	
	
	
	return 0;
}
