import java.util.*;
public class biggesttuan {
	static int  num=0;
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int [][] a=new int[100][100];
		int [] b=new int[100];
		int [][] res=new int[100][100];//�ŵĽ��
		System.out.println("�������ĸ����ͱߵ���Ŀ");
		int n=in.nextInt();
		int m=in.nextInt();
		System.out.println("�������");
		for(int i=0;i<m;i++)
		{
			int x=in.nextInt();
			int y=in.nextInt();
			a[x][y]=1;
			a[y][x]=1;
		}
		b[0]=0;
		trackback(n,m,a,b,res);//����
		for(int i=0;i<num;i++)
		{
			if(res[i][0]>res[num][0])
			{
				res[num][0]=res[i][0];
			}
		}
		for(int i=0;i<num;i++)//�ó������
		{
			if(res[i][0]==res[num][0])
			{
				for(int j=1;j<=res[num][0];j++)
				{
					System.out.print("   "+res[i][j]);
				}
				System.out.println("");
			}
		}
	}
 
	private static void trackback(int n, int m, int[][] a,int [] b,int[][] c) {
		if(n<=0)
		{
			c[num][0]=b[0];
				for(int i=1;i<=b[0];i++)
				{
					c[num][i]=b[i];
				}
				num++;
			return;
		}
		else
		{
			int state=0;
			b[0]++;
			b[b[0]]=n;
			for(int i=1;i<=b[0];i++)//�����֮���Ƿ�Ϊ��ȫ��ͼ
			{
				if(a[b[i]][n]==1||b[i]==n)
					;
				else
					state=1;
			}
			if(state==0)
				trackback(n-1,m,a,b,c);
			b[0]--;
			trackback(n-1,m,a,b,c);
		}
		
	}
 
 
}
