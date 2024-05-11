#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	vector<string> ban;
	vector< pair<string, string> > result;
	
	for (int i=0; i<N; i++) {
		string name, inst;
		cin >> name >> inst;
		
		if (i<M) {
			ban.push_back(inst);
		} else {
			
			if (K>0) {
				bool isValid = 1;
				for (int j=0; j<(int)ban.size(); j++) {
					if (inst==ban[j]) {
						isValid = 0;
						break;
					}
				}
				
				if (isValid) {
					result.push_back(make_pair(name, inst));
					ban.push_back(inst);
					K--;
				}
			}
			
		}
		
	}
	
	cout << (int)result.size() << '\n';
	for (int i=0; i<(int)result.size(); i++) {
		cout << result[i].first << '\n';
	}
	
	return 0;
}
