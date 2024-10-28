#include <iostream>
#include <locale>
using namespace std;


struct Fecha {
    int dia;
    int mes;
    int anio;
};


struct Estudiante {
    string nombre;
    int edad;
    int estatura;
    char genero;
    int codigo;
    double calificacion;
    Fecha fecha_nacimiento;
    bool activo = true;
} curso[100];  




void llenar(Estudiante curso[], int x) {

    for (int i = 0; i < x; i++) {
        cout << "\n--- Estudiante " << (i + 1) << " ---" << endl;
        
        cout << "Nobre: ";cin >> curso[i].nombre;
        
        cout << "Edad: ";cin >> curso[i].edad;
        
        cout << "Estatura (cm): ";cin >> curso[i].estatura;
        
        cout << "Género (M/F): ";cin >> curso[i].genero;
        
        cout << "Código de estudiante: ";cin >> curso[i].codigo;
        
        cout << "Calificación (0-100): ";cin >> curso[i].calificacion;
        
        
        cout << "Fecha de nacimiento:" << endl;
        
		cout << "Día: ";cin >> curso[i].fecha_nacimiento.dia;
		
		cout << "Mes: ";cin >> curso[i].fecha_nacimiento.mes;
		
		cout << "Año: ";cin >> curso[i].fecha_nacimiento.anio;
        
    }
}
void ver(Estudiante curso[], int x) {
    cout << "\n=== LISTA DE ESTUDIANTES ===" << endl;
    for (int i = 0; i < x; i++) {
        
        if (curso[i].activo) {
            cout << "\n--- Estudiante " << (i + 1) << " ---" << endl;
            cout << "Nombre: " << curso[i].nombre << endl;
            cout << "Edad: " << curso[i].edad << " años" << endl;
            cout << "Estatura: " << curso[i].estatura << " cm" << endl;
            cout << "Género: " << curso[i].genero << endl;
            cout << "Código: " << curso[i].codigo << endl;
            cout << "Calificación: " << curso[i].calificacion << endl;
            cout << "Fecha de nacimiento: " 
                 << curso[i].fecha_nacimiento.dia << "/"
                 << curso[i].fecha_nacimiento.mes << "/"
                 << curso[i].fecha_nacimiento.anio << endl;
        }
    }
}


void consultar(Estudiante curso[], int x, int cod) {
    bool encontrado = false;
    
    
    for (int i = 0; i < x; i++) {
        
        if (curso[i].codigo == cod && curso[i].activo) {
            cout << "\n=== DATOS DEL ESTUDIANTE ===" << endl;
            cout << "Nombre: " << curso[i].nombre << endl;
            cout << "Edad: " << curso[i].edad << " años" << endl;
            cout << "Estatura: " << curso[i].estatura << " cm" << endl;
            cout << "Género: " << curso[i].genero << endl;
            cout << "Código: " << curso[i].codigo << endl;
            cout << "Calificación: " << curso[i].calificacion << endl;
            cout << "Fecha de nacimiento: " 
                 << curso[i].fecha_nacimiento.dia << "/"
                 << curso[i].fecha_nacimiento.mes << "/"
                 << curso[i].fecha_nacimiento.anio << endl;
            encontrado = true;
            break;  
        }
    }
    
    if (!encontrado) {
        cout << "No se encontró ningún estudiante con ese código." << endl;
    }
}

