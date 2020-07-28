/// Segment Trees
#include <iostream>
using namespace std;

void Build(int*arr,int*SegTree,int node,int L,int R)
{
    if(L==R)
    {
        SegTree[node]=arr[L];
        return;
    }
    int mid=(L+R)/2;
    Build(arr,SegTree,2*node,L,mid);
    Build(arr,SegTree,2*node+1,mid+1,R);
    SegTree[node]=SegTree[2*node]+SegTree[2*node+1];
    return;
}


void update(int*arr,int*SegTree,int node,int L,int R,int index,int Value)
{
    if(L==R){
        arr[index]=Value;
        SegTree[node]=Value;
        return;
    }
    int mid=(L+R)/2;
    if(index>mid){
        update(arr,SegTree,2*node+1,mid+1,R,index,Value);
    }
    else{
        update(arr,SegTree,2*node,L,mid,index,Value);
    }
    SegTree[node]=SegTree[2*node]+SegTree[2*node+1];
}

int Query(int*arr,int*SegTree,int node,int L,int R,int l,int r)
{
    if(R<l||r<L){return 0;}
    if(L>=l&&R<=r){return SegTree[node];}
    int mid=(L+R)/2;
    int lht=Query(arr,SegTree,2*node,L,mid,l,r);
    int rht=Query(arr,SegTree,2*node+1,mid+1,R,l,r);
    return lht+rht;
}


int main()
{
    int N;
    cin>>N;
    int arr[N];
    int SegTree[2*N+1];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    int q;
    cin>>q;
    Build(arr,SegTree,1,0,N-1);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<Query(arr,SegTree,1,0,N-1,l,r)<<endl;
    }
    return 0;
}
