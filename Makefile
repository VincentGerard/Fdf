.SILENT:
NAME=fdf
SRC_DIR:=./src
OBJS_DIR:=./obj
INCLUDE_DIR:=./include
INCLUDE:= -I include -I /usr/include/X11 -I lib/mlx_linux -I lib/libft/include

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
	rm -rf $(OBJS_DIR)/*

fclean: clean
	rm -f fdf
	rm -f libft.a

re: fclean fdf

run: all
	echo "Run=>"
	./fdf maps/test_maps/42.fdf

leak: all
	valgrind --track-origins=yes --leak-check=yes ./fdf maps/test_maps/42.fdf

norme:
	norminette $(SRC_DIR) $(INCLUDE_DIR)