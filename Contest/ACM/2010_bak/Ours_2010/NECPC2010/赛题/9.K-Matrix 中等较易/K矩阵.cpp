#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define N 201
int array[N][N];
int sum[N];
int main()
{
    int n,var;
    freopen("KArray.in","r",stdin);
    freopen("out.out","w",stdout);
    //int now = clock();
    //int max=0;
    while(scanf("%d%d",&n,&var)!=EOF)
    {   
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&array[i][j]);
        int flag=0;
        for(int i=0;i<n&&!flag;++i)
        {   
            memset(sum,0,sizeof(sum));
            for(int j=i;j<n;++j)
            {   
                int count=0;
                for(int k=0;k<n;++k)
                {
                    sum[k]+=array[j][k];
                    if(sum[k]>var) count++;
                }
                if(count==n) break;
                int tmp=0,left=0;
                for(int k=0;k<n;++k)
                {
					tmp += sum[k];
                    while(tmp>var)
                    {
                        tmp-=sum[left];
                        left++;
                    }
					if(tmp==var)
                    {
                        flag=1;
                        break;
                    }
					/*
					//���tmp����sum[n-1]��==var���޷��ж� 
                    if(tmp<var) tmp+=sum[k];
                    else if(tmp==var)
                    {
                        flag=1;
                        break;
                    }
                    //������ڵĻ����sum[k]Ҳ�ü�
					//ֻ��һ��sum[left]�޷���֤tmp�ͻ�<var
					//�������ע�Ͳ��� 
                    else if(tmp>var)
                    {
                        tmp-=sum[left];
                        left++;
                    }
                    */
				}
            }
        }
        if(flag) printf("yes\n");
        else printf("no\n");
        //if(!flag&&n>max) max=n; 
    }
    //printf("%dms\n",clock()-now);
}
