#include<bits/stdc++.h>
using namespace std;
struct segm
{
	int l,r,z;
	segm(int l=0,int r=0,int z=0):l(l),r(r),z(z){}
	bool operator<(const segm &other)const
	{
		return z>other.z;
	}
};
priority_queue<segm>pq;
int a[4005][4005],f[4005][4005];
bitset<4005>bs[4005];
bitset<4005>bss[4005];
int t1[4000005],t2[4000005],q1[4000005],q2[4000005];
int main()
{
	int n;
	scanf("%d",&n);
	int ff=n*n/4;
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)
		if(j-i&1)scanf("%d",&a[i][j]),t1[a[i][j]]=i,t2[a[i][j]]=j;
	for(int i=1;i<n;i++)f[i][i+1]=a[i][i+1];
	for(int z=1;z<=ff;z++)
	{
		int l=t1[z],r=t2[z];
		if(!f[l][r])
		{
			if(!f[l+1][r-1]||f[l+1][r-1]>a[l][r])continue;
			f[l][r]=a[l][r];
		}
		if(f[l][r]!=z)continue;
		bs[l][r]=bss[r][l]=1; 
		int head=0,tail=-1;
		tail++;
		q1[tail]=l,q2[tail]=r;
		while(head<=tail)
		{
			int p=head++,l=q1[p],r=q2[p],flag=1;
			if(l==1&&r==n)break;
			if(l!=1&&r!=n&&!bs[l-1][r+1]&&a[l-1][r+1]<z)
			{
				f[l-1][r+1]=z;
				tail++;
				q1[tail]=l-1,q2[tail]=r+1;
				bs[l-1][r+1]=bss[r+1][l-1]=1;
				if(l-1==1&&r+1==n)
				{
					flag=0;
					break;
				}
			}
			if(!flag)break;
			if(r!=n)
			{
				bitset<4005>sb=(~bs[l])&bs[r+1];
				for(int x=sb._Find_first();x!=4005;x=sb._Find_next(x))
				{
					if(x<=r+1)continue;
					f[l][x]=z;
					tail++;
					q1[tail]=l,q2[tail]=x;
					bs[l][x]=bss[x][l]=1;
					if(l==1&&x==n)
					{
						flag=0;
						break;
					}
				}
			}
			if(!flag)break;
			if(l!=1)
			{
				bitset<4005>sb=bss[l-1]&(~bss[r]);
				for(int x=sb._Find_first();x!=4005;x=sb._Find_next(x))
				{
					if(x>=l-1)break;
					f[x][r]=z;
					tail++;
					q1[tail]=x,q2[tail]=r;
					bs[x][r]=bss[r][x]=1;
					if(x==1&&r==n)
					{
						flag=0;
						break;
					}
				}
			}
			if(!flag)break;
		}
		if(f[1][n])break;
	}
	cout<<f[1][n]<<endl;
	cerr << f[1][n] << endl;
	return 0;
}