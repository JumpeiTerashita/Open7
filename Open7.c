#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MT.h"

int Card[7];
int CardOpen[] = { 0,0,0,0,0,0,0 };
int NewOpened = 0;

int ShuffleCheck(int* CardBox){
	for (int first = 0; first < 7; first++) {
		for (int second = first	+	1; second < 7; second++) {
			if (CardBox[first]==CardBox[second]) {
				return TRUE;
			}
		}
	}
	return FALSE;
}

void CardShuffle(void)
{
	init_genrand((unsigned)time(NULL));
	do {
		for (int i = 0; i < 7; i++) {
			Card[i] = (genrand_int32() % 7)	+	1;
		}
	} while(ShuffleCheck(Card));
}

void CardShow(void)
{
	for (int i = 0; i < 7; i++) {
		if (CardOpen[i] == TRUE) printf("[%d]", Card[i]); else printf("[*]");
	}
}

void CardChoice(void)
{
	int CardPlace = 0;
	scanf("%d", &CardPlace);
	CardOpen[CardPlace-1] = TRUE;
	NewOpened = CardPlace-1;
	if (CardPlace > 7 || CardPlace < 0) printf("ERROR!");
	return;
}

int CardIsFullOpen(void)
{
	for (int i = 0; i < 6; i++) {
		if(CardOpen[i]!= 1) return FALSE;
	}
	return TRUE;
}

