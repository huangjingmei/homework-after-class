#include<stdio.h>
int n;  //n������վ
 
int main(){
    scanf("%d",&n); 
    int **r=new int*[n+1];    //��������һ��ռ䣬������±�i�͵�i����ֵ��ͬ������ 
    for(int i=0;i<n+1;i++){
        r[i]=new int[n+1];
    }
    
    for(i=1;i<n+1;i++){  //��ѡ���Ե����룬�ò��ŵĶ����� 
        for(int j=i+1;j<n+1;j++)
            scanf("%d",&r[i][j]);
    }
    for(i=1;i<n+1;i++)  //���磺��3վ������վ�ļ�ǮΪ0�������ף����ȴ�ĳһվ�ߵ����Լ���
        r[i][i]=0;
    
    for(int l=2;l<=n;l++){  //����������վ��ʼ���𲽼���ÿ�������վ֮������Ž�
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            for(int k=i+1;k<j;k++){
                int temp=r[i][k]+r[k][j];
                if(temp<r[i][j])
                    r[i][j]=temp; 
            }   
        }
    }
    printf("%d\n",r[1][n]);
    return 0;
}
