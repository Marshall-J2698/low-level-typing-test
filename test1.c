#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random_word_generator.h"

int main() {
    FILE* fl_ptr;
    char file_ch;

    int key_value;
    char key_char;
    char test_text[256];

    int size;

    int i = 0;
    int j;
    generateRandomTextFile(20);
    printf("\033[0;36m\e[1mPlease type the following:\e[m\n\n\033[0m");

    fl_ptr = fopen("randomWords.txt","r");
    if (NULL == fl_ptr){
        printf("nice try bucko. file's not openin for nobody!");
        return 1;
    }
    else {
        while(fgets(test_text,256,fl_ptr));
    }
    fseek(fl_ptr, 0L, SEEK_END); //I have no idea what this and the following line mean tbh i just found them online when trying to find size of a file in C. Thanks stackOverflow!
    size = ftell(fl_ptr);
    char user_input[256];
    printf(test_text);
    printf("\n\n");
    while(i < size){
        key_value = getch();
        key_char = key_value;
        if (key_value==8){
            printf("\b \b");
            if(i>0){
              i--;  //only reduces the value of i to a minimum of zero; any lower than that, and youll be able to type longer than char limit
            }
        }else{
            printf("%c",key_value);
            user_input[i] = key_char;
            i++;
        }
    }
    printf("\n\nHere are the results: \n");
    printf("\033[0;32m");
    for(j=0;j<size+1;j++){
        if(user_input[j]==test_text[j]){
            printf("%c",test_text[j]);
        }
        else{
            printf("\033[0;31m");
            printf("%c",test_text[j]);
            printf("\033[0;32m");
        }
    }
    printf("\033[0m");
    printf("\n\n\ntype ENTER key to close\n");  
    getchar(); 
return 0;
}
