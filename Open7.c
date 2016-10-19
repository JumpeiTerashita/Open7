#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Card[7];
int CardOpen[] = { 0,0,0,0,0,0,0 };
int NewOpened = 0;

void CardShuffle(void)
{
	srand((unsigned)time(NULL));
	while (Card[0] == 0)
	{
		Card[0] = (rand() % 8);
	}
	while ((Card[0] == Card[1]) || (Card[1] == 0))
	{
		Card[1] = (rand() % 8);
	}
	while ((Card[2] == Card[1]) || (Card[2] == Card[0]) || (Card[2] == 0))
	{
		Card[2] = (rand() % 8);
	}
	while ((Card[3] == Card[2]) || (Card[3] == Card[1]) || (Card[3] == Card[0]) || (Card[3] == 0))
	{
		Card[3] = (rand() % 8);
	}
	while ((Card[4] == Card[3]) || (Card[4] == Card[2]) || (Card[4] == Card[1]) || (Card[4] == Card[0]) || (Card[4] == 0))
	{
		Card[4] = (rand() % 8);
	}
	while ((Card[5] == Card[4]) || (Card[5] == Card[3]) || (Card[5] == Card[2]) || (Card[5] == Card[1]) || (Card[5] == Card[0]) || (Card[5] == 0))
	{
		Card[5] = (rand() % 8);
	}
	while ((Card[6] == Card[5]) || (Card[6] == Card[4]) || (Card[6] == Card[3]) || (Card[6] == Card[2]) || (Card[6] == Card[1]) || (Card[6] == Card[0]) || (Card[6] == 0))
	{
		Card[6] = (rand() % 8);
	}
}

void CardShow(void)
{
	if (CardOpen[0] == 1) printf("[%d]", Card[0]); else printf("[*]");
	if (CardOpen[1] == 1) printf("[%d]", Card[1]); else printf("[*]");
	if (CardOpen[2] == 1) printf("[%d]", Card[2]); else printf("[*]");
	if (CardOpen[3] == 1) printf("[%d]", Card[3]); else printf("[*]");
	if (CardOpen[4] == 1) printf("[%d]", Card[4]); else printf("[*]");
	if (CardOpen[5] == 1) printf("[%d]", Card[5]); else printf("[*]");
	if (CardOpen[6] == 1) printf("[%d]", Card[6]); else printf("[*]");
}

void CardChoice(void)
{
	int CardPlace = 0;
	scanf("%d", &CardPlace);
	if (CardPlace == 1) { CardOpen[0] = 1; NewOpened = 1; }
	if (CardPlace == 2) { CardOpen[1] = 1; NewOpened = 2; }
	if (CardPlace == 3) { CardOpen[2] = 1; NewOpened = 3; }
	if (CardPlace == 4) { CardOpen[3] = 1; NewOpened = 4; }
	if (CardPlace == 5) { CardOpen[4] = 1; NewOpened = 5; }
	if (CardPlace == 6) { CardOpen[5] = 1; NewOpened = 6; }
	if (CardPlace == 7) { CardOpen[6] = 1; NewOpened = 7; }
	if (CardPlace > 7 || CardPlace < 0) printf("ERROR!");
}

void CardEffect(void)
{
	if (
		(CardOpen[0] == 1)
		&& (CardOpen[1] == 1)
		&& (CardOpen[2] == 1)
		&& (CardOpen[3] == 1)
		&& (CardOpen[4] == 1)
		&& (CardOpen[5] == 1)
		&& (CardOpen[6] == 1)
		)
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
