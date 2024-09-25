#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

void crearm(char mat[][3]){ //la función que crea la matriz
	for (int i=0; i<3;i++){
		for (int j=0; j<3; j++){
		
		mat[i][j]=' ' ;
		}		
	}
}	
	
void ver(char mat[][3]){	//la función que muestra la matriz
	for (int f = 0; f < 3; f++){
		for(int c = 0; c < 3; c++){
			cout<<"|"<<mat[f][c]<<"|";
		}
		cout<<endl;	
	}
}

void ubicar(char mat[][3], char sim){
		int i, j;
	cout<<"en que posicion va a ubicar el caracter? (coordenada x y y): ";
	cin>>i>>j;		//i y j se guardan para luego meterlas en la matriz, y asi dar la posición   
	//validar coordenadas
    if (i >= 0 && i < 3 && j >= 0 && j < 3 && mat[i][j] == ' ') {
        mat[i][j] = sim;  // poner el simbolo correspondiente
    } else {
        cout << "Posición inválida o ocupada. Intente de nuevo.\n";
        ubicar(mat, sim);  // Recursión
    }
}	


int condiciones(char mat[][3]){

    // Comprobar filas y columnas para 'X'
    for (int i = 0; i < 3; i++) {
        if (mat[i][0] == 'X' && mat[i][1] == 'X' && mat[i][2] == 'X') {
            cout << "Gana X" << endl;
            return true;
            
        }
        if (mat[0][i] == 'X' && mat[1][i] == 'X' && mat[2][i] == 'X') {
            cout << "Gana X" << endl;
            return true;
        }
    }
    // Comprobar diagonales para 'X'
    if (mat[0][0] == 'X' && mat[1][1] == 'X' && mat[2][2] == 'X') {
        cout << "Gana X" << endl;
        return true;
		    
    }
    if (mat[0][2] == 'X' && mat[1][1] == 'X' && mat[2][0] == 'X') {
        cout << "Gana X" << endl;
        return true;
        
    }
    // Comprobar filas y columnas para 'O'
    for (int i = 0; i < 3; i++) {
        if (mat[i][0] == 'O' && mat[i][1] == 'O' && mat[i][2] == 'O') {
            cout << "Gana O" << endl;
            return true;
           
        }
        if (mat[0][i] == 'O' && mat[1][i] == 'O' && mat[2][i] == 'O') {
        	
            cout << "Gana O" << endl;
            return true;
           
        }
    }
    // Comprobar diagonales para 'O'
    if (mat[0][0] == 'O' && mat[1][1] == 'O' && mat[2][2] == 'O') {
        cout << "Gana O" << endl;
        return true;
        
    }
    if (mat[0][2] == 'O' && mat[1][1] == 'O' && mat[2][0] == 'O') {
        cout << "Gana O" << endl;
        return true;
        
	
}
return false;

}
int dado(){
	char tablerop[3][3], tableroi[3][3];
	bool ganador=false;
	crearm(tablerop); //los tableros tienen que imprimirse antes del ciclo, o si no el tablero se reinia 				
	crearm(tableroi); //y no se guardan las x y o puestas
	while(ganador==false){ //se usa un ciclo while para que cuando no se cumpla la función pare
	
	system("color B");
	
	cout<<"Turno jugador 1 " ;
	char sim='X'; //se le asigna al jugador 1 el simbolo X
	int dado=1+rand()%6;
	cout<<"\nEl numero es: " <<dado;
	if (dado%2 ==0){
		cout<<"\njuegas en el tablero par";
		cout<<endl;
		ver(tablerop); //se le manda tablero par como argumento
		ubicar(tablerop, sim); //se le manda tablero par como argumento y el simbolo para que llene (ubique los datos)
		ganador = condiciones(tablerop);  //ganador va a ser igual a lo que retorne la funcion condiciones, este ayuda a romper con el ciclo while
		//funcion para llenar tablero par
	}else{
		cout<<endl;
		cout<<"\njuegas en el tablero impar\n";
		cout<<endl;
		ver(tableroi);
		ubicar(tableroi, sim);
		ganador = condiciones(tableroi);
	}
	//jugador 2
	cout<<"\nTurno jugador 2 " ;
	sim='O';
	dado=1+rand()%6;
	cout<<"\nEl numero es: " <<dado;
	if (dado%2 ==0){
		cout<<"\njuegas en el tablero par";
		cout<<endl;
		ver(tablerop);
		ubicar(tablerop, sim);
		ganador = condiciones(tablerop);
	}else{
		cout<<endl;
		cout<<"\njuegas en el tablero impar";
		cout<<endl;
		ver(tableroi);
		ubicar(tableroi, sim);
		ganador = condiciones(tableroi);
		}
	
	}
}
	
int main(){
	char mat[3][3];
	srand(time(NULL));
	dado();
}

