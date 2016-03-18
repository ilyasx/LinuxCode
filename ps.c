/*
 * Linux PS command simplest implementation
 * Created by Muhammad Ilyas email: m_Ilyas@outlook.com

 *******************************************************************************
 * In order to use this command you have to given an argument in proper format
 * Process ID -> ./myps \n
 * Process Name -> ./myps -p PID
 * Process State -> ./myps -p PID -s
 * Process VM Size -> ./myps -p PID -v
 * Process CMDLine -> ./myps -p PID -c
 * All -> ./myps -p PID -s -v -c


*/
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <linux/limits.h>
#include <sys/times.h>
#define clear() printf("\033[H\033[J")

void readPID();
void readVMSize(int a,char * argv[]);
void readCMDline(int a,char * argv[]);
void readState(char * argv[]);
void readProcess(char* argv[]);
void HowToUse();

int main(int argc,char *argv[]){
	//HowToUse();
/*
    cmd line argument check here
*/
	int i=1;
    if(argv[1] == NULL){
        readPID();
    }
    else if(strcmp(argv[i],"-p") != 0  ){
        printf("Please enter -p with Process id i.e (-p 1)\n");

    }
    else if(argc>1){
        //printf("test argc>1\n");
        if(argc>1){
        /*
            option implementation of cmdline argument
    */

            while(i!=argc){
               // printf("%s\n",argv[i]);
                if(strcmp(argv[i],"-p") == 0){
                    readProcess(argv);
                }
                else if(strcmp(argv[i],"-s") == 0){
                        readState(argv);
                }
                else if(strcmp(argv[i],"-v") == 0){
                    readVMSize(3,argv);
                }
                else if(strcmp(argv[i],"-c") == 0){
                    readCMDline(3,argv);
                }

            i++;
            }
       }


    }

return 0;


}
/*
    read process name form proc
*/

void readProcess(char* argv[]){
char a[100]="/proc/", b[10], c[10]="/comm";
        strcat(a,argv[2]);
        strcat(a,c);
            //strcat(a,c);
            FILE *fp;
            char buff[255];
            fp = fopen(a,"r");
            if(!fp){
                printf("Process not found\n");
            }
            else {
                fscanf(fp, "%s",buff);
              //  cle          ar();
                printf("Process Name: %s \n",buff);
            }

}
/*
    reading process state form proc
*/

void readState(char * argv[]){
    char a[10]="/proc/", c[10]="/status",buff[100],buff2[100];
    strcat(a,argv[2]);strcat(a,c);
    FILE *fp;
	//printf("%s",a);
	fp = fopen(a,"r");
	if(!fp){
		printf("Process not found\n");
	}
	else {
        fgets(buff,100, fp);
        fgets(buff2,100,fp);
    clear();
    }
    printf("%s \n",buff);
    printf("%s",buff2);

}
/*
    reading cmdline from proc/pid/cmdline
*/

void readCMDline(int a,char * argv[]){
    char h[50]="/proc/",l[10]="/cmdline",buff[250];
    strcat(h,argv[2]);strcat(h,l);
    printf("%s\n",h);

   FILE *fp;
    fp = fopen(h,"r");
    if(!fp){
        printf("Process not found\n");
    }
    else {
        fgets(buff,255,fp);
        //  cle          ar();
        printf("%s \n",buff);
    }
    fclose(fp);


}
/*
    reading process vm size from proc
*/

void readVMSize(int a,char * argv[]){
    char h[40]="/proc/",g[10]="/statm",buff[250];
    strcat(h,argv[2]);strcat(h,g);
                //printf("%s",h);
                FILE *fp;
                fp = fopen(h,"r");
                if(!fp){
                    printf("Process not found\n");
                }
                else {
                    fscanf(fp, "%s",buff);
                //  cle          ar();
                    printf("Virtual Memory: %s \n",buff);
                }
                fclose(fp);


}
/*
    reading PID && PPID and process name
*/

void readPID(){
        char str[15],buff[255],d[50]= "/proc/",a[100]="/proc/", c[10]="/comm";
        __pid_t PID = 0,ParentId=0;
        PID = getpid();
        ParentId = getppid();
        printf("PID          CMD\n");
        printf("%i          ",PID);
        sprintf(str, "%d", PID);
        strcat(a,str);
        strcat(a,c);
            //strcat(a,c);
            //printf("\n%s\n",a);
            FILE *fp;
            //char buff[255];

        fp = fopen(a,"r");
        if(!fp){
            printf("Process not found\n");
        }
        else {
            fscanf(fp, "%s",buff);
            //  cle          ar();
            printf("%s \n",buff);
        }
        fclose(fp);
        printf("%i          ",ParentId);
        sprintf(str, "%d", ParentId);
        strcat(d,str);
        strcat(d,c);
            //strcat(a,c);
            //printf("\n%s\n",d);
            //FILE *fp;
            //char buff[255];
        fp = fopen(d,"r");
        if(!fp){
            printf("Process not found\n");
        }
        else {
            fscanf(fp, "%s",buff);
            //  cle          ar();
            printf("%s \n",buff);
        }
        fclose(fp);
}
