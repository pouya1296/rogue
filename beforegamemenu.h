#include "ncurses.h"
#include "setting.h"
#include "game.h"
#include "profile.h"

void startbeforegame(char username[100]){
    int color = 1;
    int music = 0;
    int difficulty =0;
 while (1)
    {
         clear();
         curs_set(false);
         noecho();
    int boxheight = 25;
    int boxwidth = 80;
    int y_box = (LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;
    init_pair(2,COLOR_WHITE, COLOR_BLUE);
    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
    box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    keypad(stdscr, true);
    refresh();
    wrefresh(window);
    char names[6][20] = {"New game", "Load game", "Scoreboard", "Setting new game", "profile", "Quit"};
    int choice =0;
    while(1){
          curs_set(false);
         noecho();
     box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    keypad(stdscr, true);
    refresh();
    wrefresh(window);
        for(int i =0; i<6; i++){
            if(i == choice){
                wattron(window, A_REVERSE);
            }
            mvwprintw(window, 1 + i, 3,"%s", names[i]);
            if(i == choice){
                wattroff(window, A_REVERSE);
            }
            
        }
        wrefresh(window);

        int key = getch();
        if(key == KEY_UP){
            if(choice != 0){
                choice --;
            }
            else
            choice =5;
        }
         if(key == KEY_DOWN){
            if(choice != 5){
                choice ++;
            }
            else
            choice =0;
        }
        else if(key == 10){
            break;
        }

    }
    if(choice == 0){
       startgame(difficulty, color, music, username, 0); 
       curs_set(false);
    }
     else if(choice == 1){
        startloadedgame(username);
        curs_set(false);
    }
    else if(choice == 2){
    }
    else if(choice == 3){
      startsetting(&difficulty, &color, &music);    }
    else if(choice == 4){
      startprofile(username);
    }
    else if(choice == 5){
      break;
    }
    clear();
    }}