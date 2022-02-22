#include "libreria.h"

int main()
{

    int opc;
    do{
        menu();
        cin>>opc;

        switch (opc) {
        case 1:
            ListadoMed();
            break;
        case 2:
        InsertarMed();
            break;
        case 3:
            RegistrarVenta();
            break;
        case 4:
            buscarReceta();
            break;
        case 5:
            buscarMed();
            break;
        case 6:
            ListadoVent();
            break;
        case 7:
            listadoOrdenadoAgrupado();
            break;
        case 0:
            cout<<"Adios \n";
            break;
        default:
            cout<<"Ha esocgido una opcion invalida \n";
            break;
        }

        system("pause");
    }while(opc!=0);

    return 0;
}
