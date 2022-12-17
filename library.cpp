#include "library.h"

int max_in_use(int n1, int n2){
    if (n1 > n2) return n1;
    return n2;
}

char or_comparison(char c1, char c2){
    if ((c1 == '0' && c2 == 'x') || (c2 == '0' && c1 == 'x')) return 'x';
    if ((c1 == '1' && c2 == 'x') || (c2 == '1' && c1 == 'x') || (c1 == '0' && c2 == '1') || (c2 == '0' && c1 == '1') || (c1 == '1' && c2 == '1')) return '1';
    return '0';
}

char and_comparison(char c1, char c2){
    if ((c1 == '1' && c2 == 'x') || (c2 == '1' && c1 == 'x')) return 'x';
    if ((c1 == '0' && c2 == 'x') || (c2 == '0' && c1 == 'x') || (c1 == '0' && c2 == '0') || (c1 == '0' && c2 == '1') || (c2 == '0' && c1 == '1')) return '0';
    return '1';
}

char not_comparison(char c){
    if (c == '1') return '0';
    if (c == '0') return '1';
    return 'x';
}

char eq (char c1, char c2) {
    if ((c1 == '1' && c2 == '1') || (c1 == '0' && c2 == '0')) return '1';
    if ((c1 == '0' && c2 == '1') || (c2 == '0' && c1 == '1')) return '0';
    return 'x';
}

char more (char c1, char c2) {
    if (c1 == '0' && c2 == '1' || c1 == '0' && c2 == '0' || c1 == '1' && c2 == '1') return '0';
    if (c1 == '1' && c2 == '0') return '1';
    return 'x';
}

char less_ (char c1, char c2) {
    if (c1 == '1' && c2 == '0' || c1 == '0' && c2 == '0' || c1 == '1' && c2 == '1') return '0';
    if (c1 == '0' && c2 == '1') return '1';
    return 'x';
}

char more_eq (char c1, char c2) {
    if (c1 == 'x' && c2 == '1' || c1 == '0' && c2 == 'x') return 'x';
    if (c1 == '0' && c2 == '1') return '0';
    return '1';
}

char less_eq (char c1, char c2) {
    if (c1 == 'x' && c2 == '0' || c1 == '1' && c2 == 'x') return 'x';
    if (c1 == '1' && c2 == '0') return '0';
    return '1';
}

Vector::Vector (){
    in_use = 0;
    array = nullptr;
}

Vector::Vector (int n){
    in_use = n;
    array = new char [n];
    for (int i = 0; i < in_use; i++) array[i] = 'x';
}

Vector::Vector (const string& str){
    in_use = (int) str.length();
    array = new char [in_use];
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '0' || str[i] == '1') {
            array[i] = str[i];
        } else array[i] = 'x';
    }
}

Vector::~Vector (){
    delete [] array;
}

void Vector::set_array(const string& str){
    delete [] array;
    in_use = (int) str.length();
    array = new char [in_use];
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '0' || str[i] == '1') {
            array[i] = str[i];
        } else array[i] = 'x';
    }
}

void Vector::get_array(){
    for (int i = 0; i < in_use; i++) cout << array[i];
    cout << endl << in_use << endl;
}

void Vector::add_x(int new_in_use) {
    if (in_use != new_in_use) {
        char *new_array = new char[new_in_use];
        for (int i = 0; i < in_use; i++) new_array[i] = array[i];
        for (int i = in_use; i < new_in_use; i++) new_array[i] = 'x';
        delete[] array;
        in_use = new_in_use;
        array = new char[in_use];
        for (int i = 0; i < in_use; i++) array[i] = new_array[i];
        delete[] new_array;
    }
}

Vector Vector::get_res_vector (Vector other){
    int max = max_in_use(this->in_use, other.get_in_use());
    this->add_x(max);
    other.add_x(max);
    Vector res(max);
    return res;
}

Vector Vector::and_operation(const Vector& other) {
    Vector res = this->get_res_vector(other);
    for (int i = 0; i < in_use; i++) res.array[i] = and_comparison(array[i], other.array[i]);
    return res;
}

