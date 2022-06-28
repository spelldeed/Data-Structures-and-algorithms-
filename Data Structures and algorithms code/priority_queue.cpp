#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
#define fon(i,a,n) for(ll i=a;i>=n;i--)

using namespace std;


void max_heapify(vector<ll> &v, ll k)
{
      ll m=2*k;
      ll n=2*k+1;
      ll largest=k;
      if((m<=v.size()-1)&&(v[m]>v[largest]))
      {
          largest=m;
      }
      if ((n<=v.size()-1)&&(v[n]>v[largest]))
      {
          largest=n;
      }
      if(largest!=k)
      {
          swap(v[largest],v[k]);
      }
}

void insert(vector<ll> &v)
{
    cout<<"Enter the number : ";
    ll k;
    cin>>k;
    if(v.size()==0)
    {
        v.push_back(k);
    }
    else
    {
        v.push_back(k);
        fon(i,(v.size()/2)-1,0)
        {
            max_heapify(v,i);
        }


    }
}

void Delete(vector<ll> &v)
{
    if (v.size()==0)
    {
        cout<<"Priority Queue is empty";
        return;
    }
    cout<<"Enter the number : ";
    ll k;
    cin>>k;
    ll index=v.size();
    fo(i,0,v.size())
    {
        if(v[i]==k)
        {
            index=i;
            break;
        }
    }
    if(index!=v.size())
    {
        swap(v[index],v[v.size()-1]);
        v.pop_back();
        fon(i,v.size()-1,0)
        {
            max_heapify(v,i);
        }
    }
    else
    {
        cout<<"Entered number does not exist\n";
        return;
    }
}


void print(vector<ll> &v)
{
    fo(i,0,v.size())
    {
        cout<<v[i]<< " ";
    }
    cout<<"\n";
}
int main()
{
    ll n;
    vector<ll> v;
    int c=0;
    do
    {
        int ans;
        cout<<"Choose: \n1 to insert\n2 to delete\n3 to get the highest priority node\n4 to print";
        cout<<"\nEnter your choice: ";
        cin>>ans;
        switch(ans)
        {
            case 1:
            insert(v);
            break;
            case 2:
            Delete(v);
            break;
            case 3:
            if(v.size()==0)
            {
                cout<<"The queue is empty\n";
            }
            else
            {
                cout<<v[0]<<"\n";
            }
            break;
            case 4:
            print(v);
            break;
            default:
            cout<<"Invalid choice\n";
            break;
        }
        cout<<"Would you like to continue\nEnter 1 if yes, else 0 to exit : ";
        cin>>c;

    } while(c!=0);
    

    return;
}