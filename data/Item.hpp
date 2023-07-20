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
    string id;          /** ID item. */
    string name;        /** Nama item. */
    int price;          /** Harga dari item dalam satuan Rupiah. */
    int quantity;       /** Jumlah item yang tersedia di restoran. */
    string category;    /** Kategori item. */

    /**
     * Konstruktor Item
     * 
     * @param id ID item.
     * @param name Nama item.
     * @param price Harga dari item dalam satuan Rupiah.
     * @param quantity Jumlah item yang tersedia di restoran,
     * @param category Kategori item.
     */
    Item(string id, string name, int price, int quantity, string category) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->category = category;
    }

    /**
     * Mengembalikan string yang berisi informasi item.
     * 
     * @return string yang berisi informasi item.
     */
    string toString() const {
        return "ID: " + this->id + "\n"
            + "Nama: " + this->name + "\n"
            + "Harga: " + to_string(this->price) + "\n"
            + "Jumlah Tersedia: " + to_string(this->quantity) + "\n"
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
