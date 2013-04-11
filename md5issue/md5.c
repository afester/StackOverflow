#include <openssl/md5.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
int file;
struct stat s;
unsigned long size;
char* buffer;
unsigned char md5[MD5_DIGEST_LENGTH];

file = open("testfile", O_RDONLY);
if (file < 0)
    return 0;

if (fstat(file, &s) < 0)
{
    close(file);
    return 0;
}

size = s.st_size;                       //GET FILE SIZE
printf("filesize: %lu\n", size);        //PRINT FILESIZE FOR DEBUGGING
buffer = (char*)mmap(0, size, PROT_READ, MAP_SHARED, file, 0); //MAP FILE CONTENT TO BUFFER
MD5((unsigned char*)buffer, size, md5); //GENERATE MD5
munmap(buffer, size);                   //UNMAP BUFFER
close(file);

for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
    printf("%02x", md5[i]);
printf("\n");



    char* teststring = "\x61\x0a"; //SAME STRING AS IN THE FILE

    MD5((unsigned char*)teststring, 2, md5);

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
        printf("%02x", md5[i]);
    printf("\n");

    return 0;
}
