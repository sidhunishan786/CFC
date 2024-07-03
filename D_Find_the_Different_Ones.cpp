#include<bits/stdc++.h>

using namespace std;
// fast input and output 
void init_code(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
//user  -->>  "sidhunishan786"
#define mp make_pair
#define nl "\n"
#define pb push_back
#define mod 1000000007
#define bp __builtin_popcount
#define gd __gcd
#define int long long int
#define ld float
const double pi=3.1415926;
// seive 
vector<int> soe(int n){
    vector<bool> v(n+1,true);
    v[0]=v[1]=false;

    for (int i = 2; i*i <= n; i++)
    {
        if(v[i]){
            for (int j = i*i; j<v.size(); j=j+i)
            {
            v[j]=false;
            }
        }

    }
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]) ans.push_back(i);
      
    }
    
    
    return ans;
   
}

// fast exponentation 

int b_expo(int n,int m){
    if(m==0){
        return 1;
    }
    if(m==1) return n%mod;

    int x=b_expo(n,m/2);
    if(m%2==1){
        return ((x)*(x)*(n))%mod;
    }
    return ((x)*(x))%mod;
}

// fibonacci series 

vector<int> fibseries(){
    int rem=1;
    int a=0;
    int b=1;
    int c=1;
    vector<int> fib(60);
    for (int i = 0; i < 60; i++)
    {
        
        fib[i]=a%10;
        a=b%10;
        b=c%10;
        c=(a+b)%10;
        
    }
    return fib;
}


// function for printing vector

template <typename T> void printv(vector<T> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

bool ispalin(string s){
    for (int i = 0; i < s.size()/2; i++)
    {
        if(s[i]!=s[s.size()-i-1]) return false;
        /* code */
    }
    
    return true;
}



vector<int> merge_sorted_vecs(vector<int> v,vector<int> t){
    vector<int> ans(v.size()+t.size());
    int idx=0;
    int iv=0,it=0;
    while (iv<v.size() && it<t.size())
    {
        if(v[iv]<t[it]){
            ans[idx]=v[iv];
            iv++;
        }
        else
        {
            ans[idx]=t[it];
            it++;
        }
        idx++;
        /* code */
    }
    while (iv<v.size())
    {
        ans[idx]=v[iv];
        iv++;
        idx++;
        /* code */
    }
    while (it<t.size())
    {
        ans[idx]=v[it];
        it++;
        idx++;
    }
    
    return ans;
    

}

//disjoint set union

int find(int x,vector<int> &p){
    if(x==p[x]) return x;

    return p[x]=find(p[x],p);
}

void union_(int x,int y,vector<int> &p){
    x=find(x,p);
    y=find(y,p);
    p[min(x,y)]=max(x,y);
    return ;
}

int factorial(int n){
    int x=1;
    for (int i = 2; i <=n; i++)
    {
        x=x*i;
    }
    return x;

}

int NCR(int n,int r){
    int ans=1;
    for (int i = n; i >n-r; i--)
    {
        ans*=i;
        
        /* code */
    }
    for (int i = 1; i <=r; i++)
    {
        ans/=i;
        /* code */
    }

    return ans;
    
    
}
void input_arr(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cin>>v[i];
   
    }
    
}
bool isprime(int x){
    int y=sqrt(x);
    for (int i = 2; i <=y; i++)
    {
        if(x%i==0) return false;
        /* code */
    }
    return true;
}

bool issorted(vector<int> s){
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i-1]>s[i]) return false;
        /* code */
    }
    return true;
    
}
int sum_of_digs(int n){
    int x=0;
    while (n)
    {
        x+=(n%10);
        n/=10;
      
    }

    return x;
}
vector<int> add_arrays(vector<int> v1,vector<int> v2){
    vector<int> v3(v1.size(),0);
    int c=0;
    for (int i = 99; i >=0; i--)
    {
        int curr=v1[i]+v2[i]+c;
        v3[i]=curr%10;
        c=curr/10;

    }
    return v3;
    
}

int sum_of_arr(vector<int> v){
    int ans=0;
    for (int i = 0; i < v.size(); i++)
    {
        ans+=v[i];
        /* code */
    }
    return ans;
    
}
int sqrtoflonglong(int x){
    int ans=1;
    while (ans*ans<x)
    {
        ans++;
        /* code */
    }
    if(ans*ans==x) return ans;
    
    return ans-1;

}
unordered_map<int,int> factorize(int n){
    int count = 0;
    unordered_map<int,int> m;

    while (!(n % 2)) {
        n >>= 1; 
        count++;
    }
 
    
    if (count){
        m.insert(make_pair(2,count));
    }
 
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count){
            m.insert(make_pair(i,count));
        }
            
    }
   
    if (n > 2){
        m.insert(make_pair(n,1));
    }
    return m;

}

int no_of_digs(int n){
    int c=0;
    while (n)
    {
        n/=10;
        c++;
        /* code */
    }
    return c;
    
}


void computeLPSArray(string pat, int M, vector<int> &lps)
{

    int len = 0;
 
    lps[0] = 0; 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            
            if (len != 0) {
                len = lps[len - 1];
 
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPSearch(string pat, string txt)
{
    int M = (pat.length());
    int N = (txt.length());
    vector<int> lps(M),ans;

    computeLPSArray(pat, M, lps);
 
    int i = 0; 
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            
            ans.push_back(i-j);
            j = lps[j - 1];
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
           
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return ans;
}


//------------------------------------------------------------- header files &  functions -------------------------------------------------------------------//




int solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    input_arr(v);
    vector<int> dis(n+20,INT_MAX-2);
   
    dis[0]=-1;
    dis[1]=0;
    int idx=2;
    for (int i = 1; i < n; i++)
    {
       
        if(v[i]!=v[i-1]){dis[idx]=i;idx++;}

    }
    dis[idx]=n+1;
    idx++;
    // cout<<"dis is -> ";
    // printv(dis);

    int q;
    cin>>q;
    while (q--)
    {
        int st,ed;
        cin>>st>>ed;
        st--;
        ed--;
        if(st==ed){
            cout<<-1<<" "<<-1<<nl;
            continue;
        }
        int stu = lower_bound(dis.begin(),dis.end(),st)-dis.begin();
        int edu = lower_bound(dis.begin(),dis.end(),ed)-dis.begin();

        // stu=dis[stu];
        // edu=dis[edu];
        if(dis[stu]>st){
            stu--;
        }
        if(dis[edu]>ed){
            edu--;
        }
        // cout<<"st and ed are --> ";
        // cout<<st<<" - "<<ed<<nl;
        // cout<<"stu and edu are --> ";
        // cout<<stu<<" - "<<edu<<nl;

        if(stu==edu){
            cout<<-1<<" "<<-1<<nl;
        }
        else
        {
            // cout<<"diff\n";
            cout<<max(dis[stu]+1,st+1)<<" "<<dis[stu+1]+1<<nl;
        }
        
    }
    
    return 1;
    

    
}


int32_t main()
{  
 


    int t;
    t=1; // for single test case.
    cin>>t;
    ////
    
    while (t--)
    {
        solve();
        
    }
    return 0;

}