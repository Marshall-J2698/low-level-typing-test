#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateRandomTextFile(int numWords);

// int main(){
//     generateRandomTextFile(17);
//     getchar();
// }

void generateRandomTextFile(int numWords){
    FILE* source_fl;
    FILE* overrite_existing = fopen("randomWords.txt", "w");
    FILE* write_new = freopen("randomWords.txt","a", overrite_existing);

    int j, k;


    source_fl = fopen("mostCommonWords.txt","r");
    if (NULL == source_fl){
        printf("The source file is not opening my man");
        exit(1);
    }else{
        srand(time(NULL)*time(NULL));
        char currentWord[64];
        for (int i = 0; i<numWords; i++){
            int randNum = rand() % 500;
            int j = 0;
            fseek(source_fl,0, SEEK_SET);
            for (j;j<(randNum+1);j++){
                fgets(currentWord,64,source_fl);
            }
            int k = 0;
            for (k=0;k<sizeof(currentWord);k++){
                if(currentWord[k] == '\n'){
                    currentWord[k] = ' ';
                }
            }
            fprintf(write_new, "%s",currentWord);
            }

        }
        fclose(write_new);
    }
    

