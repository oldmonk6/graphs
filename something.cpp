#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int prime(int n1,int n2)
{
    int mul=1;
    int k=max(n1,n2);
    vector<int>ans(k,0);
    vector<int>ans2(k,0);
    for(int i=2;i<n1;i++)
    {
        if(n1%i==0){
        while(n1%i==0)
        {
            n1=n1/i;
            ans[i]+=1;
        }
        }
    }
    if(n1!=1)ans[n1]+=1;
    for(int i=2;i<n2;i++)
    {
        if(n2%i==0){
        while(n2%i==0)
        {
            n2=n2/i;
            ans2[i]+=1;

        }
        }
    }
    if(n2!=1)ans2[n2]+=1;
    for(int i=2;i<ans.size();i++)
    {
        if(ans[i]>0 && ans2[i]>0)
        {
            if(ans[i]==ans2[i])mul=mul*pow(i,ans[i]);
            else {
               mul=mul*pow(i,min(ans[i],ans2[i]));
            }
          
        }
        
    }
    return mul;

    

}
int main()
{
    int n1,n2;
    cout<<"enter the value of two numbers";
    cin>>n1>>n2;
    cout<<prime(n1,n2);

}