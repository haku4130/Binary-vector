#include "menu.h"

int main() {
    Vector first("1010");
    //creation_menu(first);
    Vector second("0101");
    //creation_menu(second);
    first.get_array();
    second.get_array();
    processing_menu(first, second);
    return 0;
}
