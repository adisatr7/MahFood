#include <iostream>
#include "Item.h"

using namespace std;


Item::Item(string id, string name, int price, int quantity, string category) {
    this->id = id;
    this->name = name;
    this->price = price;
    this->quantity = quantity;
    this->category = category;
}

string Item::toString() { 
    // Kemalikan string yang berisi informasi item
    return "ID: " + this->id + "\n"
        + "Nama: " + this->name + "\n"
        + "Harga: " + to_string(this->price) + "\n"
        + "Jumlah Tersedia: " + to_string(this->quantity) + "\n"
        + "Kategori: " + this->category + "\n";
}

void Item::show() {
    cout << this->toString() << endl;
}