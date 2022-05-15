#include <iostream>
#include <conio.h>
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
		lista();
		return main();
		break;

	case 3:
		system("cls");
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;

	case 5:
		eliminar();
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}

void agendar()
{ 
	cout << "Inserte el numero de citas que desea agendar:" << endl;
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
		cout << "Nombre del paciente consultado:" << endl;
		getline(cin, nomp[i]); 
		cout << "Hora del tratamiento:" << endl;
		cin >> hora[i];
		cout << "Nombre del tratamiento:" << endl;
		getline(cin,nomt[i]);
		cout << "Descripcion:" << endl;
		getline(cin,desc[i]);
		cout << "Precio unitario del tratamiento:" << endl;
		cin >> preut[i];
		cout << "Cantidad del tratamiento:" << endl;
		cin >> cant[i];
		cout << "Precio unitario:" << endl;
		cin >> precun[i];
	}
}

void lista()
{
	for (int i = 0;i < id;i++)
	{ 
		if (id == 0)
		{
			cout << "REGISTRO ELIMINADO" << i + 1<<endl;
		}
		else
		{
			cout << "Cita:" << i + 1 << endl;
			cout << nomp[i];
			cout << hora[i];
			cout << nomt[i];
			cout << desc[i];
			cout << preut[i];
			cout << cant[i];
			cout << precun[i];
		}
	}
}

void eliminar()
{
	int j;
	cout << "inserte el registro a eliminar";
	cin >> j;
	j = j - 1;
	for (int i = j;i == j;i++)
	{
		cout << "Eliminando registro" << j + 1 << endl;
		
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
	int j, opcion;
	 cout << "inserte el numero registro a modificar";
	 cin >> j;
	 j = j - 1;

	 cout << "Nombre del paciente que sera consultado:" << endl;
	 getline(cin, nomp[i]);
	 cout << "Hora del tratamiento:" << endl;
	 cin >> hora[i];
	 cout << "Nombre del tratamiento:" << endl;
	 getline(cin, nomt[i]);
	 cout << "Descripcion del tratamiento:" << endl;
	 getline(cin, desc[i]);
	 cout << "Precio unitario del tratamiento:" << endl;
	 cin >> preut[i];
	 cout << "Cantidad del tratamiento:" << endl;
	 cin >> cant[i];
	 cout << "Precio unitario:" << endl;
	 cin >> precun[i];
}

void archivos()
{
	ofstream archivo;
	string nombrearchivo;
	int texto2, texto5, texto6;
	string texto, texto3, texto4;

	nombrearchivo = "citas";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	archivo << "NOMBRE PACIENTE QUE SERA CONSULTADO" << "\t";
	archivo << "HORA DEL TRATAMIENTO" << "\t";
	archivo << "NOMBRE DEL TRATAMIENTO" << "\t";
	archivo << "DESCRIPCION DEL TRATAMIENTO" << "\t";
	archivo << "PRECIO UNITARIO" << "\t";
	archivo << "CANTIDAD DEL TRATAMIENTO" << "\t";
	archivo << "PRECIO UNITARIO" << "\t";
	archivo << "TOTAL" << "\t";

	for (int i = 0; i < id; i++)
	{
		if (id == 0)
		{

		}
		else
		{
			texto = nomp[i];
			archivo << texto << "\t" << "\t";
			texto2 = hora[i];
			archivo << texto2 << "\t" << "\t";
			texto3 = nomt[i];
			archivo << texto3 << "\t " << "\t";
			texto4 = desc[i];
			archivo << texto4 << "\t" << "\t";
			texto5 = precun[i];
			archivo << texto5 << "\t " << "\t";
			texto6 = cant[i];
			archivo << texto6 << "\t " << "\t";
			total[i] = (precun[i] *cant[i]);
			texto = total[i];
		}
	}


	archivo.close();
}


