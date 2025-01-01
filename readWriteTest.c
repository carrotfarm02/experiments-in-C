#include<stdlib.h>
#include<stdio.h>


/* 
  This is a demonstration program that writes a sequence of bytes to a buffer and then to a file. 
  It uses a simple counter. 
*/

#define BUF_SZ 1<<10 // 1024

// Helper function that prints the command usage and exits
void usage(char * error){
   printf("%s\nusage: <filename> <size>\n", error);
   exit(0);
}

void print_args(int argc, char **argv){
   int i=0;
   while (i < argc) {
     printf("arg: %i value: '%s'\n", i, argv[i]);
     i=i+1;
   }
}

#define DEBUG 1

int main(int argc, char **argv){

    unsigned int buf[BUF_SZ/8];
    if (argc != 3){
        if (DEBUG) {
            print_args(argc, argv);
        }
        usage("Unexpected number of arguments");
    }
    // arg parsing 
    char *filename=argv[1];
    unsigned long size = atol(argv[2]);


    unsigned long bytes_written = 0;
    unsigned long counter = 0;
    // TODO Open the file!!

    while (bytes_written < size) {
    
        // initialize the data
        for (int i =  0; i < BUF_SZ/8; i++){
            buf[i] = counter;
            counter = counter + 1;
        }

        // TODO write the bytes to a file!

        bytes_written = bytes_written + BUF_SZ;
        if (DEBUG) {
            printf("counter %i\n", counter);
        }
    }

    // TODO Sync the file and close it

    if (DEBUG) {
        printf("bytes_written %i\n", bytes_written);
    }
 
    
    return 0;
}