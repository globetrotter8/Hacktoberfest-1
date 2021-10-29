
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class matrix
{
    public:
void swap(int arr[100][100],int n,int m)
{
    int i,j;
    int tarr[100][100];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            tarr[j][i]=arr[i][j];
        }
    }
    display(tarr,n,m);
}
int sumDiag(int arr[100][100],int n)
{
    int sum=0,i,j;
    for(i=0;i<n;i++)
    {
        sum+=arr[i][i];
    }
    return sum;
}
bool checkUpperTriangle(int arr[100][100],int n)
{
   int i,j;
   for(i=0;i<n;i++)
   {
       for(j=0;j<=i;j++)
       if(arr[i][j]!=0)
       return false;
   }
   return true;
}
void inputArr(int arr[100][100],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
}
void display(int arr[100][100],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
}
};
int main()
{
    matrix obj;
    int arr[100][100];
    int brr[100][100];
    int n,m,i,n1,m1,j;
    cout<<"Enter the size of the array:\n ";
    cin>>n>>m;
    obj.inputArr(arr,n,m);
    obj.display(arr,n,m);
    if(n==m)
    {
    if(obj.checkUpperTriangle(arr,n))
    cout<<"Upper Triangular\n";
    else
    cout<<"Not Upper Triangular\n";
    }
    else
    cout<<"Not Upper Triangular\n";
    cout<<"Transpose: \n";
    obj.swap(arr,n,m);
    if(n==m)
    cout<<"Diagnol Sum: "<<obj.sumDiag(arr,n);
    cout<<"Enter the size of the array";
    cin>>n1>>m1;
    obj.inputArr(brr,n1,m1);
    int oparr[100][100];
    int c,k;
    cout<<"Enter 1.Add\n2.Subtract\n3.Multiply\n";
    cin>>c;
    switch(c)
    {
        case 1:
        if(n1==n&&m1==m)
        {
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        oparr[i][j]=arr[i][j]+brr[i][j];
        obj.display(oparr,n,m);
        }
        break;
        case 2:
        if(n1==n&&m1==m)
        {
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        oparr[i][j]=arr[i][j]-brr[i][j];
        obj.display(oparr,n,m);
        }
        break;
        case 3:
        if(m==n1)
        {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++) 
            {
                oparr[i][j] = 0;
                for (k = 0; k < m; k++)
                    oparr[i][j] += arr[i][k] * brr[k][j];
            }
        } 
        obj.display(oparr,n,m1);
        }
        break;
    return 0;
}}
