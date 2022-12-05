#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define phicialpage 3 //物理内存数
#define procpage 10 //进程含有的页面数量
#define page 20 //访问序列的页面数量
int Pagechange() {
	//用数组代替栈，始终保持下标最小的位置上的页面是最近访问最少的页面，下标最大的页面是最近访问最多的序列
	int Numofstack = 0;//记录栈中已有多少个页面，初始数量为0
	int stack[phicialpage]; //数组模仿栈
	int pagematrix[page]; //访问页面序列数组
	srand(time(0));//随机初始化
	for (int i = 0; i < phicialpage; i++)
	{//初始化栈，-1表示栈中没有任何元素
		stack[i] = -1;
	}
	printf("Page sequence: ");
	for (int i = 0; i < page; i++)
	{//随机初始化访问序列并输出
		pagematrix[i] = rand() % procpage;
		printf("%d ", pagematrix[i]);
	}
	printf("\n  SeqID           Working Set\n");
	int hitcount = 0;//记录命中次数
	for (int i = 0; i < page; i++)
	{//遍历整个访问序列
		if (Numofstack < phicialpage) {//当物理内存未慢时，判断是否命中，命中则将访问过的页面压入栈顶，并将其他栈中页面位置下移；未命中则直接将访问的页面压入栈顶
			int hit = 0;
			for (int j = 0; j < phicialpage; j++)
			{//遍历已在物理内存中的页面
				if (stack[j] == pagematrix[i]) {
					//命中
					int tmp = stack[j];
					hit = 1; hitcount++;
					for (int k = j + 1; k < Numofstack; k++)
					{
						stack[k - 1] = stack[k];//栈中元素前移
					}
					stack[Numofstack-1] = tmp;//栈顶变为此时访问的页面
					printf("  %2d              %2d  %2d  %2d    *hit*\n", i + 1, stack[0], stack[1], stack[2]);
					break;
				}
			}
			if (hit == 0)
			{//未命中则直接压入
				stack[Numofstack] = pagematrix[i];
				Numofstack++;
				printf("  %2d              %2d  %2d  %2d\n", i + 1, stack[0], stack[1], stack[2]);
			}
		}//当物理内存没满时，不需要置换操作
		else {//物理内存满时，进行判断，如果命中则将访问过的页面压入栈顶，并将其他栈中页面位置下移；未命中则触发置换
			int hit = 0;
			for (int j = 0; j < phicialpage; j++)
			{//遍历已在物理内存中的页面
				if (stack[j] == pagematrix[i]) {
					//命中
					int tmp = stack[j];
					hit = 1; hitcount++;
					for (int k = j+1; k < phicialpage; k++)
					{
						stack[k - 1] = stack[k];//栈中元素前移
					}
					stack[phicialpage - 1] = tmp;//栈顶变为此时访问的页面
					printf("  %2d              %2d  %2d  %2d    *hit*\n", i + 1, stack[0], stack[1], stack[2]);
					break;
				}
			}
			if (hit == 0)
			{//未命中，需要置换
				for (int k = 1; k < phicialpage; k++)
				{
					stack[k - 1] = stack[k];//栈中元素前移
				}
				stack[phicialpage - 1] = pagematrix[i];//栈顶变为此时访问的页面
				printf("  %2d              %2d  %2d  %2d\n", i + 1, stack[0], stack[1], stack[2]);
			}
		}
	}
	int miss = page - hitcount;//计算未命中数
	printf("Hit = %d,Miss = %d\n", hitcount, miss);
	printf("Page fault Rate = %d/%d = %f\n",miss,page,(float)miss/(float)page);//计算未命中率
	return 1;
}
#define phicialpage 5 //物理内存数
#define procpage 10 //进程含有的页面数量
#define page 11 //访问序列的页面数量
int Pagechange2() {
	//用数组代替栈，始终保持下标最小的位置上的页面是最近访问最少的页面，下标最大的页面是最近访问最多的序列
	int Numofstack = 0;//记录栈中已有多少个页面，初始数量为0
	int stack[phicialpage]; //数组模仿栈
	int pagematrix[page]= { 4,7,0,7,1,0,1,2,1,2,6 };; //访问页面序列数组
	srand(time(0));//随机初始化
	for (int i = 0; i < phicialpage; i++)
	{//初始化栈，-1表示栈中没有任何元素
		stack[i] = -1;
	}
	printf("Page sequence: ");
	for (int i = 0; i < page; i++)
	{//随机初始化访问序列并输出
		printf("%d ", pagematrix[i]);
	}
	printf("\n  SeqID               Working Set\n");
	int hitcount = 0;//记录命中次数
	for (int i = 0; i < page; i++)
	{//遍历整个访问序列
		if (Numofstack < phicialpage) {//当物理内存未慢时，判断是否命中，命中则将访问过的页面压入栈顶，并将其他栈中页面位置下移；未命中则直接将访问的页面压入栈顶
			int hit = 0;
			for (int j = 0; j < phicialpage; j++)
			{//遍历已在物理内存中的页面
				if (stack[j] == pagematrix[i]) {
					//命中
					int tmp = stack[j];
					hit = 1; hitcount++;
					for (int k = j + 1; k < Numofstack; k++)
					{
						stack[k - 1] = stack[k];//栈中元素前移
					}
					stack[Numofstack - 1] = tmp;//栈顶变为此时访问的页面
					printf("  %2d              %2d  %2d  %2d  %2d  %2d    *hit*\n", i + 1, stack[0], stack[1], stack[2], stack[3], stack[4]);
					break;
				}
			}
			if (hit == 0)
			{//未命中则直接压入
				stack[Numofstack] = pagematrix[i];
				Numofstack++;
				printf("  %2d              %2d  %2d  %2d  %2d  %2d\n", i + 1, stack[0], stack[1], stack[2], stack[3], stack[4]);
			}
		}//当物理内存没满时，不需要置换操作
		else {//物理内存满时，进行判断，如果命中则将访问过的页面压入栈顶，并将其他栈中页面位置下移；未命中则触发置换
			int hit = 0;
			for (int j = 0; j < phicialpage; j++)
			{//遍历已在物理内存中的页面
				if (stack[j] == pagematrix[i]) {
					//命中
					int tmp = stack[j];
					hit = 1; hitcount++;
					for (int k = j + 1; k < phicialpage; k++)
					{
						stack[k - 1] = stack[k];//栈中元素前移
					}
					stack[phicialpage - 1] = tmp;//栈顶变为此时访问的页面
					printf("  %2d              %2d  %2d  %2d  %2d  %2d    *hit*\n", i + 1, stack[0], stack[1], stack[2], stack[3], stack[4]);
					break;
				}
			}
			if (hit == 0)
			{//未命中，需要置换
				for (int k = 1; k < phicialpage; k++)
				{
					stack[k - 1] = stack[k];//栈中元素前移
				}
				stack[phicialpage - 1] = pagematrix[i];//栈顶变为此时访问的页面
				printf("  %2d              %2d  %2d  %2d  %2d  %2d\n", i + 1, stack[0], stack[1], stack[2], stack[3], stack[4]);
			}
		}
	}
	int miss = page - hitcount;//计算未命中数
	printf("Hit = %d,Miss = %d\n", hitcount, miss);
	printf("Page fault Rate = %d/%d = %f\n", miss, page, (float)miss / (float)page);//计算未命中率
	return 1;
}
int main() {
	Pagechange();
	//Pagechange2();
	return 1;
}