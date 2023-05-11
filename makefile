prog:image.o level1.o texte.o music.o main.o 
	gcc image.o level1.o texte.o music.o main.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer


main.o:main.c 
	gcc -c main.c -g 
texte.o:texte.c 
	gcc -c texte.c -g 
level1.o:level1.c 
	gcc -c level1.c -g 
image.o:image.c 
	gcc -c image.c -g 
music.o:music.c 
	gcc -c music.c -g 

