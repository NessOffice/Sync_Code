#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 52;
struct Card{
	char suit;
	char value;
	Card(int _suit, int _value):suit(_suit), value(_value){}
};
struct Pile
{
	stack<Card> cards;
	int next, pre;
};
bool match(Card card1, Card card2)
{
	return (card1.suit == card2.suit) || (card1.value == card2.value);
}
int main()
{
	Pile piles[maxn];
	char cardInfo[4];
	int n = 0, cnts[maxn], cnt;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s", cardInfo) && cardInfo[0] != '#')
	{
		piles[n].cards.push(Card(cardInfo[0], cardInfo[1]));
		piles[n].next = n + 1;
		piles[n].pre = n - 1;
		n++;
		if(n == maxn)
		{
			int i, last = 0;//last用于减少计算量(然而从170ms到150ms也没减多少……)
			while(1)
			{
				i = last;
				bool flag = false;
				while(i < n)//只用一层循环是不够的，因为可能有后面的牌叠上来了之后能叠到前面的情况
				{
					int pre = piles[i].pre, pre3 = i;
					for(int j = 0;j < 3 && pre3 != -1;j++)
						pre3 = piles[pre3].pre;
					if(pre3 != -1 && match(piles[pre3].cards.top(), piles[i].cards.top()))
					{
						piles[pre3].cards.push(piles[i].cards.top());
						piles[i].cards.pop();
						last = pre3;
						flag = true;
					}
					else if(pre != -1 && match(piles[pre].cards.top(), piles[i].cards.top()))
					{
						piles[pre].cards.push(piles[i].cards.top());
						piles[i].cards.pop();
						last = pre;
						flag = true;
					}
					if(piles[i].cards.empty())
					{
						piles[piles[i].pre].next = piles[i].next;
						piles[piles[i].next].pre = piles[i].pre;
					}
					if(flag) break;
					i = piles[i].next;
				}
				if(i >= n) break;
				flag = false;
			}
			cnt = i = n = 0;
			while(i < maxn)
			{
				cnts[cnt] = 0;
				while(!piles[i].cards.empty()){cnts[cnt]++;piles[i].cards.pop();}
				cnt++;
				i = piles[i].next;
			}
			printf("%d pile%sremaining:", cnt, cnt > 1 ? "s " : " ");
			for(i = 0;i < cnt;i++) printf(" %d", cnts[i]); 
			printf("\n");
		}
	}
	return 0;
}
