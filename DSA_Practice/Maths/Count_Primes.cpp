class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n+1,0);
        for(int i=2;i<n+1;i++){
            primes[i]=1;
        }
        for(int i=2;i*i<=n;i++){         //we could go till n but we don't need to check for i beyond 5 that is sqr n=30
            if(primes[i]==1){
                for(int j=i*i;j<=n;j+=i){   //we could start from 2*i but that actually gets marked previously by someone so we can start with i*i
                    primes[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(primes[i]==1) cnt++;
        }
        return cnt;
    }
};