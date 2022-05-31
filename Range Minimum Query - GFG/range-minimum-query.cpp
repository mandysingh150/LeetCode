// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends

int size;
void build(int a[], int tree[], int node, int l, int r) {
    if(l == r) {
        tree[node] = a[l];
    }
    else {
        int mid = (l+r)/2;
        build(a, tree, 2*node, l, mid);
        build(a, tree, 2*node+1, mid+1, r);
        tree[node] = min(tree[node*2], tree[2*node+1]);
    }
}

/* The functions which 
builds the segment tree */
int *constructST(int arr[],int n)
{
    size=n;
    int *tree = new int[4*n];
    build(arr, tree, 1, 0, n-1);
    return tree;
}


int h(int st[], int a, int b, int node=1, int l=0, int r=size-1) {
    if(a > b)
        return INT_MAX;
    if(a<=l and r<=b)
        return st[node];
    
    int mid = (l+r)/2;
    return min(h(st, a, min(b, mid), 2*node, l, mid), 
                h(st, max(a, mid+1), b, 2*node+1, mid+1, r));
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b) {
    return h(st, a, b, 1, 0, n-1);
}