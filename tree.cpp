#include"tree.h"
using namespace std;
#define max 30

char Name[max][max]={
    "李文博", "王静雅", "张伟强", "陈丽娜", "刘晓东",
    "杨明轩", "赵雪梅", "黄志强", "周晓峰", "吴海燕",
    "徐嘉诚", "孙悦玲", "朱浩然", "马小萱", "胡俊杰",
    "林美琳", "高翔宇", "郭瑞琪", "何佳欣", "林子涵",
    "罗建辉", "梁婷婷", "宋博文", "郑雅琴", "谢思远",
    "韩冰洁", "冯志勇", "于慧敏", "董家豪", "苏婉清"
};
char Sex[max][max]={
    "男", "女", "男", "女", "男",
    "女", "男", "女", "男", "女",
    "男", "女", "男", "女", "男",
    "女", "男", "女", "男", "女",
    "男", "女", "男", "女", "男",
    "女", "男", "女", "男", "女"
};
char Time[max][max]={
    "1976-04", "1982-11", "1958-07", "2001-03", "1994-12",
    "1963-09", "1988-01", "2010-05", "1972-08", "1999-02",
    "1967-06", "2004-10", "1985-03", "1970-11", "1995-07",
    "1960-02", "2000-09", "1983-04", "1978-12", "1993-06",
    "1965-01", "2007-08", "1980-03", "1997-10", "1974-05",
    "1969-09", "2002-12", "1987-07", "1971-01", "1998-04"
};
void creat(tree &T,int t)
{
    if(t<=max)
    {
        T=new node;
        T->name=Name[t-1];
        T->position=t;
        T->sex=Sex[t-1];
        T->time=Time[t-1];
        creat(T->lchild,2*t);
        creat(T->rchild,2*t+1);
    }
}
void show(tree &T)
{
    if(T)
    {
        cout<<T->name<<" ";
        if(T->lchild||T->rchild)
        {
            cout<<"(";
            show(T->lchild);
            cout<<",";
            show(T->rchild);
            cout<<")";
        }
    }
}
void find(tree &T,char *n,tree &tr)
{
    if(T)
    {
        if(strcmp(T->name,n)==0)
        {
            tr=T;
        }
        else
        {
            find(T->lchild,n,tr);
            find(T->rchild,n,tr);
        }
    }
}

void find_person(tree &T,char *n)
{
    tree tr=NULL;
    find(T,n,tr);
    if(tr==NULL)
    {
        cout<<"查无此人"<<endl;
        return;
    }
    cout<<"姓名:"<<tr->name<<endl;
    cout<<"序号:"<<tr->position<<endl;
    cout<<"性别:"<<tr->sex<<endl;
    cout<<"出生年月:"<<tr->time<<endl;
    cout<<endl;
}
void find_other(tree &T,char *n)
{
    tree tr=NULL;
    find(T,n,tr);
    if(tr==NULL)
    {
        cout<<"查无此人"<<endl;
        return;
    }
    if(tr->lchild!=NULL)
    {
        cout<<n<<"兄弟信息:"<<endl;
        cout<<"姓名:"<<tr->lchild->name<<endl;
        cout<<"序号:"<<tr->lchild->position<<endl;
        cout<<"性别:"<<tr->lchild->sex<<endl;
        cout<<"出生年月:"<<tr->lchild->time<<endl;
    }
    else
    {
        cout<<"无兄弟"<<endl;
    }
    cout<<endl;
    if(tr->rchild!=NULL)
    {
        cout<<n<<"孩子信息:"<<endl;
        cout<<"姓名:"<<tr->rchild->name<<endl;
        cout<<"序号:"<<tr->rchild->position<<endl;
        cout<<"性别:"<<tr->rchild->sex<<endl;
        cout<<"出生年月:"<<tr->rchild->time<<endl;
    }
    else
    {
        cout<<"无孩子"<<endl;
    }
    cout<<endl;
}

void change(tree &T,char *n)
{
    tree tr=NULL;
    find(T,n,tr);
    if(tr==NULL)
    {
        cout<<"查无此人"<<endl;
        return;
    }
    cout<<"请输入新信息:"<<endl;
    cout<<"姓名:";
    scanf("%s",tr->name);
    cout<<"性别('男''女'):";
    scanf("%s",tr->sex);
    cout<<"出生年月(xxxx-xx):";
    scanf("%s",tr->time);
    cout<<endl;
}

void add(tree &T,char *n)
{
    tree tr=NULL;
    find(T,n,tr);
    if(tr==NULL)
    {
        cout<<"查无此人"<<endl;
        return;
    }
    tree p=tr;//p指向父母
    /*if(tr->rchild!=NULL)
    {
        tr=tr->rchild;
        while(tr->lchild!=NULL)
        {
            tr=tr->lchild;
        }
        tr->lchild=new node;
        tr=tr->lchild;//tr指向孩子
    }
    else
    {
        tr->rchild=new node;
        tr=tr->rchild;//tr指向孩子
    }*/
    while(tr->rchild!=NULL)
    {
        tr=tr->rchild;
    }
    tr->rchild=new node;
    tr=tr->rchild;//tr指向孩子

    if(tr==NULL)
    {
        cout<<"fuck"<<endl;
    }
    cout<<"姓名:";
    char *na = (char *)malloc(max * sizeof(char));
    scanf("%s",na);
    tr->name=na;
    cout<<"性别('男''女'):";
    char *s = (char *)malloc(max * sizeof(char));
    scanf("%s",s);
    tr->sex=s;
    cout<<"出生年月(xxxx-xx):";
    char *t = (char *)malloc(max * sizeof(char));
    scanf("%s",t);
    tr->time=t;
    tr->position=2*(p->position)+1;
    cout<<endl;
}

void printTreeHelper(tree root, int space) {
    if (root == NULL) return;

    space += 5;

    printTreeHelper(root->rchild, space);

    printf("\n");
    for (int i = 5; i < space; i++) printf("  ");
    printf("%s\n", root->name);

    printTreeHelper(root->lchild, space);
}

void printTree(tree root) {
    printTreeHelper(root, 0);
    cout<<endl;
}