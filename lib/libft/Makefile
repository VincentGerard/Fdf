.SILENT:
NAME:=libft.a
SRC_DIR:=./src
OBJS_DIR:=./obj
INCLUDE:=-I ./include

SRC:= $(shell find $(SRC_DIR) -wholename "$(SRC_DIR)*.c" -exec basename \{}  \; | xargs)

OBJS:= $(SRC:.c=.o)

OBJS_WITH_PATH:= $(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME)

%.o: $(addprefix ../src/, $(basename %).c) 
	echo Creating $@
	cc -o $@ -c $(SRC_DIR)/$(basename $(@F)).c -Wall -Wextra $(INCLUDE)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS))
	echo $(NAME) done!
	ar r $(NAME) $(OBJS_WITH_PATH)

clean:
	echo Cleaning done!
	rm -rf $(OBJS_DIR)/* -f

fclean: clean
	rm fdf -f

re: fclean fdf
