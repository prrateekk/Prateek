#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Sum from digits from number a to b

ll int dp[10],pw[10];
int init(){
	dp[0]=0;
	dp[1]=45;
	int p=10;
	for (int i=2;i<10;i++){
		dp[i]=10*dp[i-1]+dp[1]*p;
		p*=10;
	}
	pw[0]=1;
	for (int i=1;i<10;i++){
		pw[i]=pw[i-1]*10;
	}
	return 0;

}

int d[10],fc[10];

int fsum(){
	fc[0]=0;
	for (int i=1;i<10;i++){
		fc[i] = fc[i-1]+i;
	}
	return 0;
}

ll int control(int x){
	int i=0;
	int temp=x;
	while (x){
		d[i]=x%10;
		i++;
		x/=10;
	}
	i--;
	ll int sum = 0;
	while (i>=0){
		sum+=(dp[i]*d[i]+(fc[d[i]-1]*pw[i]));
		sum+=(d[i]*((temp%pw[i])+1));
		i--;
	}
	return sum;
}

int sumdigits(int x){
	int sum=0;
	while (x){
		sum+=(x%10);
		x/=10;
	}
	return sum;
}

int main(){
	init();
	fsum();
	while (1){
		int a,b;
		cin >> a >> b;
		if (a==-1) break;
		ll int resa=control(a);
		ll int resb=control(b);
		ll int res=resb-resa+sumdigits(a);
		cout << res << endl;
	}
	return 0;
}
