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

//------------------------------------------------------------- header files &  functions -------------------------------------------------------------------//
vector<vector<int> > tree;
vector<int> traverse(int idx,string col,int &a){
    
    vector<int> curr = {0,0};
    for (int i = 0; i < tree[idx].size(); i++)
    {
        vector<int> temp = traverse(tree[idx][i],col,a);
        curr[0]+=temp[0];
        curr[1]+=temp[1];
       
    }
    if(col[idx-1]=='B'){
        curr[1]++;
    }
    else
    {
        curr[0]++;
    }

    if(curr[0]==curr[1]){
        // cout<<"idx - "<<idx<<nl;
        a++;
    }
    // cout<<curr.first<<" -- "<<curr.second<<" at index "<<idx<<nl;

    return curr;
    

}

int solve(){

    int n;
    cin>>n;
    tree=  vector<vector<int> >(n+1);
   
   
    for (int i = 2; i <tree.size(); i++)
    {
        int temp;
        cin>>temp;
        tree[temp].push_back(i);

        
        
    }
    string col;
    cin>>col;
    int a=0;
    traverse(1,col,a);
    cout<<a<<nl;


    
    
    return 1;
    
}


int32_t main()
{  



    // for (int i = 2; i <=10; i++)
    // {
    //     for (int j = 1; j < i; j++)
    //     {
    //         solve(15,i,j);
    //         /* code */
    //     }
        
    //     /* code */
    // }
    





    // return 1;


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