#include <cstdio>
int main()
{
    int map[30], rmap[30], failed = 0, cnt = 0;
    char message[110], cipher[110], text[110];
    scanf("%s%s%s", message, cipher, text);
    for(int i = 0;i < 30;i++)
        map[i] = rmap[i] = -1;
    for(int i = 0;!failed && cipher[i];i++)
    {
        if(map[message[i]-'A'] >= 0 && map[message[i]-'A'] != cipher[i]-'A')
            failed = 1;
        if(rmap[cipher[i]-'A'] >= 0 && rmap[cipher[i]-'A'] != message[i]-'A')
            failed = 1;
        if(map[message[i]-'A'] < 0) cnt++;
        map[message[i]-'A'] = cipher[i]-'A';
        rmap[cipher[i]-'A'] = message[i]-'A';
    }
    if(failed || cnt < 26) printf("Failed\n");
    else for(int i = 0;text[i];i++)
        putchar(map[text[i]-'A']+'A');
	return 0;
}
