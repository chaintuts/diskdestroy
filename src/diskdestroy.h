/* This file contains includes and function prototypes for the disk destroyer
*
* Author: Josh McIntyre
*/
#include <stdio.h>
#include <stdlib.h>

// Update the progress indicator every 10 Megabytes destroyed
const int PROGRESS_INDICATOR_BYTES = 10000000; 
const int MEGABYTE = 1000000;

// Function prototype for destroy
void destroy(char* disk_path);
