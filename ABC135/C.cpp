#include <iostream>
#include <vector>

using namespace std;
int main(){
  long n, ans;
  cin >> n;
  ans = 0;  

  vector < int > a(n+1);
  
  for(int i=0;i<=n;i++){
    cin >> a[i];
  }

  for(int i=0;i<n;i++){
    int b;
    cin >> b;
     
    if(a[i] >= b){ 
      ans += b;
    } else{
       if(a[i] + a[i+1] >= b){
         ans += b;      
        //  ans += 
         a[i+1] -= b - a[i];
       }else{
         ans += a[i];
         ans += a[i+1];
         a[i+1] = 0;
       } 
    }
  }
 cout << ans << endl;
}
