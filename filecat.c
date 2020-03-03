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
  if (outFile < 0 || inFile < 0) {
    perror("Error");
    return 1;
  }
  //read inFile to readFile. reads sizeof(buffer) bytes into buffer
  //writes readFile to outFile.
  readFile = read(inFile, buffer, sizeof(buffer));
  write(outFile, buffer, readFile);
  //close inFile and outFile, and return 0
  close(inFile);
  close(outFile);
  return 0;

}

// strace results (first line is single line comment, because it contains a multiline comment)
// execve("./filecat", ["./filecat"], [/* 46 vars */]) = 0
/*
brk(NULL)                               = 0x7b3000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd8b1b9d000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=84169, ...}) = 0
mmap(NULL, 84169, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fd8b1b88000
close(3)                                = 0
open("/lib64/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\20&\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=2156160, ...}) = 0
mmap(NULL, 3985888, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7fd8b15af000
mprotect(0x7fd8b1772000, 2097152, PROT_NONE) = 0
mmap(0x7fd8b1972000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1c3000) = 0x7fd8b1972000
mmap(0x7fd8b1978000, 16864, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7fd8b1978000
close(3)                                = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd8b1b87000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd8b1b85000
arch_prctl(ARCH_SET_FS, 0x7fd8b1b85740) = 0
mprotect(0x7fd8b1972000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7fd8b1b9e000, 4096, PROT_READ) = 0
munmap(0x7fd8b1b88000, 84169)           = 0
open("XDG_VTNR=1", O_RDWR|O_CREAT|O_APPEND, 03777713142350530) = -1 EACCES (Permission denied)
open(NULL, O_RDONLY)                    = -1 EFAULT (Bad address)
write(2, "File access failed", 18File access failed)      = 18
exit_group(1)                           = ?
+++ exited with 1 +++

*/
