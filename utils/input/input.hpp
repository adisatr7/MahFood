#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>

using std::string;


/**
 * Meminta input string dari user.
 * 
 * @param prompt Pesan yang akan ditampilkan sebelum meminta input dari user.
 * 
 * @return string yang dimasukkan user.
 */
string inputString(string prompt);

/**
 * Meminta input bilangan bulat dari user. Jika input yang dimasukkan bukan integer, maka akan
 * meminta input ulang dari user.
 * 
 * @param prompt Pesan yang akan ditampilkan sebelum meminta input dari user.
 * 
 * @return integer yang dimasukkan user.
 */
int inputInteger(string prompt);

#endif
