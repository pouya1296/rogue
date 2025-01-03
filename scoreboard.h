#include <ncurses.h>


int loadllusers(data users[]) {
    FILE *file = fopen("database.dat", "rb");
    int userCount = 0;
    while ((userCount < 100 )&& (fread(&users[userCount], sizeof(data), 1, file) == 1)) {
        userCount++;
    }
    fclose(file);
    return userCount;
}

void startscore(char username[]){
       clear();
    curs_set(true);
    cbreak();
data user[100];
int usercount =0;
usercount =loadllusers(user);
for(int i =0; i<usercount; i++){
    mvprintw(i + 2, 0, "username:%s totalscore:%d totalgold:%d experience:%d", user[i].username, user[i].totalscore, user[i].totalscore/10, user[i].experience );
}
refresh();
getch();
  clear();
  nocbreak();
}