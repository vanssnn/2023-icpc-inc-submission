#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool sortCompare(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second < b.second) {
		return true;
	} else {
		return false;
	}
		
	return (a.first > b.first);
}

int main() {
	
	int N, M;
	cin >> N >> M;
	
	pair<int, int> treasure[N];
	
	
	for (int i=0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		
		treasure[i] = make_pair(v, w);
	}
	
	sort(treasure, treasure + N, sortCompare);
	
	
	int s[M];
	for (int i=0; i < M; i++) {
		cin >> s[i];
	}
	
	sort(s, s+M);
	
	long long int sum = 0;
	priority_queue< pair<int, int> > pq;
	
    int j = 0;
	for (int i = 0; i < M; i++) {
    	while (j < N && treasure[j].second <= s[i]) {
        	pq.push(treasure[j]);
        	j++;
    	}
        
    	if (!pq.empty()) {
        	sum += (pq.top()).first;
        	pq.pop();
    	}
	}
	
	cout << sum << '\n';
	
//	 for (int i = 0; i < N; i++) {
//    	cout << treasure[i].second << " " << treasure[i].first << endl;
//	}
//	for (int i = 0; i < M; i++) {
//		cout << s[i] << endl;
//	}
	
	return 0;	
}
