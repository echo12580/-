#include <stdio.h>
#include"one.h"
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")
#define FrameX 13
#define FrameY 3
#define Frame_height 20
#define Frame_width 18
int i, j, Temp, Temp1, Temp2;
int a[80][80] = { 0 };
int b[4];
struct Tetris {
	int x;
	int y;
	int flag;
	int next;
	int speed;
	int numder;
	int score;
	int level;
};
HANDLE hOut;
void sort(int a[], int n)
{
	int i, j, * p = a;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (*(p + i) < *(p + j))		//����
			{
				int t;
				t = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = t;
			}
		}
	}
}
void Music()
{
	mciSendString(TEXT("open E:\\m.mp3"), 0, 0, 0);
	mciSendString(TEXT("play E:\\m.mp3"), 0, 0, 0);
	
}
int Max()
{
	int a[10];
	int i;
	FILE* fpRead = fopen("D:\\data.txt", "r");  //����"r"�Ǳ�ʾ ��
	if (fpRead == NULL)
	{
		return 0;
	}
	for (i = 0; i < 10; i++)
	{
		fscanf(fpRead, "%d ", &a[i]);
	}
	sort(a, 10);
	printf("��߼�¼%d", a[0]);
	printf("\n");
	return 1;
}
void Rank(struct Tetris* tetris)
{
	//������д���ݣ�������0~9д�뵽data.txt�ļ���  
	FILE* fpWrite = fopen("D:\\data.txt", "a+");
	fprintf(fpWrite, "%d ", tetris->score);
	fclose(fpWrite);
} 

/*�����ַ���*/
void Rabbit() {
	color(3);
	gotoxy(84, 10);
	printf("��������    ��������");
	gotoxy(84, 11);
	printf("��  ��    ��  ��"); 
	gotoxy(84, 12);
	printf("��  ��    ��  ��");
	gotoxy(83, 13);
	printf("_��");
	gotoxy(95, 13);
	printf("��_");
	gotoxy(82, 14);
	printf("��");
	gotoxy(96, 14);
	printf("��");
	gotoxy(82, 15);
	printf("��             ��");
	gotoxy(82, 16);
	printf("��");
	gotoxy(96, 16);
	printf("��");
	gotoxy(82, 17);
	printf("��             ��");
	//
	gotoxy(82, 18);
	printf("�� �� �� �� �� �� �� ��");
	gotoxy(84, 19);
	printf("�� ��     �� ��");
	gotoxy(82,20);
	printf("�� �� �� �T �� �� �� ��");
	color(5);
	gotoxy(87, 13);
	printf("'~ '' ~'");
	color(4);
	gotoxy(86, 14);
	printf("��    ��");
	color(13);
	gotoxy(85, 15);
	printf("��");
	gotoxy(94, 15);
	printf("��");
	gotoxy(89, 17);
	printf("�� ");

}

