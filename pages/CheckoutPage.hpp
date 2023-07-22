#include "../config.hpp"
#include "../data/shoppingCart.hpp"
#include "../global/states.hpp"
#include "../utils/inputHandler.hpp"
#include "../utils/router.hpp"

#ifndef CHECKOUTPAGE_HPP
#define CHECKOUTPAGE_HPP


void CheckoutPage() {
    int totalPrice = 0;
    cout << "===============" << endl;
    cout << "   Checkout    " << endl;
    cout << "===============" << endl;
    cout << endl;

    for (int i = 0; i < shoppingCart.length(); i++) {
        Item item = *shoppingCart.get(i).itemPointer;
        int qty = shoppingCart.get(i).quantity;
        string subtotal = shoppingCart.get(i).printTotalPrice();
        cout << i+1 << ". " << item.name << " (x" << qty << ")\t\t" << subtotal << endl;
        totalPrice += shoppingCart.get(i).getTotalPrice();
    }

    cout << endl;
    cout << "Total harga: Rp" << totalPrice << endl;

    int money = 0;

    money = inputInteger("Masukan uang bayar: Rp ");

    if (money >= totalPrice) {
        cout << endl;
        cout << "Kembalian: Rp" << money - totalPrice << endl;
        cout << endl;
        cout << "Terima kasih telah berbelanja di " << RESTAURANT_NAME << "!" << endl;
        cout << endl;
        global::keepRunning = false;    // TODO: Ask the client whether they want different outcome
        return;
    }

    cout << endl;
    cout << "Maaf, uang Anda tidak cukup!" << endl;
    cout << "Tekan sembarang tombol untuk kembali ke menu sebelumnya...";
    getch();
    navigate(&homePage);
}

#endif