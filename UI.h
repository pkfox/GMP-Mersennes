#ifndef UI_H
#define UI_H

#include <string>
#include <locale.h>
#include <ncursesw/ncurses.h>

namespace UI {
    void Init();
    void Cleanup();
    void PrintMessage(const std::string& msg, int row, int col);
}

#endif
