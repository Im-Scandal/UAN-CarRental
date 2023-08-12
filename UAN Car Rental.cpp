#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <climits>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int opcionMenu, opcionModificar, opcionAUX;
int tiempo, precio, precioTotal, km, kmTotal, ubicacion, placaEncontrada, aux;
string placa, nuevoDato, tipo, disponibiliad, espaciosAImprimir;
char opcionConfirmar;
int coincidencia, recaudo, recaudoAUX, limiteMostrar;

vector<vector<string>> content;
vector<string> row;
string line, word;

void menuCatalogoAutos();
void menuAlquiler();
void menuIngresos();
void menuModificarAuto();
void menuAgregarAuto();
void menuAlquilarCarro();
void menuReingresarCarro();

void mostrarStock();
void mostrarStockTipo();
void mostrarStockDisponibilidad();
void mostrarStockHistorial();
int autosDisponibles();
int autosAlquilados();
void encontrarPlaca();
void mostrarInfoAuto();
void eliminarAuto();
void ordenarEspacios(int categoria, int numero);
void totalIngresos();
void ingresosPorAutos();

void comprobacionArchivo();
void reescribirArchivo();
void opcionFail();
void comprobacionEscritura();

int main() {
    comprobacionArchivo();
    do
    {

        system("clear");

        cout << "				UAN CAR RENTAL" << endl << endl;

        cout << "1. Catálogo de autos" << endl;
        cout << "2. Alquiler" << endl;
        cout << "3. Ingresos" << endl;
        cout << "4. Cerrar programa" << endl << endl;
        cout << "Seleccione una opción: ";
        cin >> opcionMenu;
        opcionFail();
        system("clear");
        switch (opcionMenu)
        {
        case 1:
        {
            menuCatalogoAutos();
            opcionMenu = 0;
            break;
        }

        case 2:
        {
            menuAlquiler();
            opcionMenu = 0;
            break;
        }

        case 3:
        {
            menuIngresos();
            opcionMenu = 0;
            break;
        }

        case 4:
        {
            cout << "Quiere cerrar el programa? - s/n" << endl;
            cin >> opcionConfirmar;
            if (opcionConfirmar == 's' || opcionConfirmar == 'S')
            {
                reescribirArchivo();
                break;
            }
            else
            {
                opcionMenu = 0;
                system("clear");
                break;
            }
            break;
        }

        default:
        {
            cout << "Esa opción no esta disponible" << endl;
            system("pause");
            break;
        }
        }

    } while (opcionMenu != 4);

    return 0;
}

