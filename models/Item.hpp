#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>

using std::string;
using std::to_string;
using std::cout;
using std::endl;


/**
 * Definisi struct Item yang merupakan item yang dijual di restoran.
 */
struct Item {
    string name;        /** Nama item. */
    int price;          /** Harga dari item dalam satuan Rupiah. */
    int stock;          /** Jumlah item yang tersedia di restoran. */
    string category;    /** Kategori item. */

    /**
     * Konstruktor Item
     * 
     * @param name Nama item.
     * @param price Harga dari item dalam satuan Rupiah.
     * @param stock Jumlah item yang tersedia di restoran,
     * @param category Kategori item.
     */
    Item(string name, int price, int stock, string category) {
        this->name = name;
        this->price = price;
        this->stock = stock;
        this->category = category;
    }

    /**
     * Konstruktor kosong.
     */
    Item() {
        this->name = "";
        this->price = 0;
        this->stock = 0;
        this->category = "";
    }

    /**
     * Mengembalikan string yang berisi informasi item.
     * 
     * @return string yang berisi informasi item.
     */
    string toString() const {
        return "Nama: " + this->name + "\n"
             + "Harga: " + to_string(this->price) + "\n"
             + "Jumlah Tersedia: " + to_string(this->stock) + "\n"
             + "Kategori: " + this->category + "\n";
    }

    /**
     * Menampilkan informasi item ke layar.
     */
    void show() const {
        cout << this->toString() << endl;
    }
};

#endif
