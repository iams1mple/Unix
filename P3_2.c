// Program no. 3.2

#include<stdio.h>
#include<string.h>
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]){
    
    if(argc != 2){
        fprintf(stderr, "usage: %s <pattern>\n", argv[0]);
        return 1;
    }
    
    char pattern[MAX_LINE_LENGTH];
    
    strcpy(pattern,argv[1]);
    
    char line[MAX_LINE_LENGTH];
    
    while(fgets(line, sizeof(line), stdin)!=NULL){
        if(strstr(pattern,line)!= NULL){
            printf("%s\n",line);
        }
    }
    return 0;
}
