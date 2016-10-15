#include <curses.h>

int main() 
{ 
initscr(); 
keypad(stdscr, true); 
noecho(); 
raw(); 

char tempznak = 0; 
while (tempznak != 27) 
{ 
    tempznak = getch(); 
    printw("[%d] ", tempznak); 
    refresh(); 
} 
return 0; 
}