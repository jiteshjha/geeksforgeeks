#include<bits/stdc++.h>

using namespace std;
void Sieve(int n) {

  bool prime[n+1];

  memset(prime, true, sizeof(prime));

      double limit = floor(sqrt(n));
  for(int i = 2; i <= limit; i++) {
    if(prime[i] == true) {
      for(int j = 2*i; j <= n; j = j + i) {
        prime[j] = false;
      }
    }
  }

  for(int i = 2; i <= n; i++)
    if(prime[i] == true)
      printf("%d\t", i);
}

int main() {
  int num = 25;
  Sieve(25);

  return 0;
}
