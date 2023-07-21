#include "Item.hpp"

#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP


struct Transaction {
    Item item;          /** Item yang dibeli. */
    int quantity;       /** Jumlah item yang dibeli. */

    /**
     * Konstruktor Transaction.
     * 
     * @param item Item yang dibeli.
     * @param quantity Jumlah item yang dibeli.
     * @param price Harga total dari item yang dibeli.
     */
    Transaction(Item item, int quantity) {
        this->item = item;
        this->quantity = quantity;
    }

    // Default constructor
    Transaction() {
        this->item = Item();
        this->quantity = 0;
    }

    /**
     * Mengembalikan harga total dari item yang dibeli.
     * 
     * @return harga total dari item yang dibeli dalam bentuk `int`.
     */
    int getTotalPrice() {
        return this->item.price * this->quantity;
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