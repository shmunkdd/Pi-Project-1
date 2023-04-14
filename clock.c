#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "FBCurses.h"

void convertTime(int val1, colorcode_t oncolor, colorcode_t offcolor, int column){
        int count = 7;
        while(val1!=0){
                if(val1 %2 == 0){
                        setPixel(count, column, offcolor);
                }
                else{
                        setPixel(count, column, oncolor);
                }
                val1 = val1 / 2;
                count--;
        }
        for (int i = count; i >=0; i--){
                setPixel(i, column, offcolor);
        }
}
void showTime(colorcode_t oncolor, colorcode_t offcolor){
        time_t realtime;
        struct tm * timeinfo;
        time (&rawtime);
        timeinfo = localtime (&rawtime);

        binaryTime(timeinfo->tm_hour, oncolor, offcolor, 1);
        binaryTime(timeinfo->tm_min, oncolor, offcolor, 3);
        binaryTime(timeinfo->tm_sec, oncolor, offcolor, 5);
        
int main(){
        initScreen();
        colorcode_t background=initColor(COLOR_PINK);
        colorcode_t offcolor=initColor(COLOR_BLACK);
        colorcode_t oncolor=initColor(COLOR_WHITE);
        clearScreen(background);
        while(!kbhit()){
                showTime(oncolor, offcolor);
                sleep(1);
        }
        cleanupScreen();
}


        
        
