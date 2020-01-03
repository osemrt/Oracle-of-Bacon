#include "main.h"

//A utility function to clear the stdout
void clearScreen() {
	//CSI[2J clears screen,
    //CSI[H moves the cursor to top-left corner
    char *CLEAR_SCREEN = "\x1B[1J\x1B[H";
    printf("%s", CLEAR_SCREEN);
}