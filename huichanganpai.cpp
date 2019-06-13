#include <iostream>
#include <vector>
#include <algorithm>
  using namespace std;
  struct active
 {
      int time;//记录活动的开始、结束时间
      bool ok;//true表示活动开始,false标志活动结束时间
  };
 bool cmp(active x,active y)//比较时间点的大小
 {
     return x.time<y.time;
 }
 
 int greedy(vector<active> x)//容器
 {
     int roomnum=0,count=0,n=x.size();//roomnum记录需要的会场个数，count记录活动，n=x.size()
     sort(x.begin(),x.end(),cmp);//从小到大排序一下各个活动时间点,排序规则是cmp
     for(int i=0;i<n;i++)//从第一个活动开始排序时间点
     {
         if(x[i].ok)//如果是活动开始时间 +1
             count++;
         else//如果是活动结束时间 -1            
			 count--;
       if((i==n-1 || x[i].time<x[i+1].time) && count>roomnum)//此时间点有多个活动进行，而这个重叠活动最大值就是需要的最大会场数
             roomnum=count;                             
     }                                              
     return roomnum;                                   
 }
 
 int main()
 {
     vector<active> x;//容器
     int n,i;
     active temp;
     while(cin>>n,n)//输入n个活动,即2n个active
     {
         for(i=0;i<n;i++)
         {
             temp.ok=true;             
			 cin>>temp.time;
             x.push_back(temp);//活动开始时间，标志temp.time为true,进入容器
             temp.ok=false;
             cin>>temp.time;
             x.push_back(temp);//活动结束时间，标志temp.time为false,进入容器
         }
         cout<<greedy(x)<<endl;//返回容器内找到值的位置。
         x.clear();//clear只是把那些元素全部删除掉，并不是释放内存
    }
     return 0;
 }