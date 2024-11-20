

#include <libc.h>

int main(){

    int fd = open("file1.txt",O_RDWR);
    char *ptr = malloc(1 * sizeof(char));
    ssize_t readbytes = read(fd,ptr,1);
    printf("%zd",readbytes);


}