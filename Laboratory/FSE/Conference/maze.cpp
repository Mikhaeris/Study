#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Maze {
private:
	vector<vector<int>> maze;

public:
	Maze() = default;

	Maze(vector<vector<int>> vec) {
		int n = vec.size();
		initializeMaze(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				maze[i][j] = vec[i][j];
			}
		}
	}

	const vector<vector<int>>& getLinkMaze() {
		return maze;
	}

	void initializeMaze(int n) {
		for (int i = 0; i < n; i++) {
			maze.push_back(vector<int>(n));
		}
	}

	void enterMaze() {
		int n = 0; cout << "Enter n: "; cin >> n;
		initializeMaze(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> maze[i][j];
			}
		}
	}

	void generateMaze() {

	}

	void graphToMaze(const vector<vector<int>>& adjacencyList) {
		int n = sqrt(adjacencyList.size());
		for (int i = 0; i < adjacencyList.size(); i++) {
			if (!adjacencyList[i].empty()) {
				cout << "0" << " ";
			}
			else {
				cout << "1" << " ";
			}

			if ((i + 1) % n == 0) {
				cout << endl;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

			}
		}
	}

	void printMaze() {
		for (int i = 0; i < maze.size(); i++) {
			for (int j = 0; j < maze.size(); j++) {
				cout << maze[i][j] << " ";
			}
			cout << endl;
		}
	}

};

class Graph {
private:
	vector<vector<int>> adjacencyList;

public:
	Graph() = default;

	Graph(vector<vector<int>> vec) {
		initializeMaze(vec.size());

		for (int i = 0; i < vec.size(); i++) {
			adjacencyList[i] = vec[i];
		}
	}

	const vector<vector<int>>& getLinkGraph() {
		return adjacencyList;
	}

	void initializeMaze(int n) {
		for (int i = 0; i < n; i++) {
			adjacencyList.push_back(vector<int>(n));
		}
	}

	void mazeToGraph(const vector<vector<int>>& maze) {
		int mazeSize = maze.size();
		for (int i = 0; i < maze.size(); i++) {
			for (int j = 0; j < maze.size(); j++) {
				vector<int> tempVertexAdjacencyList;
				if (maze[i][j] == 0) {
					if (j - 1 >= 0 && maze[i][j - 1] == 0) {
						tempVertexAdjacencyList.push_back(i * mazeSize + (j - 1));
					}
					if (i - 1 >= 0 && maze[i - 1][j] == 0) {
						tempVertexAdjacencyList.push_back((i - 1) * mazeSize + j);
					}
					if (j + 1 < mazeSize && maze[i][j + 1] == 0) {
						tempVertexAdjacencyList.push_back(i * mazeSize + (j + 1));
					}
					if (i + 1 < mazeSize && maze[i + 1][j] == 0) {
						tempVertexAdjacencyList.push_back((i + 1) * mazeSize + j);
					}
				}
				adjacencyList.push_back(tempVertexAdjacencyList);
			}
		}
	}

	// Bfs
	void bfs(int start) {

		// add check border and break
		int n = adjacencyList.size();

		queue<int> queueBurning;
		vector<bool> used(n);

		vector<int> length(n), parent(n);

		queueBurning.push(start);
		used[start] = true;
		parent[start] = -1;

		while (!queueBurning.empty()) {
			int vecrtex = queueBurning.front();
			queueBurning.pop();

			for (int i = 0; i < adjacencyList[vecrtex].size(); i++) {
				int currentVertex = adjacencyList[vecrtex][i];
				if (!used[currentVertex]) {
					used[currentVertex] = true;
					queueBurning.push(currentVertex);
					length[currentVertex] = length[vecrtex] + 1;
					parent[currentVertex] = vecrtex;
				}
			}
		}

		//int to = 15;
		int to = 41;
		if (!used[to])
			cout << "No path!" << endl;
		else {
			vector<int> path;
			for (int v = to; v != -1; v = parent[v]) {
				path.push_back(v);
			}

			reverse(path.begin(), path.end());
			cout << "Path: ";
			for (size_t i = 0; i < path.size(); ++i) {
				cout << path[i] << " ";
			}
			cout << endl;
		}
	}

	void printGraph() {
		for (int i = 0; i < adjacencyList.size(); i++) {
			cout << i << ": ";
			for (int j = 0; j < adjacencyList[i].size(); j++) {
				cout << adjacencyList[i][j] << " ";
			}
			cout << endl;
		}
	}
};


int main() {
	/*Maze maze({
	{1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1},
	{1, 1, 1, 0, 1},
	{0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1},});*/

	Maze maze({
		{1,1,1,1,1,1,1},
		{0,0,0,0,0,0,1},
		{1,0,1,1,1,0,1},
		{1,0,0,0,1,0,1},
		{1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0},
		{1,1,1,1,1,1,1}
		});

	/*Maze maze({
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,1,1},
	{1,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
	{1,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,1,1,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,1,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0,0,0,1,0,1,0,1},
	{1,0,1,1,1,0,1,0,1,0,1,0,1,1,1},
	{1,0,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,1,1,1,1,0,1,0,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		});*/

		//maze.enterMaze();

	maze.printMaze();
	cout << "-----------" << endl;

	Graph graph;
	graph.mazeToGraph(maze.getLinkMaze());
	graph.printGraph();
	cout << "-----------" << endl;

	graph.bfs(7);

	Maze maze1;
	maze1.graphToMaze(graph.getLinkGraph());
	maze1.printMaze();
	return 0;
}