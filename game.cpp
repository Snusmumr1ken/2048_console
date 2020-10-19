#include "game.h"
#include "my_getch.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void    Game::main_menu()
{
    int a;
    My_getch get;
    
    cout << "\033[2J\033[1;1H";
    cout << "\033[1;31mWelcome to console 2048!\033[0m" << endl << endl;
    cout << run << endl;
    cout << help << endl;
    cout << credits << endl;
    cout << exit << endl;

    a = get.getch();
    cout << a << endl;
    if (a == 66)
    {
        if      (run[7] == '>')
        {
            run     = "\033[1;32m Run a game\033[0m";
            help    = "\033[1;32m> Help\033[0m";
        }
        else if (help[7] == '>')
        {
            help    = "\033[1;32m Help\033[0m";
            credits = "\033[1;32m> Credits\033[0m";
        }
        else if (credits[7] == '>')
        {
            credits = "\033[1;32m Credits\033[0m";
            exit    = "\033[1;32m> Exit\033[0m";
        }
    }
    else if (a == 65)
    {
        if (help[7] == '>')
        {
            help    = "\033[1;32m Help\033[0m";
            run     = "\033[1;32m> Run a game\033[0m";
        }
        else if (credits[7] == '>')
        {
            credits = "\033[1;32m Credits\033[0m";
            help    = "\033[1;32m> Help\033[0m";
        }
        else if (exit[7] == '>')
        {
            credits = "\033[1;32m> Credits\033[0m";
            exit    = "\033[1;32m Exit\033[0m";
        }
    }
    else if (a == 10)
    {
        if (run[7] == '>')
        {
            cout << "\033[2J\033[1;1H";
            game();
        }
        else if (exit[7] == '>')
        {
            cout << "\033[2J\033[1;1H";
            cout << "\033[1;32mGood luck:)\nBye!\033[0m\n";
            return ;
        }
        else if (credits[7] == '>')
        {
            cout << "\033[2J\033[1;1H";
            cout << "\033[1;31mCreated by Andrii Nyvchyk in 2018\033[0m" << endl;
            cout << "\033[1;4;32mandrii.nyvchyk@gmail.com\n\033[0m" << endl << endl;
            a = get.getch();
        }
        else if (help[7] == '>')
        {
            cout << "\033[2J\033[1;1H";
            cout << "This is console version of the popular game 2048!\n";
            cout << "The game's objective is to slide numbered tiles\n";
            cout << "on a grid to combine them ";
            cout << "to create a tile with the number 2048.\n\n";
            cout << "You can move by using arrows on your keyboard.\nGood luck!\n\n\n";
            a = get.getch();
        }
    }
    cout << "\033[2J\033[1;1H";
    main_menu();
}

void    Game::move()
{
    My_getch get;
    int a;

    a = get.getch();
    if (a == 66)
        move_down();
    else if (a == 68)
        move_left();
    else if (a == 67)
        move_right();
    else if (a == 65)
        move_up();
    else
        move();
}

void    Game::game()
{
    My_getch    get;
    int         a;

    generate_game_field();
    while (1)
    {
        show_game_field();
        move();

        if (check_if_won() || check_if_lose())
        {
            a = get.getch();
            break;
        }
        add_new_elem();
    }
}

void    Game::add_new_elem()
{
    int x;
    int y;

    srand(time(NULL));
    x = rand() % 4;
    y = rand() % 4;
    while (game_field[x][y] != 0)
    {
        x = rand() % 4;
        y = rand() % 4;
    }
    if (rand() % 4 == 1)
        game_field[x][y] = 4;
    else
        game_field[x][y] = 2;
}

void    Game::move_down()
{
    cout << "\033[2J\033[1;1H";
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            if (i < 3 && game_field[i][j] != 0)
            {
                int k = i;
                while (k < 3)
                {
                    if (game_field[k + 1][j] == 0)
                    {
                        game_field[k + 1][j] = game_field[k][j];
                        game_field[k][j] = 0;
                    }
                    else if (game_field[k + 1][j] == game_field[k][j])
                    {
                        game_field[k][j] = 0;
                        game_field[k + 1][j] *= 2;
                    }
                    k++;
                }
            }
        }
    }
}

