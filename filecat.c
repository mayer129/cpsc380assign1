#include <stdio.h>
#include <fcntl.h>

/**
*  @author: Travis Mayer
*     ID: 002273275
*     Email: mayer129@mail.chapman.edu
*     Course: CPSC 353-01
*     Sources:
*	      https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/
*       https://www.tutorialspoint.com/cprogramming/c_file_io.htm
*       https://linux.die.net/man/3/read
*       https://linuxconfig.org/cat-command
*       https://stackoverflow.com/questions/2844163/how-do-i-use-strace-to-know-about-system-calls-in-my-c-program
*	      http://www.cplusplus.com/reference/cstdio/stderr/
*
*/

int main(int argc, char** argv) {
  //create large buffer and declare file variables
  char buffer[2048];
  int inFile, outFile, readFile;
  //initialize outfile with arg 2. will create new file if doesn't exist, read/write mode, and appends to end
  //initialize inFile with arg 1. read only
  outFile = open(argv[2], O_CREAT | O_APPEND | O_RDWR);
  inFile = open(argv[1], O_RDONLY);
  //error checking. if outfile or infile failed to initialize, their value should be -1.
  //This also catches a case where args are not given
  if (outFile < 0 || inFile < 0) {
    perror("Error");
    return 1;
  }
  //read inFile to readFile. reads sizeof(buffer) bytes into buffer
  //writes readFile to outFile.
  while (readFile = read(inFile, buffer, sizeof(buffer))) {
    write(outFile, buffer, readFile);
  }

  //close inFile and outFile, and return 0
  close(inFile);
  close(outFile);
  return 0;

}
