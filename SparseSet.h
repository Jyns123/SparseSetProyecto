#ifndef SPARSESET_H
#define SPARSESET_H

#include <vector>
using namespace std;

class SparseSet {
private:
    vector<int> sparse;
    vector<int> dense;
    size_t size;

public:
    SparseSet(size_t max_size);  

    void insert(int element);
    void erase(int element);
    bool contains(int element);
    void printPosition(int element) const; 
    size_t getSize() const;
    void clear();
    void print() const;
};

#endif
