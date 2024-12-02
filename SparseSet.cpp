#include "SparseSet.h"
#include <iostream>
#include <iomanip>
#include "colores.h"

#define INVALID_INDEX -1

SparseSet::SparseSet(size_t max_size) : size(0) {
    sparse.resize(max_size, INVALID_INDEX);
}

void SparseSet::insert(int element) {
    if (element >= 0 && element < sparse.size() && sparse[element] == INVALID_INDEX) {
        sparse[element] = size;
        dense.push_back(element);
        size++;
        cout << GREEN << "Elemento " << element << " insertado.\n" << RESET;
    } else {
        cout << RED << "Elemento ya presente o fuera de rango.\n" << RESET;
    }
}

void SparseSet::erase(int element) {
    if (element >= 0 && element < sparse.size() && sparse[element] != INVALID_INDEX) {
        size_t index = sparse[element];
        int last_element = dense.back();
        dense[index] = last_element;
        sparse[last_element] = index;
        dense.pop_back();
        sparse[element] = INVALID_INDEX;
        size--;
        cout << RED << "Elemento " << element << " eliminado.\n" << RESET;
    } else {
        cout << RED << "Elemento no encontrado.\n" << RESET;
    }
}

bool SparseSet::contains(int element) {
    return element >= 0 && element < sparse.size() && sparse[element] != INVALID_INDEX;
}

void SparseSet::printPosition(int element) const {
    if (element >= 0 && element < sparse.size() && sparse[element] != INVALID_INDEX) {
        cout << CYAN << "Elemento " << element << " está en posición: "
                  << "Sparse[" << element << "]=" << sparse[element] 
                  << ", Dense[" << sparse[element] << "]=" << element << "\n" << RESET;
    } else {
        cout << RED << "Elemento no encontrado o fuera de rango.\n" << RESET;
    }
}

size_t SparseSet::getSize() const {
    return size;
}

void SparseSet::clear() {
    sparse.assign(sparse.size(), INVALID_INDEX);
    dense.clear();
    size = 0;
    cout << YELLOW << "Sparse Set limpiado.\n" << RESET;
}



void SparseSet::print() const {
    cout << "\n" << YELLOW << "---------------------------------" << RESET << "\n";
    cout << GREEN << "Estado presente del Sparse Set:\n" << RESET;
    cout << YELLOW << "Tamaño del Sparse Set: " << size << "\n" << RESET;


    cout << BLUE << "Índices sparse:  ";
    for (size_t i = 0; i < sparse.size(); ++i) {
        cout << setw(4) << i;
    }
    cout << RESET << "\n";

    cout << "Valores sparse:  ";
    for (int val : sparse) {
        if (val == -1) {
            cout << RED << setw(4) << val << RESET; 
        } else {
            cout << setw(4) << val; 
        }
    }
    cout << RESET << "\n";

    cout << "Arreglo dense:   ";
    for (int val : dense) {
        cout << setw(4) << val;
    }
    if (dense.empty()) {
        cout << "(vacío)";
    }
    cout << RESET << "\n";

    cout << YELLOW << "---------------------------------" << RESET << "\n";
}