int color(int c) {//����������ɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}
void gotoxy(int x, int y) {//��ȡ���λ��
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void title()
{
	color(15);
	gotoxy(24, 3);
	printf("Ȥ~ζ~��~��~˹~��~��\n");
	color(11);
	gotoxy(18, 5);
	printf("��");
	gotoxy(18, 6);
	printf("����");
	gotoxy(18, 7);
	printf("��");

	color(14);
	gotoxy(26, 6);
	printf("����");
	gotoxy(28, 7);
	printf("����");

	color(10);
	gotoxy(36, 6);
	printf("����");
	gotoxy(36, 7);
	printf("����");

	color(13);
	gotoxy(45, 5);
	printf("��");
	gotoxy(45, 6);
	printf("��");
	gotoxy(45, 7);
	printf("��");
	gotoxy(45, 8);
	printf("��");

	color(12);
	gotoxy(56, 6);
	printf("��");
	gotoxy(52, 7);
	printf("������");
}
/*
 �����ַ���
 */
void flower()
{
	gotoxy(66, 11);      
	color(12);            
	printf("(_)");      
	gotoxy(64, 12);
	printf("(_)");        
	gotoxy(68, 12);
	printf("(_)");       
	gotoxy(66, 13);
	printf("(_)");       
	gotoxy(67, 12);      
	color(6);
	printf("@");
	gotoxy(72, 10);
	color(13);
	printf("(_)");     
	gotoxy(76, 10);
	printf("(_)");     
	gotoxy(74, 9);
	printf("(_)");      
	gotoxy(74, 11);
	printf("(_)");      
	gotoxy(75, 10);
	color(6);
	printf("@");        
	gotoxy(71, 12);
	printf("|");          
	gotoxy(72, 11);
	printf("/");          
	gotoxy(70, 13);
	printf("\\|");     
	gotoxy(70, 14);
	printf("`|/");
	gotoxy(70, 15);
	printf("\\|");
	gotoxy(71, 16);
	printf("| /");
	gotoxy(71, 17);
	printf("|");
	gotoxy(67, 17);
	color(10);
	printf("\\\\\\\\");        
	gotoxy(73, 17);
	printf("//");
	gotoxy(67, 18);
	color(2);
	printf("^^^^^^^^");
	gotoxy(65, 19);
	color(5);
	printf("���������");
	gotoxy(65, 20);
	color(5);
	printf("������ ��� ��ӳɼ");


}
void welcome()
{
	int n;
	int i, j = 1;
	color(14);
	for (i = 9; i <= 20; i++)
	{
		for (j = 15; j <= 60; j++)
		{
			gotoxy(j, i);
			if (i == 9 || i == 20) printf("=");
			else if (j == 15 || j == 59)printf("||");
		}

		printf("\n");

	}
	flower();
	color(12);
	gotoxy(25, 12);
	printf("1.��ʼ��Ϸ");
	gotoxy(40, 12);
	printf("2.����˵��");
	gotoxy(32, 14);
	printf("3.��߼�¼");
	gotoxy(25, 17);
	printf("4.��Ϸ����");
	gotoxy(40, 17);
	printf("5.�˳�");
	gotoxy(21, 22);
	color(3);
	printf("��ѡ��1 2 3 4 5 ��: [ ]\b\b");
	color(14);
	scanf_s("%d", &n);
	
	switch (n) {
	case 1:
		system("cls");
		DrwaGameframe();
		Gameplay();
		break;
	case 2:
		explation();
		break;
	case 3:
		Max();
		printf("�����������������");
		_getch();
		system("cls");
		title();
		flower();
		welcome();
		break;
	case 4:
		regulation();
		break;
	case 5:
		close();
		break;
	
	}

}
void DrwaGameframe()
{
	gotoxy(FrameX + Frame_width - 7, FrameY - 2);
	color(11);
	printf("Ȥζ����˹����");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 7);
	color(2);
	printf("*************");
	gotoxy(FrameX + 2 * Frame_width + 13, FrameY + 7);
	color(3);
	printf("��һ�����ַ���");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 13);
	color(3);
	printf("*************");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 17);
	color(14);
	printf("��������ת");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 19);
	printf("�ո���ͣ��Ϸ");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 15);
	printf("Esc:�˳���Ϸ");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 21);
	printf("o:�򿪱�������");
	gotoxy(FrameX, FrameY);
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 23);
	printf("c:�رձ�������");
	gotoxy(FrameX, FrameY);
	color(13);
	printf("��");
	gotoxy(FrameX + 2 * Frame_width - 2, FrameY);
	printf("��");
	gotoxy(FrameX, FrameY + Frame_height);
	printf("��");
	gotoxy(FrameX + 2 * Frame_width - 2, FrameY + Frame_height);
	printf("��");
	Rabbit();
	a[FrameX][FrameY + Frame_height] = 2;
	a[FrameX + 2 * Frame_width - 2][FrameY + Frame_height] = 2;
	for (i = 2; i <=2 * Frame_width - 2; i += 2)
	{
		gotoxy(FrameX + i, FrameY);
		printf("��");                                  
	}
	for (i = 2; i <=2 * Frame_width - 2; i += 2)
	{
		gotoxy(FrameX + i, FrameY + Frame_height);
		printf("��");                                 //��ӡ�º��
		a[FrameX + i][FrameY + Frame_height] = 2;    //����º��Ϊ��Ϸ�߿򣬷�ֹ�������
	}
	for (i = 1; i < Frame_height + 1; i++)
	{
		gotoxy(FrameX, FrameY + i);
		printf("��");                                 //��ӡ������
		a[FrameX][FrameY + i] = 2;                   //���������Ϊ��Ϸ�߿򣬷�ֹ�������
	}
	for (i = 1; i < Frame_height; i++)
	{
		gotoxy(FrameX + 2 * Frame_width - 2, FrameY + i);
		printf("��");                                       //��ӡ������
		a[FrameX + 2 * Frame_width - 2][FrameY + i] = 2;   //���������Ϊ��Ϸ�߿򣬷�ֹ�������   
	}

}

