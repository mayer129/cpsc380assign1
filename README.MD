# filecat
File Concatenation C Program
## Information
*  @author: Travis Mayer
*     ID: 002273275
*     Email: mayer129@mail.chapman.edu
*     Course: CPSC 380-01

## Program Purpose
The purpose of this program is to get familiar with the standard system calls and how to use them in a program. Using only open(), close(), read() and write() system calls.
## Steps to Compile & Run:
1. Path to the filecat directory
2. type `gcc filecat.c -o filecat` to compile the program
3. type ``./filecat <source file> <destination file>``
* This will compile the program. The program will then copy the contents of the source file and append them to the end of the contents of the destination file

### Strace Output
Using the strace command `strace ./filecat <source file> <destination file>` to intercept and record the system calls of the process, results in this output:

`execve("./filecat", ["./filecat", "readFile.txt", "writeFile.txt"], [/* 46 vars */]) = 0
brk(NULL)                               = 0xa2a000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f6c83de8000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=84169, ...}) = 0
mmap(NULL, 84169, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f6c83dd3000
close(3)                                = 0
open("/lib64/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\20&\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=2156160, ...}) = 0
mmap(NULL, 3985888, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f6c837fa000
mprotect(0x7f6c839bd000, 2097152, PROT_NONE) = 0
mmap(0x7f6c83bbd000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1c3000) = 0x7f6c83bbd000
mmap(0x7f6c83bc3000, 16864, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f6c83bc3000
close(3)                                = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f6c83dd2000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f6c83dd0000
arch_prctl(ARCH_SET_FS, 0x7f6c83dd0740) = 0
mprotect(0x7f6c83bbd000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7f6c83de9000, 4096, PROT_READ) = 0
munmap(0x7f6c83dd3000, 84169)           = 0
open("writeFile.txt", O_RDWR|O_CREAT|O_APPEND, 03777771476551170) = 3
open("readFile.txt", O_RDONLY)          = 4
read(4, "ReadFile Contents\n", 2048)    = 18
write(3, "ReadFile Contents\n", 18)     = 18
read(4, "", 2048)                       = 0
close(4)                                = 0
close(3)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++`
