// ConsoleApplication133.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <unordered_map>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


struct graph {
	int v = 0, w = 0;
	graph() {};
	graph(int v_, int w_) : v(v_), w(w_) {};
	graph& operator=(const graph& V) {
		v = V.v; w = V.w;
		return *this;
	}
	bool operator<(const graph& V) {
		return w < V.w;
	}
	bool operator>(const graph& V) {
		return w > V.w;
	}
};

class priorty_queue {
private:
	vector<graph> heap;
	int heap_size;
	unordered_map<int, int> pos;
	int parent(int i) const;
	int left(int i) const;
	int right(int i) const;
	void max_heapify(int i);
	void build_max_heap(vector<graph> V);
public:
	priorty_queue();
	priorty_queue(vector<graph> V);
	graph top() const;
	graph extract_top();
	void decrease_key(int i, const graph& key);
	void insert(const graph& key);
	int size() const;
	bool empty() const;
	int position(const graph& V);
};


priorty_queue::priorty_queue() {
	build_max_heap(vector<graph>());
}

priorty_queue::priorty_queue(vector<graph> V) {
	build_max_heap(V);
}

int priorty_queue::parent(int i) const {
	return floor(i / 2 * 1.0);
}

int priorty_queue::left(int i) const {
	return i * 2;
}

int priorty_queue::right(int i) const {
	return i * 2 + 1;
}

void priorty_queue::max_heapify(int i) {
	int l = left(i);
	int r = right(i);
	int largest = -1;
	if (l <= heap_size && heap[i] > heap[l]) {
		largest = l;
	}
	else {
		largest = i;
	}
	if (r <= heap_size && heap[largest] > heap[r]) {
		largest = r;
	}
	if (largest != i) {
		swap(pos[heap[largest].v], pos[heap[i].v]);
		swap(heap[largest], heap[i]);
		max_heapify(largest);
	}
}

void priorty_queue::build_max_heap(vector<graph> V) {
	heap_size = V.size();
	heap.clear();
	heap.push_back(graph());
	heap.insert(heap.end(), V.begin(), V.end());
	for (int i = 1; i <= heap_size; i++) {
		pos[i] = i;
	}
	for (int i = ceil(heap_size / 2.0); i >= 1; i--) {
		max_heapify(i);
	}
}

graph priorty_queue::top() const {
	assert(!empty());
	return heap[1];
}

graph priorty_queue::extract_top() {
	assert(!empty());
	graph max = heap[1];
	pos[max.v] = -1;
	pos[heap[heap_size].v] = 1;
	heap[1] = heap[heap_size];
	heap_size--;
	max_heapify(1);
	return max;
}

void priorty_queue::decrease_key(int i, const graph& key) {
	heap[i] = key;
	while (i > 1 && heap[parent(i)] > heap[i]) {
		swap(pos[heap[parent(i)].v], pos[heap[i].v]);
		swap(heap[parent(i)], heap[i]);
		i = parent(i);
	}
}

void priorty_queue::insert(const graph& key) {
	heap_size++;
	if (heap_size >= heap.size()) {
		heap.push_back(key);
	}
	else {
		heap[heap_size] = key;
	}
	pos[heap[heap_size].v] = heap_size;
	decrease_key(heap_size, key);
}

int priorty_queue::size() const {
	return heap_size;
}

bool priorty_queue::empty() const {
	return heap_size == 0;
}

int priorty_queue::position(const graph& V) {
	return pos[V.v];
}





void task_1()//матрица смежности <-> список ребер 
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G;
	for (int i = 0; i < N; i++) {
		G.push_back(vector<int>(N, 0));
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		G[a - 1][b - 1] = 1;
		G[b - 1][a - 1] = 1;
	}

	ofstream a;
	a.open("out.txt");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a << G[i][j] << " ";
		}
		a << "\n";
	}
	a.close();


}

