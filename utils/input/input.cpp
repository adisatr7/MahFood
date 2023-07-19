#include "input.hpp"

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