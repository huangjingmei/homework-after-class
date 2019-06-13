#include<stdio.h>
#include<memory.h>
int time_i;
int z;
int n;
int time_a = 0;   //���յ�ʱ��һ��С��time_a, �� min_t < time_a
int min_t =999999;   //min_t���������
int a[1024];
int b[1024];
int F[1024][1024];   //F[i][j]��ʾ����A���ǰi�����񻨷�С�ڵ���j����ʱ������B����Ҫ���ѵ���Сʱ��

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
     time_a += a[i];   //���趼�ڻ���A�����У��ó���ʱ���time_a
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
            if(j > a[i])  //�жϵ�ǰʱ���Ƿ����������ڻ���A������
            {
                F[i][j] = min(F[i - 1][j - a[i]], F[i - 1][j] + b[i]);   //�������A��ɵ�i�����񣬻���j���ӣ�˵�����ǰi-1������ʱ������A����j-a[i]���ӣ���ô����B����ʱ����F[i-1][j-a[i]]����
            }
            else
            {
                F[i][j] = F[i - 1][j] + b[i];   //��ʾB��������ʱ�䡣����A�������ǰi-1�����񣬻���j���ӣ�B��ɵ�i������
            }
        }
    }
    int temp;
    for(i = 0; i <= time_a; i++)   //��������F,F[n][i]
    {
        temp = max(F[n][i], i);   //��ʾ���ǰn���������A����i���ӣ�����B��F[n][i]��������µ�����깤ʱ��
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