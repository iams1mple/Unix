//Program no. 5

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

void file_lock(int fd){
    struct flock fl;
    fl.l_type = F_WRLCK; 
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    if(fcntl(fd, F_SETLKW, &fl)==-1){
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    printf("File locked successfully\n");
}

void file_unlock(int fd){
    struct flock fl;
    fl.l_type = F_UNLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    if(fcntl(fd,F_SETLK, &fl)==-1){
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    printf("unlock successfully\n");
}


int main(){
    int fd;
    char *filename = "Testfile.txt";
    
    //fileopen
    if((fd=open(filename, O_RDWR | O_CREAT, 0666))==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    //try write
    if(write(fd,"hello, world\n",14)!=14){
        perror("write");
        exit(EXIT_FAILURE);
    }
    
    file_lock(fd);
    
    //try write again
    if(write(fd,"locked file content\n",20)==-1){
        perror("write");
        printf("Error: cannot write in a locked file");
    }
    
    file_unlock(fd);
    
    //write again
    if(write(fd,"unlocked file contentn",22)!= 22){
        perror("write");
        exit(EXIT_FAILURE);
    }
    close(fd);
    
return 0;
    
}