void menuCatalogoAutos()
{
    do
    {
        cout << "				UAN CAR RENTAL - CATALOGO DE AUTOS \n" << endl;
        cout << "1. Stock \n";
        cout << "2. Buscar un Auto \n";
        cout << "3. Agregar un nuevo auto \n";
        cout << "4. Regresar al menú principal \n" << endl;
        cout << "Elija una opción: ";
        cout << " \n";
        cin >> opcionMenu;
        opcionFail();
        system("clear");
        switch (opcionMenu)
        {
        case 1:
        {
            do
            {
                cout << "STOCK \n";
                cout << "Cantidad de autos: " << content[0].size() - 1 << " \n";
                cout << "Cantidad de autos disponibles: " << autosDisponibles() << " \n";
                cout << "Cantidad de autos alquilados: " << autosAlquilados() << " \n";
                cout << " \n";

                cout << "1. Ver todos \n";
                cout << "2. Tipo de Vehiculo \n";
                cout << "3. Disponibilidad \n";
                cout << "4. Regresar al menú catalogo \n" << endl;
                cout << "Elija una opción: ";
                cout << " \n";
                cin >> opcionMenu;
                opcionFail();
                switch (opcionMenu)
                {
                case 1: {
                    system("clear");
                    cout << "Todos los Vehiculos \n";
                    mostrarStock();
                    cout << "\n";
                    break; }
                case 2: {
                    cout << "TIPO VEHICULO \n";
                    cout << "1. Economico \n";
                    cout << "2. Intermedio \n";
                    cout << "3. Ejecutivo \n" << endl;
                    cout << "Elija una opción: ";
                    cout << " \n";
                    cin >> opcionMenu;
                    opcionFail();
                    switch (opcionMenu)
                    {
                    case 1:
                        cout << "   Economico \n";
                        tipo = "E",
                            mostrarStockTipo();
                        cout << "\n";
                        break;

                    case 2:
                        cout << "   Intermedio \n";
                        tipo = "I",
                            mostrarStockTipo();
                        cout << "\n";
                        break;

                    case 3:
                        cout << "   Ejecutivo \n";
                        tipo = "J",
                            mostrarStockTipo();
                        cout << "\n";
                        break;

                    default:
                        cout << "Esa opci" << "\243" << "n no esta disponible" << endl;
                        break;
                    }
                    break; }
                case 3: {
                    cout << "DISPONIBILIDAD \n";
                    cout << "1. Disponibles \n";
                    cout << "2. Alquilados \n" << endl;
                    cout << "Elija una opción: ";
                    cout << " \n";
                    cin >> opcionMenu;
                    opcionFail();
                    switch (opcionMenu)
                    {
                    case 1:
                        cout << "Disponibles: " << autosDisponibles() << " \n";
                        disponibiliad = "1";
                        mostrarStockDisponibilidad();
                        cout << "\n";
                        break;

                    case 2:
                        cout << "Alquilados: " << autosAlquilados() << " \n";
                        disponibiliad = "0";
                        mostrarStockDisponibilidad();
                        cout << "\n";
                        break;

                    default:
                        cout << "Esa opci" << "\243" << "n no esta disponible" << endl;
                        break;
                    }
                    break; }
                case 4:break;
                default: {
                    cout << "Esa opci" << "\243" << "n no esta disponible" << endl;
                    break; }
                }

            } while (opcionMenu != 4);
            opcionMenu = 0;
            break;
        }
        case 2:
        {
            do
            {
                cout << "BUSCAR UN AUTO \n";
                cout << "Ingrese la placa del carro:" << endl;
                cin >> placa;
                comprobacionEscritura();
                encontrarPlaca();
                if (placaEncontrada == 1)
                {
                    mostrarInfoAuto();
                    cout << "1. Modificar los datos del carro \n";
                    cout << "2. Eliminar el carro \n";
                    cout << "3. Ir a menu alquiler \n";
                    cout << "4. Regresar al menú catalogo \n" << endl;
                    cout << "Elija una opción: ";
                    cout << " \n";
                    cin >> opcionMenu;
                    opcionFail();
                    switch (opcionMenu)
                    {
                    case 1:
                    {
                        menuModificarAuto();
                        break;
                    }
                    case 2:
                    {
                        cout << "Quiere eliminar el carro? - s/n" << endl;
                        cin >> opcionConfirmar;
                        if (opcionConfirmar == 's' || opcionConfirmar == 'S')
                        {
                            eliminarAuto();
                            cout << "\n";
                            opcionMenu = 4;
                            cout << " Carro eliminado correctamente" << endl;
                        }
                        break;
                    }
                    case 3:
                        menuAlquiler();
                        break;
                    case 4:
                        break;
                    default: {
                        cout << "Esa opción no esta disponible" << endl;
                        break; }
                    }
                }
                else if (placaEncontrada == 0)
                {
                    cout << "1. Volver a buscar una placa" << endl;
                    cout << "2. VOlver al menú catalogo" << endl;
                    cin >> opcionMenu;
                    opcionFail();
                    switch (opcionMenu)
                    {
                    case 1:
                        break;
                    case 2:
                    {
                        opcionMenu = 4;
                        break;
                    }
                    default:
                    {
                        cout << "Esa opción no está disponible" << endl;
                        break;
                    }

                    }
                }

            } while (opcionMenu != 4);
            opcionMenu = 3;
            break;
        }
        case 3:
        {
            cout << "AGREGAR NUEVO AUTO \n";
            menuAgregarAuto();
            cout << "Carro exitosamente agregado" << endl;
            cout << " \n";   
            break;

        default:
            cout << "Esa opci" << "\243" << "n no esta disponible" << endl;
            break;
        }
        }
    } while (opcionMenu != 4);
}
void menuAlquiler()
{
    do
    {
        cout << "				UAN CAR RENTAL - Alquiler" << endl << endl;
        cout << "1. Alquilar un auto" << endl;
        cout << "2. Devolver un auto" << endl;
        cout << "3. Historial de alquiler" << endl;
        cout << "4. Volver al menú" << endl << endl;
        cout << "Seleccione una opción: ";
        cin >> opcionMenu;
        opcionFail();
        system("clear");
        switch (opcionMenu)
        {
        case 1:
        {
            do
            {
                cout << "ALQUILAR UN AUTO" << endl << endl;
                cout << "Ingrese la placa del carro: " << endl;
                cin >> placa;
                comprobacionEscritura();
                encontrarPlaca();
                if (placaEncontrada == 1)
                {
                    mostrarInfoAuto();
                    cout << "1. Alquilar" << endl;
                    cout << "2. Volver a buscar una placa" << endl;
                    cout << "3. Volver al menú alquiler" << endl;
                    cout << "Seleccione una opción: ";
                    cin >> opcionMenu;
                    opcionFail();
                    system("clear");
                    switch (opcionMenu)
                    {
                    case 1:
                        menuAlquilarCarro();
                        opcionMenu = 3;
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    }
                }
                else if (placaEncontrada == 0)
                {
                    cout << "1. Volver a buscar una placa" << endl;
                    cout << "2. VOlver al menú alquiler" << endl;
                    cin >> opcionMenu;
                    opcionFail();
                    switch (opcionMenu)
                    {
                    case 1:
                        break;
                    case 2:
                    {
                        opcionMenu = 3;
                        break;
                    }
                    default:
                    {
                        cout << "Esa opción no está disponible" << endl;
                        break;
                    }

                    }
                }
            } while (opcionMenu != 3);
            opcionMenu = 0;
            break;
        }
        case 2:
        {
            do
            {
                cout << "DEVOLVER UN AUTO" << endl << endl;
                cout << "Ingrese la placa del carro:" << endl;
                cin >> placa;
                comprobacionEscritura();
                encontrarPlaca();
                if (placaEncontrada == 1)
                {
                    mostrarInfoAuto();
                    cout << "1. Reingresar" << endl;
                    cout << "2. Volver a buscar una placa" << endl;
                    cout << "3. Volver al menú alquiler" << endl;
                    cout << "Seleccione una opción: ";
                    cin >> opcionMenu;
                    opcionFail();
                    system("clear");
                    switch (opcionMenu)
                    {
                    case 1:
                        menuReingresarCarro();
                        opcionMenu = 3;
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    }
                }
                else if (placaEncontrada == 0)
                {
                    cout << "1. Volver a buscar una placa" << endl;
                    cout << "2. VOlver al menú alquiler" << endl;
                    cin >> opcionMenu;
                    opcionFail();
                    switch (opcionMenu)
                    {
                    case 1:
                        break;
                    case 2:
                    {
                        opcionMenu = 3;
                        break;
                    }
                    default:
                    {
                        cout << "Esa opción no está disponible" << endl;
                        break;
                    }

                    }
                }

            } while (opcionMenu != 3);
            opcionMenu = 0;
            break;
        }
        case 3:
        {
            cout << "Historial de Alquiler" << endl;
            mostrarStockHistorial();
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout << "Esa opción no esta disponible" << endl;
            break;
        }
        }
    } while (opcionMenu != 4);
}
void menuIngresos()
{
    do
    {
        cout << "				UAN CAR RENTAL - Ingresos" << endl << endl;
        cout << "Se ha recaudado un total de: $";
        totalIngresos();
        cout << endl << endl;

        cout << "1. Ver ingresos por carros" << endl;
        cout << "2. Volver al menú" << endl << endl;
        cout << "Seleccione una opción: ";
        cin >> opcionMenu;
        opcionFail();
        switch (opcionMenu)
        {
        case 1:
        {
            ingresosPorAutos();
            break;
        }
        case 2:
        {
            break;
        }
        default:
        {
            cout << "Esa opción no está disponible" << endl;
        }
        }
    } while (opcionMenu != 2);
}
void menuModificarAuto()
{
    do {
        cout << "Modificar Datos" << endl << endl;
        cout << "1. Placa" << endl;
        cout << "2. Marca" << endl;
        cout << "3. Modelo" << endl;
        cout << "4. Kilometraje" << endl;
        cout << "5. Costo/Precio" << endl;
        cout << "6. Tipo de Seguro" << endl;
        cout << "7. Tipo de Vehiculo" << endl;
        cout << "0. Volver" << endl << endl;
        cout << "Seleccione una opción" << endl;
        cin >> opcionModificar;
        opcionFail();
        switch (opcionModificar)
        {
        case 1:
        {
            cout << "PLACA" << endl << endl;
            cout << "Ingrese la nueva Placa" << endl << endl;
            cin >> nuevoDato;
            comprobacionEscritura();
            for (int i = 0, j = 1; j < content[0].size(); j++)
            {
                if (nuevoDato == content[i][j])
                {
                    if (ubicacion == j)
                    {
                        cout << "La placa que ingresó, es la que se encuentra actualmente" << endl;
                        coincidencia = 1;
                        break;
                    }
                    else
                    {
                        cout << "La placa que ingresó ya existe en el sistema" << endl;
                        coincidencia = 1;
                        break;
                    }
                }
                else
                {
                    coincidencia = 0;
                }
            }
            if (coincidencia == 0)
            {
                cout << content[0][ubicacion] << " -> " << nuevoDato << endl;
                content[0][ubicacion] = nuevoDato;
                cout << "Placa exitosamente modificada" << endl;
                cout << content[0][ubicacion] << endl;
            }

            cout << " \n";
            break;
        }
        case 2:
        {
            cout << "MARCA" << endl << endl;
            cout << "Ingrese la nueva Marca" << endl << endl;
            cin >> nuevoDato;
            comprobacionEscritura();
            for (int i = 1, j = 1; j < content[0].size(); j++)
            {
                if (nuevoDato == content[i][j])
                {
                    if (ubicacion == j)
                    {
                        cout << "La Marca que ingresó, es la que se encuentra actualmente" << endl;
                        coincidencia = 1;
                        break;
                    }
                }
                else
                {
                    coincidencia = 0;
                }
            }
            if (coincidencia == 0)
            {
                cout << content[1][ubicacion] << " -> " << nuevoDato << endl;
                content[1][ubicacion] = nuevoDato;
                cout << "Marca exitosamente modificada" << endl;
                cout << content[1][ubicacion] << endl;
            }

            cout << " \n";
            break;
        }
        case 3:
        {
            cout << "MODELO" << endl << endl;
            cout << "Ingrese el nuevo Modelo " << endl << endl;
            cin >> nuevoDato;
            comprobacionEscritura();
            for (int i = 2, j = 1; j < content[0].size(); j++)
            {
                if (nuevoDato == content[i][j])
                {
                    if (ubicacion == j)
                    {
                        cout << "El Modelo que ingresó, es el que se encuentra actualmente" << endl;
                        coincidencia = 1;
                        break;
                    }
                }
                else
                {
                    coincidencia = 0;
                }
            }
            if (coincidencia == 0)
            {
                cout << content[2][ubicacion] << " -> " << nuevoDato << endl;
                content[2][ubicacion] = nuevoDato;
                cout << "Modelo exitosamente modificado" << endl;
                cout << content[2][ubicacion] << endl;
            }

            cout << " \n";
            break;
        }
        case 4:
        {
            cout << "KILOMETRAJE" << endl << endl;
            cout << "Ingrese el nuevo Kilometraje" << endl << endl;
            cin >> km;
            opcionFail();
            nuevoDato = std::to_string(km);

            cout << content[5][ubicacion] << " -> " << nuevoDato << endl;
            content[5][ubicacion] = nuevoDato;
            cout << "Kilometraje exitosamente modificado" << endl;
            cout << content[5][ubicacion] << endl;
            cout << " \n";
            break;
        }
        case 5:
        {
            cout << "COSTO/PRECIO" << endl << endl;
            cout << "Ingrese el nuevo Kilometraje" << endl << endl;
            cin >> precio;
            opcionFail();
            nuevoDato = std::to_string(precio);

            cout << content[8][ubicacion] << " -> " << nuevoDato << endl;
            content[8][ubicacion] = nuevoDato;
            cout << "Kilometraje exitosamente modificado" << endl;
            cout << content[8][ubicacion] << endl;
            cout << " \n";
            break;
        }
        case 6:
        {
            cout << "TIPO DE SEGURO" << endl << endl;
            cout << "1. Full" << endl;
            cout << "2. SOAT" << endl;
            cout << "3. SOAT + Choque Simple" << endl;
            cout << "Seleccione el tipo de seguro: " << endl;
            cin >> opcionAUX;
            opcionFail();
            switch (opcionAUX)
            {
            case 1:
            {
                cout << content[4][ubicacion] << " -> FULL" << endl;
                content[4][ubicacion] = "F";
                cout << "Tipo de seguro exitosamente modificado" << endl;
                cout << content[4][ubicacion] << endl;
                cout << " \n";
                break;
            }
            case 2:
            {
                cout << content[4][ubicacion] << " -> SOAT" << endl;
                content[4][ubicacion] = "S";
                cout << "Tipo de seguro exitosamente modificado" << endl;
                cout << content[4][ubicacion] << endl;
                cout << " \n";
                break;
            }
            case 3:
            {
                cout << content[4][ubicacion] << " -> SOAT + Choque Simple" << endl;
                content[4][ubicacion] = "SC";
                cout << "Tipo de seguro exitosamente modificado" << endl;
                cout << content[4][ubicacion] << endl;
                cout << " \n";
                break;
            }
            }
            break;
        }
        case 7:
        {
            cout << "TIPO DE VEHÍCULO" << endl << endl;
            cout << "1. Economico" << endl;
            cout << "2. Intermedio" << endl;
            cout << "3. Ejecutivo" << endl;
            cout << "Seleccione el tipo de vehículo: " << endl;
            cin >> opcionAUX;
            switch (opcionAUX)
            {
            case 1:
            {
                cout << content[3][ubicacion] << " -> Economico" << endl;
                content[3][ubicacion] = "E";
                cout << "Tipo de vehiculo exitosamente modificado" << endl;
                cout << content[3][ubicacion] << endl;
                cout << " \n";
                break;
            }
            case 2:
            {
                cout << content[3][ubicacion] << " -> Intermedio" << endl;
                content[3][ubicacion] = "I";
                cout << "Tipo de vehiculo exitosamente modificado" << endl;
                cout << content[3][ubicacion] << endl;
                cout << " \n";
                break;
            }
            case 3:
            {
                cout << content[3][ubicacion] << " -> Ejecutivo" << endl;
                content[3][ubicacion] = "J";
                cout << "Tipo de vehiculo exitosamente modificado" << endl;
                cout << content[3][ubicacion] << endl;
                cout << " \n";
                break;
            }
            }
            break;
        }
        case 0:
        {
            opcionMenu = 3;
            break;
        }

        }
    } while (opcionModificar != 0);
}
void menuAgregarAuto()
{
    cout << "PLACA" << endl << endl;
    do {
        cout << "Ingrese la Placa" << endl << endl;
        cin >> nuevoDato;
        comprobacionEscritura();
        for (int i = 0, j = 1; j < content[0].size(); j++)
        {
            if (nuevoDato == content[i][j])
            {
                cout << "La placa que ingresó ya existe en el sistema" << endl;
                coincidencia = 1;
                break;
            }
            else
            {
                coincidencia = 0;
            }
        }
        if (nuevoDato.length() < 6 || nuevoDato.length() > 6)
        {
            cout << "Ingresa una placa valida" << endl;
        }
    } while (coincidencia == 1 || nuevoDato.length() < 6 || nuevoDato.length() > 6);
    if (coincidencia == 0)
    {
        content[0].push_back(nuevoDato);
    }
    cout << " \n";

    cout << "MARCA" << endl << endl;
    cout << "Ingrese la Marca" << endl << endl;
    cin >> nuevoDato;
    comprobacionEscritura();
    content[1].push_back(nuevoDato);
    cout << " \n";

    cout << "MODELO" << endl << endl;
    cout << "Ingrese el Modelo " << endl << endl;
    cin >> nuevoDato;
    comprobacionEscritura();
    content[2].push_back(nuevoDato);
    cout << " \n";

    cout << "KILOMETRAJE" << endl << endl;
    cout << "Ingrese el Kilometraje" << endl << endl;
    cin >> km;
    opcionFail();
    nuevoDato = std::to_string(km);
    content[5].push_back(nuevoDato);
    cout << " \n";

    cout << "COSTO/PRECIO" << endl << endl;
    cout << "Ingrese el costo" << endl << endl;
    cin >> precio;
    opcionFail();
    nuevoDato = std::to_string(precio);
    content[8].push_back(nuevoDato);
    cout << " \n";

    cout << "TIPO DE SEGURO" << endl << endl;
    cout << "1. Full" << endl;
    cout << "2. SOAT" << endl;
    cout << "3. SOAT + Choque Simple" << endl;
    cout << "Seleccione el tipo de seguro: " << endl;
    cin >> opcionAUX;
    opcionFail();
    switch (opcionAUX)
    {
    case 1:
    {
        nuevoDato = "F";
        content[4].push_back(nuevoDato);
        cout << " \n";
        break;
    }
    case 2:
    {
        nuevoDato = "S";
        content[4].push_back(nuevoDato);
        cout << " \n";
        break;
    }
    case 3:
    {
        nuevoDato = "SC";
        content[4].push_back(nuevoDato);
        cout << " \n";
        break;
    }
    }

    cout << "TIPO DE VEHÍCULO" << endl << endl;
    cout << "1. Economico" << endl;
    cout << "2. Intermedio" << endl;
    cout << "3. Ejecutivo" << endl;
    cout << "Seleccione el tipo de vehículo: " << endl;
    cin >> opcionAUX;
    switch (opcionAUX)
    {
    case 1:
    {
        nuevoDato = "E";
        content[3].push_back(nuevoDato);
        cout << " \n";
        break;
    }
    case 2:
    {
        nuevoDato = "I";
        content[3].push_back(nuevoDato);
        cout << " \n";
        cout << " \n";
        break;
    }
    case 3:
    {
        nuevoDato = "J";
        content[3].push_back(nuevoDato);
        cout << " \n";
        break;
    }
    }
    cout << " \n";
    nuevoDato = "1";
    content[6].push_back(nuevoDato);//EstadoActual
    nuevoDato = "0";
    content[7].push_back(nuevoDato);//Dias
    nuevoDato = " ";
    content[9].push_back(nuevoDato);//Recaudo
    nuevoDato = "0";
}
void menuAlquilarCarro()
{
    if (content[6][ubicacion] == "1")
    {
        cout << "Tiempo que desea alquilarlo: " << endl;
        cin >> tiempo;
        opcionFail();
        nuevoDato = std::to_string(tiempo);
        content[7][ubicacion] = nuevoDato;

        std::string::size_type sz;
        precio = stoi(content[8][ubicacion], &sz);
        precioTotal = tiempo * precio;
        cout << "El total a pagar es: $" << precioTotal << endl;

        content[9][ubicacion] = std::to_string(precioTotal);

        content[6][ubicacion] = "0";
        cout << "Vehículo alquilado satisfactoriamente" << endl;
    }
    else if (content[6][ubicacion] == "0")
    {
        cout << "Este carro ya está alquilado" << endl;
    }
}
void menuReingresarCarro()
{
    if (content[6][ubicacion] == "0")
    {
        cout << "Ingrese la cantidad de Km recorridos:" << endl;
        cin >> km;
        opcionFail();

        std::string::size_type sz;
        kmTotal = stoi(content[5][ubicacion], &sz);
        kmTotal = kmTotal + km;
        cout << "El nuevo total de km es: " << kmTotal << "km" << endl;

        content[5][ubicacion] = std::to_string(km);
        content[6][ubicacion] = "1";
        cout << "Vehículo reingresado satisfactoriamente" << endl;
    }
    else if (content[6][ubicacion] == "1")
    {
        cout << "Este carro no está alquilado" << endl;
    }
}

