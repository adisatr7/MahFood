#include "../config.hpp"
#include "../data/items.hpp"
#include "../data/shoppingCart.hpp"
#include "../global/states.hpp"
#include "../utils/router.hpp"
#include "../utils/inputHandler.hpp"
#include "../utils/menuSelect.hpp"

using global::currentUser;

#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP


void HomePage() {

    // Daftar pilihan yang dapat dipilih user lewat menu
    if (shoppingCart.length() == 0) {
        options.push("Buat Pesanan Baru");
    } else {
        options.push("Tambahkan Barang ke Keranjang");
    }
    options.push("Checkout");
    options.push("Keluar");

    cout << "================================" << endl;
    cout << "   Selamat datang di " << RESTAURANT_NAME << endl;
    cout << "================================" << endl;
    cout << endl;
    cout << "Semoga harimu menyenangkan, " << currentUser.name << "!" << endl;
    cout << endl;
    
    // Menampilkan daftar belanjaan user (jika ada)
    if (shoppingCart.length() > 0) {
        cout << "Kamu memiliki " << shoppingCart.length() << " item di keranjangmu:" << endl;
        for (int i = 0; i < shoppingCart.length(); i++) {
            Transaction transaction = shoppingCart.get(i);
            Item item = *transaction.itemPointer;
            int qty = shoppingCart.get(i).quantity;
            cout << i+1 << ". " << item.name << " (x" << qty << ") - " << transaction.printTotalPrice() << endl;
        }
        cout << endl;
    }

    // Menampilkan daftar pilihan menu
    menuSelect();

    // Utk mencegah bug menu looping terus
    if (menuChoice == -1)
        return;

    // Memproses pilihan menu
    switch (menuChoice) {
        case 0:
            navigate(&shopPage);
            break;
        case 1:
            // Jika keranjang sudah diisi, buka halaman checkout
            if (shoppingCart.length() > 0)
                navigate(&checkoutPage);
            
            // Jika keranjang masih kosong, tampilkan pesan error
            else {
                menuChoice = -1;
                cout << endl;
                cout << "Keranjang belanja masih kosong!" << endl;
                cout << "Silahkan tambahkan barang ke keranjangmu terlebih dahulu." << endl;
                cout << endl;
                cout << "Tekan sembarang tombol untuk kembali...";
                getch();
            }
            break;
        case 2:
            global::keepRunning = false;
            break;
    }
}

#endif
