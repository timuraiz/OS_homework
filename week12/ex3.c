#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>			// in order to handle shourtcut in right sequence
int main() {

	char* dev  = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	int fd = open(dev,O_RDONLY);
	struct input_event ev1;
	bool ifPpressed = false;
	double apper_p;
	bool ifEpressed = false;
	double apper_e;
	bool ifCpressed = false;
	double apper_c;
	bool ifApressed = false;
	double apper_a;
	bool ifTpressed = false;
	double apper_t;
	clock_t start, end;
	
	FILE *file_txt;
	// New shortcut is t + a should return "The owner of this work Timur Aizatvafin!"
    //Available shortcuts: p + e, p + c + a, t + a
    printf("p + e ---> I passed the Exam!\n");
    printf("p + c + a ---> Get some cappuccino!\n");
    printf("t + a ---> The owner of this work Timur Aizatvafin!\n");
	while(1){

		read(fd, &ev1, sizeof(ev1));
		file_txt = fopen("ex3.txt", "a");
		if (ev1.type == EV_KEY && ev1.value == 1 && ev1.code == 25){		// handling p char

			ifPpressed = true;
			apper_p = clock();
		}
		if (ev1.type == EV_KEY && ev1.value == 1 && ev1.code == 18){		// handling e char

			ifEpressed = true;
			apper_e = clock();	
		}
		if (ev1.type == EV_KEY && ev1.value == 1 && ev1.code == 46){		// handling c char

			ifCpressed = true;	
			apper_c = clock();
		}
		if (ev1.type == EV_KEY && ev1.value == 1 && ev1.code == 30){		// handling a char

			ifApressed = true;
			apper_a = clock();
		}
		if (ev1.type == EV_KEY && ev1.value == 1 && ev1.code == 20){		// handling t char

			ifTpressed = true;
			apper_t = clock();
		}

		if (ifPpressed&&ifEpressed&&apper_p<=apper_e){										// print if shortcut is handled
			printf("\nI passed the Exam!\n");
			fprintf(file_txt,"I passed the Exam!\n");						// print to the file if shortcut is handled
			ifPpressed = false;
			ifEpressed = false;
		}
		if (ifPpressed&&ifCpressed&&ifApressed&&apper_p<=apper_c&&apper_c<=apper_a){							// print if shortcut is handled
			printf("\nGet some cappuccino!\n");
			fprintf(file_txt,"Get some cappuccino!\n");						// print to the file if shortcut is handled
			ifPpressed = false;
			ifApressed = false;
			ifCpressed = false;
		}
		if (ifTpressed&&ifApressed&&apper_t<=apper_a){										// print if shortcut is handled
			printf("\nThe owner of this work Timur Aizatvafin!\n");
			fprintf(file_txt,"The owner of this work Timur Aizatvafin!\n"); // print to the file if shortcut is handled
			ifTpressed = false;
			ifApressed = false;
			
		}
		fclose(file_txt);

		
	}
	close(fd);
	return 0;

}


