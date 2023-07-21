#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;


/**
 * Wadah untuk menyimpan data (elemen) di dalam Linked List. Disini menggunakan 
 * template agar Node dapat menyimpan berbagai jenis data.
 */
template <typename T>
struct Node {
    T data;         /** Data yang akan disimpan. */
    Node *next;     /** Pointer menuju Node berikutnya. */

    /**
     * Konstruktor Node. Digunakan untuk membuat Node baru.
     * 
     * @param value Reference ke data yang akan disimpan.
     */
    Node(const T& value) {
        this->data = value;
        this->next = nullptr;
    }

    /**
     * Konstruktor kosong.
     */
    Node() {
        this->next = nullptr;
    }
};


/**
 * Struktur data Linked List untuk menyimpan berbagai data. Disini menggunakan
 * template agar LinkedList dapat menyimpan berbagai jenis tipe data.
 */
template <typename T>
struct LinkedList {
    Node<T>* head;      /** Pointer menuju Node pertama di Linked List. */
    Node<T>* tail;      /** Pointer menuju Node terakhir di Linked List. */

    /**
     * Konstruktor LinkedList yang digunakan untuk membuat Linked List baru.
     */
    LinkedList() {
        Node<T> *head = nullptr;       // Pointer menuju Node pertama.
        Node<T> *tail = nullptr;       // Pointer menuju Node terakhir.
    }

    /**
     * Menambahkan elemen baru ke dalam Linked List. Nilai elemen baru akan
     * disimpan di akhir (tail) dari Linked List.
     * 
     * @param value Reference ke data yang akan disimpan.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void push(const T& value) {

        // Pointer menuju Node baru
        Node<T>* newNode = new Node<T>(value);

        // Jika Linked List kosong, maka elemen baru akan menjadi elemen pertama.
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        // Jika Linked List tidak kosong, maka sisipkan elemen baru di akhir Linked List.
        tail->next = newNode;
        tail = newNode;
    }

    /**
     * Menambahkan elemen baru ke dalam Linked List pada posisi tertentu.
     * 
     * @param value Reference ke data yang akan disimpan.
     * @param index Indeks posisi yang dituju.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void insertAt(const T& value, int index) {
    
        // Pointer menuju Node baru
        Node<T>* newNode = new Node<T>(value);

        int indexCursor = 0;            // Cursor untuk menelusuri Linked List.
        Node<T>* current = head;        // Pointer menuju Node yang ditunjuk oleh cursor.

        // Jika Linked List kosong, maka elemen baru akan menjadi elemen pertama.
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Jika Linked List tidak kosong, maka cari posisi yang dituju.
        while (current != nullptr && indexCursor < index - 1) {
            current = current->next;
            indexCursor++;
        }

        // Jika posisi yang dituju tidak valid, maka hentikan proses.
        if (current == nullptr) {
            cout << "Index out of bound" << endl;
            return;
        }

        // Jika posisi yang dituju valid, maka sisipkan elemen baru.
        newNode->next = current->next;
        current->next = newNode;
    }

    /**
     * Menghapus elemen pertama yang memiliki nilai tertentu.
     * 
     * @param value Reference ke data yang akan dihapus. 
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void removeHead(const T& value) {

        // Jika Linked List kosong, maka hentikan proses.
        if (head == nullptr) {
            cout << "Linked List is empty" << endl;
            return;
        }

        // Jika elemen pertama memiliki nilai yang dicari, maka hapus elemen pertama.
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Jika elemen pertama tidak memiliki nilai yang dicari, maka cari elemen yang memiliki nilai yang dicari.
        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        // Jika elemen yang memiliki nilai yang dicari tidak ditemukan, maka hentikan proses.
        if (current->next == nullptr) {
            cout << "Value not found" << endl;
            return;
        }

        // Jika elemen yang memiliki nilai yang dicari ditemukan, maka hapus elemen tersebut.
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    /**
     * Menghapus elemen terakhir yang memiliki nilai tertentu.
     * 
     * @param value Reference ke data yang akan dihapus.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void removeTail(const T& value) {

        // Jika Linked List kosong, maka hentikan proses.
        if (head == nullptr) {
            cout << "Linked List is empty" << endl;
            return;
        }

        // Jika Linked List hanya memiliki satu elemen, maka hapus elemen tersebut.
        if (head->next == nullptr) {
            Node<T>* temp = head;
            head = nullptr;
            delete temp;
            return;
        }

        // Jika Linked List memiliki lebih dari satu elemen, maka cari elemen yang memiliki nilai yang dicari.
        Node<T>* current = head;
        while (current->next->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        // Jika elemen yang memiliki nilai yang dicari tidak ditemukan, maka hentikan proses.
        if (current->next->next == nullptr) {
            cout << "Value not found" << endl;
            return;
        }

        // Jika elemen yang memiliki nilai yang dicari ditemukan, maka hapus elemen tersebut.
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    /**
     * Menghapus elemen pada posisi tertentu.
     * 
     * @param index Indeks posisi yang dituju.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void removeAt(int index) {
         
        // Jika Linked List kosong, maka hentikan proses.
        if (head == nullptr) {
            cout << "Linked List is empty" << endl;
            return;
        }

        // Jika Linked List hanya memiliki satu elemen, maka hapus elemen tersebut.
        if (head->next == nullptr) {
            Node<T>* temp = head;
            head = nullptr;
            delete temp;
            return;
        }

        // Jika Linked List memiliki lebih dari satu elemen, maka cari elemen yang memiliki nilai yang dicari.
        Node<T>* current = head;
        int indexCursor = 0;
        while (current->next->next != nullptr && indexCursor < index - 1) {
            current = current->next;
            indexCursor++;
        }

        // Jika posisi yang dituju tidak valid, maka hentikan proses.
        if (current->next->next == nullptr) {
            cout << "Index out of bound" << endl;
            return;
        }

        // Jika posisi yang dituju valid, maka hapus elemen tersebut.
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    /**
     * Mendapatkan panjang Linked List.
     * 
     * @return Panjang Linked List.
     */
    int length() const {

        // Jika Linked List kosong, maka panjang Linked List adalah 0.
        if (head == nullptr) {
            return 0;
        }

        // Jika Linked List tidak kosong, maka hitung panjang Linked List.
        int length = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        return length;
    }

    /**
     * Mencetak seluruh elemen yang ada di dalam Linked List.
     */
    void print() const {

        // Pointer menuju Node pertama.
        Node<T>* current = head;    

        // Cetak seluruh elemen yang ada di dalam Linked List.
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
    }

    /**
     * Menghapus seluruh elemen yang ada di dalam Linked List.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    void clear() {

        // Pointer menuju Node pertama.
        Node<T>* current = head;

        // Hapus seluruh elemen yang ada di dalam Linked List.
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }

        // Atur nilai head menjadi nullptr.
        head = nullptr;
    }

    /**
     * Destruktor LinkedList yang digunakan untuk menghapus Linked List. Berguna
     * untuk mencegah memory leak atau kebocoran memori komputer.
     */
    ~LinkedList() {
        clear();
    }
};

#endif
