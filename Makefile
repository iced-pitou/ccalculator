.PHONY: all compile run clean

CC := gcc 
MAIN := ccalculator
SRCS := *.c
GTK_FLGS := $$(pkg-config --cflags gtk4)
GTK_LBS := $$(pkg-config --libs gtk4)

all: compile run clean # default

compile:
	@$(CC) $(GTK_FLGS) -o $(MAIN) $(SRCS) $(GTK_LBS)

run:
	@./$(MAIN)

clean:
	@rm $(MAIN)
