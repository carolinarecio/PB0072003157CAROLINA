#include <iostream>

using namespace std;
int main()
{
	int opcion,edad[3];
	int salir=1; 
	char nompac[30], nomtrat[30], desc[100];
	do {

		cout << "Citas dentales Caro" << endl;
		cout << "1.-Agendar cita\n2.-Modificar cita\n3.-Elminar cita\n4.-Lista de citas \n5.-Limpiar pantalla\n6.-Salir\n";
		cout << "Ingrese la opción que guste: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			while (int i = 1; i < 4; i++) {
				cout << "-PACIENTE " << i << "-\n";
				cout << "Nombre del Paciente: ";
				cin >> nompac[i];
				cout << "Edad: ";
				cin >> edad[i];
				cout << "\n** Cita agendada" 
                "te esperamos! **\n";
			}
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			system("cls");
			opcion = 0;
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "\nIngrese una opción que sea válida\n";
		}
		if (opcion !=0 ) {
			cout << "¿Quisiera volver al menú?(Sí=1 No=2)\nOpción: ";
			cin >> salir;
		}
	} while (salir == 1);
}
