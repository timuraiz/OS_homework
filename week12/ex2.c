#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main() {

	char* dev  = "/dev/input/by-path/platform-i8042-serio-0-event-kbd"; 
	int fd = open(dev,O_RDONLY);		// open directory /dev/input/by-path/platform-i8042-serio-0-event-kbd in 'r' format
	struct input_event ev1;
	FILE *file_txt;						// pointer to ex2.txt
	while(1){

		read(fd, &ev1, sizeof(ev1));
		file_txt = fopen("ex2.txt", "a");	// open ex2.txt in 'a' format
		if (ev1.type == EV_KEY && ev1.value == 1){  // handling pressing

			fprintf(file_txt,"PRESSED 0x%04x (%i).\n",ev1.code,ev1.code);	
		}
		if (ev1.type == EV_KEY && ev1.value == 0){	// handling realising
			fprintf(file_txt,"REALESED 0x%04x (%i).\n",ev1.code,ev1.code);
		}
		fclose(file_txt);		// closing ex2.txt
	}
	close(fd);
	return 0;

}


