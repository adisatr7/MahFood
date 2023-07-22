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
        options.push(items.get(i).name + "\t\tRP " + to_string(items.get(i).price));
    }
    options.push("\nKembali ke menu utama");

    cout << "=================" << endl;
    cout << "   DAFTAR MENU   " << endl;
    cout << "=================" << endl;
    cout << endl;
    menuSelect();

    // Jika user memilih menu terakhir, kembali ke menu utama
    if (menuChoice == items.length()) {
        navigate(&homePage);
        resetMenuChoice();
        return;
    }
    
    // Jika user memilih menu lain, tanyakan ingin pesan berapa
    int qty = inputInteger("Mau pesan berapa?\n> ");

    // Jika user memasukan bilangan negatif, tampilkan pesan error
    if (qty <= 0) {
        cout << "Jumlah pesanan tidak valid!" << endl;
        cout << "Tekan sembarang tombol untuk mencoba lagi..." << endl;
        getch();
        return;
    }

    // Jika user memasukan bilangan positif, masukkan pesanan ke keranjang
    Item selectedItem = items.get(menuChoice - 1);
    currentUser.cart.push(Transaction(&selectedItem, qty));

    // Tampilkan pesan berhasil
    cout << "Pesanan berhasil ditambahkan!" << endl;
    cout << "Tekan sembarang tombol untuk melanjutkan..." << endl;
    getch();

    // Kembali ke menu utama
    navigate(&homePage);
    return;
}

#endif
