// practicing with java.
import java.util.*; // scanner, arraylist
import java.math.*;
public class boj9020{
  static int maxn = 10001;
  static int prime[];
  static int n,t;
  public static void main(String[] args){
      // call sieve()
      prime = new int[maxn+5];
      sieve();
      ArrayList<Integer> lkk = new ArrayList<Integer>();
      for (int i = 0; i < maxn; i++){
        if (prime[i] == 1) lkk.add(i);
      }
      // get input.
      Scanner scanner = new Scanner(System.in);
      t = scanner.nextInt();
      while (t-- > 0){
        n = scanner.nextInt();
        int mindiff = 0x3c3c3c;
        int ans1 = 0,ans2 = 0;
        for (int i = 0; i < lkk.size(); i++){
          int val = lkk.get(i);
          int chk = n-val;
          int l = 0, r = lkk.size()-1;
          while (l <= r){
            int mid = (l+r)>>1;
            if (lkk.get(mid) == chk && mindiff > Math.abs(chk-val)){
              ans1 = chk;
              ans2 = val;
              mindiff = Math.abs(chk-val);
            }else if (lkk.get(mid) < chk){
              l = mid+1;
            }else{
              r = mid-1;
            }
          }
        }
        if (ans1 >= ans2) System.out.println(ans2 + " " + ans1);
        else System.out.println(ans1 + " " + ans2);
      }
  }
  public static void sieve(){
    for (int i = 0; i < maxn; i++){
      prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i*i <= maxn; i++){
      if (prime[i] == 1){
        for (int j = i*i; j <= maxn; j += i){
          prime[j] = 0;
        }
      }
    }
  }
}
