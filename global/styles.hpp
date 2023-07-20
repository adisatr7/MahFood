//============================================================================
// > Global Styles
//----------------------------------------------------------------------------
// Berisi konstanta escape code untuk menghias output di terminal. 
//============================================================================

#ifndef GLOBAL_STYLES_HPP
#define GLOBAL_STYLES_HPP

#include <iostream>

using std::string;


namespace BG_COLOR {
    const string DEFAULT = "\u001b[49m";

    const string BLACK = "\u001b[40m";
    const string RED = "\u001b[41m";
    const string GREEN = "\u001b[42m";
    const string YELLOW = "\u001b[43m";
    const string BLUE = "\u001b[44m";
    const string MAGENTA = "\u001b[45m";
    const string CYAN = "\u001b[46m";
    const string WHITE = "\u001b[47m";

    const string BRIGHT_BLACK = "\u001b[100m";
    const string BRIGHT_RED = "\u001b[101m";
    const string BRIGHT_GREEN = "\u001b[102m";
    const string BRIGHT_YELLOW = "\u001b[103m";
    const string BRIGHT_BLUE = "\u001b[104m";
    const string BRIGHT_MAGENTA = "\u001b[105m";
    const string BRIGHT_CYAN = "\u001b[106m";
    const string BRIGHT_WHITE = "\u001b[107m";
}

namespace COLOR {
    const string DEFAULT = "\u001b[0m";

    const string BLACK = "\u001b[30m";
    const string RED = "\u001b[31m";
    const string GREEN = "\u001b[32m";
    const string YELLOW = "\u001b[33m";
    const string BLUE = "\u001b[34m";
    const string MAGENTA = "\u001b[35m";
    const string CYAN = "\u001b[36m";
    const string WHITE = "\u001b[37m";
}

namespace FONT {
    const string DEFAULT = "\u001b[0m";

    const string BOLD = "\u001b[1m";
    const string UNDERLINE = "\u001b[4m";
    const string BLINK = "\u001b[5m";
    const string REVERSE = "\u001b[7m";
}

#endif