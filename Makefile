SRC		= game.cpp main.cpp my_getch.cpp

OBJ		= $(SRC:.cpp=.o)

NAME	= 2048

all: $(NAME)

$(NAME): $(OBJ)
	g++ -std=c++11 $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	g++ -std=c++11 -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
