#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define MaxCodeLen 1000                                     //������󳤶�
#define MaxTapeLen 3000                                     //ֽ����󳤶�

char Code[MaxCodeLen];                                      //����
char Tape[MaxTapeLen];                                      //ֽ��
int St[MaxCodeLen / 2];                                     //����ƥ�����ŵ�ջ
int top = 0;                                                //ջ��

int isLegalInstruction(char ch)
{
    int Ret = 0;
    switch(ch)
    {
        case '>' :
        case '<' :
        case '+' :
        case '-' :
        case '.' :
        case ',' :
        case '[' :
        case ']' : Ret = 1; break;
        case '\n' :
        case ' ' :
        case '\t' : Ret = 2; break;
        default : break;
    }
    return Ret;
}

int main()
{
    freopen("Pro.txt", "r", stdin);
    char ch;
    int len = 0;
    int cur = 0;
    int i, cnt;
    char* p = Tape + MaxTapeLen / 2;                        //Ϊ�˷��������ƶ�����ֽ�����м俪ʼ
    while((ch = getchar()) != EOF)
    {
        //printf("ch = %c\n", ch);
        switch(isLegalInstruction(ch))
        {
            case 0 :
                printf("illegal instruction\n");
                return 0;
            case 1 :
                Code[len++] = ch;
                break;
            default:
                break;
        }
    }
    //Code[len] = '\0';
    //printf("%s\n", Code);
    freopen("CON", "r", stdin);
    while(cur < len)
    {
        switch(Code[cur])
        {
            case '>' :
                p++;
                break;
            case '<' :
                p--;
                break;
            case '+' :
                (*p)++;
                break;
            case '-' :
                (*p)--;
                break;
            case '.' :
                printf("%c", *p);
                break;
            case ',' :
                *p = getchar();
                break;
            case '[' :
                if(*p)
                {
                    St[top++] = cur;
                }
                else
                {
                    cnt = 0;
                    for(i = cur; i < len; i++)
                    {
                        if(Code[i] == '[')
                            cnt++;
                        if(Code[i] == ']')
                            cnt--;
                        if(!cnt)
                            break;
                    }
                    if(!cnt)
                    {
                        cur = i;
                    }
                    else
                    {
                        printf("parentheses do not match\n");   //�����ű������Ŷ�
                        return 0;
                    }
                }
                break;
            case ']' :
                cur = St[top - 1] - 1;
                top--;
                break;
            default:
                break;
        }
        cur++;
        if(top < 0)
        {
            printf("parentheses do not match\n");               //�����ű������Ŷ�
            return 0;
        }
    }
    printf("\n");
    return 0;
}