Vector Vector::or_operation(const Vector& other){
    Vector res = this->get_res_vector(other);
    for (int i = 0; i < in_use; i++) res.array[i] = or_comparison(array[i], other.array[i]);
    return res;
}

Vector Vector::not_operation(){
    Vector res(in_use);
    for (int i = 0; i < in_use; i++) res.array[i] = not_comparison(array[i]);
    return res;
}

bool Vector::certainty(){
    for (int i = 0; i < in_use; i++) if (array[i] == 'x') return false;
    return true;
}

int Vector::get_in_use() const{
    return in_use;
}

char Vector::get_array_i(int i){
    if (i >= in_use){
        cout << "Out of array! The result is unexpected.\n";
        return 'x';
    }
    return array[i];
}

void Vector::set_array_i(int i, char c) {
    if (i >= in_use){
        cout << "Out of array!\n";
        return;
    }
    array[i] = c;
}

Vector Vector::eq_operation(const Vector& other) {
    Vector res = this->get_res_vector(other);
    for (int i = 0; i < in_use; i++) {
        res.array[i] = eq(array[i], other.array[i]);
    }
    return res;
}

Vector Vector::more_operation(const Vector& other) {
    Vector res = this->get_res_vector(other);
    for (int i = 0; i < in_use; i++) {
        res.array[i] = more(array[i], other.array[i]);
    }
    return res;
}

Vector Vector::more_eq_operation(const Vector& other) {
    Vector res = this->get_res_vector(other);
    for (int i = 0; i < in_use; i++) {
        res.array[i] = more_eq(array[i], other.array[i]);
    }
    return res;
}

Vector Vector::less_operation(const Vector& other) {
    Vector res = this->get_res_vector(other);
    for (int i = 0; i < in_use; i++) {
        res.array[i] = less_(array[i], other.array[i]);
    }
    return res;
}

Vector Vector::less_eq_operation(const Vector& other) {
    Vector res = this->get_res_vector(other);
    for (int i = 0; i < in_use; i++) {
        res.array[i] = less_eq(array[i], other.array[i]);
    }
    return res;
}

Vector Vector::comparison (const Vector& other, const string& op) {
    if (op == "==") return this->eq_operation(other);
    if (op == ">") return this->more_operation(other);
    if (op == ">=") return this->more_eq_operation(other);
    if (op == "<") return this->less_operation(other);
    if (op == "<=") return this->less_eq_operation(other);
    return this->get_res_vector(other);
}

Vector Vector::comparison_operator (Vector other, const string& op) {
    if (op == "==") return other == *this;
    if (op == ">") return other > *this;
    if (op == ">=") return other >= *this;
    if (op == "<") return other < *this;
    if (op == "<=") return other <= *this;
    return this->get_res_vector(other);
}

string Vector::get_string_array() {
    string str(array);
    return str;
}

Vector::Vector (const Vector &other){
    delete [] array;
    in_use = other.in_use;
    array = new char [in_use];
    for (int i = 0; i < in_use; i++) array[i] = other.array[i];

}

Vector &Vector::operator = (const Vector &other) {
    if (&other != this) {
        delete[] array;
        in_use = other.in_use;
        array = new char[in_use];
        for (int i = 0; i < in_use; i++) array[i] = other.array[i];
        return *this;
    }
    return *this;
}

Vector Vector::operator && (const Vector& other){
    return this->and_operation(other);
}

Vector Vector::operator|| (const Vector& other) {
    return this->or_operation(other);
}

Vector operator ~ (Vector vector) {
    return vector.not_operation();
}

Vector Vector::operator == (const Vector& other){
    return eq_operation(other);
}

Vector Vector::operator > (const Vector& other){
    return more_operation(other);
}

Vector Vector::operator >= (const Vector& other){
    return more_eq_operation(other);
}

Vector Vector::operator < (const Vector& other){
    return less_operation(other);
}

Vector Vector::operator <= (const Vector& other){
    return less_eq_operation(other);
}