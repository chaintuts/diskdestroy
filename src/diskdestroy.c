/* This is a simple disk-destroy program for UNIX-based systems
*
* Author: Josh McIntyre
*/
#include "diskdestroy.h"

// The main entry point for the program
int main(int argc, char* argv[])
{
	// Print usage
	if (argc != 2)
	{
		printf("Usage: ./diskdestroy <disk path>\n");
		printf("Ex: ./diskdestroy /dev/sdb\n");
		return 1;
	}

	// Call data destruction function with the user specified disk path
	destroy(argv[1]);

	return 0;
}

// Destroys data on the entire given disk path by zero-filling
void destroy(char* disk_path)
{
	// Open the disk file path for writing
	FILE* disk;
	disk = fopen(disk_path, "wb");
	if (disk == NULL)
	{
		printf("Unable to access disk for destruction. Terminating.\n");
		return;
	}

	// Get the size of the disk in bytes
	fseek(disk, 0L, SEEK_END);
	long int size = ftell(disk);
	rewind(disk);

	// Confirm destruction
	printf("Selected disk %s is %ld Megabytes\n", disk_path, (size / MEGABYTE));
	printf("Are you sure you wish to destroy this disk?\n");
	printf("All data will be PERMANENTLY UNRECOVERABLE\n");
	printf("Confirm destruction: [y/n]");

	char confirm;
	scanf("%c", &confirm);

	if (confirm != 'y')
	{
		printf("Destruction aborted!\n");
		return;
	}

	// Prepare output for progress update
	setbuf(stdout, NULL);	
	printf("Destroying disk\n");
	printf("Working: ");
	
	// Zero out the disk from beginning to end
	// Do the first byte so that we never divide by zero in the progress indicator check
	long int i;
	fputc(0x0, disk);
	for(i = 1; i < size; i++)
	{
		// Write the zero byte to disk
		fputc(0x0, disk);
	
		// Display progress for the user
		// Every N bytes, add to the progress indicator
		if (i % PROGRESS_INDICATOR_BYTES == 0)
		{
			printf("\r");
			printf("%ld of %ld Megabytes destroyed", (i / MEGABYTE), (size / MEGABYTE));
		}
	}
	printf("\r");
	printf("%ld of %ld Megabytes destroyed", (i / MEGABYTE), (size / MEGABYTE));
	printf("\n");
	
	// Close the file and exit
	fclose(disk);
	printf("Destruction complete!\n");
}
