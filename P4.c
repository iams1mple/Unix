// Program no. 4

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *filename = argv[1];
    char hard_linkname[256], sys_linkname[256];
    struct stat file_stat;
    
    //create hardlink 
    
    if(link(filename , "hard_link")==-1){
        
        perror("error creating hard link");
        exit(EXIT_FAILURE);
    }
    
    //create system link
    
    if(symlink(filename,"sys_link")== -1){
        perror("error creating system link");
        exit(EXIT_FAILURE);
    }
    
    //get file info
    
    if(stat(filename,&file_stat)==-1){
        perror("error getting file infomartion");
        exit(EXIT_FAILURE);
    }
    
    //diplay information of hard link
    
    printf("Hard link information \n");
    printf("Numbers of hard links: %ld\n",file_stat.st_nlink);
    
    //display info of symbolic links
    
    if(lstat("sys_link",&file_stat)==-1){
        perror("error getting system information");
        exit(EXIT_FAILURE);
    }
    
    printf("Information about system link");
    printf("Numbers of system links: %ld \n",file_stat.st_nlink);
    
    return 0;
}
