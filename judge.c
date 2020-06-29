#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <dirent.h>
#include"headerfile.h"
int c;
//judge_function
char s1[100],s2[100],s3[100],s4[100];
int correct_testcase;


void judge(){
//generator func and read the number of testcases
    c=generator();
//open files and compare between them
    FILE *fp1, *fp2;
    int ch1, ch2;
    for(int i=0;i<c-1;i++){
       strcpy(s1,".\\my_output\\my_output");
       itoa(i+1,s2,10);
        strcpy(s3,".txt");
        strcat(s1,s2);
        strcat(s1,s3);
       
        fp1 = fopen(s1, "r");
        strcpy(s1,".\\output\\output");
        itoa(i+1,s2,10);
        strcpy(s3,".txt");
        strcat(s1,s2);
        strcat(s1,s3);

        fp2 = fopen(s1, "r");
        ch1 = getc(fp1);
        ch2 = getc(fp2);
 
        while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2)){
            ch1 = getc(fp1);
            ch2 = getc(fp2);
         }

        if (ch1 == ch2){
            printf("test case %d : Yes\n",i+1);
            correct_testcase+=1;
        }
            
        else if (ch1 != ch2){
           printf("test case %d : No\n",i+1); 
        }

        fclose(fp1);
        fclose(fp2);
    }
}

void printnum(){
    printf("correct_testcases : %d\n",correct_testcase);
    printf("your number is : %.1f from 100 .\n",((float)correct_testcase/(c-1))*100);
}

void main(){
    printf("----------------------------------\n");
    printf("welcom to judge.\n");
    printf("*put your test cases in input folder on seperate files.\n");
    printf("----------------------------------\n");
    judge();
    printf("----------------------------------\n");
    printnum();
    system("pause");
}


