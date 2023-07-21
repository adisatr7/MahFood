#include <iostream>
#include "../config.hpp"
#include "../data/items.hpp"
#include "../global/states.hpp"
#include "../utils/router.hpp"
#include "../utils/inputHandler.hpp"

using global::currentUser;


int input = 0;

string options[] = {
    "Lihat Menu",
    "Lihat Pesanan",
    "Keluar"
};

#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP

void HomePage() {

    cout << "================================" << endl;
    cout << "   Selamat datang di " << RESTAURANT_NAME << endl;
    cout << "================================" << endl;
    cout << endl;
    cout << "Semoga harimu menyenangkan, " << currentUser.name << "!" << endl;
    menuSelect(&input, options, 3);

    switch (input) {
        case 0:
            // navigate(&menuPage);
            break;
        case 1:
            // navigate(&orderPage);
            break;
        case 2:
            global::keepRunning = false;
            break;
    }
}

#endif