void mostrarStock()
{
    limiteMostrar = 5;
    for (int i = 0, j = 0; i < content.size() - 4; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
        }
        if (i == content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
            cout << endl;
        }
    }
    for (int j = 1, i = 0; j < content[0].size(); j++)
    {
        i = 0;
        for (; i < content.size() - 4; i++)
        {
            if (i == 0)
                cout << "[  ";
            if (i != content.size() - limiteMostrar)
            {
                cout << content[i][j];
                ordenarEspacios(i, j);
            }
            if (i == content.size() - limiteMostrar)
            {
                cout << content[i][j];
                ordenarEspacios(i, j);
            }
        }
    }
}
void mostrarStockTipo()
{
    limiteMostrar = 5;
    for (int i = 0, j = 0; i < content.size() - 4; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
        }
        if (i == content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
            cout << endl;
        }
    }
    for (int j = 1, i = 3; j < content[0].size(); j++)
    {
        i = 3;
        if (content[i][j] == tipo)
        {
            i = 0;
            for (; i < content.size() - 4; i++)
            {
                if (i == 0)
                    cout << "[  ";
                if (i != content.size() - limiteMostrar)
                {
                    cout << content[i][j];
                    ordenarEspacios(i, j);
                }
                if (i == content.size() - limiteMostrar)
                {
                    cout << content[i][j];
                    ordenarEspacios(i, j);
                }
            }
        }
    }
}
void mostrarStockDisponibilidad()
{
    limiteMostrar = 5;
    for (int i = 0, j = 0; i < content.size() - 4; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
        }
        if (i == content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
            cout << endl;
        }
    }
    for (int j = 1, i = 6; j < content[0].size(); j++)
    {
        i = 6;
        if (content[i][j] == disponibiliad)
        {
            i = 0;
            for (; i < content.size() - 4; i++)
            {
                if (i == 0)
                    cout << "[  ";
                if (i != content.size() - limiteMostrar)
                {
                    cout << content[i][j];
                    ordenarEspacios(i, j);
                }
                if (i == content.size() - limiteMostrar)
                {
                    cout << content[i][j];
                    ordenarEspacios(i, j);
                }
            }
        }
    }
}
void mostrarStockHistorial()
{
    limiteMostrar = 4;
    for (int i = 0, j = 0; i < content.size() - 3; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
        }
        if (i == content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
            cout << endl;
        }
    }
    for (int j = 1, i = 7; j < content[0].size(); j++)
    {
        i = 7;
        if (content[i][j] != "0")
        {
            i = 0;
            for (; i < content.size() - 3; i++)
            {
                if (i == 0)
                    cout << "[  ";
                if (i != content.size() - limiteMostrar)
                {
                    cout << content[i][j];
                    ordenarEspacios(i, j);
                }
                if (i == content.size() - limiteMostrar)
                {
                    cout << content[i][j];
                    ordenarEspacios(i, j);
                }
            }
        }
    }
}
int autosDisponibles()
{
    int countDisp = 0;
    for (int i = 6, j = 1; j < content[0].size(); j++) {
        if (content[i][j] == "1") {
            countDisp++;
        }
    }
    return countDisp;
}
int autosAlquilados()
{
    int countAlq = 0;
    for (int i = 6, j = 1; j < content[0].size(); j++) {
        if (content[i][j] == "0") {
            countAlq++;
        }
    }
    return countAlq;
}
void encontrarPlaca()   
{
    for (int i = 0, j = 0; j < content[0].size(); j++)
    {
        aux = 1;
        if (placa == content[i][j])
        {
            placaEncontrada = 1;
            ubicacion = j;
            break;
        }
        else
        {
            aux = 0;
        }
    }
    if (aux == 0)
    {
        cout << "Placa no encontrada" << endl;
        placaEncontrada = 0;
    }
}
void mostrarInfoAuto()
{
    limiteMostrar = 2;
    for (int i = 0, j = 0; i < content.size() - 1; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
        }
        if (i == content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
            cout << endl;
        }
    }
    for (int j = ubicacion, i = 0; i < content.size() - 1; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
        }
        if (i == content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
            cout << endl;
        }
    }
}
void eliminarAuto()
{
    for (int i = 0; i < content.size(); i++)//Reemplaza el carro seleccionado por el ultimo carro del vector 
    {
        string auxiliar = content[i][content[0].size() - 1];
        content[i][ubicacion] = auxiliar;
    }

    for (int i = 0; i < content.size(); i++)//Elimina el ultimo elemento del vector
    {
        content[i].pop_back();
    }
}
void ordenarEspacios(int categoria, int numero)
{
    espaciosAImprimir = content[categoria][numero];
    int espacios = 12 - espaciosAImprimir.length();

    if (categoria != content.size() - limiteMostrar)
    {
        for (int l = 0; l < espacios; l++)
        {
            cout << " ";
        }
        cout << "|";
    }
    else
    {
        for (int l = 0; l < espacios; l++)
        {
            cout << " ";
        }
        cout << "]\n";
    }
}
void totalIngresos()
{
    for (int j = 1; j < content[0].size(); j++)
    {
        std::string::size_type sz;
        recaudoAUX = stoi(content[9][j], &sz);
        recaudo = recaudo + recaudoAUX;
    }
    cout << recaudo;
    recaudo = 0;
}
void ingresosPorAutos()
{
    limiteMostrar = 8;
    for (int i = 0, j = 0; i < content.size()-7; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - limiteMostrar)
        {
            cout << content[i][j];
            ordenarEspacios(i, j);
        }
        if (i == content.size() - limiteMostrar)
        {
            cout << content[i][j];
            int k = 1;
            ordenarEspacios(k, j);
            cout << content[9][j];
            ordenarEspacios(i, j);
            cout << endl;
        }
    }
    for (int j = 1, i = 0; j < content[0].size(); j++)
    {
        i = 0;
        for (; i < content.size()-7; i++)
        {
            if (i == 0)
                cout << "[  ";
            if (i != content.size() - limiteMostrar)
            {
                cout << content[i][j];
                ordenarEspacios(i, j);
            }
            if (i == content.size() - limiteMostrar)
            {
                cout << content[i][j] <<"\t  |"<<content[9][j];
                ordenarEspacios(i, j);
            }
        }
    }
}

