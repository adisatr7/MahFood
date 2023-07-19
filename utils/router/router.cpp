#include <iostream>
#include <ncurses.h>
#include "router.h"

using std::cout;
using std::endl;


// Navigate to a page.
int navigate(void (*page)()) {
    try {
        clear();
        page();
        return 0;
    }

    catch (const char* message) {
        cout << message << endl;
        return -1;
    }
}