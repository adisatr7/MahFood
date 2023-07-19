#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>


/**
 * Wadah untuk menyimpan data (elemen) di dalam Linked List. Disini menggunakan 
 * template agar Node dapat menyimpan berbagai jenis data.
 */
template <typename T>
struct Node {

    /** 
     * Data yang akan disimpan.
     */
    T data;         

    /** 
     * Pointer menuju Node berikutnya.
     */
    Node* next;     

    /**
     * Konstruktor Node. Digunakan untuk membuat Node baru.
     */
    Node(const T& value);
};


/**
 * Struktur data Linked List untuk menyimpan berbagai data. Disini menggunakan
 * template agar LinkedList dapat menyimpan berbagai jenis tipe data.
 */
template <typename T>
struct LinkedList {

    /**
     * Pointer menuju Node pertama di Linked List.
     */
    Node<T>* head;

    /**
     * Pointer menuju Node terakhir di Linked List.
     */
    Node<T>* tail;


    /**
     * Konstruktor LinkedList yang digunakan untuk membuat Linked List baru.
     */
    LinkedList();

    /**
     * Menambahkan elemen baru ke dalam Linked List. Nilai elemen baru akan
     * disimpan di akhir (tail) dari Linked List.
     * 
     * @param value Reference ke data yang akan disimpan.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void push(const T& value);

    /**
     * Menambahkan elemen baru ke dalam Linked List pada posisi tertentu.
     * 
     * @param value Reference ke data yang akan disimpan.
     * @param index Indeks posisi yang dituju.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void insertAt(const T& value, int index);

    /**
     * Menghapus elemen pertama yang memiliki nilai tertentu.
     * 
     * @param value Reference ke data yang akan dihapus. 
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void removeHead(const T& value);

    /**
     * Menghapus elemen terakhir yang memiliki nilai tertentu.
     * 
     * @param value Reference ke data yang akan dihapus.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void removeTail(const T& value);

    /**
     * Menghapus elemen pada posisi tertentu.
     * 
     * @param index Indeks posisi yang dituju.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void removeAt(int index);

    /**
     * Mendapatkan panjang Linked List.
     * 
     * @return Panjang Linked List.
     */
    int length() const;

    /**
     * Mencetak seluruh elemen yang ada di dalam Linked List.
     */
    void print() const;

    /**
     * Menghapus seluruh elemen yang ada di dalam Linked List.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void clear();

    /**
     * Destruktor LinkedList yang digunakan untuk menghapus Linked List. Berguna
     * untuk mencegah memory leak atau kebocoran memori komputer.
     */
    ~LinkedList();
};

#endif
