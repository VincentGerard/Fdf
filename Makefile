.SILENT:
SRC_DIR:=./src
OBJS_DIR:=./obj
INCLUDE_DIR:=./include

SRC:= $(shell find $(SRC_DIR) -wholename "$(SRC_DIR)*.c" -exec basename \{}  \; | xargs)

OBJS:= $(SRC:.c=.o)

all: app

%.o: $(addprefix ../src/, $(basename %).c) 
	echo Creating $@
	cc -o $@ -c $(SRC_DIR)/$(basename $(@F)).c -Wall -Wextra -Werror -I $(INCLUDE_DIR)

app: $(addprefix $(OBJS_DIR)/, $(OBJS))
	echo App done!
	gcc -o app $(addprefix $(OBJS_DIR)/, $(OBJS)) -I $(INCLUDE_DIR) -Wall -Werror -Wextra 

clean:
	echo Cleaning done!
	rm -rf $(OBJS_DIR)/* -f

fclean: clean
	rm app -f

re: fclean app

