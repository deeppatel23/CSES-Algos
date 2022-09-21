#include<bits/stdc++.h>
using namespace std;

//TLE
// int rabinKarp(string word, string pat) {
//     int p = 0, t = 0, h = 1, q = INT_MAX, d = 256, ans = 0;
//     int n = word.size(), m = pat.size();

//     // The value of h would be "pow(d, M-1)%q" 
//     for (int i = 0; i < m-1; i++) {
//         h = (h * d) % q;
//     }

//     // Calculate the hash value of pattern and first window of text 
//     for (int i = 0; i < m; i++) { 
//         p = (d * p + pat[i]) % q; 
//         t = (d * t + word[i]) % q; 
//     } 

//     for (int i = 0; i <= n-m; i++) {
//         if (p == t) {
//             for (int j = 0; j < m; j++) { 
//                 if (word[i+j] != pat[j]){
//                   break;
//                 } 
//                 // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
//                 if (j == m-1) {
//                     ans++;       
//                 }
//             } 
//         }
//         // Calculate hash value for next window of text: Remove leading digit, add trailing digit 
//         if ( i < n-m) { 
//             t = (d*(t - word[i]*h) + word[i+m])%q; 
//             // We might get negative value of t, converting it to positive 
//             if (t < 0) 
//                 t = (t + q); 
//         } 
//     }
//     return ans;
// }

vector<int>computeTempArr(string pat) {
    vector<int>lps(pat.size(), 0);
    int len = 0;
	int i = 1, M = pat.size();
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len != 0) {
				len = lps[len - 1];
			}
			else {  // if (len == 0)
				lps[i] = 0;
				i++;
			}
		}
	}
    return lps;
}

int kmp(string txt, string pat) {
    vector<int>lps;
    lps = computeTempArr(pat);
    int i = 0, j = 0, ans = 0, N = txt.size(), M = pat.size();
    while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
            ans++;
			j = lps[j - 1];
		}

		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
    return ans;
}

int main() {
    string word, pat;
    cin >> word >> pat;
    int ans = 0;
    ans = kmp(word, pat);
    cout << ans << endl;
    return 0;
}