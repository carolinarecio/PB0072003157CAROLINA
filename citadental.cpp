#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

void agendar();
void lista();
void archivos();
void eliminar();
void modificar();

int i,id;
string *nomp, *nomt, *desc;
int *cant, *hora, *preut, *precun, *total;

int main()
{
    int opc;
    
    cout << "\t" << "BIENVENIDO A TU CITA DENTAL, ESCOGE LA OPCION QUE QUIERA" << "\n";
    cout << "1. Agendar cita" << endl << "2. Modificar cita" << endl << "3. Eliminar cita" << endl << "4. Lista de citas vigentes" << endl << "5. Limpiar pantalla" << endl << "6. Salir" << endl;
    
    cin >> opc;
    
    switch (opc)
    {
        case 1:
        agendar();
        return main();
        break;
        
        case 2:
        modificar();
        return main();
        break;
        
        case 3:
        eliminar();
        return main();
        break;
        
        case 4:
        lista();
        return main();
        break;
        
        case 5:
        system("clear");
        return main();
        break;
        
        case 6:
        archivos();
        return main();
        break;
    }
}

void agendar()
{
    
    cout << "Ingrese el numero de citas que desea agendar: ";
    cin >> id;
        
    cant = new int[id];
    hora = new int[id];
    preut = new int[id];
    precun = new int[id];
    nomp = new string [id];
    nomt = new string[id];
    desc = new string[id];
    
    for (int i = 0;i < id;i++)
    {
        
        cin.ignore(); // Se usa cuando antes de usar "getline" se utilizo un "cin >>" ya que si no ponemos esto se lee el salto de linea del ultimo "cin" como si fuera parte del "getline"
        
        cout << endl  << "Nombre del paciente #"<< i + 1 <<":" << endl;
        getline(cin, nomp[i]);
        
        cout << endl << "Hora del tratamiento:" << endl;
        cin >> hora[i];
        
        cout << endl  << "Nombre del tratamiento:" << endl;
        cin.ignore();
        getline(cin,nomt[i]);
        
        cout << endl  << "Descripcion:" << endl;
        getline(cin,desc[i]);
        
        cout << endl  << "Precio unitario del tratamiento:" << endl;
        cin >> preut[i];
        
        cout << endl  << "Cantidad del tratamiento:" << endl;
        cin >> cant[i];
        
        /*cout << "Precio unitario:" << endl;
        cin >> precun[i];*/
        
    
        system("clear"); // Limpiamos todo lo que habia antes para que se proceda a capturar al siguiente paciente
    }
    
    system("clear");
}

void lista()
{
    for (int i = 0;i < id;i++)
    {
        
        int precioUnitario = preut[i];
        int subTotal = precioUnitario * cant[i];
        float total = subTotal + (subTotal * .16); // Usamos float para que pueda soportar decimales nuestro numero
        
        cout << "Cita: #" << i + 1 << endl;
        cout << "Paciente [#" << i + 1 << "]: " << nomp[i] << endl;
        cout << "Hora de la cita [#" << i + 1 << "]: " << hora[i] << endl;
        cout << "Tratamiento [#" << i + 1 << "]: " << nomt[i] << endl;
        cout << "Descripción del tratmiento [#" << i + 1 << "]: " << desc[i] << endl;
        cout << "Cantidad [#" << i + 1 << "]: " << cant[i] << endl;
        cout << "Precio unitario [#" << i + 1 << "]: $" << precioUnitario<< endl;
        cout << "Subtotal [#" << i + 1 << "]: $" << subTotal << endl;
        cout << "Total [#" << i + 1 << "]: $" << total;
        
        cout  << endl << endl;
    }
}

void eliminar()
{
    int j;
    cout << "ingrese el  registro a eliminar: ";
    cin >> j;
    
    j = j - 1;
    for (int i = j;i == j;i++)
    {
        cout << "Eliminando registro: " << j + 1 << endl;
        
        nomp[i] = " ";
        hora[i]=0;
        nomt[i]=" ";
        desc[i]=" ";
        preut[i]=0;
        cant[i]=0;
        precun[i]=0;

    }
}

void modificar()
{
    int j;
    cout << "ingrese el numero registro a modificar: ";
    cin >> j;
    j = j - 1;

    cin.ignore(); // Se usa cuando antes de usar "getline" se utilizo un "cin >>" ya que si no ponemos esto se lee el salto de linea del ultimo "cin" como si fuera parte del "getline"

    cout << endl  << "Nombre del paciente #"<< j + 1 <<":" << endl;
    getline(cin, nomp[j]);

    cout << endl << "Hora del tratamiento:" << endl;
    cin >> hora[j];

    cout << endl  << "Nombre del tratamiento:" << endl;
    cin.ignore();
    getline(cin,nomt[j]);

    cout << endl  << "Descripcion:" << endl;
    getline(cin,desc[j]);

    cout << endl  << "Precio unitario del tratamiento:" << endl;
    cin >> preut[j];

    cout << endl  << "Cantidad del tratamiento:" << endl;
    cin >> cant[j];
}

void archivos()
{
    ofstream archivo;
    string nombrearchivo;

    nombrearchivo = "citas.txt"; // Aqui tuvimos que poner la ruta completa del archivo

    archivo.open(nombrearchivo.c_str(), ios::out);

    if (archivo.fail())
    {
        cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
        exit(1);
    }


    for (int i = 0; i < id; i++)
    {
        if (id == 0)
        {

        }
        else
        {
            
            int precioUnitario = preut[i];
            int subTotal = precioUnitario * cant[i];
            float total = subTotal + (subTotal * .16); // Usamos float para que pueda soportar decimales nuestro numero
            
            
            archivo << "Cita: #" << i + 1 << endl;
            archivo << "Paciente [#" << i + 1 << "]: " << nomp[i] << endl;
            archivo << "Hora de la cita [#" << i + 1 << "]: " << hora[i] << endl;
            archivo << "Tratamiento [#" << i + 1 << "]: " << nomt[i] << endl;
            archivo << "Descripción del tratmiento [#" << i + 1 << "]: " << desc[i] << endl;
            archivo << "Cantidad [#" << i + 1 << "]: " << cant[i] << endl;
            archivo << "Precio unitario [#" << i + 1 << "]: $" << precioUnitario<< endl;
            archivo << "Subtotal [#" << i + 1 << "]: $" << subTotal << endl;
            archivo << "Total [#" << i + 1 << "]: $" << total;
            
            archivo << endl << endl;
        }
    }


    archivo.close();
}
