application_static: staticlib
		gcc-10 main.c -lFunktionsgenerator -o main.elf -lm

staticlib:
		gcc-10 Funktionsgenerator.c -c
		ar -crs libFunktionsgenerator.a Funktionsgenerator.o
		sudo cp Funktionsgenerator.h /usr/include
		sudo cp libFunktionsgenerator.a /usr/li
