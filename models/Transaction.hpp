#include "Item.hpp"

#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP


struct Transaction {
    Item *itemPointer;  /** Item yang dibeli. */
    int quantity;       /** Jumlah item yang dibeli. */

    /**
     * Konstruktor Transaction.
     * 
     * @param itemPointer Item yang dibeli.
     * @param quantity Jumlah item yang dibeli.
     */
    Transaction(Item *itemPointer, int quantity) {
        this->itemPointer = itemPointer;
        this->quantity = quantity;
    }

    // Default constructor
    Transaction() {
        this->itemPointer = nullptr;
        this->quantity = 0;
    }

    /**
     * Mengembalikan harga total dari item yang dibeli.
     * 
     * @return harga total dari item yang dibeli dalam bentuk `int`.
     */
    int getTotalPrice() {
        if (itemPointer == nullptr) {
            std::cout << "Error: Item pointer is null." << std::endl;
            return -1;
        }

        return itemPointer->price * quantity;
    }

    /**
     * Mengembalikan string harga dengan tanda titik sebagai pemisah ribuan.
     * 
     * @example 10000 -> 10.000
     * 
     * @return string harga dengan tanda titik sebagai pemisah ribuan.
     */
    string formatPrice() {
        int price = getTotalPrice();

        // Add thousands separator
        string priceStr = to_string(price);
        int len = priceStr.length();
        for (int i = len - 3; i > 0; i -= 3) {
            priceStr.insert(i, ".");
        }

        return priceStr;
    }

    /**
     * Mengembalikan string harga total dalam Rupiah.
     * 
     * @example Rp 10.000
     * 
     * @return string harga total dalam Rupiah.
     */
    string printTotalPrice() {
        return "Rp " + formatPrice();
    }
};

#endif