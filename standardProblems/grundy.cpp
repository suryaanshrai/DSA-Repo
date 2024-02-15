#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> grundy;

int calculateMex(unordered_set<int> Set) { 
    int Mex = 0; 
    while (Set.find(Mex) != Set.end()) Mex++; 
    return Mex;
}

int calculateGrundy (int n) { 
    if (n == 0) 
        return 0;
    unordered_set<int> Set;
	if (grundy.find(n/2) == grundy.end()) grundy[n/2] = calculateGrundy(n/2);
	if (grundy.find(n/3) == grundy.end()) grundy[n/3] = calculateGrundy(n/3);
	if (grundy.find(n/6) == grundy.end()) grundy[n/6] = calculateGrundy(n/6);
    Set.insert(grundy[n/2]); 
    Set.insert(grundy[n/3]); 
    Set.insert(grundy[n/6]); 
    grundy[n] = calculateMex(Set)
    return grundy[n]; 
} 

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << calculateGrundy(n) << endl;
	}
    return 0;
}
