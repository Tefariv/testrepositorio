#include <iostream>
using namespace std;

void burbuja(int mat[]){
	
	
	for (int i=0; i<5; i++){
		for(int j=0; j<4; j++){
		
		if(mat[j] >mat[j+1]){
			int aux=mat[j];
			mat[j]=mat[j+1];
			mat[j+1]=aux;
		}
		}
	}

	cout<<"Num en orden ascendente";
	for(int i=0; i<5; i++){
		cout<<endl;
		cout<<mat[i];
	}
		cout<<"Num en orden descendente";
	for(int i=4; i>=0; i--){
		cout<<endl;
		cout<<mat[i];
}
}

void insercion(int mat[]){
	int i, aux, pos ;
	for(i=0;i<5; i++){
		pos=i;
		aux=mat[i];
		while((pos>0 ) && (mat[pos-1] > aux)){
			mat[pos]=mat[pos-1];
			pos--;
		}
	mat[pos]=aux;
	}
	
	cout<<"Num en orden ascendente";
	for(int i=0; i<5; i++){
		cout<<endl;
		cout<<mat[i];
	}
		cout<<"Num en orden descendente";
	for(int i=4; i>=0; i--){
		cout<<endl;
		cout<<mat[i];
	}
}

void seleccion(int mat[]){
	int i, j, aux, min;
	for(i=0; i<5; i++){
		int min=i;
		for(j=i+1; j<5; j++){
			if(mat[j]< mat[min]){
				min=j;
			}
		}
		aux=mat[i];
		mat[i]=mat[min];
		mat[min]=aux;
	}	
	
	
	
	cout<<"Num en orden ascendente";
	for(int i=0; i<5; i++){
		cout<<endl;
		cout<<mat[i];
		}
	cout<<"Num en orden descendente";
	for(int i=4; i>=0; i--){
		cout<<endl;
		cout<<mat[i];
	
}
}




int main(){
	int mat[]={2, 4,3,1,5};
	int op;
	do{
	cout<<"Metodo burbuja \n Metodo insercion \n Metodo seleccion" <<endl;
	cout<<"Que opcion desea ver? "; cin>>op;
	
	
	switch(op)
	{
		case 1:
			cout<<"Metodo burbuja" <<endl;
			burbuja(mat);
			
			break;
		case 2:
			cout<<"metodo insercion" <<endl;
			insercion(mat);
			
			break;
		case 3:
			cout<<"Metodo seleccion" <<endl;
			seleccion(mat);
			
			break;
	}

	}while(op!=3);
	
}
