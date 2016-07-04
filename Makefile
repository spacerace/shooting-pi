all:
	gcc -I./ -O3 -Wall -lm shooter.c random.c -o shooting-pi