void task_2()//Неориентированный граф задан списком рёбер. Найдите степени всех вершин графа.
{
	fstream qqqqqq;
	qqqqqq.open("1.txt");
	int n;
	qqqqqq >> n;
	int a, b;
	map<int, int> G;
	for (int i = 0; i < n; i++) {
		qqqqqq >> a >> b;
		G[a]++;
		G[b]++;
	}
	ofstream aaaaa;
	aaaaa.open("1.txt");
	aaaaa << G.size() << "\n";
	for (auto now : G)
	{
		aaaaa << now.first << " " << now.second << endl;
	}
	aaaaa.close();


}


void bfs(vector<vector<int> > G, int F, int S) //Part of the task 3
{
	queue<int> Q;
	vector<bool> used(G.size(), false);
	vector<int> depth(G.size(), -1);
	vector<int> parent(G.size(), -1);
	ofstream aaaaa;
	aaaaa.open("out.txt");
	used[F] = true;
	depth[F] = 0;
	parent[F] = -1;
	Q.push(F);
	while (!Q.empty()) {
		int v = Q.front();
		for (int i = 0; i < G[v].size(); i++) {
			if (!used[G[v][i]]) {
				used[G[v][i]] = true;
				depth[G[v][i]] = depth[v] + 1;
				parent[G[v][i]] = v;
				Q.push(G[v][i]);
			}
		}
		Q.pop();
	}
	if (!used[S]) {
		aaaaa << "-1\n";
		return;
	}
	aaaaa << depth[S] << "\n";
	int v = S;
	vector<int> ans;
	while (v != -1) {
		ans.push_back(v + 1);
		v = parent[v];
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0;i <ans.size() ;i++) {
		aaaaa << ans[i] << "\t";
	}
	aaaaa << endl;

}

















void task3()//Задан ориентированный граф и в нём выбраны две вершины. Нужно построить кратчайший путь из одной вершины в другую.
//В первой строке выведите длину кратчайшего пути или -1, если такого пути нет. Во второй строке выведите сам путь.Если таких путей несколько, выведите любой из них.
{
	fstream qqqqqq;
	qqqqqq.open("1.txt");
	int N, M, S, F;
	qqqqqq >> N >> M >> F >> S;
	vector<vector<int> > G(N);
	int a, b;
	for (int i = 0; i < M; i++) {
		qqqqqq >> a >> b;
		G[a - 1].push_back(b - 1);
	}
	bfs(G, F - 1, S - 1);



}


void task4_()//Задан взвешенный ориентированный граф. Найдите вес кратчайшего пути между двумя заданными
//вершинами.
//Выведите вес кратчайшего пути между заданными вершинами или -1, если пути не существует.
{
	int N, M, w, s;
	ifstream in("in.txt");
	ofstream out("out.txt");
	in >> N >> M;
	in >> w >> s;
	vector<vector<graph>> G(N + 3);
	vector<graph> vertexes(N + 3);
	int a, b, d;
	for (int i = 0; i < M; i++) {
		in >> a >> b >> d;
		G[a].push_back(graph(b, d));
	}
	priorty_queue PQ;
	PQ.insert(graph(w, 0));
	for (int i = 1; i <= N; i++) {
		if (i != w) {
			PQ.insert(graph(i, 100000000));
		}
	}
	vector<int> dist(G.size() + 3, 100000000);
	dist[w] = 0;
	while (!PQ.empty()) {
		int u = PQ.extract_top().v;
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v;
			int weight = G[u][i].w;
			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				PQ.decrease_key(PQ.position(G[u][i]), graph(v, dist[v]));
			}
		}
	}
	if (dist[s] == 100000000) {
		out << -1;
	}
	else {
		out << dist[s];
	}
}





int main()
{
	task4_();
	return 0;
}










void task4()//Задан взвешенный ориентированный граф. 
//Найдите вес кратчайшего пути между двумя заданными вершинами. (АЛгоритм Дейкстры)
{
	int start, finish;
	auto data = getData(start, finish);
	Route(data, start, finish);


}





