#include<iostream>

using namespace std;

int main() {
	long long int N, M, K;
	cin >> N >> M >> K;
	
	int cut = 3;
	
	if (N*M==K) {
		cut = 0;
	} else if (K%N==0 || K%M==0) {
		cut = 1;
	} else {
		for (long long int i=1; i<N; i++) {
			if (K<=M*i&&K%i==0){
				cut=2;
				break;
			}
		}
		
		K = N*M-K;
		for (long long int i=1; i<M; i++) {
			if (K<=N*i&&K%i==0){
				cut=2;
				break;
			}
		}
	}
	
	cout << cut << '\n';
	
	return 0;
}
