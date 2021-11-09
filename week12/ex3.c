#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
int main() {

	char* dev  = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	int fd = open(dev,O_RDONLY);
	struct input_event ev1;
	bool ifPpressed = false;
	bool ifEpressed = false;
	bool ifCpressed = false;
	bool ifApressed = false;
	bool ifTpressed = false;
	FILE *file_txt;
	// New shortcut is t + a or a + t should return "The owner of this work Timur Aizatvafin!"
	while(1){

		read(fd, &ev1, sizeof(ev1));
		file_txt = fopen("ex3.txt", "a");
		if (ev1.type == EV_KEY && ev1.value == 1 && ev1.code == 25){		// handling p char

			ifPpressed = true;	
		}
		if (ev1.type == EV_KEY && ev1.value == 1 && ev1.code == 18){		// handling e char

			ifEpressed = true;	
		}
		if (ev1.type == EV_KEY && ev1.value == 1 && ev1.code == 46){		// handling c char

			ifCpressed = true;	
		}
		if (ev1.type == EV_KEY && ev1.value == 1 && ev1.code == 30){		// handling a char

			ifApressed = true;	
		}
		if (ev1.type == EV_KEY && ev1.value == 1 && ev1.code == 20){		// handling t char

			ifTpressed = true;	
		}

		if (ifPpressed&&ifEpressed){										// print if shortcut is handled
			printf("I passed the Exam!\n");
			fprintf(file_txt,"I passed the Exam!\n");						// print to the file if shortcut is handled
			ifPpressed = false;
			ifEpressed = false;
		}
		if (ifPpressed&&ifCpressed&&ifApressed){							// print if shortcut is handled
			printf("Get some cappuccino!\n");
			fprintf(file_txt,"Get some cappuccino!\n");						// print to the file if shortcut is handled
			ifPpressed = false;
			ifApressed = false;
			ifCpressed = false;
		}
		if (ifTpressed&&ifApressed){										// print if shortcut is handled
			printf("The owner of this work Timur Aizatvafin!\n");
			fprintf(file_txt,"The owner of this work Timur Aizatvafin!\n"); // print to the file if shortcut is handled
			ifTpressed = false;
			ifApressed = false;
			
		}
		fclose(file_txt);

		
	}
	close(fd);
	return 0;

}


