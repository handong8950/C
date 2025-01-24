#include<iostream>
#include<string.h>
using namespace std;

typedef struct node{
    int position;
    char *name;
    char *sex;
    char *time;
    struct node *lchild,*rchild;
}node,*tree;

void creat(tree &T,int t);//创建二叉树
void show(tree &T);
void find(tree &T,char *n,tree &tr);//找到对应人
void find_person(tree &T,char *n);//查看信息
void find_other(tree &T,char *n);//查看兄弟孩子信息
void change(tree &T,char *n);//改变信息
void add(tree &T,char *n);//添加孩子
void printTreeHelper(tree root, int space);
void printTree(tree root);//打印二叉树