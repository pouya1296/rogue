    #include "ncurses.h"
    
    int startchangecolor(){
    while (1)
    {
         clear();
         curs_set(false);
         noecho();
    int boxheight = 25;
    int boxwidth = 80;
    int y_box = (LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;
    init_pair(2,COLOR_WHITE, COLOR_RED);
    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
    box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    keypad(stdscr, true);
    refresh();
    wrefresh(window);
    char names[6][20] = {"RED", "BLUE", "GREEN"};
    int choice =0;
    while(1){
 
        for(int i =0; i<3; i++){
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
            choice =2;
        }
         if(key == KEY_DOWN){
            if(choice != 2){
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
       return 1;
    }
     else if(choice == 1){
        return 2;
    }
    else if(choice == 2){
        return 3;   
    }
    clear();
    }}