void comprobacionArchivo()
{
    fstream baseDatos("Base_Datos.txt", ios::in);
    if (baseDatos.is_open())
    {
        while (getline(baseDatos, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
    {
        baseDatos.open("Base_Datos.txt", ios::out);

        baseDatos << "Placa,\n";
        baseDatos << "Marca,\n";
        baseDatos << "Modelo,\n";
        baseDatos << "TCarro,\n";
        baseDatos << "TSeguro,\n";
        baseDatos << "Km,\n";
        baseDatos << "AlqDisp,\n";
        baseDatos << "Dias,\n";
        baseDatos << "Precio,\n";
        baseDatos << "Ingresos,\n";

        baseDatos.close();
        fstream baseDatos("Base_Datos.txt", ios::in);

        while (getline(baseDatos, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }

    baseDatos.close();
}
void reescribirArchivo()
{
    ofstream baseDatos;

    baseDatos.open("Base_Datos.txt", ios::out);

    for (int i = 0, j = 0; i < content.size(); i++)
    {
        for (; j < content[0].size(); j++)
        {
            if (j == content[0].size() - 1)
            {
                baseDatos << content[i][j] << "," << endl;
                break;
            }
            else
            {
                baseDatos << content[i][j] << ",";
            }
        }
        j = 0;
    }

    baseDatos.close();
}
void opcionFail()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Opción no valida" << endl;
        getchar();
    }
}
void comprobacionEscritura()
{
    for (int i = 0; i < placa.length(); i++)
    {
        placa[i] = toupper(placa[i]);
    }
    for (int i = 0; i < nuevoDato.length(); i++)
    {
        nuevoDato[i] = toupper(nuevoDato[i]);
    }
}
