#include<stdio.h>
#include<memory.h>
int time_i;
int z;
int n;
int time_a = 0;   //最终的时间一定小于time_a, 即 min_t < time_a
int min_t =999999;   //min_t设置无穷大，
int a[1024];
int b[1024];
int F[1024][1024];   //F[i][j]表示机器A完成前i个任务花费小于等于j分钟时，机器B所需要花费的最小时间

int max(int z,int x)
{
	if(z>x)
		return z;
	else 
		return x;
}

int min(int z,int x)
{
	if(z<x)
		return z;
	else 
		return x;
}


void inPut()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
     scanf("%d", &a[i]);
     time_a += a[i];   //假设都在机器A上运行，得出的时间和time_a
    }
    for(i=1; i <= n; i++)
        scanf("%d", &b[i]);
 
}
void solve()
{
    memset(F, 0, sizeof(F));
    for(int i = 1; i <= n; i++)
    {
        for( int j = 0; j <= time_a; j++)
        {
            if(j > a[i])  //判断当前时间是否满足任务在机器A上运行
            {
                F[i][j] = min(F[i - 1][j - a[i]], F[i - 1][j] + b[i]);   //代表机器A完成第i个任务，花费j分钟，说明完成前i-1个任务时，机器A花了j-a[i]分钟，那么机器B花的时间是F[i-1][j-a[i]]分钟
            }
            else
            {
                F[i][j] = F[i - 1][j] + b[i];   //表示B机器花的时间。其中A机器完成前i-1个任务，花了j分钟；B完成第i个任务
            }
        }
    }
    int temp;
    for(i = 0; i <= time_a; i++)   //遍历数组F,F[n][i]
    {
        temp = max(F[n][i], i);   //表示完成前n个任务机器A花了i分钟，机器B花F[n][i]分钟情况下的最迟完工时间
        if(min_t > temp)
            min_t = temp;   
    }
}

void main()
{
    inPut();
    solve();
    printf("%d\n", min_t);
}