/*��������˹����*/
void MakeTetris(struct Tetris* tetris)
{
	a[tetris->x][tetris->y] = b[0];
	switch (tetris->flag)
	{
	case 1: {
		color(10);
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x + 2][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	}
	case 2: {
		color(13);
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y] = b[2];
		a[tetris->x + 4][tetris->y] = b[3];
		break;
	}
	case 3: {
		color(14);
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y - 2] = b[2];
		a[tetris->x][tetris->y + 1] = b[3];
		break;
	}
	case 4: {
		color(11);
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y] = b[2];
		a[tetris->x][tetris->y + 1] = b[3];
		break;
	}
	case 5: {
		color(10);
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x - 2][tetris->y] = b[3];
		break;
	}
	case 6: {
		color(9);
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x - 2][tetris->y] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	}
	case 7: {
		color(8);
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	}
	case 8: {
		color(14);
		a[tetris->x][tetris->y + 1] = b[1];
		a[tetris->x - 2][tetris->y] = b[2];
		a[tetris->x + 2][tetris->y+1] = b[3];
		break;
	}
	case 9: {
		color(13);
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x - 2][tetris->y] = b[2];
		a[tetris->x - 2][tetris->y + 1] = b[3];
		break;
	}
	case 10: {
		color(12);
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x - 2][tetris->y] = b[2];
		a[tetris->x + 2][tetris->y-1] = b[3];
		break;
	}
	case 11: {
		color(8);
		a[tetris->x][tetris->y + 1] = b[1];
		a[tetris->x - 2][tetris->y - 1] = b[2];
		a[tetris->x - 2][tetris->y] = b[3];
		break;
	}
	case 12: {
		color(7);
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x - 2][tetris->y - 1] = b[3];
		break;
	}
	case 13: {
		color(6);
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	}
	case 14: {
		color(5);
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y + 1] = b[3];
		break;
	}
	case 15: {
		color(4);
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x - 2][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	}
	case 16: {
		color(3);
		a[tetris->x][tetris->y + 1] = b[1];
		a[tetris->x][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y - 1] = b[3];
		break;
	}
	case 17: {
		color(2);
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	}
	case 18: {
		color(15);
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x - 2][tetris->y + 1] = b[3];
		break;
	}
	case 19: {
		color(7);
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x - 2][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	}
	}
}
/*��ӡ����˹����*/
void PrintTetris(struct Tetris* tetris)
{
	for (i = 0; i < 4; i++)
	{
		b[i] = 1;
	}
	MakeTetris(tetris);
	for (i = tetris->x - 2; i <= tetris->x + 4; i += 2)
	{
		for (j = tetris->y - 2; j <= tetris->y + 1; j++)
		{
			if (a[i][j] == 1 && j > FrameY)
			{
				gotoxy(i, j);
				printf("��");
			}

		}
	}
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 1);
	color(4);
	printf("level:");
	color(12);
	printf("%d", tetris->level);
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 3);
	color(4);
	printf("score:");
	color(12);
	printf("%d", tetris->score);
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 5);
	color(4);
	printf("speed:");
	color(12);
	printf("%dms", tetris->speed);
}
/*�ж϶���˹�����Ƿ��ƶ�*/
int ifMove(struct Tetris* tetris) {
	if (a[tetris->x][tetris->y] != 0)
	{
		return 0;
	}
	else
	{
		if (
			(tetris->flag == 1 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
			(tetris->flag == 2 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y] == 0 && a[tetris->x + 4][tetris->y] == 0)) ||
			(tetris->flag == 3 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y - 2] == 0 && a[tetris->x][tetris->y + 1] == 0)) ||
			(tetris->flag == 4 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y] == 0 && a[tetris->x][tetris->y + 1] == 0)) ||
			(tetris->flag == 5 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y] == 0)) ||
			(tetris->flag == 6 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
			(tetris->flag == 7 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
			(tetris->flag == 8 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y + 1] == 0)) ||
			(tetris->flag == 9 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y + 1] == 0)) ||
			(tetris->flag == 10 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y - 1] == 0)) ||
			(tetris->flag == 11 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0)) ||
			(tetris->flag == 12 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y - 1] == 0)) ||
			(tetris->flag == 15 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y + 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
			(tetris->flag == 14 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 && a[tetris->x + 2][tetris->y + 1] == 0)) ||
			(tetris->flag == 13 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
			(tetris->flag == 16 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y - 1] == 0)) ||
			(tetris->flag == 19 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y] == 0)) ||
			(tetris->flag == 18 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y + 1] == 0)) ||
			(tetris->flag == 17 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y + 1] == 0 && a[tetris->x + 2][tetris->y] == 0)))
		{
			return 1;
		}
		
	}
	//
	return 0;
}
/*�������˹����ۼ�*/
void CleanTetris(struct Tetris* tetris) {
	for (i = 0; i < 4; i++)
	{
		b[i] = 0;
	}
	MakeTetris(tetris);
	for (i = tetris->x - 2; i <= tetris->x + 4; i += 2) {
		for (j = tetris->y - 2; j <= tetris->y + 1; j++) {
			if (a[i][j] == 0 && j > FrameY) {
				gotoxy(i, j);
				printf("  ");
			}
		}
	}
}
/*�ж��Ƿ����У���ɾ�����еĶ���˹����*/
void Del_Fullline(struct Tetris* tetris) {
	int k, del_rows = 0;
	for (j = FrameY + Frame_height - 1; j >= FrameY + 1; j--) 
	{
		k = 0;
		for (i = FrameX + 2; i < FrameX + 2 * Frame_width - 2; i += 2) {
			if (a[i][j] == 1) 
			{
				k++;
				if (k == Frame_width - 2) 
				{
					for (k = FrameX + 2; k < FrameX + Frame_width - 2; k += 2) {
						a[k][j] = 0;
						gotoxy(k, j);
						printf("  ");
						
					}

					for (k = j - 1; k > FrameY; k--) {
						for (i = FrameX + 2; i < FrameX + 2 * Frame_width - 2; i += 2) {
							if (a[i][k] == 1) {
								a[i][k] = 0;
								gotoxy(i, k);
								printf("  ");
								a[i][k + 1] = 1;
								gotoxy(i, k + 1);
								//
							    printf("��");
							}
						}
					}
					Music();
					//mciSendString(TEXT("close E:\\m.mp3"), NULL, 0, NULL);
					j++;
					del_rows++;
				}
				
			}
		}
	}
	tetris->score += 100 * del_rows;
	if (del_rows > 0 && (tetris->score % 1000 == 0 || tetris->score / 1000 > tetris->level - 1)) 
	{
		tetris->speed -= 20;
		tetris->level++;
	}
	

}
/*�����������˹�������͵����*/
void Flag(struct Tetris* tetris) {
	tetris->numder++;
	srand(time(NULL));
	if (tetris->numder == 1) {
		tetris->flag = rand() % 19 + 1;
	}
	tetris->next = rand() % 19 + 1;
}


