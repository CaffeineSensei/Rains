#pragma once



namespace tc{   //terminal control;
    
    void move_to(int x,int y);
    void set_fore_color(int g);
    void set_back_color(int id);
    void clean_screen();
    void reset_color();
    void hide_cursor();
    void show_cursor();
    void set_screen(int x,int y);
}