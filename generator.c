#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <dirent.h>

int generator(){
    system("gcc my_program.c -o my_program.exe");
    system("gcc main_program.c -o main_program.exe");

    char s1[100],s2[100],s3[100],s4[100];
    DIR *d;
    int count=0;
    int c=1;
    int cc=10;
    struct dirent *dir;
    d = opendir("input");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(count>=2){
                
                /////student code ////////////

                strcpy(s1,"my_program.exe <.\\input\\");
                strcpy(s2,dir->d_name);
               
                strcpy(s3,">.\\my_output\\my_output");
                itoa(c,s4,10);
                strcat(s1,s2);
                strcat(s1,s3);
                strcat(s1,s4);
                strcat(s1,".txt");
                system(s1);

                /////////////teacher code///////////

                strcpy(s1,"main_program.exe <.\\input\\");
                strcpy(s2,dir->d_name);
                strcpy(s3,">.\\output\\output");
                itoa(c,s4,10);
                strcat(s1,s2);
                strcat(s1,s3);
                strcat(s1,s4);
                strcat(s1,".txt");
                system(s1);
                c++;

            }
            count++;
        }
        closedir(d);
    }
    printf("number of testcases : %d\n",c-1);
    
    return c;
}
