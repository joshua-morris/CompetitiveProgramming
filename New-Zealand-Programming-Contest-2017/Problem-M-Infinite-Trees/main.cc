#include <bits/stdc++.h>

using namespace std;

class UnionFind {
	private: vector<int> p , rank;
	public:
		UnionFind(int N) {
			rank.assign(N, 0);
			p.assign(N,0);
			for (int i=0;i<N;i++) p[i] = i;
		}
		int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
		void unionSet(int i, int j) {
			if (!isSameSet(i, j)) {
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) p[y]=x;
				else {
					p[x] =y;
					if (rank[x] == rank[y]) rank[y]++;
				}
			}
		}

};

int equivalent(vector<vector<int>> tree1, vector<vector<int>> tree2) {
	UnionFind uf(tree1.size() + tree2.size());
	vector<pair<int,int>> todo;
	if (tree1[0].size() == 0 && tree2[0].size() == 0) {
		return 1;
	} else if (tree1[0].size() == 0 && tree2[0].size() != 0) {
		return 0;
	} else if (tree1[0].size() != 0 && tree2[0].size() == 0) {
		return 0;
	}

	todo.push_back(make_pair(tree1[0][0], tree2[0][0]));
	while(todo.size()) {
		int x,y;
		x = todo.back().first; y = todo.back().second; todo.pop_back();
		if(uf.isSameSet(x, tree1.size() + y)) continue;
		if(tree1[x].size() != tree2[y].size()) return 0;
		for (int i=0;i<(int)tree1[x].size();i++) {
			todo.push_back(make_pair(tree1[x][i], tree2[y][i]));
		}
		uf.unionSet(x,tree1.size()+y);
	}

	return 1;
}

int main() {
	while(1) {
	int N, M;
	cin >> N >> M;
	if (!(N||M)) {
		break;
	}
	vector<vector<int>> tree1, tree2;
	for (int i=0;i<N;i++) {
		tree1.push_back({});
		int numChildren;
		cin >> numChildren;
		int current;
		while (numChildren--) {
			cin >> current;
			tree1[i].push_back(current);
		}
	}
	for (int j=0;j<M;j++) {
		tree2.push_back({});
		int numChildren;
		cin >> numChildren;
		int current;
		while (numChildren--) {
			cin >> current;
			tree2[j].push_back(current);
		}
	}
	int res = equivalent(tree1, tree2);
	if (res)
		printf("YES\n");
	else
		printf("NO\n");
	}
}
