#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::string;

using std::unique_ptr;
using std::make_unique;
using std::move;
using std::out_of_range;

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP


/**
 * Wadah untuk menyimpan data (elemen) di dalam Linked List. Disini menggunakan 
 * template agar Node dapat menyimpan berbagai jenis data.
 */
template <typename T>
struct Node {
    T data;                     /** Data yang akan disimpan. */
    unique_ptr<Node<T>> next;   /** Pointer unik menuju Node selanjutnya. */

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
    unique_ptr<Node<T>> head;   /** Pointer menuju Node pertama di Linked List. */
    Node<T> *tail;              /** Pointer menuju Node terakhir di Linked List. */

    /**
     * Konstruktor LinkedList yang digunakan untuk membuat Linked List baru.
     */
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    /**
     * Entah kenapa, jika tidak ada konstruktor copy, smart pointer
     * tidak dapat bekerja sebagai mana mestinya. Pusing...
     */
    LinkedList(const LinkedList<T>& other) {
        head = nullptr;
        tail = nullptr;

        // Buat pointer baru yang menunjuk ke head dari Linked List.
        Node<T>* current = other.head.get();

        // Salin seluruh elemen dari Linked List lain.
        while (current != nullptr) {
            push(current->data);
            current = current->next.get();
        }
    }


    /**
     * Mendapatkan elemen pada posisi tertentu.
     * 
     * @param index Indeks posisi yang dituju.
     * 
     * @return Elemen pada index yang diberikan.
     */
    T get(int index) const {

        // Cek apakah index yang dituju valid.
        if (index < 0 || index >= length())
            cout << "Error: Index tidak valid!" << endl;

        // Cursor untuk menelusuri Linked List.
        int indexCursor = 0;

        // Pointer menuju Node yang ditunjuk oleh cursor. Dimulai dari head.
        Node<T>* current = head.get();

        // Telusuri Linked List hingga index yang dituju.
        while (current != nullptr && indexCursor < index) {
            current = current->next.get();
            indexCursor++;
        }
        return current->data;
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
        unique_ptr<Node<T>> newNode = make_unique<Node<T>>(value);

        // Jika Linked List kosong, maka elemen baru akan menjadi elemen pertama.
        if (head == nullptr) {
            head = move(newNode);
            tail = head.get();
            return;
        }

        // Jika Linked List tidak kosong, maka sisipkan elemen baru di akhir Linked List.
        tail->next = move(newNode);
        tail = tail->next.get();
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
        unique_ptr<Node<T>> newNode = make_unique<Node<T>>(value);

        int indexCursor = 0;            // Cursor untuk menelusuri Linked List.
        Node<T>* current = head;        // Pointer menuju Node yang ditunjuk oleh cursor.

        // Jika Linked List kosong, maka elemen baru akan menjadi elemen pertama.
        if (index == 0) {
            newNode->next = move(head);
            head = move(newNode);
            return;
        }

        // Jika Linked List tidak kosong, maka cari posisi yang dituju.
        while (current != nullptr && indexCursor < index - 1) {
            current = current->next.get();
            indexCursor++;
        }

        // Jika posisi yang dituju tidak valid, maka hentikan proses.
        if (current == nullptr) {
            cout << "Error: Index tidak valid!" << endl;
            return;
        }

        // Jika posisi yang dituju valid, maka sisipkan elemen baru.
        newNode->next = move(current->next);
        current->next = move(newNode);
    }

    /**
     * Menghapus elemen pertama yang memiliki nilai tertentu.
     * 
     * @param value Reference ke data yang akan dihapus. 
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    int removeFirstNode(const T& value) {

        // Jika Linked List kosong, maka hentikan proses.
        if (head == nullptr) {
            cout << "Linked List is empty" << endl;
            return -1;
        }

        // Jika elemen pertama memiliki nilai yang dicari, maka hapus elemen pertama.
        if (head->data == value) {
            head = move(head->next);
            return 0;
        }

        // Jika elemen pertama tidak memiliki nilai yang dicari, maka cari elemen yang memiliki nilai yang dicari.
        Node<T>* current = head.get();
        while (current->next != nullptr && current->next->data != value) {
            current = current->next.get();
        }

        // Jika elemen yang memiliki nilai yang dicari tidak ditemukan, maka hentikan proses.
        if (current->next == nullptr) {
            cout << "Error: Data tidak ditemukan!" << endl;
            return -1;
        }

        // Jika elemen yang memiliki nilai yang dicari ditemukan, maka hapus elemen tersebut.
        current->next = move(current->next->next);
        return 0;
    }

    /**
     * Menghapus elemen terakhir yang memiliki nilai tertentu.
     * 
     * @param value Reference ke data yang akan dihapus.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    int removeTail(const T& value) {

        // Jika Linked List kosong, maka hentikan proses.
        if (head == nullptr) {
            cout << "Error: Linked List kosong!" << endl;
            return -1;
        }

        // Jika Linked List hanya memiliki satu elemen, maka hapus elemen tersebut.
        if (head->next == nullptr && head->data == value) {
            head.reset();
            return 0;
        }

        // Jika Linked List memiliki lebih dari satu elemen, maka cari elemen yang memiliki nilai yang dicari.
        Node<T>* current = head.get();
        while (current->next != nullptr && current->next->data != value) {
            current = current->next.get();
        }

        // Jika elemen yang memiliki nilai yang dicari tidak ditemukan, maka hentikan proses.
        if (current->next == nullptr) {
            cout << "Value not found" << endl;
            return -1;
        }

        // Jika elemen yang memiliki nilai yang dicari ditemukan, maka hapus elemen tersebut.
        current->next = move(current->next->next);
        return 0;
    }

    /**
     * Menghapus elemen pada posisi tertentu.
     * 
     * @param index Indeks posisi yang dituju.
     * 
     * @return `0` jika berhasil, `-1` jika gagal.
     */
    int removeAt(int index) {
         
        // Jika Linked List kosong, maka hentikan proses.
        if (head == nullptr) {
            cout << "Error: Linked List kosong!" << endl;
            return -1;
        }

        // Jika Linked List hanya memiliki satu elemen, maka hapus elemen tersebut.
        if (head->next == nullptr) {
            head.reset();
            return 0;
        }

        // Jika Linked List memiliki lebih dari satu elemen, maka cari elemen yang memiliki nilai yang dicari.
        Node<T>* current = head.get();
        int indexCursor = 0;
        while (current->next != nullptr && indexCursor < index - 1) {
            current = current->next.get();
            indexCursor++;
        }

        // Jika posisi yang dituju tidak valid, maka hentikan proses.
        if (current->next->next == nullptr) {
            cout << "Error: Index tidak valid!" << endl;
            return -1;
        }

        // Jika posisi yang dituju valid, maka hapus elemen tersebut.
        current->next = move(current->next->next);
        return 0;
    }

    /**
     * Mendapatkan panjang Linked List.
     * 
     * @return Panjang Linked List.
     */
    int length() const {

        // Jika Linked List kosong, maka panjang Linked List adalah 0.
        if (head == nullptr)
            return 0;

        // Jika Linked List tidak kosong, maka hitung panjang Linked List.
        int length = 0;
        Node<T>* current = head.get();
        while (current != nullptr) {
            length++;
            current = current->next.get();
        }
        return length;
    }

    /**
     * Menghapus seluruh elemen yang ada di dalam Linked List.
     */
    void clear() {
        // Gunakan reset() untuk menghapus elemen yang ada di dalam Linked List.
        head.reset();
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
