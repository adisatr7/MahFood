#include "../config.hpp"
#include "../global/states.hpp"
#include "../utils/router.hpp"
#include "../utils/inputHandler.hpp"
#include "../utils/menuSelect.hpp"

#ifndef WELCOMEPAGE_HPP
#define WELCOMEPAGE_HPP


void WelcomePage() {

    // Daftar pilihan yang dapat dipilih user lewat menu
    options.push("Daftar Sekarang");
    options.push("Sudah Punya Akun? Masuk");
    options.push("Keluar");

    cout << "================================" << endl;
    cout << "   Selamat datang di " << RESTAURANT_NAME << endl;
    cout << "================================" << endl;
    cout << endl;
    menuSelect();

    switch (menuChoice) {
        case 0:
            navigate(&registerPage);
            // options.clear();
            return;
        case 1:
            navigate(&loginPage);
            // options.clear();
            return;
        case 2:
            global::keepRunning = false;
            break;
    }
}

#endif