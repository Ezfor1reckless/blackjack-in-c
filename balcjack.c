#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<math.h>
void shuffle(char* card);
void sendcards(char* card);
int score(char card);
int sumup(const char* card, int a);
void compare(int ,int);
char player1[52], player2[52];
char card[52] = { 'A','2','3','4','5','6','7','8','9','T','J','K','Q',
'A','2','3','4','5','6','7','8','9','T','J','K','Q',
'A','2','3','4','5','6','7','8','9','T','J','K','Q',
'A','2','3','4','5','6','7','8','9','T','J','K','Q' };
int main()
{
	char ch1[10], ch2[10], a, b, c, d, e, f;
	printf("请输入player1的姓名:");
	scanf_s("%s", ch1, 10);
	printf("请输入player2的姓名:");
	scanf_s("%s", ch2, 10);
	shuffle(card);
	sendcards(card);
	printf("是否开启下一局?");
	for (int i = 0; i < 4; i++) {
		printf("是否开启下一局?");
		getchar();
		if (getchar() == 'y' || getchar() == 'Y')
		{
			shuffle(card);
			sendcards(card);
		}
	}

	return 0;
}
void shuffle(char* card)
{
	char temp;
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		int j = rand() % 52;
		temp = card[i];
		card[i] = card[j];
		card[j] = temp;
	}
}
void sendcards(char* card)
{
	int  flag = 0;
	int   def1 = 2;
	int   def2 = 2;
	for (int i = 0; i < 2; i++) {
		player1[i] = card[i];
		for (int j = 0; j < 2; j++)player2[j]= card[j + 2];
	}
	printf("显示玩家的初始手牌:\n");
	printf("player1:%c %c\n", player1[0], player1[1]);
	printf("player2:%c %c\n", player2[0], player2[1]);
	printf("player1是否要牌?");
	getchar();
	if (getchar() == 'y' || getchar() == 'Y') {
		player1[def1] = card[flag];
		flag++, def1++;
		printf("player1当前手牌为:");
		for (int i = 0; i < 3; i++)printf("%c ", player1[i]);
	}
	printf("player2是否要牌?");
	getchar();
	if (getchar() == 'y' || getchar() == 'Y')
	{
		player2[def2] = card[flag];
		flag++, def2++;
		printf("player2当前手牌为:");
		for (int i = 0; i < 3; i++)printf("%c ", player2[i]);
	}
	printf("player1是否要牌?");
	getchar();
	if (getchar() == 'y' || getchar() == 'Y')
	{
		player1[def1] = card[flag];
		flag++, def1++;
		printf("player1当前手牌为:");
		for (int i = 0; i < 4; i++)printf("%c ", player1[i]);
	}
	printf("player2是否要牌?");
	getchar();
	if (getchar() == 'y' || getchar() == 'Y')
	{
		player2[def2]= card[flag];
		flag++, def2++;
		printf("player2当前手牌为:");
		for (int i = 0; i < 4; i++)printf("%c ", player2[i]);
	}
	printf("player1是否要牌?");
	getchar();
	if (getchar() == 'y' || getchar() == 'Y')
	{
		player1[def1] = card[flag];
		flag++, def1++;
		printf("player1当前手牌为:");
		for (int i = 0; i < 5; i++)printf("%c ", player1[i]);
	}
	printf("player2是否要牌?");
	getchar();
	if (getchar() == 'y' || getchar() == 'Y')
	{
		player2[def2] = card[flag];
		flag++;
		def2++;
		printf("player2当前手牌为:");
		for (int i = 0; i < 5; i++)printf("%c ", player2[i]);
	}
	compare(def1, def2);
}
int sumup(const char*card , int def)
{
	int sum = 0;
	int num = 0;
	for (int i = 0; i <def ; i++)
	{
		sum += score(card[i]);
		if (card[i] == 'A')
		{
			num++;
		}
	}
	while (sum > 21 && num > 0)
	{
		sum -= 10; // 把A从11分变为1分
		num--;
	}
	return sum;
}
int score(char card)
{
	if (card >= '2' && card <= '9')
	{
		return card - '0';
	}
	else if (card == 'T' || card == 'J' || card == 'Q' || card == 'K')
	{
		return 10;
	}
	else if (card == 'A') {
		return 11;
	}
	return 0;
}
void compare( int def1, int def2)
{
	int static p1 = 0;
	int static p2 = 0;
	printf("\n");
	int score1 = sumup(player1, def1);
	printf("player1's score:%d\n", score1);
	int score2 = sumup(player2, def2);
	printf("player2'score:%d\n", score2);
	if (score1 <= 21 && score2 <=21) {
		if (score1 < score2) {
			printf("player1 win.\n"); p1++;
		}
		else printf("player2 win.\n"); p2++;
	}
	else if (score1 >=21 && score2 <= 21) {
		printf("player2 win.\n"); p2++;
	}
	else if (score2 >= 21 && score1 <=21) {
		printf("player1 win.\n"); p1++;
	}
	else if (score1 >= 21 && score2 >= 21) {
		if (score1 > score2) {
			printf("player1 win.\n"); p1++;
		}
		else { printf("player2 win.\n"); p2++; }
	}
	printf("rank:%d:%d\n", p1, p2);
	if (p1 > p2)printf("player1 win the game!");
	else if (p2 > p1)printf("player2 win the game!");
	else printf("none win the game!");
}
