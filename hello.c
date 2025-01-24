/*输入一个字符串，写一函数，将此字符串中从第m个字符开始的全部字符复制成为另一个字符串。
void copystr(char *p1, char *p2, int m);
例：
（1）输入：
abc
5
输出：Input error!
（2）输入：
Nothing is impossible to a willing heart.
9
输出：is impossible to a willing heart.

 请注意，main()函数与给定函数必须按如下所示编写：
int main()
{
    void copystr(char *p1, char *p2, int m);
    char str1[81],str2[81];
    int m;
    
    //printf("Please input string:\n");
    gets(str1);
    
    //printf("Please input the begin location of the character:\n ");
    scanf("%d",&m);
    
    if(strlen(str1)<m)
    {
        printf("Input error!");
    }
    else
    {
        copystr(str1,str2,m);
        printf("%s\n",str2);
    }

    return 0;
}
*/
#include<stdio.h>
#include<string.h>
int main()
{
    void copystr(char *p1, char *p2, int m);
    char str1[81],str2[81];
    int m;
    
    //printf("Please input string:\n");
    gets(str1);
    
    //printf("Please input the begin location of the character:\n ");
    scanf("%d",&m);
    
    if(strlen(str1)<m)
    {
        printf("Input error!");
    }
    else
    {
        copystr(str1,str2,m);
        printf("%s\n",str2);
    }

    return 0;
}
void copystr(char *p1, char *p2, int m)
{
    int i;
    for(i=0;p1[m-1]!='\0';i++)
    {
        p2[i]=p1[m-1];
        m++;
    }
    p2[i]='\0';
}
