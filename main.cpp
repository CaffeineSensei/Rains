#include <iostream>
#include <thread>
#include "terminal.h"
#include "util.h"
#include <stdlib.h>
#include <chrono>

#define WIDTH 102
#define HEIGHT 39

using namespace std::chrono_literals;

int point[WIDTH][3] = {0};

char createCh()
{
    char temp = 0;
    int flag = rand() % 2;
    if (flag == 0)
    {
        temp = rand() % 6 + 'A';
    }
    else
    {
        temp = rand() % 10 + '0';
    }
    return temp;
}

void init()
{
    tc::set_screen(HEIGHT,WIDTH*2);
    tc::hide_cursor();
    for (int i = 0; i < WIDTH; i++)
    {
        point[i][0] = 2 * i + 1;
        point[i][1] = rand() % HEIGHT;
        point[i][2] = 1 + rand()%3;
    }
    tc::clean_screen();
}

int loop()
{
    
    while (true)
    {
        for (int k = 0; k < HEIGHT; k++)
        {
            for (int i = 0; i < WIDTH; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    tc::move_to(point[i][0], (point[i][1] + k*(point[i][2]) + j) % HEIGHT);
                   
                    if (j == 6)
                    {
                        tc::set_fore_color(82);
                    }
                    
                    else if (j == 7)
                    {
                        tc::set_fore_color(15);
                        //tc::set_back_color(15);
                    }
                    else
                    {
                        tc::set_fore_color(6 * j + 16);
                    }
                    std::cout << createCh();
                    tc::reset_color();
                    if (shouldExit)
                    {
                        return 0;
                    }
                    
                }
            }
            std::cout << std::flush;
            std::this_thread::sleep_for(120ms);
            tc::clean_screen();
        } 
    }
}

void exit()
{
    tc::set_screen(24,80);
    tc::move_to(1,1);
    tc::show_cursor();
    tc::reset_color();
    tc::clean_screen();
}

int main()
{
    std::thread exitThred(ut::exitLoop);
    init();
    loop();
    exitThred.join();
    exit();

    return 0;
}