void CardEffect(void)
{
	if (CardIsFullOpen())
	{
		CardShow();
		printf("\nすべてのカードをオープンしました！\nあなたの勝利です！\n");
		exit(0);
	}
	if (NewOpened == 1)
	{
		printf("あなたの選んだカードは%dでした\n", Card[0]);
		if (Card[0] == 1)
		{
			printf("左から1番目（CardPlace=1）・右から1番目（CardPlace=7）をめくることができます\n");
			if ((CardOpen[0] == 1) && (CardOpen[6] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[0] == 2)
		{
			printf("左から2番目（CardPlace=2）・右から2番目（CardPlace=6）をめくることができます\n");
			if ((CardOpen[1] == 1) && (CardOpen[5] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[0] == 3)
		{
			printf("左から3番目（CardPlace=3）・右から3番目（CardPlace=5）をめくることができます\n");
			if ((CardOpen[2] == 1) && (CardOpen[4] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[0] == 4)
		{
			printf("左右から4番目（CardPlace=4）をめくることができます\n");
			if (CardOpen[3] == 1) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[0] == 5)
		{
			printf("左から5番目（CardPlace=5）・右から5番目（CardPlace=3）をめくることができます\n");
			if ((CardOpen[4] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[0] == 6)
		{
			printf("左から6番目（CardPlace=6）・右から6番目（CardPlace=2）をめくることができます\n");
			if ((CardOpen[5] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[0] == 7)
		{
			printf("左から7番目（CardPlace=7）・右から7番目（CardPlace=1）をめくることができます\n");
			if ((CardOpen[6] == 1) && (CardOpen[0] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
	}

	if (NewOpened == 2)
	{
		printf("あなたの選んだカードは%dでした\n", Card[1]);
		if (Card[1] == 1)
		{
			printf("左から1番目（CardPlace=1）・右から1番目（CardPlace=7）をめくることができます\n");
			if ((CardOpen[0] == 1) && (CardOpen[6] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[1] == 2)
		{
			printf("左から2番目（CardPlace=2）・右から2番目（CardPlace=6）をめくることができます\n");
			if ((CardOpen[1] == 1) && (CardOpen[5] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[1] == 3)
		{
			printf("左から3番目（CardPlace=3）・右から3番目（CardPlace=5）をめくることができます\n");
			if ((CardOpen[2] == 1) && (CardOpen[4] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[1] == 4)
		{
			printf("左右から4番目（CardPlace=4）をめくることができます\n");
			if (CardOpen[3] == 1) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[1] == 5)
		{
			printf("左から5番目（CardPlace=5）・右から5番目（CardPlace=3）をめくることができます\n");
			if ((CardOpen[4] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[1] == 6)
		{
			printf("左から6番目（CardPlace=6）・右から6番目（CardPlace=2）をめくることができます\n");
			if ((CardOpen[5] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[1] == 7)
		{
			printf("左から7番目（CardPlace=7）・右から7番目（CardPlace=1）をめくることができます\n");
			if ((CardOpen[6] == 1) && (CardOpen[0] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
	}

	if (NewOpened == 3)
	{
		printf("あなたの選んだカードは%dでした\n", Card[2]);
		if (Card[2] == 1)
		{
			printf("左から1番目（CardPlace=1）・右から1番目（CardPlace=7）をめくることができます\n");
			if ((CardOpen[0] == 1) && (CardOpen[6] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[2] == 2)
		{
			printf("左から2番目（CardPlace=2）・右から2番目（CardPlace=6）をめくることができます\n");
			if ((CardOpen[1] == 1) && (CardOpen[5] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[2] == 3)
		{
			printf("左から3番目（CardPlace=3）・右から3番目（CardPlace=5）をめくることができます\n");
			if ((CardOpen[2] == 1) && (CardOpen[4] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[2] == 4)
		{
			printf("左右から4番目（CardPlace=4）をめくることができます\n");
			if (CardOpen[3] == 1) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[2] == 5)
		{
			printf("左から5番目（CardPlace=5）・右から5番目（CardPlace=3）をめくることができます\n");
			if ((CardOpen[4] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[2] == 6)
		{
			printf("左から6番目（CardPlace=6）・右から6番目（CardPlace=2）をめくることができます\n");
			if ((CardOpen[5] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[2] == 7)
		{
			printf("左から7番目（CardPlace=7）・右から7番目（CardPlace=1）をめくることができます\n");
			if ((CardOpen[6] == 1) && (CardOpen[0] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
	}

	if (NewOpened == 4)
	{
		printf("あなたの選んだカードは%dでした\n", Card[3]);
		if (Card[3] == 1)
		{
			printf("左から1番目（CardPlace=1）・右から1番目（CardPlace=7）をめくることができます\n");
			if ((CardOpen[0] == 1) && (CardOpen[6] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[3] == 2)
		{
			printf("左から2番目（CardPlace=2）・右から2番目（CardPlace=6）をめくることができます\n");
			if ((CardOpen[1] == 1) && (CardOpen[5] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[3] == 3)
		{
			printf("左から3番目（CardPlace=3）・右から3番目（CardPlace=5）をめくることができます\n");
			if ((CardOpen[2] == 1) && (CardOpen[4] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[3] == 4)
		{
			printf("左右から4番目（CardPlace=4）をめくることができます\n");
			if (CardOpen[3] == 1) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[3] == 5)
		{
			printf("左から5番目（CardPlace=5）・右から5番目（CardPlace=3）をめくることができます\n");
			if ((CardOpen[4] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[3] == 6)
		{
			printf("左から6番目（CardPlace=6）・右から6番目（CardPlace=2）をめくることができます\n");
			if ((CardOpen[5] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[3] == 7)
		{
			printf("左から7番目（CardPlace=7）・右から7番目（CardPlace=1）をめくることができます\n");
			if ((CardOpen[6] == 1) && (CardOpen[0] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
	}

	if (NewOpened == 5)
	{
		printf("あなたの選んだカードは%dでした\n", Card[4]);
		if (Card[4] == 1)
		{
			printf("左から1番目（CardPlace=1）・右から1番目（CardPlace=7）をめくることができます\n");
			if ((CardOpen[0] == 1) && (CardOpen[6] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[4] == 2)
		{
			printf("左から2番目（CardPlace=2）・右から2番目（CardPlace=6）をめくることができます\n");
			if ((CardOpen[1] == 1) && (CardOpen[5] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[4] == 3)
		{
			printf("左から3番目（CardPlace=3）・右から3番目（CardPlace=5）をめくることができます\n");
			if ((CardOpen[2] == 1) && (CardOpen[4] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[4] == 4)
		{
			printf("左右から4番目（CardPlace=4）をめくることができます\n");
			if (CardOpen[3] == 1) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[4] == 5)
		{
			printf("左から5番目（CardPlace=5）・右から5番目（CardPlace=3）をめくることができます\n");
			if ((CardOpen[4] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[4] == 6)
		{
			printf("左から6番目（CardPlace=6）・右から6番目（CardPlace=2）をめくることができます\n");
			if ((CardOpen[5] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[4] == 7)
		{
			printf("左から7番目（CardPlace=7）・右から7番目（CardPlace=1）をめくることができます\n");
			if ((CardOpen[6] == 1) && (CardOpen[0] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
	}

	if (NewOpened == 6)
	{
		printf("あなたの選んだカードは%dでした\n", Card[5]);
		if (Card[5] == 1)
		{
			printf("左から1番目（CardPlace=1）・右から1番目（CardPlace=7）をめくることができます\n");
			if ((CardOpen[0] == 1) && (CardOpen[6] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[5] == 2)
		{
			printf("左から2番目（CardPlace=2）・右から2番目（CardPlace=6）をめくることができます\n");
			if ((CardOpen[1] == 1) && (CardOpen[5] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[5] == 3)
		{
			printf("左から3番目（CardPlace=3）・右から3番目（CardPlace=5）をめくることができます\n");
			if ((CardOpen[2] == 1) && (CardOpen[4] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[5] == 4)
		{
			printf("左右から4番目（CardPlace=4）をめくることができます\n");
			if (CardOpen[3] == 1) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[5] == 5)
		{
			printf("左から5番目（CardPlace=5）・右から5番目（CardPlace=3）をめくることができます\n");
			if ((CardOpen[4] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[5] == 6)
		{
			printf("左から6番目（CardPlace=6）・右から6番目（CardPlace=2）をめくることができます\n");
			if ((CardOpen[5] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[5] == 7)
		{
			printf("左から7番目（CardPlace=7）・右から7番目（CardPlace=1）をめくることができます\n");
			if ((CardOpen[6] == 1) && (CardOpen[0] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
	}

	if (NewOpened == 7)
	{
		printf("あなたの選んだカードは%dでした\n", Card[6]);
		if (Card[6] == 1)
		{
			printf("左から1番目（CardPlace=1）・右から1番目（CardPlace=7）をめくることができます\n");
			if ((CardOpen[0] == 1) && (CardOpen[6] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[6] == 2)
		{
			printf("左から2番目（CardPlace=2）・右から2番目（CardPlace=6）をめくることができます\n");
			if ((CardOpen[1] == 1) && (CardOpen[5] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[6] == 3)
		{
			printf("左から3番目（CardPlace=3）・右から3番目（CardPlace=5）をめくることができます\n");
			if ((CardOpen[2] == 1) && (CardOpen[4] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[6] == 4)
		{
			printf("左右から4番目（CardPlace=4）をめくることができます\n");
			if (CardOpen[3] == 1) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}

		if (Card[6] == 5)
		{
			printf("左から5番目（CardPlace=5）・右から5番目（CardPlace=3）をめくることができます\n");
			if ((CardOpen[4] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[6] == 6)
		{
			printf("左から6番目（CardPlace=6）・右から6番目（CardPlace=2）をめくることができます\n");
			if ((CardOpen[5] == 1) && (CardOpen[2] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
		if (Card[6] == 7)
		{
			printf("左から7番目（CardPlace=7）・右から7番目（CardPlace=1）をめくることができます\n");
			if ((CardOpen[6] == 1) && (CardOpen[0] == 1)) { printf("めくれるカードがありません！ゲームセット！"); exit(0); }
		}
	}
}

int main(void)
{
	CardShuffle();

	while (!(
		(CardOpen[0] == 1)
		&& (CardOpen[1] == 1)
		&& (CardOpen[2] == 1)
		&& (CardOpen[3] == 1)
		&& (CardOpen[4] == 1)
		&& (CardOpen[5] == 1)
		&& (CardOpen[6] == 1)
		))
	{
		CardShow();
		CardChoice();
		CardEffect();
	}
	return 0;
}
