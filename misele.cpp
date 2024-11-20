#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Sele {
    string nombre;
    int edad;
};

void llenar(Sele &jugador) {
    cout << "Ingrese nombre: ";
    cin >> jugador.nombre;
    cout << "Ingrese edad: ";
    cin >> jugador.edad;
}

void mostrar(Sele jugador[], int cant) {
    cout << "Datos ingresados:" << endl;
    for (int i = 0; i < cant; i++) {
        cout << "Jugador " << (i + 1) << ":" << endl;
        cout << "Nombre: " << jugador[i].nombre << endl;
        cout << "Edad: " << jugador[i].edad << endl;
    }
}

void guardar(Sele jugador[], int cant) {
    ofstream archivo("sele.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < cant; i++) {
            archivo << "Jugador " << (i + 1) << ":" << endl;
            archivo << "Nombre: " << jugador[i].nombre << endl;
            archivo << "Edad: " << jugador[i].edad << endl;
        }
        archivo.close();
        cout << "Datos guardados en 'sele.txt'" << endl;
    } else {
        cout << "El archivo no se pudo crear." << endl;
    }
}

int main() {
    int cant, op;

    cout << "¿Cuántos jugadores ingresará? ";
    cin >> cant;

    Sele jugadores[100];

    do {
        cout << "\nOpciones:" << endl;
        cout << "1. Ingresar datos de jugadores" << endl;
        cout << "2. Mostrar datos de jugadores" << endl;
        cout << "3. Guardar datos en archivo" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese opción: ";
        cin >> op;

        switch (op) {
            case 1:
                for (int i = 0; i < cant; i++) {
                    cout << "\nJugador " << (i + 1) << ":" << endl;
                    llenar(jugadores[i]);
                }
                break;

            case 2:
                mostrar(jugadores, cant);
                break;

            case 3:
                guardar(jugadores, cant);
                break;

            case 4:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (op != 4);

    return 0;
}
