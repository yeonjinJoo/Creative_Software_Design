#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_case(char* a){
	char x = *a;
    if(x > 64 && x < 91){
        *a = x + 32;
    }
    else if(x > 96 && x < 123){
        *a = x - 32;
    }
}

int main(void){
	int size = 100;
    
    while(1){
        int notcharExist = 0;
        char* word = (char*)malloc(size*sizeof(char));
        scanf("%[^\n]s", word);
        
        if(strcasecmp(word, "exit") == 0){
            break;
        }
        
        for(int i = 0; i < strlen(word); i++){
            char c = word[i];
            if( c < 65 || c > 90 && c < 97 || c > 122 ){
                printf("Error: Wrong input!\n");
                notcharExist = 1;
                break;
            }
            else{
                convert_case(&word[i]);
            }
        }
        
        if(notcharExist == 0){
            printf("%s\n", word);
        }
        else{
            break;
        }
    }
	return 0;
}