/*��ʾ����˹���飬��ʼ��Ϸ*/
void Gameplay() {
	struct Tetris t, * tetris = &t;
	char ch;
	tetris->numder = 0;
	tetris->speed = 300;
	tetris->score = 0;
	tetris->level = 1;
	while (1) {
		Flag(tetris);
		Temp = tetris->flag;
		tetris->x = FrameX + 2 * Frame_width + 6;
		tetris->y = FrameY + 10;
		tetris->flag = tetris->next;
		PrintTetris(tetris);
		tetris->x = FrameX + Frame_width;
		tetris->y = FrameY - 1;
		tetris->flag = Temp;
		while (1)
		{

		label:PrintTetris(tetris);
			Sleep(tetris->speed);
			CleanTetris(tetris);
			Temp1 = tetris->x;
			Temp2 = tetris->flag;
			if (_kbhit())
			{
				ch = _getch();
				if (ch == 75)
				{
					tetris->x -= 2;
					if (ifMove(tetris) != 0)
					{
						tetris->y++;
						if (ifMove(tetris) == 0)
						{
							tetris->y--;
							PrintTetris(tetris);
							Del_Fullline(tetris);
							break;
						}
					}
				}
				if (ch == 77)
				{
					tetris->x += 2;
					if (ifMove(tetris) != 0)
					{
						tetris->y++;
						if (ifMove(tetris) == 0)
						{
							tetris->y--;
							PrintTetris(tetris);
							Del_Fullline(tetris);
							break;
						}
					}
				}
				if (ch == 80)
				{
					if (ifMove(tetris) != 0)
					{
						tetris->y += 2;
						if (ifMove(tetris) == 0)
						{
							tetris->y -= 2;
						}
					}
				}
				if (ch == 72)
				{
					if (tetris->flag >= 2 && tetris->flag <= 3)
					{
						tetris->flag++;
						tetris->flag %= 2;
						tetris->flag += 2;
					}
					if (tetris->flag >= 4 && tetris->flag <= 7)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 4;
					}
					if (tetris->flag >= 8 && tetris->flag <= 9)
					{
						tetris->flag++;
						tetris->flag %= 2;
						tetris->flag += 8;
					}
					if (tetris->flag >= 10 && tetris->flag <= 11)
					{
						tetris->flag++;
						tetris->flag %= 2;
						tetris->flag += 10;
					}
					if (tetris->flag >= 12 && tetris->flag <= 15)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 12;
					}
					if (tetris->flag >= 16 && tetris->flag <= 19)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 16;
					}
					if (ifMove(tetris) != 0)
					{
						tetris->y++;
						if (ifMove(tetris) == 0)
						{
							tetris->y--;
							PrintTetris(tetris);
							Del_Fullline(tetris);
							break;
						}
					}
				}
				if (ch == 32)
				{
					PrintTetris(tetris);
					while (1)
					{
						if (_kbhit())
						{
							ch = _getch();
							if (ch == 32)
							{
								goto label;
							}
						}
					}
				}
				if (ch == 27)
				{
					system("cls");
					memset(a, 0, 6400 * sizeof(int));
					title();
					flower();
					welcome();
				}
				if (ifMove(tetris) == 0)
				{
					tetris->x = Temp1;
					tetris->flag = Temp2;
				}
				if (ch == 111) {
					
						mciSendString(TEXT("open E:\\yueguang.mp3"), 0, 0, 0);
						mciSendString(TEXT("play E:\\yueguang.mp3"), 0, 0, 0);
				}
				if (ch == 99) {
					mciSendString(TEXT("close E:\\yueguang.mp3"), NULL, 0, NULL);
				}
				else
				{
					goto label;
				}
			}
			tetris->y++;
			if (ifMove(tetris) == 0) {
				tetris->y--;
				PrintTetris(tetris);
				Del_Fullline(tetris);
				break;
			}
		}
		for (i = tetris->y - 2; i < tetris->y + 2; i++)
		{
			if (i == FrameY)
			{
				system("cls");
				gotoxy(29, 7);
				printf("    \n");
				color(12);   
				printf("\t\t\t��������      ��      ��      ����\n");
				printf("\t\t\t��            ����    ��      ��   ��\n");
				printf("\t\t\t������        ��  ��  ��      ��     ��\n");
				printf("\t\t\t��            ��    ����      ��   ��\n");
				printf("\t\t\t��������      ��      ��      ����\n");
				gotoxy(17, 18);
				printf("��Ҫ������һ��-------1");
				gotoxy(44, 18);
				printf("�����ˣ��˳���-------2\n");
				int n;
				gotoxy(32, 20);
				printf("ѡ��1/2��: ");
				color(11);
				scanf_s("%d", &n);
				Rank(tetris);
				switch (n)
				{
				case 1:
					system("cls");
					Replay(tetris);
					break;
				case 2:
					close();
					break;
				}

			}
		}
		tetris->flag = tetris->next;
		tetris->x = FrameX + 2 * Frame_width + 6;
		tetris->y = FrameY + 10;
		CleanTetris(tetris);
	}
}
void Replay(struct Tetris* tetris)
{
	system("cls");
	memset(a, 0, 6400 * sizeof(int));
	DrwaGameframe();
	Gameplay();
}
void explation()
{
	int i, j = 1;
	system("cls");
	color(13);
	gotoxy(32, 3);
	printf("����˵��");
	color(2);
	for (i = 6; i <= 18; i++)
	{
		for (j = 15; j <= 60; j++)
		{
			gotoxy(j, i);
			if (i == 6 || i == 18) printf("=");
			else if (j == 15 || j == 59) printf("||");
		}
	}
	color(3);
	gotoxy(18, 7);
	printf("tip1:��ҿ���ͨ�� �� ����������ƶ�����");
	color(10);
	gotoxy(18, 9);
	printf("tip2:��ҿ���ͨ�� ��ʹ������ת");
	color(14);
	gotoxy(18, 11);
	printf("tip3:��ҿ���ͨ�� �����ٷ�������");
	color(11);
	gotoxy(18, 13);
	printf("tip4:���ո����ͣ��Ϸ���ٰ��ո������");
	color(4);
	gotoxy(18, 15);
	printf("tip5:��ESC�˳���Ϸ");
	color(7);
	gotoxy(18, 17);
	printf("�����������������");
	_getch();
	system("cls");
	title();
	flower();
	welcome();
}
void regulation()
{
	int i, j = 1;
	system("cls");
	color(13);
	gotoxy(34, 3);
	printf("��Ϸ����");
	color(2);
	for (i = 6; i <= 20; i++)
	{
		for (j = 12; j <= 70; j++)
		{
			gotoxy(j, i);
			if (i == 6 || i == 20) printf("=");
			else if (j == 12 || j == 69) printf("||");
		}
	}
	color(12);
	gotoxy(16, 7);
	printf("tip1:��ͬ��״��С�������Ļ�Ϸ����£����ͨ������");
	gotoxy(22, 9);
	printf("�����λ�úͷ���ʹ��������Ļ�ײ�ƴ��������");
	gotoxy(22, 11);
	printf("һ�л���");
	color(14);
	gotoxy(16, 13);
	printf("tip2:ÿ����һ�У���������100");
	color(11);
	gotoxy(16, 15);
	printf("tip3:ÿ�ۼ�1000�֣�������һ���ȼ�");
	color(10);
	gotoxy(16, 17);
	printf("tip4:�����ȼ���ʹ���������ٶȼӿ죬��Ϸ�ٶȼӴ�");
	color(7);
	gotoxy(16, 19);
	printf("�����������������");
	_getch();
	system("cls");
	title();
	flower();
	welcome();
}
void close()
{
	exit(0);
}
