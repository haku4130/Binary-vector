#ifndef LAB3_CPP_LIBRARY_CLASS_VECTOR_H
#define LAB3_CPP_LIBRARY_CLASS_VECTOR_H

#include <iostream>
#include <cstring>

using namespace std;

class Vector {
private:
    int in_use;
    char *array;
    void add_x(int);
public:
    Vector ();
    explicit Vector (int);
    explicit Vector (const string&);
    ~Vector ();
    void set_array(const string &);
    void set_array_i(int, char);
    Vector get_res_vector (Vector &);
    Vector and_operation (Vector&);
    Vector or_operation(Vector&);
    Vector eq_operation(Vector&);
    Vector more_operation(Vector&);
    Vector more_eq_operation(Vector&);
    Vector less_operation(Vector&);
    Vector less_eq_operation(Vector&);
    [[nodiscard]] int get_in_use() const;
    char get_array_i(int);
    void get_array();
    Vector not_operation();
    bool certainty();
    [[nodiscard]] string get_string_array() const;
    Vector comparison(Vector&, const string&);
    Vector comparison_operator (Vector &other, const string& op);
    Vector (const Vector &);
    Vector (Vector &&) noexcept ;
    Vector &operator = (const Vector &);
    Vector &operator = (Vector &&) noexcept ;
    Vector operator && (Vector&);
    Vector operator || (Vector&);
    Vector operator == (Vector&);
    Vector operator > (Vector&);
    Vector operator >= (Vector&);
    Vector operator < (Vector&);
    Vector operator <= (Vector&);
    Vector operator ~();
};

ostream &operator << (ostream &os, const Vector& v);
istream& operator >> (istream& in, Vector& v);

#endif