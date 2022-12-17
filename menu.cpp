#include "menu.h"
#include <iostream>

using namespace std;

int get_int(const char message[]){
    int n;
    cout << message;
    while (!(cin >> n).good()) {
        cout << "Incorrect number!\n";
        cout << message;
        cin.clear();
        cin.ignore(100, '\n');
    }
    cin.clear();
    cin.ignore(100, '\n');
    return n;
}

int get_menu_item(int min, int max) {
    int res = get_int("Select menu item: ");
    while (res < min || res > max){
        cout << "Invalid menu item.\n";
        res = get_int("Select menu item: ");
    }
    return res;
}

int get_vector_number(int min, int max) {
    int res = get_int("Select vector number: ");
    while (res < min || res > max){
        cout << "Invalid vector number.\n";
        res = get_int("Select vector number: ");
    }
    return res;
}

void print_creation_menu(){
    cout << "\n1. Empty vector.\n"
            "2. Number of nulls.\n"
            "3. Char string.\n"
            "0. Exit.\n\n";
}

void creation_menu(Vector &vector){
    print_creation_menu();
    int choice;
    choice = get_menu_item(0, 3);
    if (choice == 1) return;
    if (choice == 2) {
        int n = -1;
        while (n < 0) n = get_int("Input n: ");
        Vector copy(n);
        vector = copy;
        return;
    }
    if (choice == 3) {
        string str;
        cin >> str;
        Vector copy(str);
        vector = copy;
        return;
    }
    exit(0);
}

void print_processing_menu(){
    cout << "\n1. OR operation.\n"
            "2. AND operation.\n"
            "3. NOT operation.\n"
            "4. Vectors comparison.\n"
            "5. Certainty analysis.\n"
            "6. Vectors output.\n"
            "7. Change vector`s value.\n"
            "0. Exit.\n\n";
}

void processing_menu(Vector &vector1, Vector &vector2){
    print_processing_menu();
    int choice, n;
    string str;
    Vector vector_res;
    do {
        choice = get_menu_item(0, 7);
        switch (choice) {
            case 1:
                //vector1.or_operation(vector2).get_array();
                vector_res = vector1 || vector2;
                vector_res.get_array();
                break;
            case 2:
                //vector1.and_operation(vector2).get_array();
                vector_res = vector1 && vector2;
                vector_res.get_array();
                break;
            case 3:
                n = get_vector_number(1, 2);
                if (n == 1) {
                    //vector1.not_operation().get_array();
                    vector_res = ~vector1;
                    vector_res.get_array();
                } else {
                    vector_res = ~vector2;
                    vector_res.get_array();
                    //vector2.not_operation().get_array();
                }
                break;
            case 4:
                cin >> str;
                //vector1.comparison(vector2, str).get_array();
                vector1.comparison_operator(vector2, str).get_array();
                break;
            case 5:
                n = get_vector_number(1, 2);
                if (n == 1) cout << vector1.certainty() << endl;
                else cout << vector2.certainty() << endl;
                break;
            case 6:
                vector1.get_array();
                vector2.get_array();
                break;
            case 7:
                n = get_vector_number(1, 2);
                cin >> str;
                if (n == 1) vector1.set_array(str);
                else vector2.set_array(str);
                break;
            default:
                break;
        }
    } while (choice);
}