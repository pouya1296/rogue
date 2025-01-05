#include <ncurses.h>


int loadlusers(data users[]) {
    FILE *file = fopen("database.dat", "rb");
    int userCount = 0;
    while ((userCount < 100 )&& (fread(&users[userCount], sizeof(data), 1, file) == 1)) {
        userCount++;
    }
    fclose(file);
    return userCount;
}

int ranksearch(data users[], int usercount, int rank){
    for(int i =0 ; i<usercount; i++){
        if(users[i].rank == rank){
            return i;
        }
    }
}
void startscore(char username[]){
    noecho();
    cbreak();
    setlocale(LC_ALL, "");
    init_pair(1, COLOR_WHITE,  COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    data user[100];
int usercount =0;
usercount =loadlusers(user);
for(int i =0; i<usercount; i++){
    for(int j =i+1; j<usercount; j++ ){
        if(user[j].totalscore > user[i].totalscore){
            data temp = user[i];
            user[i] = user[j];
            user[j] = temp;
        }
    }
}
    int height = 10;
    int width =80;
    int starty = (LINES - height) /2;
    int satartx = (COLS - width)/2;
     clear();
    WINDOW *window = newwin(height, width, starty, satartx);
    keypad(window, TRUE);
    wbkgd(window, COLOR_PAIR(1));
    int key = 0;
    int start = 0;
    int max = height -2;
    refresh();
    while (key!= 27) {

        werase(window);
        box(window, 0, 0);
        wattron(window, COLOR_PAIR(4));
         mvwprintw(window, 1, 1, "RANK      USERNAME           TOTALSCORE       GOLD      GAMES      EXPERIENCE");
         wattroff(window, COLOR_PAIR(4));

        for (int i = start ; (i < usercount) && (i<start + 5); i++) {
            if(strcmp(username, user[i].username) == 0)
            wattron(window, A_REVERSE);
            if(i<3)
            wattron(window, COLOR_PAIR(3) | A_BOLD);
            else
            wattron(window, COLOR_PAIR(2));
            mvwprintw(window, i -start + 2, 1, "%d" , i+1);
            if(i == 0){
            mvwprintw(window, i -start + 2, 12, " LEGEND %s" , user[i].username);
            mvwprintw(window,i-start +2, 11, "🏆");
            }
            else if(i == 1){
            mvwprintw(window, i -start + 2, 12, " MOSALAT %s" , user[i].username);
            mvwprintw(window,i-start +2, 11, "🥈");
            }
            else if(i ==2){
            mvwprintw(window, i -start + 2, 12, " SAVAR %s" , user[i].username);
            mvwprintw(window,i-start +2, 11, "🥉");}
            else
            mvwprintw(window, i -start + 2, 11, "%s" , user[i].username);
            mvwprintw(window, i -start + 2, 30, "%d" , user[i].totalscore);
            mvwprintw(window, i -start + 2, 47, "%d" , user[i].totalgold);
            mvwprintw(window, i -start + 2, 57, "%d" , user[i].numberofgames);
            mvwprintw(window, i -start + 2, 68, "%d" , user[i].experience);
            if(strcmp(username, user[i].username) == 0)
            wattroff(window, A_REVERSE);
            if(i<3)
            wattroff(window, COLOR_PAIR(3) | A_BOLD);
            else
            wattroff(window, COLOR_PAIR(2));
        }
        wrefresh(window);
        key = wgetch(window);
            if (key == KEY_UP){
                if (start > 0) 
                start--;}
            else if (key == KEY_DOWN){
                if ((start) < usercount) 
                start++;}
        
    }

    delwin(window);

     clear();
}