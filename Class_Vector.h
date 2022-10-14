#ifndef LAB3_CPP_LIBRARY_CLASS_VECTOR_H
#define LAB3_CPP_LIBRARY_CLASS_VECTOR_H

#define MAX_SIZE 100

#include <iostream>
#include <cstring>

using namespace std;

char not_operation(char c);

class Vector {
    friend Vector OR(Vector first, Vector second);
    friend Vector AND(Vector first, Vector second);
private:
    int in_use;
    char array[MAX_SIZE]{};
    void add_x(int new_in_use);
public:
    Vector ();
    explicit Vector (int n);
    explicit Vector (const char arr[]);
    void set_array(const char arr[]);
    void get_array();
    Vector NOT();
    bool certainty();
};

#endif