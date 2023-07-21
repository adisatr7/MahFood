//============================================================================
// > Global Variables
//----------------------------------------------------------------------------
// Berisi variabel-variabel global yang dapat diakses oleh aplikasi.
//============================================================================

#include "../models/User.hpp"

#ifndef GLOBAL_STATES_HPP
#define GLOBAL_STATES_HPP


namespace global {

    /**
     * Menyimpan status apakah aplikasi masih berjalan atau tidak.
     */
    bool keepRunning = true;

    /**
     * User yang sedang login.
     */
    User currentUser = User("", "", "");
}

#endif