#ifndef LIBRERIA_H
#define LIBRERIA_H
#include <iostream>
#define MAX 1000
using namespace std;

struct medicamento {
    string nombre, categoria, tipo;
    int cantidad;
};

struct receta {
    int id;
    string nombre;
    string med;
    int cant;
    string tipo;
    string medico;
    string tecnico;
    string fecha;
};

struct grouping{
    string grupo;
    string nombre;
    int cant;
};

string categoria[]={"Analgesicos", "Antiealergicos", "Antiinflamatorios", "Antidepresivos"};
int cantCat = 4;

string tipo [] ={"Frasco", "Tableta", "Pomada"};
int cantTipo = 3;


medicamento listado[MAX];
int cantMed = 0;

receta ventas[MAX];
int cantVenta = 0;



void menu (){
    system("cls");
    cout<<" GESTION Y CONTROL DE MEDICAMENTOS"<<endl;
    cout<<"-----------------------------------"<<endl<<endl;
    cout<<" (1) Listado de Medicamento Existentes"<<endl;
    cout<<" (2) Insertar Medicamento"<<endl;
    cout<<" (3) Registrar una Venta"<<endl;
    cout<<" (4) Buscar Receta"<<endl;
    cout<<" (5) Buscar Medicamento"<<endl;
    cout<<" (6) Listado de ventas"<<endl;
    cout<<" (7) Listado de medicamentos veniddos por tipos"<<endl;
    cout<<" (0) Salir "<<endl;
    cout<<" Escoja una opcion: ";
}

void InsertarMed(){
    if (cantMed<MAX){
        cout<<"Iserte el nombre del medicamento: ";
        cin>>listado[cantMed].nombre;
        int pos;
        do{
            cout<<"CATEGORIA, escoja un elemento: \n";
            for(int i=0;i<cantCat;i++)
                cout<<i+1<<"\t"<<categoria[i]<<endl;

            cin>>pos;

        }while(pos<=0 || pos>cantCat);
        listado[cantMed].categoria = categoria[pos-1];

        do{
            cout<<"TIPO, escoja un elemento: \n";
            for(int i=0;i<cantTipo;i++)
                cout<<i+1<<"\t"<<tipo[i]<<endl;

            cin>>pos;

        }while(pos<=0 || pos>cantTipo);
        listado[cantMed].tipo = tipo[pos-1];

        cout<<"Cantidad: ";
        cin>>listado[cantMed].cantidad;
        cantMed++;
    }
    else {
        cout<<"no puede insertar mas medicamentos.";
    }
}

void ListadoMed(){
    cout<<"\nLISTADO DE MEDICAMENTOS EXISTENTES: \n";
    cout<<"Nombre\t\t\t Categoria \t\t\t Tipo\t\t\t Cantidad \n";
    for (int i=0; i<cantMed; i++){
        cout<<listado[i].nombre<<"\t\t\t "<<listado[i].categoria<<"\t\t\t "<<listado[i].tipo<<"\t\t\t "<<listado[i].cantidad<<endl;
    }
}

//registrar una venta
void RegistrarVenta(){
    cout<<"Inserte el id de la receta: ";
    cin>>ventas[cantVenta].id;
    cout<<"Nombre del paciente: ";
    cin>>ventas[cantVenta].nombre;
    cout<<"Nombre del medicamento: ";
    cin>>ventas[cantVenta].med;
    cout<<"cantidad: ";
    cin>>ventas[cantVenta].cant;
    cout<<"tipo: ";

    int pos;
    do{
        cout<<"tipo, escoja un elemnto: \n";
        for(int i=0;i<cantTipo;i++)
            cout<<i+1<<"\t"<<tipo[i]<<endl;

        cin>>pos;

    }while(pos<=0 || pos>cantTipo);
    ventas[cantVenta].tipo = tipo[pos-1];

    cout<<"Nombre del medico: ";
    cin>>ventas[cantVenta].medico;
    cout<<"nombre del tecnico: ";
    cin>>ventas[cantVenta].tecnico;
    cout<<"Fecha: ";
    cin>>ventas[cantVenta].fecha;
    cantVenta++;

}

void buscarMed(){
    string nombreMed;
    cout<<"Introduzca el Nombre del Medicamento que Desea Buscar: "<<endl;
    cin>>nombreMed;


    for(int i=0;i<cantMed;i++){
        if(listado[i].nombre==nombreMed){
           int opcion;
           int cantNueva;

           do{
               cout<<"Nombre\t\t\t categoria \t tipo\t cantidad \n";
               cout<<listado[i].nombre<<"\t\t\t "<<listado[i].categoria<<"\t\t "<<listado[i].tipo<<"\t\t "<<listado[i].cantidad<<endl;
               cout<<endl<<endl;
               cout<<"Opciones \n";
               cout<<"(1) Agregar cantidad \n";
               cout<<"(2) Baja del Medicamento \n";
               cout<<"(0) Salir \n";
               cout<<"Escoja una Opcion: ";
               cin>>opcion;

               switch (opcion) {
               case 1:
                   cout<<"Inserte la cantidad de medicamento a insertar: ";
                   cin>>cantNueva;
                   listado[i].cantidad+=cantNueva;
                   break;
               case 2:
               listado[i].cantidad=0;
                   break;
               case 0:
                   break;
               default:
                   cout<<"Ha esocgido una opcion invalida \n";
                   break;
               }
           }while(opcion!=0);
           break;
        }

    }
}

void buscarReceta(){
    int idReceta;
    cout<<"\nINTRODUZCA EL ID DE LA RECETA QUE DESEA BUSCAR: "<<endl;
    cin>>idReceta;
    for(int i=0;i<cantVenta;i++){
        if(ventas[i].id==idReceta){
            cout<<"ID\t\t\t Nombre\t\t\t Nombre del Paciente \t\t Tipo\t\t Cantidad \n";
            cout<<ventas[i].id<<"\t\t\t "<<ventas[i].med<<"\t\t\t "<<ventas[i].nombre<<"\t\t\t "<<ventas[i].tipo<<"\t\t\t "<<ventas[i].cant<<endl;
            break;
        }

    }
}


void listadoOrdenadoAgrupado(){



    grouping all[MAX];
    int cant =0;
    for (int i=0;i<cantVenta;i++) {
        bool find = false;
        for(int j=0;j<cant;j++){
            if(all[j].nombre==ventas[i].med)
            {
                all[j].cant+=ventas[i].cant;
                find = true;
                break;
            }
        }
        if(!find){
            all[cant].cant = ventas[i].cant;
            all[cant].nombre = ventas[i].med;
            for(int j=0;j<cantMed;j++)
                if(listado[j].nombre==ventas[i].med){
                    all[cant].grupo = listado[j].categoria;
                    break;
                }
            cant++;
        }
    }


    cout<<"Medicamento\t\t\tCantidad\n";
    for(int j=0;j<cantTipo;j++){
        cout<<"Tipo: "<<categoria[j]<<endl;

        for(int i=0;i<cant;i++){
            if(all[i].grupo==categoria[j])
                cout<< all[i].nombre<<"\t\t\t"<<all[i].cant<<endl;
        }

        cout<<"---------------------------------------------------- \n";

    }


}

#endif // LIBRERIA_H
