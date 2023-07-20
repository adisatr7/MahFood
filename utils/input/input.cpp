#include <ncurses.h>
#include "input.hpp"
#include "router.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::stoi;


string inputString(string prompt) {
    string input;
    cout << prompt;
    cin >> input;
    return input;
}


int inputInteger(string prompt) {
    
    // Ulangi terus menerus sampai input yang dimasukkan adalah bilangan bulat
    while (true) {

        // Minta input user. Utk menghindari error, input disimpan dalam string utk sementara
        string input = inputString(prompt);

        // Coba konversi string ke integer. Jika berhasil, return integer tersebut
        try {
            return stoi(input);
        } 
        
        // Jika gagal, berarti input yang dimasukkan bukan bilangan bulat. Tampilkan pesan error
        catch (invalid_argument) {
            cout << "Input yang dimasukkan bukan bilangan bulat. Silakan coba lagi." << endl;
        }
    }
}


char keyPress(string prompt) {
    cout << prompt;
    return getch();
}

// TODO: Figure out the best way to refresh the page and the best page routing structure
int menuSelect(string options[], int length, int choice) {

    // Tampilkan pilihan menu
    for (int i=0; i<length; i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }

    // Menerima input tombol keyboard dari user
    int keyPress = getch();

    // Handle input user
    switch (keyPress) {

        // Jika user menekan tombol panah atas, kurangi choice
        case KEY_UP:
            choice--;
            reloadPage();
            break;
        
        // Jika user menekan tombol panah bawah, tambahkan choice
        case KEY_DOWN:
            choice++;
            reloadPage();
            break;
        
        // Jika user menekan tombol enter, return choice
        case 10:
            return choice;
    }

    // Jika input user valid, return input tersebut
    if (choice >= 1 && choice <= length) {
        return choice;
    }

    // Jika tidak valid, tampilkan pesan error
    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
}
