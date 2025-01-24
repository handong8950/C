#include<iostream>
#include<cstring>
#include"tree.h"
using namespace std;

int main()
{
	tree T;
	creat(T,1);
	while(1)
	{
		cout << "0:显示家族树" << "  ";
		cout<<"1:查询信息"<<"  ";
		cout<<"2:修改信息"<<"  ";
		cout<<"3:查询兄弟孩子信息"<<"  ";
		cout<<"4:添加孩子"<<"  ";
		cout<<"-1:退出"<<endl;
		cout<<"输入选项:";
		int in;
		cin>>in;
		if(in==-1)
		{
			cout<<"已退出"<<endl;
			break;
		}
		switch(in)
		{
			case 0:
				printTree(T);
				break;
			case 1:
				char *n1;
				scanf("%s",n1);
				find_person(T,n1);
				break;
			case 2:
				char *n2;
				scanf("%s",n2);
				change(T,n2);
				break;
			case 3:
				char *n3;
				scanf("%s",n3);
				//find_other(T,n3);
				add(T,n3);
				break;
			case 4:
				char *n;
				scanf("%s",n);
				find_other(T,n);
				break;
			default:printf("请重新输入\n");
    			break;
		}
		in=-1;
	}
	return 0;
}