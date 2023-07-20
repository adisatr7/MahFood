#ifndef WELCOMEPAGE_HPP
#define WELCOMEPAGE_HPP

#include <iostream>
#include "routes.hpp"
#include "../config.hpp"
#include "../utils/router.hpp"
#include "../utils/inputHandler.hpp"


using std::cout;
using std::endl;
using std::string;


int input = 0;

string options[] = {
    "Daftar Akun Baru",
    "Sudah Punya Akun? Masuk",
    "Keluar"
};


void WelcomePage() {
    cout << "==============================================" << endl;
    cout << "   Selamat datang di " << RESTAURANT_NAME << endl;
    cout << "==============================================" << endl;
    cout << endl;
    menuSelect(&input, options, 3);

    switch (input) {
        case 0:
            // navigate(&registerPage);
            break;
        case 1:
            navigate(&loginPage);
            break;
        case 2:
            global::keepRunning = false;
            break;
    }
}

#endif