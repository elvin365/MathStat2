#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
//const short N = 100;
#define N 100
float func_statistics(float*);


void qsortx(int *a, int low, int  high) {

	int i = 0, j = 0;
	int tmp = 0, medianofthree = 0;

	i = low;
	j = high;
	int k = 0, l = 0, m = 0;
	k = *(a + 0);
	l = *(a + high);
	m = *(a + (high + low) / 2);
	/*Median-of-three*/
	if (k > l && k < m || k < l && k > m)
		medianofthree = k;
	else
		if (l > k && l < m || l < k && l > m)
			medianofthree = l;
		else
			medianofthree = m;
	/*Median-of-three*/
	//printf("\n%d\n", medianofthree);
	do {
		while (*(a + i) < medianofthree)
		{
			i++;
		}
		while (*(a + j) > medianofthree)
		{
			j--;
		}
		if (i <= j)
		{
			if (*(a + i) > *(a + j))
			{
				tmp = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = tmp;
			}
			i++;
			if (j > 0)
			{
				j--;
			}
		}
	} while (i <= j);

	if (i < high)
	{
		qsortx(a, i, high);
	}
	if (j > low)
	{
		qsortx(a, low, j);
	}

}


int main()
{
	int f_x[N];

	float second_znak = 0;
	float x = 0;
	float t = 0;
	char a[20] = { 0 };
	int c;

	char myString[30];


	for (int i = 0; i < N; i++)
	{
		x = x + 0.99;//x
		/*if (i < 50)
			printf("%f\n",x);
		
		if (i >= 50)
			printf("%f\n",x);*/
		memset(myString, 0, 30);
		t = tan(2.0 * x); //f(x)
		if (i < 50)
			printf("%.8f\n", t);

		if (i >= 50)
			printf("%.8f\n", t);
		sprintf(myString, "%f", t);//f(x)] обрезанный тангенс
		//число второе с конца после обрезания

		f_x[i] = atoi(&myString[strlen(myString) - 2]) / 10; // �������� ���������� 8 ������ � ��� ���� ������������?
															/* if (i < 50)
															 printf("%d\n",f_x[i]);

															 if (i >= 50)
															 printf("%d\n",f_x[i]);*/
	}
	for (int i = 0; i<N; i++)
		printf("%d ", f_x[i]);
	//���� ���-�� ���� ������ ����� ( ����,������� , �����,... ) � �������� �� ���-�� �� 100 , ��� ������� �� ��� ������ �����
	float Nu_Num[10];
	qsortx(f_x, 0, N - 1); // f_x ������������ �� �����������
						   //
	int j = 0;
	short amount = 0;
	int k = 0;
	for (int k = 0; k<10; k++)
	{
		while (f_x[j] == k)
		{
			amount++;
			j++;
		}
		Nu_Num[k] = amount;// / 100.0;
						   //j++;
		amount = 0;
		//k++;
	}// �������� ������ ������ (�����)
	printf("\n");
	for (int i = 0; i<10; i++)
		printf("%f ", Nu_Num[i]);

	float Xi = func_statistics(Nu_Num);// c ������� ��������� ������� (� ��� ��� �����?)

	printf("\n%f", Xi);

	system("pause");

	return 0;

}

float func_statistics(float *Nu_Num)
{
	int i = 0;
	float res_cycle = 0;
	for (; i <= 9; i++)
	{
		res_cycle = res_cycle + (*(Nu_Num + i) - 0.1*N)*(*(Nu_Num + i) - 0.1*N);
	}
	return (10.0 * res_cycle / N);
	//sqrt not sure if i need this
}

