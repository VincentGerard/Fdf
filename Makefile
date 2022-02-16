.SILENT:
SRC_DIR:=./src
OBJS_DIR:=./obj
INCLUDE_DIR:=./include -I /usr/include/X11 -I mlx_linux

SRC:= $(shell find $(SRC_DIR) -wholename "$(SRC_DIR)*.c" -exec basename \{}  \; | xargs)

OBJS:= $(SRC:.c=.o)

all: app

%.o: $(addprefix ../src/, $(basename %).c) 
	echo Creating $@
	cc -o $@ -c $(SRC_DIR)/$(basename $(@F)).c -Wall -Wextra  -I $(INCLUDE_DIR)

app: $(addprefix $(OBJS_DIR)/, $(OBJS))
	echo App done!
	gcc -o app $(addprefix $(OBJS_DIR)/, $(OBJS)) -I $(INCLUDE_DIR) -Wall  -Wextra -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

clean:
	echo Cleaning done!
	rm -rf $(OBJS_DIR)/* -f

fclean: clean
	rm app -f

re: fclean app

run: all
	echo "Run=>"
	./app
