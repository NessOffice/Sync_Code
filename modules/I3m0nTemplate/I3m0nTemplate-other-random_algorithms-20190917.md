# random-1.退火算法

~~~cpp
// using anneal algorithm to calculate general weighted fermat point
const int maxn = 1e4+5;
const double T0 = 1e5;
const double T1 = 1e-3;
const double INF = 1e200;
int n;
double x[maxn], y[maxn], w[maxn], x_ans, y_ans, dis = INF;
double get_rand(){return (double)rand() / RAND_MAX;}
double calc(double x_new, double y_new)
{
    double dis_new = 0;
    for(int i = 1;i <= n;i++)
        dis_new += sqrt((x_new-x[i])*(x_new-x[i])+(y_new-y[i])*(y_new-y[i]))*w[i];
    if(dis_new < dis)
        dis = dis_new, x_ans = x_new, y_ans = y_new;
    return dis_new;
}
void simulate_anneal()
{
    double T = T0;
    double x_now = x_ans, y_now = y_ans;
    while(T > T1)
    {
        double x_nxt = x_now + T*(2*get_rand()-1);
        double y_nxt = y_now + T*(2*get_rand()-1);
        double delta = calc(x_nxt, y_nxt) - calc(x_now, y_now);
        if(exp(-delta / T) > get_rand())
            x_now = x_nxt, y_now = y_nxt;
        T *= 0.97;
    }
    for(int i = 1;i <= 1000;i++)
    {
        double x_nxt = x_ans + T * (2*get_rand()-1);
        double y_nxt = y_ans + T * (2*get_rand()-1);
        calc(x_nxt, y_nxt);
    }
}
int main()
{
    srand(time(0));
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%lf%lf%lf", x+i, y+i, w+i),
        x_ans += x[i], y_ans += y[i];
    x_ans /= n, y_ans /= n;
    calc(x_ans, y_ans);
    simulate_anneal();
    printf("%.3lf %.3lf", x_ans, y_ans);
    return 0;
}
~~~





// ver1.0 updated by Ness, 20190917