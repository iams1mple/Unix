//Programe no . 1

#include<stdio.h>
#include<unistd.h>
#include<limits.h>

int main(){
    
    //max no. clock ticks
    printf("Max no. of clock ticks per second %ld \n",sysconf(_SC_CLK_TCK));
    
    //max no. of child process
    printf("Max no of chil process %ld \n", sysconf(_SC_CHILD_MAX));
    
    //max path length
    printf("Max path lenght %ld\n",pathconf("/",_PC_PATH_MAX));
    
    //math characters in file name
    printf("Max charecters in a filename %ld \n",pathconf("/",_PC_NAME_MAX));
    
    //max open files per process
    printf("Max no. of files per process %ld bytes \n",sysconf(_SC_OPEN_MAX));
    
    //retrive hostname
    char hostname[HOST_NAME_MAX];
    
    if(gethostname(hostname,HOST_NAME_MAX)==0){
        printf("System hostname %s\n",hostname);
    }else{
        perror("gethostname");
    }
    
    //retrive current working directory;
    
    char cwd[PATH_MAX];
    
    if(getcwd(cwd, sizeof(cwd)) != NULL){
        printf("Current working directory: %s \n",cwd);
        
    }else{
        perror("getcwd");
    }
    return 0;
}
