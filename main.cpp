#include <iostream>
#include <cmath>
#include <stdint.h>
using namespace std;

int64_t random(int64_t  s,int64_t n){
    int64_t num=s+rand()%((n+1)-s);

  return num;
}



int64_t exp_mod(int64_t a,int64_t x, int64_t n){
     int64_t c=a%n;
     int64_t r=1;
    while(x>0){
        if(x%2!=0){r=(r*c)%n;}
        c=(c*c)%n;
        x=x/2;
    }
    return r;
}

bool es_compuesto(int64_t a,int64_t n,int64_t t,int64_t u){
     int64_t x=exp_mod(a,u,n);
    if(x==1||x==n-1){
        return false;
    }
    for(int64_t i=1;i<t+1;i++){

         int64_t xi=exp_mod(x,2,n);
        x=xi;
        if(xi==n-1){
            return false;
        }
    }
    return true;
}

int64_t miller_rabin(int64_t n , int64_t s){
     int64_t t=0;
     int64_t u=n-1;
    while(u%2==0){
        u=u/2;
        t++;
    }

    for(int64_t j=1;j<s+1;j++){
         int64_t a=random(2,n-1);

        if(es_compuesto(a,n,t,u)){return false;}

    }

    return true;

}


int64_t random_bits(int64_t b){
   int64_t n = random(0,pow(2,b)-1);

    int64_t m = ((pow(2,b-1))+1)*(1);
//cout<<"                                         m final"<<m<<endl;
  if(m>n){
        n=n+(m-1);}
  if(n%2==0){n=n+1;}
//cout<<"                                         n final--"<<n<<endl;
return n;
}

int64_t random_prime(int64_t b){
  int64_t s;
  int64_t n = random_bits(b);
  s = sqrt(n);
  while(miller_rabin(n,s) == false){
      n = n+2;
  }
return n;
}

int64_t gen_prime( int64_t n){
   int64_t s;
  n = n+1-(n%2);
  while(miller_rabin(n,s)==false){
      n = n+2;
  }
return n;
}



int main() {
     cout<<"NUMEROS PRIMOS DE 16 BITS"<<endl;
    for(int64_t i=1;i<11;i++){
    int64_t n=gen_prime(random_bits(16));
    cout<<i<<"->"<<n<<endl;
    }
cout<<endl<<"NUMEROS PRIMOS DE 32 BITS"<<endl;
    for(int64_t i=1;i<11;i++){
    int64_t n=random_bits(32);
    int64_t s=sqrt(n);
    while(miller_rabin(n,s)==false){
      n = n+2;
    }
    cout<<i<<"->"<<n<<endl;
    }
cout<<endl<<"NUMEROS PRIMOS DE 64 BITS"<<endl;
    for(int64_t i=1;i<11;i++){
     int64_t n=random_bits(64);
     int64_t s=100;//sqrt(sqrt(n));
    int64_t m=gen_prime(n);
    while(miller_rabin(n,s)==false){
      n = n+2;
      cout<<n<<endl;
    }
    cout<<i<<"->"<<m<<endl;
    }


    //if(miller_rabin(18446744073709551557,10000)){cout<<"yesssssssssssss";}
}
