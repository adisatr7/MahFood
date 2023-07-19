#include <string>

using namespace std;


#ifndef ITEM_H
#define ITEM_H

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
    Item(string id, string name, int price, int quantity, string category);

    /**
     * Mengembalikan string yang berisi informasi item.
     * 
     * @return string yang berisi informasi item.
     */
    string toString();

    /**
     * Menampilkan informasi item ke layar.
     */
    void show();
};

#endif