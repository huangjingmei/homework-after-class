#include <iostream>
#include <vector>
#include <algorithm>
  using namespace std;
  struct active
 {
      int time;//��¼��Ŀ�ʼ������ʱ��
      bool ok;//true��ʾ���ʼ,false��־�����ʱ��
  };
 bool cmp(active x,active y)//�Ƚ�ʱ���Ĵ�С
 {
     return x.time<y.time;
 }
 
 int greedy(vector<active> x)//����
 {
     int roomnum=0,count=0,n=x.size();//roomnum��¼��Ҫ�Ļ᳡������count��¼���n=x.size()
     sort(x.begin(),x.end(),cmp);//��С��������һ�¸����ʱ���,���������cmp
     for(int i=0;i<n;i++)//�ӵ�һ�����ʼ����ʱ���
     {
         if(x[i].ok)//����ǻ��ʼʱ�� +1
             count++;
         else//����ǻ����ʱ�� -1            
			 count--;
       if((i==n-1 || x[i].time<x[i+1].time) && count>roomnum)//��ʱ����ж������У�������ص�����ֵ������Ҫ�����᳡��
             roomnum=count;                             
     }                                              
     return roomnum;                                   
 }
 
 int main()
 {
     vector<active> x;//����
     int n,i;
     active temp;
     while(cin>>n,n)//����n���,��2n��active
     {
         for(i=0;i<n;i++)
         {
             temp.ok=true;             
			 cin>>temp.time;
             x.push_back(temp);//���ʼʱ�䣬��־temp.timeΪtrue,��������
             temp.ok=false;
             cin>>temp.time;
             x.push_back(temp);//�����ʱ�䣬��־temp.timeΪfalse,��������
         }
         cout<<greedy(x)<<endl;//�����������ҵ�ֵ��λ�á�
         x.clear();//clearֻ�ǰ���ЩԪ��ȫ��ɾ�������������ͷ��ڴ�
    }
     return 0;
 }