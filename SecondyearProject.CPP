#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>
#include <graphics.h>
#include <io.h>
#include <sys\stat.h>
#include <time.h>
#include <dos.h>
#include <stdlib.h>
#include <direct.h>
#include <errno.h>
#include <process.h>
int ans(char c) // Getting the code number by the ANSI table
{
    return c;
}
void har(char *str, int inx)
{
    clock_t start, end; //clock initialization
    start=clock(); // begining of the counter
    delay(2000); // counter in miliseconds
    int vk=0,yx; // initialization of natural elements
    char gx,drx; // initialization of symbol elements
    char *tx; // pointer initialization 
    tx=(char*)malloc(sizeof(char)*100); // allocation for the pointer
    for(int mx=0; mx<inx; mx++) //cycle
    {
        for(int kx=0; kx<inx; kx++)
        {
            if(str[mx]==str[kx]) {  
                vk++; // compare elements in an array
            };
        }
        gx=str[mx]; // assign the value of an element to an array
        tx[mx]=vk;
        printf("\tS=%c K=%d;",gx,vk); // Display the message of the amout of repetitions
        vk=0;
    }
    mx++;
    yx=tx[0];
    do
    {
        if(yx>=tx[--inx]);
        else yx=tx[inx];
    }
    while(inx>0);
    for(vk=0; vk<mx; vk++) {
        if(yx==tx[vk]) {
            if(drx!=str[vk]) {
                printf("\nMaximum K=%d S=%c",yx,str[vk]);    //maximum ispravit
                drx=str[vk]; //Display the message about the maximum of repetitions 
            };
        };
    }
    end=clock();
    printf("\nTime of working function: symbol characteristic %f",(end-start)/CLK_TCK);
}
void hakra(FILE *fj)
{
    clock_t start, end;
    start=clock();
    delay(2000);
    struct stat statbuf;
    fstat(fileno(fj),&statbuf);
    if(statbuf.st_mode & S_IFCHR)
        printf("\nThis is a device.");
    if(statbuf.st_mode & S_IFREG)
        printf("\nThis is a file.");
    if(statbuf.st_mode & S_IREAD)
        printf("\nYou are allowed to read a file.");
    if(statbuf.st_mode & S_IWRITE)
        printf("\nYou are allowed to write a file.");
    printf("\nDisc Label:%c",'A'+statbuf.st_dev);
    printf("\nSize in bytes: %ld",statbuf.st_size);
    printf("\ntimestamp of the last opening: %s",ctime(&statbuf.st_ctime));
    end=clock();
    printf("\nTime of working function: symbol characteristic: %f",(end-start)/CLK_TCK);
}
void palindrom(char *pal, int inw)
{
    int c,d,e,f;
    char *b;
    b=(char*)malloc(sizeof(char)*100);
    c=0;
    d=0;
    e=0;
    f=0;
    for(c=0; c<inw; c++)
    {
        if (pal[c]!=' ')
        {   b[d]=pal[c];
            d++;
        }
    }
    strlwr(b);
    for(f=0; f<strlen(b); f++)
    {
        if (b[f]==b[strlen(b)-f-1])
            e=e;
        else e=1;
    }
    if (e==0) puts("\nThis is palindrome.");
    else puts("\nThis isn`t a palindrome.");
    getch();
}
void rename()
{
    char *oldname,*newname;
    oldname=(char*)malloc(sizeof(char)*100);
    newname=(char*)malloc(sizeof(char)*100);
    fflush(stdin);         /* prompt for file to rename and new name */
    printf("\nOld name: ");
    gets(oldname);
    fflush(stdin);
    printf("\nWhat is the new name? ");
    gets(newname);
    fflush(stdin);
    if(rename(oldname,newname)==0)    /* Rename the file */
        printf("Renamed %s to %s.\n",oldname,newname);
    else
        perror("rename");
    return;
}
void remove()
{
    printf("\n“File deletion.");
    char *file;
    file=(char*)malloc(sizeof(char)*100);  /* prompt for file name to delete */
    printf("\nPlease type the address of file or the directory filename.");
    gets(file);
    fflush(stdin);
    if (remove(file)==0)  /* checking if file was removed */
        printf("\n File removed",file);
    else
        perror("\n Error has happened.");
    return;
}
void chgdr()
{
    printf("\n Choose the path for the processing.");
    char *path;
    path=(char*)malloc(sizeof(char)*100);
    printf("\n Type the main directory (Example: 'temp')");
    gets(path);
    fflush(stdin);
    int result;
    result=chdir(path);
    if(result!=0) printf("\nI can`t get to the directory%s",path);
    else printf("\n Current directory is %s",path);
}
void filemode()
{
    char *filename;
    filename=(char*)malloc(sizeof(char)*100);;
    struct stat stbuf;
    int amode,type;
    printf("\n Type the name of the file: ");
    scanf("%s",filename);
    fflush(stdin);
    if (stat(filename,&stbuf)!=0)
    {
        perror("\n I can`t info of the file properties.");
        exit(1);
    }
    printf("\n What is the mode of access to the file.");
    printf("\n‚Type '1' - writing mode, '2' - reading mode, '3' - mode of reading and writing.\n");
    scanf("%d",&type);
    switch(type)
    {
    case 1:
        amode=S_IWRITE;
        break;
    case 2:
        amode=S_IREAD;
        break;
    case 3:
        amode=S_IREAD|S_IWRITE;
        break;
    default:
        printf("\nYou typed it wrong. Please do it again.");
    }
    if (chmod(filename,amode)!=0)
    {
        perror("\n The mode can`t be changed.");
        exit(1);
    }
    exit(0);
}
void algm()
{
    clrscr();
    int dx,fx,i,j,dg=0,in=0,dw,nachalo;
    long size;
    char ix,kol,t,*data1,*data2,tr;
    data1=(char*)malloc(sizeof(char)*100);
    data2=(char*)malloc(sizeof(char)*100);
    FILE *fp1,*fp2; // Initializing files
    textbackground(4); //Color setting for cprintf - color is red
    printf("\n           ");
    cprintf("_______________________________________________________");
    printf("\n           ");
    cprintf("|This program is designed for the transformation      |");
    printf("\n           ");
    cprintf("|text files according to the rules:                   |");
    printf("\n           ");
    cprintf("|1) from one file to another                          |");
    printf("\n           ");
    cprintf("|only Latin letters and numbers.                      |");
    printf("\n           ");
    cprintf("|2) In the receiving file the next number             |");
    printf("\n           ");
    cprintf("|after letter or number increases                     |");
    printf("\n           ");
    cprintf("| on the n - times where n - is the current number    |");
    printf("\n           ");
    cprintf("|3) In the receiving file every three characters      |");
    printf("\n           ");
    cprintf("|Color setting for cprintf - color is blue            |");
    printf("\n           ");
    textbackground(1);
    cprintf("|_____________________________________________________|");
    printf("\n           ");
    cprintf("|                Choose an action:                    |");
    printf("\n           ");
    cprintf("|            1)  File Transformation                  |");
    printf("\n           ");
    cprintf("|            2)  Change current category              |");
    printf("\n           ");
    cprintf("|            3)  Rename a file                        |");
    printf("\n           ");
    cprintf("|            4) Delete a file                         |");
    printf("\n           ");
    cprintf("|            5) Change the mode of using the file     |");
    printf("\n           ");
    cprintf("|            6) Exit the program                      |");
    printf("\n           ");
    cprintf("|_____________________________________________________|");
    printf("\n");
    textbackground(0);
    scanf("%d",&nachalo);
    fflush(stdin);
    switch(nachalo)
    {
    case 1:
        clrscr();
        char *put1;
        put1=(char*)malloc(sizeof(char)*100);
        printf("\n Type the first filename fp1\n");
        gets(put1);
        fflush(stdin);
        printf("\n Filename is fp1=%s",put1);
        clock_t start, end;
        start=clock();
        delay(2000);
        if((fp1=fopen(put1,"r"))!=NULL)
        {
            while((kol=getc(fp1))!=EOF) {
                data1[in++]=kol;
            }
            hakra(fp1);
            printf("\nNumber of symbols on the file %d",in);
            har(data1, in);
        }
        else
        {
            printf("\nError: fp1 doesn`t exist");
            getch();
            return;
        };
        fclose(fp1);
        end=clock();
        printf("\n Time of the opening of fp1 file and writing to the array: %f",(end-start)/CLK_TCK);
        printf("\n Content of the fp1 file: ");   // Display of the array //
        for(i=0; i<in; i++)
        {
            printf("%c",data1[i]);
        } // checking of the array //
        palindrom(data1,in);
        printf("\n Should we keep it going? (Type any character)\n");
        scanf("%c",&tr);
        fflush(stdin);
        char *put2;
        put2=(char*)malloc(sizeof(char)*100);
        printf("\nType the second filenamefp2\n");
        gets(put2);
        fflush(stdin);
        printf("\n Filename is fp2=%s",put2);
        start=clock();
        delay(2000);
        if((fp2=fopen(put2,"w+"))!=NULL)
        {
            for(fx=0; fx<in; fx++)
            {
                if((((ans(data1[fx]))>=48)&&((ans(data1[fx]))<=57))||(((ans(data1[fx]))>=65)&&((ans(data1[fx]))<=90))||(((ans(data1[fx]))>=97)&&((ans(data1[fx]))<=122)))
                {
                    if((((ans(data1[fx]))>=48)&&((ans(data1[fx]))<=57)))
                    {
                        switch(data1[fx])
                        {
                        case '0':
                            fx++;
                            for(j=0; j<1; j++) {
                                t=data1[fx];
                                fprintf(fp2,"%c",t);
                                dg++;
                                if(dg==3) {
                                    t=' ';
                                    fprintf(fp2,"%c",t);
                                    dg=0;
                                };
                            }
                            break;
                        case '1':
                            fx++;
                            for(j=0; j<2; j++) {
                                t=data1[fx];
                                fprintf(fp2,"%c",t);
                                dg++;
                                if(dg==3) {
                                    t=' ';
                                    fprintf(fp2,"%c",t);
                                    dg=0;
                                };
                            }
                            break;
                        case '2':
                            fx++;
                            for(j=0; j<3; j++) {
                                t=data1[fx];
                                fprintf(fp2,"%c",t);
                                dg++;
                                if(dg==3) {
                                    t=' ';
                                    fprintf(fp2,"%c",t);
                                    dg=0;
                                };
                            }
                            break;
                        case '3':
                            fx++;
                            for(j=0; j<4; j++) {
                                t=data1[fx];
                                fprintf(fp2,"%c",t);
                                dg++;
                                if(dg==3) {
                                    t=' ';
                                    fprintf(fp2,"%c",t);
                                    dg=0;
                                };
                            }
                            break;
                        case '4':
                            fx++;
                            for(j=0; j<5; j++) {
                                t=data1[fx];
                                fprintf(fp2,"%c",t);
                                dg++;
                                if(dg==3) {
                                    t=' ';
                                    fprintf(fp2,"%c",t);
                                    dg=0;
                                };
                            }
                            break;
                        case '5':
                            fx++;
                            for(j=0; j<6; j++) {
                                t=data1[fx];
                                fprintf(fp2,"%c",t);
                                dg++;
                                if(dg==3) {
                                    t=' ';
                                    fprintf(fp2,"%c",t);
                                    dg=0;
                                };
                            }
                            break;
                        case '6':
                            fx++;
                            for(j=0; j<7; j++) {
                                t=data1[fx];
                                fprintf(fp2,"%c",t);
                                dg++;
                                if(dg==3) {
                                    t=' ';
                                    fprintf(fp2,"%c",t);
                                    dg=0;
                                };
                            }
                            break;
                        case '7':
                            fx++;
                            for(j=0; j<8; j++) {
                                t=data1[fx];
                                fprintf(fp2,"%c",t);
                                dg++;
                                if(dg==3) {
                                    t=' ';
                                    fprintf(fp2,"%c",t);
                                    dg=0;
                                };
                            }
                            break;
                        case '8':
                            fx++;
                            for(j=0; j<9; j++) {
                                t=data1[fx];
                                fprintf(fp2,"%c",t);
                                dg++;
                                if(dg==3) {
                                    t=' ';
                                    fprintf(fp2,"%c",t);
                                    dg=0;
                                };
                            }
                            break;
                        case '9':
                            fx++;
                            for(j=0; j<10; j++) {
                                t=data1[fx];
                                fprintf(fp2,"%c",t);
                                dg++;
                                if(dg==3) {
                                    t=' ';
                                    fprintf(fp2,"%c",t);
                                    dg=0;
                                };
                            }
                            break;
                        default:
                            printf("\n The sequence has not follow up as it had to be.");
                        }
                    }
                    else  {
                        t=data1[fx];
                        fprintf(fp2,"%c",t);
                        dg++;
                        if(dg==3) {
                            t=' ';
                            fprintf(fp2,"%c",t);
                            dg=0;
                        };
                    };
                };
            }
            fseek(fp2,0L,SEEK_SET);  // Return to the begging of the file
            in=0;
            while((kol=getc(fp2))!=EOF) {
                data2[in++]=kol;
            }
            hakra(fp1);
            printf("\n The number of symbols in the file %d",in);
            har(data2, in);
            printf("\n The conter of the file: ");   // Vivod massiva //
            for(i=0; i<in; i++)
            {
                printf("%c",data2[i]);
            }
        }
        else
        {
            printf("\n Error: File can`t be created.");
            getch();
            return;
        };
        fclose(fp2);
        end=clock();
        printf("\n Time of the opening fp2 file and writing in it the necessary symbols i zapis v nego nujnuh nam simvolov: %f",(end-start)/CLK_TCK);
        time_t timer;
        struct tm *tblock;
        timer=time(NULL); // takes the time of the day beret vremya dnya //
        tblock=localtime(&timer); //  convertion of date and time into the structure
        printf("\n Should we keep it going? (Type any character)\n");
        scanf("%c",&tr);
        clrscr();
        textbackground(4);
        printf("\n                                ");
        cprintf("     The program is completed    ");
        printf("\n                                   Local time     ");
        printf("\n                                      %s",asctime(tblock));
        textbackground(0);
        break;                // settextstyle
    case 2:
        chgdr();
        break;
    case 3:
        rename();;
        break;
    case 4:
        remove();
        break;
    case 5:
        filemode();
        break;
    case 6:
        exit(1);
        break;
    default:
        printf("\ntyped the wrong option");
    }
    printf("\n Do you want to repeat the program? \n Type '1' -  for Yes , '2' - for No\n");
    scanf("%d",&nachalo);
    switch(nachalo)
    {
    case 1:
        algm();// Recursion of the main function happens
    case 2:
        exit(1);
    default:
        printf("\n Thank you");
    }
    getch();
}
void main()
{
    algm();
}