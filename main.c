
#include <ncurses.h>
#include "menu.h"
#include <locale.h>



int main(){

initscr();
curs_set(false);
start_color();
startmenu();


endwin();
    return 0;
}
