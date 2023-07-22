#include "../config.hpp"
#include "../data/items.hpp"
#include "../global/states.hpp"
#include "../utils/router.hpp"
#include "../utils/inputHandler.hpp"
#include "../utils/menuSelect.hpp"

using global::currentUser;

#ifndef SHOPPAGE_HPP
#define SHOPPAGE_HPP


void ShopPage() {

    // Daftar pilihan yang dapat dipilih user lewat menu
    for (int i=0; i<items.length(); i++) {
        string itemName = items.get(i).name;
        string itemPrice = "Rp " + to_string(items.get(i).price);
        options.push(items.get(i).name + " " + to_string(items.get(i).price));
    }
    options.push("Kembali ke menu utama");

    cout << "=================" << endl;
    cout << "   DAFTAR MENU   " << endl;
    cout << "=================" << endl;
    cout << endl;
    cout << "Semoga harimu menyenangkan, " << currentUser.name << "!" << endl;
    cout << endl;
    menuSelect();

    // Jika user memilih menu terakhir, kembali ke menu utama
    if (menuChoice == items.length()) {
        navigate(&homePage);
        return;
    }
    
    // Jika user memilih menu lain, tanyakan ingin pesan berapa
    // TODO: Add to cart feature
}

#endif
