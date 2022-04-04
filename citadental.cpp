#include <iostream>
using namespace std;

struct info
{
    int id;
    char nombrep[100],nombret[100], descr[100];
    float cantidad,hora, precio;
};

int main()
{
    info citas[10];
    int opcion;
    int menu;
    int i;
    int j,op;
    do
    {
        cout << "\t" << "BIENVENIDO A TU CITA DENTAL CARO, ESCOJA LA OPCION QUE QUIERA" << "\n";
        cout << "1. Agendar cita" << endl << "2. Modificar cita" << endl << "3. Eliminar cita" << endl << "4. Lista de citas vigentes" << endl << "5. Limpiar pantalla" << endl << "6. Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
             do{
                 j = 1;
            for (i = 0; i < j; i++)
            {  
                    cout << "Numero de su cita:" << i + 1 << "\n";
                    cout << "Nombre del paciente que sera consultado:";
                    cin >> citas[i].nombrep;
                    cout << "Hora de la cita:" << endl;
                    cin >> citas[i].hora;
                    cout << "Nombre del tratamiento:" << endl;
                    cin >> citas[i].nombret;
                    cout << "Descripcion del tratamiento:" << endl;
                    cin >> citas[i].descr;
                    cout << "Cantidad del tratamiento:" << endl;
                    cin >> citas[i].cantidad;
                    cout << "Precio:" << endl;
                    cin >> citas[i].precio;
                    cout << "¿Desea agendar otra cita? 1. si 2. no \n";
                    cin >> op;
                    if (op == 1) {
                        j = j + 1;
                    } 
                    else {
                        menu = 1;
                    }
                }; 
                } while (op == 1);
            break;

        case 2:
            cout << "¿Cual es id de la cita que quiera cambiar?" << endl;
            cin >> j;
            j = j - 1;
            for (i = j; i <= j; i++)
            {
                cout << "El id es:" << i + 1 << "\n";
                    cout << "Inserte nombre del paciente:" << "\n";
                    cin >> citas[i].nombrep;
            }
            break;

        case 3:
            break;

        case 4:
            for (i = 0; i <= j; i++)
            {
                cout << "el id es:" << i + 1 << "\n";
                cout << "Nombre del paciente:";
                cout << citas[i].nombrep << "\n";
                cout << "Hora del tratamiento:";
                cout << citas[i].hora << "\n";
                cout << "Nombre de su tratamiento:";
                cout << citas[i].nombret << "\n";
                cout << "Descripcion:";
                cout << citas[i].descr << "\n";
                cout << "Cantidad del tratamiento:";
                cout << citas[i].cantidad << "\n";
                cout << "Precio:" << endl;
                cout << citas[i].precio << "\n";
            }
            menu = 1;
            break;

        case 5:

            break;

        case 6:
            cout << "Saliendo del programa";
            menu = 2;
            break;

        default:
            cout << "la opcion ingresada es incorrecta";
            menu = 1;
            break;
        }
    } while (menu == 1);

    return 0;
}
