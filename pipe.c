#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
FILE*stream;
int*fd;
//int a,b;
fd=(int*)malloc(sizeof (int)*2);
pipe(fd);
//printf("please enter the following values");
//scanf("%d %d",&a,&b);
int i;
i=fork();
if(i==-1)
{
perror("fork failed");
printf("done1");
}
else if(i==0)
{
char s[60];
close(fd[1]);
stream=fdopen(fd[0],"r");
fgets(s,60,stream);
fclose(stream);
printf("done2");
}
else
{
close (fd[0]);
stream=fdopen(fd[1],"w");
fprintf(stream,"This is a message \n :");
fclose(stream);
printf("done3");
fflush(stream);
}
}
