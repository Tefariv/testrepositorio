#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void crearHimno(){
    ofstream archivo("Himno.txt");
    
    if(archivo.is_open()){
    	archivo << "De la Católica las glorias cantemos todos a una voz y con la ciencia proclamemos que el hombre imagen es de Dios (Bis) I Brilla en la cátedra de Pedro de la verdad el esplendor en la palabra, luz y vida, de nuestro Padre y buen Pastor que nos transmite su mensaje de fortaleza, fe y amor (Bis) Coro De la Católica las glorias… II Que dialoguemos nos enseña con el estudio y el saber, que la verdad del absoluto en nuestra vida siempre esté; y dé valor al pensamiento la luz divina de la fe (Bis) III Loor perenne a los maestros que con decoro y pulcritud la fuente brinda de las ciencias a la estudiosa juventud, en los caminos luminosos de la cultura y la virtud (Bis)";
    archivo.close();        
        
    }else{
	
	cout << "Error al crear el archivo" << endl;
	}
}

void separarPartes(){
    ifstream archivo;
    archivo.open("himno.txt");
    string texto = "", linea; //en texto va a estar todo el contenido
    while(getline(archivo, linea)){
        texto += linea; //se almacena toda la informacion
    }
    archivo.close();

    int inicio = 0;
    int pos;
    string buscar = "(Bis)"; //punto de corte
    

    pos = texto.find(buscar, inicio);
    string fragmento = texto.substr(inicio, pos + 5); //substr fragmenta cadenas, comienza en 0 y termina
                                                      //en pos de donde esta bis, se suma 5 para que cuente bis
    
    ofstream parte1("parte1.txt"); //crea el archivo 1
    parte1 << fragmento;           //llena el archivo con la 1 parte
    parte1.close();
    inicio = pos + 5;
    

    pos = texto.find(buscar, inicio);
    fragmento = texto.substr(inicio, pos + 5 - inicio);
    ofstream parte2("parte2.txt");
    parte2 << fragmento;
    parte2.close();
    inicio = pos + 5;
    

    pos = texto.find(buscar, inicio);
    fragmento = texto.substr(inicio, pos + 5 - inicio);
    ofstream parte3("parte3.txt");
    parte3 << fragmento;
    parte3.close();
    inicio = pos + 5;
    

    pos = texto.find(buscar, inicio);
    fragmento = texto.substr(inicio, pos + 5 - inicio);
    ofstream parte4("parte4.txt");
    parte4 << fragmento;
    parte4.close();
}

int main(){
    crearHimno();
    separarPartes();

}


