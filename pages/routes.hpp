#ifndef ROUTES_HPP
#define ROUTES_HPP

//-----------------------------------------------------------------------------
// # Import
//-----------------------------------------------------------------------------
// Import kode-kode dari file lain yang diperlukan.
//-----------------------------------------------------------------------------

#include <iostream>                     // Input-output stream
#include "../components/Page.hpp"       // Komponen halaman aplikasi

using std::cout;
using std::endl;
using std::string;

//-----------------------------------------------------------------------------
// # Deklarasi komponen halaman
//-----------------------------------------------------------------------------
// Deklarasi objek halaman yang akan digunakan di aplikasi disini, lalu
// buat file .hpp baru untuk mengimplementasikan halaman tersebut.
//-----------------------------------------------------------------------------

Page welcomePage;
Page loginPage;
Page registerPage;
Page mainMenuPage;

//-----------------------------------------------------------------------------

#endif