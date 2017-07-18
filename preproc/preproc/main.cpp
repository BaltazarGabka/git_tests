#include <climits>

#define io(vect) cin >> v

#ifndef INT_MAX
    #error Missing int_max definition
#else
    #define INF INT_MAX
#endif // INT_MAX

#define minimum (min,val) val<min?min=val:min
#define maximum (max,val) val>max?max=val:max

#define toStr(text) ("##text##")

#define FUNCTION

#define foreach(tab,iter) for(int iter=0; iter<tab.size();iter++)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

//FUNCTION(minimum, <)
//FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}
