# This make file illustrates some more advance make file techniques
# At the bottom of the files are comments that list the techniques and where to
# learn more about them

# By uncommenting the next line the -DVERBOSE will be added to all the compile
# commands see ccalc.h for why you might want to do this
#CFLAGS=-DVERBOSE

# by default compile with debug information.  to turn off comment out 
DEBUG=-g

# optimization level : default no optizations to make debugging easier
OPT=-O0

# by adding a file to this variable it will automatically get compile and its object
# file will get linked into binaries
src=game.c player_info.c player.c faculty.c grad.c ugrad.c zombie.c 

# have make generate the names of all the object files from the list of source files
objs=$(src:%.c=%.o)

# define all the targets we want to build by default
PGMS=game

# list of phony targets that don't really create files but let us do things like "make clean"
.PHONY: clean all

# the first  target is the default one that make will try and execute 
# by making it a phony that lists all the binaries as dependencies we will
# by default when executing make with no arguments build all the binaries
all: ${PGMS}

# pattern rule to compile c files to produce the corresponding .o file
%.o: %.c
	gcc -c ${CFLAGS} ${OPT} ${DEBUG} $< -o $@

# one rule per binary that links all the calculator objects along with the data objects
# to produce the binary.  We let gcc call the linker for us as it will add all the right
# default libaries to the linker command
game: ${objs} 
	gcc ${CFLAGS} ${OPT} ${DEBUG} $^ -o $@
clean:
	rm -f $(wildcard ${PGMS} *.o)

