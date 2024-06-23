#include <stdio.h>

bool palindromo(char string[], int i, int f);

int main(){
    char  string[50];
    int i = 0;

    scanf("%[^\n]", string);
    getchar();

    while(string[i] != '\0'){
        i++;
    }

    printf("%d", palindromo(string, 0, i));

    return 0;
}

bool palindromo(char string[], int i, int f){

    // caso seja ==, significa que eu ja andei toda a string
    if(i >= f){
        return true;
    }

    if(string[i] != string[f-1]){
        return false;
    }else{
        return palindromo(string, i+1, f-1);
    }
    
}