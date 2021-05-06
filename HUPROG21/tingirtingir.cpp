#include <iostream>
#include<cmath>
#include <vector>
#include <algorithm>

using namespace std;


bool sahneye_cikti_mi(int *arr1, int *arr2, int m1)
{
    for(int i=0;i<m1;i++)
    {
        if(abs(arr1[i]-arr2[i])<=20)
            continue;
        else
            return false;  
    }
    return true;
}

bool akort_yap(int *arr1, int *arr2, int m1, int sureK, int sirasi, int giremeyensayisi)
{
    int surefin=0;
    int sayi=0;
    int negatifsayi=0;
    int harcanansure=0;
    const int m2=m1;
    int diff[m2]={0};
    int difover50=0;
    int difover50artibir=0;
    int diffTop=0;
    int X=0;

    int tempMin=0;
    int ntempMin=0;

    for(int i=0;i<m1;i++)       
    {
        diff[i]=arr1[i]-arr2[i];

        
        if(diff[i]>0 && diff[i]>100)
        {
            if(diff[i]<tempMin)
                tempMin=diff[i];
            sayi++;
        }
        if(diff[i]<0 && abs(diff[i])>100)
        {
            if(abs(diff[i])<ntempMin)
                ntempMin=abs(diff[i]);
            negatifsayi++;
        }
    }


    if(sayi>negatifsayi)
    {
        X=tempMin/100;
    }
    else if(negatifsayi>sayi)
    {
        X=(-1)*ntempMin/100;
    }



    for(int i=0;i<m1;i++)
    {
        arr2[i] += X*100;        
    }


    for(int i=0;i<m1;i++)
    {
        if(abs(arr1[i]-arr2[i])>20)
        {
            if(arr1[i]>arr2[i])
            {
                int dif=arr1[i]-arr2[i];
                difover50=dif/50;
                difover50artibir=difover50+1;
                harcanansure+=difover50artibir;
                arr2[i]+=difover50*50;
            }
            else
            {
                int dif=arr2[i]-arr1[i];
                difover50=dif/50;
                difover50artibir=difover50+1;
                harcanansure+=difover50artibir;
                arr2[i]+=difover50*50;
            }
        }
        else
            continue;
    }



    if(harcanansure<=(sirasi+1-giremeyensayisi)*sureK)
        return true;
    else
        return false;
}

int main()
{   //input
    int N,M,K;
    cin >>N>>M>>K;
    int A[M],B[N][M];
    for(int i=0;i<M;i++)
    {
        cin>>A[i];
    }
    for(int j=0;j<N;j++)
    {
        for(int l=0;l<M;l++)
        {
            cin>>B[j][l];
        }
    }



   int kac_kisi_girdi_amk=0;
   int giremeyenler=0;
   for(int i=0;i<N;i++)
   {
       if(akort_yap(A,B[i],M,K,i+1,giremeyenler))
       {
           kac_kisi_girdi_amk++;
       }
       else
       {
           giremeyenler++;
       }
        
   }
    cout<<kac_kisi_girdi_amk*500;
}    