#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "random_word_generator.h"

int main() {
    FILE* fl_ptr;
    char file_ch;

    int key_value;
    char key_char;
    char test_text[2048];

    time_t before, after;
    int total_elapsed;
    int num_words;
    double sec_double,elapsed_min,wpm;

    int size_of_test_text;

    int i = 0;
    int j;
    printf("Welcome to the typing exam! Please enter a number (between 1-25) of words that you'd like to type for the test: ");
    scanf("%d",&num_words); //TODO change this to fgets + sscanf; not fond of the way I have to use an additonal getchar since \n stuck in buffer...
    getchar();
    printf("\n\nGet ready to type...");
    Sleep(1000);
    generateRandomTextFile(num_words);
    printf("\033[0;36m\e[1mPlease type the following:\e[m\n\n\033[0m");

    fl_ptr = fopen("randomWords.txt","r");
    if (NULL == fl_ptr){
        printf("nice try bucko. file's not openin for nobody!");
        return 1;
    }
    else {
        while(fgets(test_text,2048,fl_ptr));
    }
    fseek(fl_ptr, 0L, SEEK_END); //I have no idea what this and the following line mean tbh i just found them online when trying to find size_of_test_text of a file in C. Thanks stackOverflow!
    size_of_test_text = ftell(fl_ptr);
    char user_input[2048];
    printf(test_text);
    printf("\n\n");
    before = clock();
    while(i < size_of_test_text){
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
    after = clock();
    total_elapsed = (after - before) /CLOCKS_PER_SEC;
    sec_double = total_elapsed;
    elapsed_min = (sec_double/60);
    wpm = num_words/elapsed_min;
    printf("\n\nHere are the results: \n");
    printf("\033[0;32m");
    for(j=0;j<size_of_test_text+1;j++){
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
    printf("\n you finished that in\e[0;35m %d seconds\033[0m with a \033[0;36mwpm of %lf\033[0m",total_elapsed,wpm);
    printf("\n\n\ntype ENTER key to close\n");  
    getchar(); 
return 0;
}
