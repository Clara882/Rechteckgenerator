#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<unistd.h>
#include"Funktionsgenerator.h"

void help(void) {
	printf("Version: 1.0 \n");
	printf("Autor: Clara Stute\n");
	printf("Mit diesem Programm können die Funktionswerte für einen Rechteckgenerator ausgegeben werden\n");
	printf("Amplitude, Periodenanzahl und Periodendauer können eingestellt werden\n");
	printf("Es können nur ganze Zahlen Ein- und Ausgegeben werden\n");
	printf("Optionen:\n");
	printf("-h Hilfe \n");
	printf("-f zum Erstellen einer Rechteckfunktion\n");
}

int main (int argc, char *argv[]) {
		int max = 1, min;
		int x, n = 3, wiederholungen = 4, a, i;
		int zwischenspeicher = 0, nummer = 0;
		int option;
		int Rechteckfunktion[50];

		while ((option = getopt(argc, argv, "h, f")) != -1) {
			switch (option) {
				case 'h' :
					help();
					break;
				case 'f' :
					printf("Die Werte werden in der Datei output_stream.txt gespeichert\n");
					FILE *output_stream;
					output_stream = fopen ("output_stream.txt", "w");
					
					if (NULL == output_stream){
						printf("Error! Datei output_stream.txt nicht gefunden\n");
						exit(2);
					}
					fprintf(output_stream, "Hier werden die Werte für den Rechteckgenerator ausgegeben:\n");
					for(a=1;a<=wiederholungen;a++){
						x = 0;
						nummer = zwischenspeicher+1;
						for(i=0;i<=n+2;i++){
							Rechteckfunktion[i]=Rechteckgenerator(max,min,x);
							fprintf(output_stream, "%i; ",nummer);
							zwischenspeicher=nummer;
							fprintf(output_stream, "%i; \n",Rechteckfunktion[i]);
							nummer++;
							if(i==n/2+1){
							x=1;
							}
						}
					}						
				fclose (output_stream);
			}
		}
}
