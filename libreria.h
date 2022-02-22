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

string categoria[]={"Analgesicos", "Antiealergicos", "Antinflamatorios", "Antidepresivos"};
int cantCat = 4;

string tipo [] ={"Frasco", "Tableta", "Pomada"};
int cantTipo = 3;


medicamento listado[MAX];
int cantMed = 0;

receta ventas[MAX];
int cantVenta = 0;

grouping all[MAX];
int cant =0;





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
    cout<<" (7) Listado de medicamentos vendidos por tipos"<<endl;
    cout<<" (0) Salir "<<endl;
    cout<<" Escoja una opcion: ";
}


//INSERTAR MEDICAMENTO
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
        cout<<"No puede insertar mas medicamentos.";
    }
}


//LISTADO DE MEDICAMENTOS EXISTENTES
void ListadoMed(){
    cout<<"\nLISTADO DE MEDICAMENTOS EXISTENTES: \n";
    cout<<"Nombre\t\t\t Categoria \t\t\t Tipo\t\t Cantidad \n";
    for (int i=0; i<cantMed; i++){
        cout<<listado[i].nombre<<"\t\t\t "<<listado[i].categoria<<"\t\t\t "<<listado[i].tipo<<"\t\t "<<listado[i].cantidad<<endl;
    }
}

//REGISTRAR UNA VENTA
void RegistrarVenta(){
    cout<<"Inserte el id de la receta: ";
    cin>>ventas[cantVenta].id;
    cout<<"Nombre del paciente: ";
    cin>>ventas[cantVenta].nombre;
    cout<<"Escoja el nombre del medicamento: "<<endl;
    int pos;
    do{
        for(int i=0;i<cantMed;i++)
            cout<<i+1<<"\t"<<listado[i].nombre<<" - "<<listado[i].tipo<<endl;
        cin>>pos;
        if((pos<=0 || pos>cantMed))
            cout<<"Debe escopger un medicamento valido, intentelo de nuevo "<<endl;
    }while(pos<=0 || pos>cantMed);
    ventas[cantVenta].med= listado[pos-1].nombre;
    ventas[cantVenta].tipo = listado[pos-1].tipo;
    cout<<"cantidad: ";
    cin>>ventas[cantVenta].cant;
    cout<<"Nombre del medico: ";
    cin>>ventas[cantVenta].medico;
    cout<<"nombre del tecnico: ";
    cin>>ventas[cantVenta].tecnico;
    cout<<"Fecha: ";
    cin>>ventas[cantVenta].fecha;
    cantVenta++;
}


//BUSCAR MEDICAMENTO
void buscarMed(){
    string nombreMed;
    cout<<"\nINTRODUZCA EL NOMBRE DEL MEDICAMENTO QUE DESEA BUSCAR: "<<endl;
    cin>>nombreMed;
    for(int i=0;i<cantMed;i++){
        if(listado[i].nombre==nombreMed){
           int opcion;
           int cantNueva;
           do{
               cout<<"Nombre\t\t\t categoria \t\t tipo\t\t   cantidad \n";
               cout<<listado[i].nombre<<"\t\t\t "<<listado[i].categoria<<"\t\t "<<listado[i].tipo<<"\t\t\t "<<listado[i].cantidad<<endl;
               cout<<endl<<endl;
               cout<<"Opciones \n";
               cout<<"(1) Agregar cantidad \n";
               cout<<"(2) Baja del Medicamento \n";
               cout<<"(0) Salir \n";
               cout<<"Escoja una Opcion: ";
               cin>>opcion;
               switch (opcion) {
               case 1:
                   cout<<"\n INSERTE LA CANTIDAD DE MEDICAMENTOS A AGREGAR: ";
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

//BUSCAR UNA RECETA
void buscarReceta(){
    int idReceta;
    cout<<"\nINTRODUZCA EL ID DE LA RECETA QUE DESEA BUSCAR: "<<endl;
    cin>>idReceta;
    for(int i=0;i<cantVenta;i++){
        if(ventas[i].id==idReceta){
            cout<<"ID\t\t\t Nombre\t\t\t Nombre del Paciente \t Tipo\t\t Cantidad \n";
            cout<<ventas[i].id<<"\t\t\t "<<ventas[i].med<<"\t\t\t "<<ventas[i].nombre<<"\t\t\t "<<ventas[i].tipo<<"\t\t "<<ventas[i].cant<<endl;
            break;
        }

    }
}


//LISTADO DE VENTAS REALIZADAS
void ListadoVent(){
    cout<<"\nLISTADO DE LAS VENTAS REALIZADAS: \n";
    cout<<"ID Receta\t\t Paciente \t\t Medicamento\t\t Cantidad\t\t Medico\t\t Tecnico\t\t Fecha \n";
    for (int i=0; i<cantVenta; i++){
        cout<<ventas[i].id<<"\t\t\t "<<ventas[i].nombre<<"\t\t\t "<<ventas[i].med<<"\t\t\t "<<ventas[i].cant<<"\t\t\t "<<ventas[i].medico<<"\t\t "<<ventas[i].tecnico<<"\t\t\t "<<ventas[i].fecha<<endl;
    }
}


//lISTADO DE MEDICAMENTOS ORDENADOS
void listadoOrdenadoAgrupado(){

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
