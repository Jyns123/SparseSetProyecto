#include <iostream>
#include <cstdlib>  
#include "SparseSet.h"
#include "colores.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showMenu() {
    cout << "\n==============================\n";
    cout << "      MENÚ DEL SPARSE SET      \n";
    cout << "==============================\n";
    cout << "1. Insertar un elemento\n";
    cout << "2. Eliminar un elemento\n";
    cout << "3. Comprobar si un elemento está presente\n";
    cout << "4. Mostrar posición de un elemento\n";
    cout << "5. Limpiar el sparse set\n";
    cout << "6. Salir\n";
    cout << "==============================\n";
    cout << "Elige una opción (1/2/3/4/5/6): ";
}

int readInt(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Entrada invalida. Por favor, introduce un número valido.\n";
        cin.clear();
        cin.ignore(1000, '\n');  
        cout << prompt;
    }
    return value;
}

int main() {
    size_t max_size;
    cout << "Introduce el tamaño máximo del sparse set: ";
    while (!(cin >> max_size) || max_size <= 0) {
        cout << "Por favor, introduce un número entero positivo.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Introduce el tamaño máximo del sparse set: ";
    }

    SparseSet ss(max_size);

    clearScreen();
    cout << GREEN << "Estado inicial del Sparse Set:" << RESET << "\n";
    ss.print();

    while (true) {
        showMenu();
        int choice = readInt("");

        switch (choice) {
            case 1: {
                int element = readInt("Introduce el elemento a insertar: ");
                ss.insert(element);
                break;
            }
            case 2: {
                int element = readInt("Introduce el elemento a eliminar: ");
                ss.erase(element);
                break;
            }
            case 3: {
                int element = readInt("Introduce el elemento a comprobar: ");
                if (ss.contains(element)) {
                    cout << GREEN << "El elemento " << element << " está presente.\n" << RESET;
                } else {
                    cout << RED << "El elemento " << element << " no está presente.\n" << RESET;
                }
                break;
            }
            case 4: {
                int element = readInt("Introduce el elemento para mostrar su posición: ");
                ss.printPosition(element);
                break;
            }
            case 5:
                ss.clear();
                break;
            case 6:
                cout << "Saliendo...\n";
                return 0;
            default:
                cout << RED << "Opción inválida. Por favor, elige entre 1 y 6.\n" << RESET;
                break;
        }

        cout << "\nPresiona Enter para continuar...";
        cin.ignore();
        cin.get();
        clearScreen();

        cout << GREEN << "Estado presente del Sparse Set:" << RESET << "\n";
        ss.print();
    }

    return 0;
}
//LIMITACIONES:
//NO VALORES NEGATIVOS
//SOLO INTS A MENOS DE USAR ALGUN ALGORITMO DE CONVERSION
//TAMAÑO MAXIMO PREDEFINIDO
//NO ORDENADO
//CONSUMO DE MEMORIA 
//NO VALORES REPETIDOS 

//VENTAJAS
//INSERCION O(1)
//ELIMINACION O(1)
//BUSQUEDA O(1)