#include "UI.h"

namespace UI {
    void Init() {
        setlocale(LC_ALL, "");
        initscr();
        start_color();
        use_default_colors();
        noecho();
        curs_set(0);
    }

    void Cleanup() {
        getch(); // Wait for user keypress before exit
        endwin();
    }

    void PrintMessage(const std::string& msg, int row, int col) {
        mvprintw(row, col, "%s", msg.c_str());
        refresh();
    }
}