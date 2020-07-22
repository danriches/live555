#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/time.h>

#define MAX_READ_LEN 2000000

int main(int argc, char** argv)
{
	char buff[ MAX_READ_LEN+1 ];
    int partNum = 0;

    while( 1 )
    {
        ssize_t bytesRead = read( STDIN_FILENO, buff, MAX_READ_LEN );

        if( 0 > bytesRead )
        {
            perror( "read failed" );
            exit( EXIT_FAILURE );
        }

        // implied else, read successful
        buff[ bytesRead ] = '\0';
        partNum++;
        printf("Part %d:%s\n", partNum, buff);
    }
    
    return 0;
}

//int main(int argc, char** argv) 
//{
	//FILE *input_file = NULL;
	//long lSize;
	//char * buffer;
	//size_t result;
  
	//input_file = fopen(STDIN_FILENO, "rb");
	
	//if (input_file==NULL) 
	//{
		//fputs ("File error",stderr); 
		//exit (1);
	//}

	//// obtain file size:
	//fseek (input_file , 0 , SEEK_END);
	//lSize = ftell (input_file);
	//rewind (input_file);

	//// allocate memory to contain the whole file:
	//buffer = (char*) malloc (sizeof(char)*lSize);
	//if (buffer == NULL) 
	//{        // Round 1
		//fputs ("Memory error",stderr); 
		//exit (2);
	//}

	//// copy the file into the buffer:
	//result = fread (buffer,1,lSize,input_file);
	//if (result != lSize) 
	//{
		//fputs ("Reading error",stderr); 
		//exit (3);
	//}

	//printf("Read a total of %d bytes\n", lSize);
	//printf("\n\n\n DATA:\n");
	//printf(buffer);        // Round 1
	//printf("\n");

	//fclose (input_fi        // Round 1le);
	//free (buffer);

	//return 0;
//}
