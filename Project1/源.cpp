#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define phicialpage 3 //�����ڴ���
#define procpage 10 //���̺��е�ҳ������
#define page 20 //�������е�ҳ������
int Pagechange() {
	//���������ջ��ʼ�ձ����±���С��λ���ϵ�ҳ��������������ٵ�ҳ�棬�±�����ҳ�������������������
	int Numofstack = 0;//��¼ջ�����ж��ٸ�ҳ�棬��ʼ����Ϊ0
	int stack[phicialpage]; //����ģ��ջ
	int pagematrix[page]; //����ҳ����������
	srand(time(0));//�����ʼ��
	for (int i = 0; i < phicialpage; i++)
	{//��ʼ��ջ��-1��ʾջ��û���κ�Ԫ��
		stack[i] = -1;
	}
	printf("Page sequence: ");
	for (int i = 0; i < page; i++)
	{//�����ʼ���������в����
		pagematrix[i] = rand() % procpage;
		printf("%d ", pagematrix[i]);
	}
	printf("\n  SeqID           Working Set\n");
	int hitcount = 0;//��¼���д���
	for (int i = 0; i < page; i++)
	{//����������������
		if (Numofstack < phicialpage) {//�������ڴ�δ��ʱ���ж��Ƿ����У������򽫷��ʹ���ҳ��ѹ��ջ������������ջ��ҳ��λ�����ƣ�δ������ֱ�ӽ����ʵ�ҳ��ѹ��ջ��
			int hit = 0;
			for (int j = 0; j < phicialpage; j++)
			{//�������������ڴ��е�ҳ��
				if (stack[j] == pagematrix[i]) {
					//����
					int tmp = stack[j];
					hit = 1; hitcount++;
					for (int k = j + 1; k < Numofstack; k++)
					{
						stack[k - 1] = stack[k];//ջ��Ԫ��ǰ��
					}
					stack[Numofstack-1] = tmp;//ջ����Ϊ��ʱ���ʵ�ҳ��
					printf("  %2d              %2d  %2d  %2d    *hit*\n", i + 1, stack[0], stack[1], stack[2]);
					break;
				}
			}
			if (hit == 0)
			{//δ������ֱ��ѹ��
				stack[Numofstack] = pagematrix[i];
				Numofstack++;
				printf("  %2d              %2d  %2d  %2d\n", i + 1, stack[0], stack[1], stack[2]);
			}
		}//�������ڴ�û��ʱ������Ҫ�û�����
		else {//�����ڴ���ʱ�������жϣ���������򽫷��ʹ���ҳ��ѹ��ջ������������ջ��ҳ��λ�����ƣ�δ�����򴥷��û�
			int hit = 0;
			for (int j = 0; j < phicialpage; j++)
			{//�������������ڴ��е�ҳ��
				if (stack[j] == pagematrix[i]) {
					//����
					int tmp = stack[j];
					hit = 1; hitcount++;
					for (int k = j+1; k < phicialpage; k++)
					{
						stack[k - 1] = stack[k];//ջ��Ԫ��ǰ��
					}
					stack[phicialpage - 1] = tmp;//ջ����Ϊ��ʱ���ʵ�ҳ��
					printf("  %2d              %2d  %2d  %2d    *hit*\n", i + 1, stack[0], stack[1], stack[2]);
					break;
				}
			}
			if (hit == 0)
			{//δ���У���Ҫ�û�
				for (int k = 1; k < phicialpage; k++)
				{
					stack[k - 1] = stack[k];//ջ��Ԫ��ǰ��
				}
				stack[phicialpage - 1] = pagematrix[i];//ջ����Ϊ��ʱ���ʵ�ҳ��
				printf("  %2d              %2d  %2d  %2d\n", i + 1, stack[0], stack[1], stack[2]);
			}
		}
	}
	int miss = page - hitcount;//����δ������
	printf("Hit = %d,Miss = %d\n", hitcount, miss);
	printf("Page fault Rate = %d/%d = %f\n",miss,page,(float)miss/(float)page);//����δ������
	return 1;
}
#define phicialpage 5 //�����ڴ���
#define procpage 10 //���̺��е�ҳ������
#define page 11 //�������е�ҳ������
int Pagechange2() {
	//���������ջ��ʼ�ձ����±���С��λ���ϵ�ҳ��������������ٵ�ҳ�棬�±�����ҳ�������������������
	int Numofstack = 0;//��¼ջ�����ж��ٸ�ҳ�棬��ʼ����Ϊ0
	int stack[phicialpage]; //����ģ��ջ
	int pagematrix[page]= { 4,7,0,7,1,0,1,2,1,2,6 };; //����ҳ����������
	srand(time(0));//�����ʼ��
	for (int i = 0; i < phicialpage; i++)
	{//��ʼ��ջ��-1��ʾջ��û���κ�Ԫ��
		stack[i] = -1;
	}
	printf("Page sequence: ");
	for (int i = 0; i < page; i++)
	{//�����ʼ���������в����
		printf("%d ", pagematrix[i]);
	}
	printf("\n  SeqID               Working Set\n");
	int hitcount = 0;//��¼���д���
	for (int i = 0; i < page; i++)
	{//����������������
		if (Numofstack < phicialpage) {//�������ڴ�δ��ʱ���ж��Ƿ����У������򽫷��ʹ���ҳ��ѹ��ջ������������ջ��ҳ��λ�����ƣ�δ������ֱ�ӽ����ʵ�ҳ��ѹ��ջ��
			int hit = 0;
			for (int j = 0; j < phicialpage; j++)
			{//�������������ڴ��е�ҳ��
				if (stack[j] == pagematrix[i]) {
					//����
					int tmp = stack[j];
					hit = 1; hitcount++;
					for (int k = j + 1; k < Numofstack; k++)
					{
						stack[k - 1] = stack[k];//ջ��Ԫ��ǰ��
					}
					stack[Numofstack - 1] = tmp;//ջ����Ϊ��ʱ���ʵ�ҳ��
					printf("  %2d              %2d  %2d  %2d  %2d  %2d    *hit*\n", i + 1, stack[0], stack[1], stack[2], stack[3], stack[4]);
					break;
				}
			}
			if (hit == 0)
			{//δ������ֱ��ѹ��
				stack[Numofstack] = pagematrix[i];
				Numofstack++;
				printf("  %2d              %2d  %2d  %2d  %2d  %2d\n", i + 1, stack[0], stack[1], stack[2], stack[3], stack[4]);
			}
		}//�������ڴ�û��ʱ������Ҫ�û�����
		else {//�����ڴ���ʱ�������жϣ���������򽫷��ʹ���ҳ��ѹ��ջ������������ջ��ҳ��λ�����ƣ�δ�����򴥷��û�
			int hit = 0;
			for (int j = 0; j < phicialpage; j++)
			{//�������������ڴ��е�ҳ��
				if (stack[j] == pagematrix[i]) {
					//����
					int tmp = stack[j];
					hit = 1; hitcount++;
					for (int k = j + 1; k < phicialpage; k++)
					{
						stack[k - 1] = stack[k];//ջ��Ԫ��ǰ��
					}
					stack[phicialpage - 1] = tmp;//ջ����Ϊ��ʱ���ʵ�ҳ��
					printf("  %2d              %2d  %2d  %2d  %2d  %2d    *hit*\n", i + 1, stack[0], stack[1], stack[2], stack[3], stack[4]);
					break;
				}
			}
			if (hit == 0)
			{//δ���У���Ҫ�û�
				for (int k = 1; k < phicialpage; k++)
				{
					stack[k - 1] = stack[k];//ջ��Ԫ��ǰ��
				}
				stack[phicialpage - 1] = pagematrix[i];//ջ����Ϊ��ʱ���ʵ�ҳ��
				printf("  %2d              %2d  %2d  %2d  %2d  %2d\n", i + 1, stack[0], stack[1], stack[2], stack[3], stack[4]);
			}
		}
	}
	int miss = page - hitcount;//����δ������
	printf("Hit = %d,Miss = %d\n", hitcount, miss);
	printf("Page fault Rate = %d/%d = %f\n", miss, page, (float)miss / (float)page);//����δ������
	return 1;
}
int main() {
	Pagechange();
	//Pagechange2();
	return 1;
}