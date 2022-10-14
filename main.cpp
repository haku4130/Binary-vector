#include <iostream>
#include "Class_Vector.h"

using namespace std;

int main() {
    Vector test;
    test.set_array("1010101");
    test.get_array();
    Vector first("1010111x101xxx1010");
    Vector second("010100001010101");
    OR(first, second).get_array();
    AND(first, second).get_array();
    first.NOT().get_array();
    second.NOT().get_array();
    cout << first.certainty() << endl << second.certainty() << endl;
    return 0;
}