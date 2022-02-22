.SILENT:
NAME=fdf
SRC_DIR:=./src
OBJS_DIR:=./obj
INCLUDE:= -Wall -Werror -Wextra -I include -I /usr/include/X11 -I lib/mlx_linux -I lib/libft/include

SRC:= $(shell find $(SRC_DIR) -wholename "$(SRC_DIR)*.c" -exec basename \{}  \; | xargs)

OBJS:= $(SRC:.c=.o)

all: $(NAME) libft.a

%.o: $(addprefix ../src/, $(basename %).c) 
	echo Creating $@
	cc -o $@ -c $(SRC_DIR)/$(basename $(@F)).c $(INCLUDE)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS)) libft.a
	echo $(NAME) done!
	gcc -o $(NAME) libft.a $(addprefix $(OBJS_DIR)/, $(OBJS)) $(INCLUDE) -Llib/mlx_linux -L . -lft -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

libft.a:
	cd lib/libft/ && $(MAKE)
	cp lib/libft/libft.a .
	echo Libft.a done!

clean:
	echo Cleaning done!
	rm -rf $(OBJS_DIR)/* -f

fclean: clean
	rm fdf -f

re: fclean fdf

run: all
	echo "Run=>"
	./fdf
