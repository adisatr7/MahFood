//=============================================================================
// > Config
//-----------------------------------------------------------------------------
// Ini adalah file konfigurasi yang berisi konstanta-konstanta yang digunakan
// dalam program. Konstanta-konstanta ini dapat diubah sesuai kebutuhan, dan
// program akan menyesuaikan diri dengan nilai konstanta yang Anda atur.
//=============================================================================

//-----------------------------------------------------------------------------
// # Import
//-----------------------------------------------------------------------------
// Import kode-kode dari file lain yang diperlukan.
//-----------------------------------------------------------------------------

#include <iostream>
#include "./global/styles.hpp"

using std::string;

//-----------------------------------------------------------------------------
// # Export header
//-----------------------------------------------------------------------------
// Kode-kode di bawah ini akan di-export ke siapapun yg meng-import atau
// menggunakan file ini.
//-----------------------------------------------------------------------------

#ifndef CONFIG_HPP
#define CONFIG_HPP

//-----------------------------------------------------------------------------
// # Konfigurasi
//-----------------------------------------------------------------------------
// Ubah sesuai kebutuhan.
//-----------------------------------------------------------------------------

string RESTAURANT_NAME = "MahFood";
string OWNER_NAME = "Mahfud";

namespace STYLE {
    const string RESET = "\033[0m";
    const string HIGHLIGHT = COLOR::GREEN + FONT::BOLD + FONT::UNDERLINE;
}

//-----------------------------------------------------------------------------
// # Penutup
//-----------------------------------------------------------------------------

#endif

//-----------------------------------------------------------------------------