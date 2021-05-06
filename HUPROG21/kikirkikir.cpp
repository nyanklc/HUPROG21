#include <iostream>
#include <cmath>
using namespace std;

int findSmallestElement(int arr[], int n)
    {
        int temp = arr[0];
        for(int i=0; i<n; i++) 
        {
            if(temp>arr[i]) 
            {
            temp=arr[i];
            }
        }
        return temp;
    }
int findLargestElement(int arr[],int n)
{
    for(int i = 1;i < n; ++i)
    {
       if(arr[0] < arr[i])
           arr[0] = arr[i];
    }
    return arr[0];
}


int main() {
    //input 
    int K,N,M;
    cin>>K>>N>>M;
    //starting grams
    int *grams=NULL;
    long long int *Si=NULL;
    grams=new int[N];
    Si=new long long int[N];
    for(int i=0;i<N;i++)
    {
        cin>>Si[i];
        grams[i]=0;
    }
    
    int* Bi=NULL,*Di=NULL;
    long long int* Mi=NULL;

    Bi=new int[K];
    Mi=new long long int[K];
    Di=new int[K];
    for (int i=0; i<K; i++) {
        Bi[i] = 0;
        Mi[i] = 0;
        Di[i] = 0;
    }
    for(int i=0;i<K;i++)
    {
        cin>>Bi[i]>>Mi[i]>>Di[i];
    }

    long long int* denetimArr=NULL;
    denetimArr=new long long int [K];

    for (int i=0; i<K; i++) {
        denetimArr[i] = 0;
    }

    //Bakilacak limits
    int bakilacakalt[K]={0};
    int bakilacakust[K]={0};
    for(int i=0;i<K;i++)
    {
        bakilacakalt[i]=Di[i]-1;
        if(Di[i]+M>N)
        {
            bakilacakust[i]=N-1;
        }
        else
        bakilacakust[i]=Di[i]-1+M;
    }

    //find minimum and maximum bakilacaklar
    int enkucuk = findSmallestElement(bakilacakalt,K);
    int enbuyuk=findLargestElement(bakilacakust,K);
    //cout<<"enk: "<<enkucuk<<" enb: "<<enbuyuk<<endl;

    int index=0;
    //for each meal
    for(int meal=0;meal<K;meal++)
    {
        
        //distribute mama
        for(int i=0;;i++)
        {   
            if(Mi[meal]<=0)
                break;
            index=i+Bi[meal]-1;

            //cout<<"index: "<<index<<endl;
            //cout<<"Bi"<<Bi[meal]<<endl;

            if(index<N && index>enbuyuk)
            {
                //cout<<"ilkine girdi ";
                Mi[meal]-= (N-index+enkucuk+i-1)*(N-index+enkucuk+i)/2 - (i-1)*i/2;
                if(Mi[meal]<=0)
                    break;
                i=N-index+enkucuk;
                Bi[meal]-=N;
                //cout<<"ilkinden cikti ";
                continue;
            }
            if(index>=0 && index<enkucuk)
            {
                //cout<<"ikinciye girdi ";
                Mi[meal]-= (enkucuk-index+i-1)*(enkucuk-index+i)/2 - i*(i-1)/2;
                if(Mi[meal]<=0)
                    break;
                i=enkucuk-index+i;
                //cout<<"ikinciden cikti ";
                continue;
            }
            
            if(Mi[meal]>i+1)
            {
                grams[index]+=i+1;
                Mi[meal]-=i+1;
            }
            else
            {
                grams[index]+=Mi[meal];
                break;
            }
            if(index==N-1)
            {
                Bi[meal]-=N;
            }

            /*
            for(int asd=0;asd<N;asd++)
            {
                cout<<grams[asd]<<" ";
            }
            cout<<endl;
            */
        }   

        //cout<<"denetime kadar geldi";
        //denetim
        for(int i=0;i<M;i++)
        {
            if(Di[meal]+i>N)
            {
                break;
            }
            denetimArr[meal]+=grams[Di[meal]-1+i]+Si[Di[meal]-1+i];
        }

    }

    //output
    for(int i=0;i<K;i++)
    {
        if(i==K-1)
            cout<<denetimArr[i];
        else
            cout<<denetimArr[i]<<" ";
    }


    return 0;
}
