#include <iostream>
using namespace std;


int main() {
    //input
    long long int K,N,M;
    cin>>K>>N>>M;
    //starting grams
    long long int grams[N]={0};
    for(long long int i=0;i<N;i++)
    {
        cin>>grams[i];
    }

    long long int Bi[K],Mi[K],Di[K];
    for(long long int i=0;i<K;i++)
    {
        cin>>Bi[i]>>Mi[i]>>Di[i];
    }

    long long int denetimArr[K]={0};

    //for each meal
    for(int meal=0;meal<K;meal++)
    {
        //distribute mama
        for(long long int i=0;;i++)
        {
            if( Bi[meal]-1+i > N-1 )
                Bi[meal]-=N;

            if(i+1>Mi[meal])
            {
                grams[Bi[meal]-1+i]+=Mi[meal];
                break;
            }
            Mi[meal]-=i+1;
            grams[Bi[meal]-1+i]+=i+1;

        }

        //denetim
        for(long int i=0;i<M;i++)
        {
            if(Di[meal]+i>N)
            {
                break;
            }
            denetimArr[meal]+=grams[Di[meal]-1+i];
        }

        /*
        //output deneme
        if(meal!=K-1)
            cout<<denetimArr[meal]<<" ";
        else
            cout<<denetimArr[meal];
        */
    }

    //output
    for(long long int i=0;i<K;i++)
    {
        cout<<denetimArr[i]<<" ";
    }


    return 0;
}
