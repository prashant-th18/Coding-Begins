#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
void Get_YES_NO(int flag){printf("%s\n",(flag?"YES":"NO"));}
inline int read()
{
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*f;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vector<ll>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        vector<ll>cost[k];
        for(int i=0;i<n;i++){
            cost[a[i]%k].push_back(a[i]);
        }

        ll ans=0;
        vector<ll>b;
        while(cost[0].size()>=2){
            ll x=cost[0].back();
            cost[0].pop_back();
            ll y=cost[0].back();
            cost[0].pop_back();
            ans+=(x+y)/k;
        }
        while(cost[0].size()){
            b.push_back(cost[0].back());
            cost[0].pop_back();
        }
        for(int i=1;i<=k/2;i++){
            ll l=i;
            ll r=k-i;
            if(l==r){
                while(cost[l].size()>=2){
                    ll x=cost[l].back();cost[l].pop_back();
                    ll y=cost[l].back();cost[l].pop_back();
                    ans+=(x+y)/k;
                }
            }else {
                while(cost[l].size()&&cost[r].size()){
                    ll x=cost[l].back();cost[l].pop_back();
                    ll y=cost[r].back();cost[r].pop_back();
                    ans+=(x+y)/k;
                }
            }



            while(cost[l].size()){
                b.push_back(cost[l].back());
                cost[l].pop_back();
            }
            while(cost[r].size()){
                b.push_back(cost[r].back());
                cost[r].pop_back();
            }
        }
        sort(b.begin(),b.end());
        int m=b.size();
        ll res1=0,res2=0;
        for(int i=0;i<m/2;i++)res1+=(b[i]+b[m-i-1])/k;
        for(int i=m-2;i>=0;i-=2)res2+=(b[i]+b[i+1])/k;
        ll res=0;
        vector<int>vis(m,0);
        for(int i=m-1;i>=0;i--){
            if(vis[i])continue;
            int index_j=i;
            ll sum=k;
            for(int j=m-1;j>=0;j--){
                if(vis[j]||i==j)continue;
                if(sum>(b[i]+b[j])%k){
                    sum=(b[i]+b[j])%k;
                    index_j=j;
                }
            }
            res+=(b[i]+b[index_j])/k;
            vis[i]=vis[index_j]=1;
        }
        cout<<ans+max(res1,max(res2,res))<<endl;
    }
    cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}

