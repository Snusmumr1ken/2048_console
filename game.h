#ifndef GAME_H
#define GAME_H
#include <iomanip>

using namespace std;

class Game
{
private:
   unsigned short   game_field[4][4];
   string  run      = "\033[1;32m> Run a game\033[0m";
   string  help     = "\033[1;32m Help\033[0m";
   string  credits  = "\033[1;32m Credits\033[0m";
   string  exit     = "\033[1;32m Exit\033[0m";

   void     show_game_field();
   void     generate_game_field();
   void     print_elem(unsigned y, unsigned x);
   bool     check_if_won();
   bool     check_if_lose();
   int      generate_coor();
   void     move_down();
   void     move_up();
   void     move_left();
   void     move_right();
   void     move();
   void     add_new_elem();
   void     game();

public:
    void    main_menu();
};

#endif // GAME_H
