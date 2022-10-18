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
    friend Vector get_res_vector (Vector first, Vector second);
private:
    int in_use;
    char array[MAX_SIZE]{};
    void add_x(int);
public:
    Vector ();
    explicit Vector (int);
    explicit Vector (const string&);
    void set_array(const string &);
    void set_array_i(int, char);
    [[nodiscard]] int get_in_use() const;
    char get_array_i(int);
    void get_array();
    Vector NOT();
    bool certainty();
};

Vector comparison (Vector first, Vector second, const string& op);

#endif