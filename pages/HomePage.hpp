#include "../config.hpp"
#include "../data/items.hpp"
#include "../global/states.hpp"
#include "../utils/router.hpp"
#include "../utils/inputHandler.hpp"
#include "../utils/menuSelect.hpp"

using global::currentUser;

#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP


void HomePage() {

    options.push("Buat Pesanan");
    options.push("Lihat Keranjang ");
    options.push("Keluar");

    cout << "================================" << endl;
    cout << "   Selamat datang di " << RESTAURANT_NAME << endl;
    cout << "================================" << endl;
    cout << endl;
    cout << "Semoga harimu menyenangkan, " << currentUser.name << "!" << endl;
    cout << endl;
    menuSelect();

    switch (menuChoice) {
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
