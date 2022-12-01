NAME = libmx.a

all: install

install: $(NAME)

$(NAME): objects
	ar -rcs $(NAME) obj/*.o
	ranlib $(NAME)

objects:
	mkdir -p obj
	clang -std=c11 -Wall -Werror -Wextra -Wpedantic -c src/*.c -I inc/
	mv *.o obj/
	
uninstall:
	rm -rf $(NAME)
	rm -rfd obj

reinstall:
	make uninstall
	make

clean:
	rm -rfd obj
