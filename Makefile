FILES = \
	src/LibX.cpp \
	src/Vector2d.cpp \
	main.cpp

OBJ_DIR = _OUT/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.cpp=.o))
DEPS = $(OBJ:.o=.d)

# -Wall -Wextra -Werror

DEPFLAGS = -MMD -MF $(@:.o=.d)
CFLAGS = -I include -std=c++98
LibX = -framework opengl -framework Appkit -lmlx

NAME = a.out

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(OBJ) $(LibX) -o $(NAME)

$(OBJ): $(OBJ_DIR)%.o:%.cpp
	@mkdir -p $(dir $@)
	g++ $(CFLAGS) -c $(@:$(OBJ_DIR)%.o=%.cpp) $(DEPFLAGS) -o $(@)

-include $(DEPS)

clean:
	rm -rf _OUT

fclean: clean
	rm -f $(NAME)

re: fclean all
