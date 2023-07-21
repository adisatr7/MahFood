//-----------------------------------------------------------------------------
// # Import
//-----------------------------------------------------------------------------
// Import kode-kode dari file lain yang diperlukan.
//-----------------------------------------------------------------------------

#include <iostream>                     // Input-output stream
#include "../components/Page.hpp"       // Komponen halaman aplikasi

//-----------------------------------------------------------------------------
// # Export Header
//-----------------------------------------------------------------------------
// Kode-kode di bawah ini akan di-export ke siapapun yg meng-import atau
// menggunakan file ini.
//-----------------------------------------------------------------------------

#ifndef ROUTES_HPP
#define ROUTES_HPP

//-----------------------------------------------------------------------------
// # Namespace
//-----------------------------------------------------------------------------
// Agar tidak perlu menuliskan `std::` setiap kali menggunakan fungsi dari
// library `<iostream>`.
//-----------------------------------------------------------------------------

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
Page homePage;
Page shopPage;

//-----------------------------------------------------------------------------

#endif