void    Game::move_up()
{
    cout << "\033[2J\033[1;1H";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i > 0 && game_field[i][j] != 0)
            {
                int k = i;
                while (k > 0)
                {
                    if (game_field[k - 1][j] == 0)
                    {
                        game_field[k - 1][j] = game_field[k][j];
                        game_field[k][j] = 0;
                    }
                    else if (game_field[k - 1][j] == game_field[k][j])
                    {
                        game_field[k][j] = 0;
                        game_field[k - 1][j] *= 2;
                    }
                    k--;
                }
            }
        }
    }
}

void    Game::move_left()
{
    cout << "\033[2J\033[1;1H";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j > 0 && game_field[i][j] != 0)
            {
                int k = j;
                while (k > 0)
                {
                    if (game_field[i][k - 1] == 0)
                    {
                        game_field[i][k - 1] = game_field[i][k];
                        game_field[i][k] = 0;
                    }
                    else if (game_field[i][k - 1] == game_field[i][k])
                    {
                        game_field[i][k] = 0;
                        game_field[i][k - 1] *= 2;
                    }
                    k--;
                }
            }
        }
    }
}

void    Game::move_right()
{
    cout << "\033[2J\033[1;1H";
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            if (j < 3 && game_field[i][j] != 0)
            {
                int k = j;
                while (k < 3)
                {
                    if (game_field[i][k + 1] == 0)
                    {
                        game_field[i][k + 1] = game_field[i][k];
                        game_field[i][k] = 0;
                    }
                    else if (game_field[i][k + 1] == game_field[i][k])
                    {
                        game_field[i][k] = 0;
                        game_field[i][k + 1] *= 2;
                    }
                    k++;
                }
            }
        }
    }
}

void    Game::generate_game_field()
{
    int x;
    int y;

    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            game_field[i][j] = 0;
    }

    x = rand() % 4;
    y = rand() % 4;
    game_field[y][x] = rand() % 10;
    if (game_field[y][x] == 1)
        game_field[y][x] = 4;
    else
        game_field[y][x] = 2;

    do
    {
        x = rand() % 4;
        y = rand() % 4;
    } while (game_field[y][x] != 0);
    game_field[y][x] = rand() % 10;
    if (game_field[y][x] == 1)
        game_field[y][x] = 4;
    else
        game_field[y][x] = 2;
}

void    print_line()
{
    cout << "\033[1;30m|\033[0m";
}

void    Game::print_elem(unsigned y, unsigned x) //ANSI codes for true men
{
    if (game_field[y][x] == 2 || game_field[y][x] == 4 || game_field[y][x] == 0)
        cout << "\033[1;31m" << setw(4) << game_field[y][x] << "\033[0m";
    else if (game_field[y][x] == 8 || game_field[y][x] == 16)
        cout << "\033[1;32m" << setw(4) << game_field[y][x] << "\033[0m";
    else if (game_field[y][x] == 32 || game_field[y][x] == 64)
        cout << "\033[1;33m" << setw(4) << game_field[y][x] << "\033[0m";
    else if (game_field[y][x] == 128 || game_field[y][x] == 256)
        cout << "\033[1;34m" << setw(4) << game_field[y][x] << "\033[0m";
    else if (game_field[y][x] == 512)
        cout << "\033[1;35m" << setw(4) << game_field[y][x] << "\033[0m";
    else if (game_field[y][x] == 1024)
        cout << "\033[1;36m" << setw(4) << game_field[y][x] << "\033[0m";
    else if (game_field[y][x] == 2048)
        cout << "\033[1;37" << setw(4) << game_field[y][x] << "\033[0m";
}

void    Game::show_game_field()
{
    cout << " ";
    cout << "\033[1;4;30m---- ---- ---- ----\033[0m\n";
    for (int i = 0; i < 4; i++)
    {
        print_line();
        for (int j = 0; j < 4; j++)
        {
            print_elem(i, j);
            print_line();
        }
        cout << endl;
    }
    cout << " ";
    cout << "\033[1;4;30m---- ---- ---- ----\033[0m\n";
}

bool    Game::check_if_won()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (game_field[i][j] == 2048)
            {
                cout << "\033[1;33mMy congrats! You have won :)\033[0m\n";
                return (1);
            }
        }
    }
    return (0);
}

bool    Game::check_if_lose()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (game_field[i][j] == 0)
                return (0);
        }
    }
    cout << "\033[1;33mSorry, you have lost :(\033[0m" << endl;
    return (1);
}
