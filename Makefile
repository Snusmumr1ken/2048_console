######################################################
#                                                    #
#         Makefile is created by anyvchyk            #
#            for 2048_console  project               #
#                                                    #
######################################################

SRC		= game.cpp main.cpp my_getch.cpp

OBJ		= $(SRC:.cpp=.o)

NAME		= 2048

all: $(NAME)

$(NAME): $(OBJ)
	@clear && g++ $(OBJ) -o $(NAME) && clear && ./2048

$(OBJ): $(SRC)
	@g++ -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
