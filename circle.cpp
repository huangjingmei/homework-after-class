#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
 
float CirclePerm(int n,float *a);
 
template <class Type>
inline void Swap(Type &a, Type &b);
 
int main()
{   int n;
    cout<<"������Բ�ĸ�����"<<endl;
	cin >> n;
   	float *a = new float[n];
	cout<<"������Բ�İ뾶��"<<endl;
	for(int i=1; i<n+1; i++){
	   cin >> a[i];
	}
	cout<<"��СԲ���г���Ϊ��";
	cout<<CirclePerm(n,a)<<endl;
	return 0;
}
 
class Circle
{
	friend float CirclePerm(int,float *);
	private:
		float Center(int t);//���㵱ǰ��ѡ���Բ�ڵ�ǰԲ������Բ�ĵĺ�����
		void Compute();//���㵱ǰԲ���еĳ���
		void Backtrack(int t);
 
		float min,	//��ǰ����ֵ
			  *x,   //��ǰԲ����Բ�ĺ�����
			  *r;   //��ǰԲ����
	    int n;      //Բ������Բ�ĸ���
};


 // ���㵱ǰ��ѡ��Բ��Բ�ĺ�����
float Circle::Center(int t)
{
    float temp=0;
    for (int j=1;j<t;j++)
	{


		//��x^2 = sqrt((r1+r2)^2-(r1-r2)^2)�Ƶ�����
        float valuex=x[j]+2.0*sqrt(r[t]*r[j]);
        if (valuex>temp)
		{
			temp=valuex;
		}
    }
    return temp;
}
 

// ���㵱ǰԲ���еĳ���
void Circle::Compute(void)
{
    float low=0,high=0;
    for (int i=1;i<=n;i++)
	{
        if (x[i]-r[i]<low)
		{
			low=x[i]-r[i];
		}
 
        if (x[i]+r[i]>high)
		{
			high=x[i]+r[i];
		}
    }
    if (high-low<min)
	{
		min=high-low;
	}
}
 
void Circle::Backtrack(int t)
{
    if (t>n)
	{
		Compute();
	}
    else
	{
		for (int j = t; j <= n; j++)
		{
			Swap(r[t], r[j]);
			float centerx=Center(t);
			if (centerx+r[t]+r[1]<min)//�½�Լ��
			{
				x[t]=centerx;
				Backtrack(t+1);
			}
			Swap(r[t], r[j]);
		}
	}
}
 
float CirclePerm(int n,float *a)
{
	Circle X;
	X.n = n;
	X.r = a;
	X.min = 100000;
	float *x = new float[n+1];
	X.x = x;
	X.Backtrack(1);
	delete []x;
	return X.min;
}
 
template <class Type>
inline void Swap(Type &a, Type &b)
{  
	Type temp=a; 
	a=b; 
	b=temp;
}