void modificar(Estudiante curso[], int x, int cod) {
    bool encontrado = false;
    
    for (int i = 0; i < x; i++) {
        if (curso[i].codigo == cod && curso[i].activo) {
            cout << "\n=== MODIFICAR DATOS ===" << endl;
            
            cout << "Nuevo nombre: ";
            cin >> curso[i].nombre;
            
            cout << "Nueva edad: ";
            cin >> curso[i].edad;
            
            
            cout << "Nueva estatura (cm): ";
            cin >> curso[i].estatura;
            
            
            cout << "Nuevo género (M/F): ";
            cin >> curso[i].genero;
            
            
            cout << "Nueva calificación (0-100): ";
            cin >> curso[i].calificacion;
            
            
            cout << "Volviste a nacer!! Nueva fecha de nacimiento:" << endl;
            cout << "Día: ";
            cin >> curso[i].fecha_nacimiento.dia;
            cout << "Mes: ";
            cin >> curso[i].fecha_nacimiento.mes;
            cout << "Año: ";
            cin >> curso[i].fecha_nacimiento.anio;
            
            
            cout << "Datos modificados" << endl;
            encontrado = true;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontró ningun estudiante" << endl;
    }
}


void eliminar(Estudiante curso[], int x, int cod) {
    bool encontrado = false;
    
    for (int i = 0; i < x; i++) {
        if (curso[i].codigo == cod && curso[i].activo) {
            curso[i].activo = false;  
            cout << "Estudiante eliminado" << endl;
            encontrado = true;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontró ningún estudiante con ese código." << endl;
    }
}


void becas(Estudiante curso[], int x) {
    cout << "\n=== ESTUDIANTES CON BECAS ===" << endl;
    

    Estudiante mejores[3];
    double maxNotas[3] = {-1, -1, -1};
    

    for (int i = 0; i < x; i++) {
        if (!curso[i].activo);
        
        double notaActual = curso[i].calificacion;
        int posicion = -1;
        
        for (int j = 0; j < 3; j++) {
            if (notaActual > maxNotas[j]) {
                posicion = j;
                break;
            }
        }
        
        if (posicion != -1) {
           
            for (int j = 2; j > posicion; j--) {
                maxNotas[j] = maxNotas[j-1];
                mejores[j] = mejores[j-1];
            }
           
            maxNotas[posicion] = notaActual;
            mejores[posicion] = curso[i];
        }
    }
    
    
    for (int i = 0; i < 3; i++) {
        if (maxNotas[i] != -1) {  
            cout << "\n" << (i + 1) << " Lugar: " << mejores[i].nombre << endl;
            cout << "Calificación: " << mejores[i].calificacion << endl;
            
            
            switch(i) {
                case 0:
                    cout << "Obtiene 100% de beca" << endl;
                    break;
                case 1:
                    cout << "Obtiene 75% de beca" << endl;
                    break;
                case 2:
                    cout << "Obtiene 50% de beca" << endl;
                    break;
            }
        }
    }
}


int main() {
	setlocale(LC_ALL, "Spanish");
    system("color B"); 
    int n, cod, op;
    
    cout << "Cuantos estudiantes va a registrar? ";
    cin >> n;
    
    
    do {
        
        cout << "\n=== MENÚ PRINCIPAL ===" << endl;
        cout << "1. Registrar estudiante/s" << endl;
        cout << "2. Mostrar estudiantes registrado/s" << endl;
        cout << "3. Consultar estudiante" << endl;
        cout << "4. Modificar estudiante" << endl;
        cout << "5. Eliminar estudiante" << endl;
        cout << "6. Ver estudiantes con becas" << endl;
        cout << "7. Salir" << endl;
        cout << "\nElija una opción: ";
        cin >> op;
        
        
        
        switch(op) {
            case 1:
                llenar(curso, n);
                break;
            case 2:
                ver(curso, n);
                break;
            case 3:
                cout << "Ingrese el código del estudiante: ";
                cin >> cod;
                
                consultar(curso, n, cod);
                break;
            case 4:
                cout << "Ingrese el código del estudiante a modificar: ";
                cin >> cod;
                
                modificar(curso, n, cod);
                break;
            case 5:
                cout << "Ingrese el código del estudiante a eliminar: ";
                cin >> cod;
            
                eliminar(curso, n, cod);
                break;
            case 6:
                becas(curso, n);
                break;
            case 7:
                cout << "Exit.." << endl;
                break;
            default:
                cout << "Error." << endl;
        }
    } while (op != 7);
    
}






