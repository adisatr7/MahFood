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

    // Daftar pilihan yang dapat dipilih user lewat menu
    options.push("Buat Pesanan");
    options.push("Lihat Keranjang ");
    options.push("Keluar");

    cout << "================================" << endl;
    cout << "   Selamat datang di " << RESTAURANT_NAME << endl;
    cout << "================================" << endl;
    cout << endl;
    cout << "Semoga harimu menyenangkan, " << currentUser.name << "!" << endl;
    cout << endl;
    
    // Menampilkan daftar belanjaan user (jika ada)
    if (currentUser.cart.length() > 0) {
        cout << "Kamu memiliki " << currentUser.cart.length() << " item di keranjangmu:" << endl;
        for (int i = 0; i < currentUser.cart.length(); i++) {
            Transaction transaction = currentUser.cart.get(i);
            Item item = *transaction.itemPointer;
            int qty = currentUser.cart.get(i).quantity;
            cout << i+1 << ". " << item.name << " (x" << qty << ") - Rp " << item.price << endl;
        }
        cout << endl;
    }


    menuSelect();

    switch (menuChoice) {
        case 0:
            navigate(&shopPage);
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
