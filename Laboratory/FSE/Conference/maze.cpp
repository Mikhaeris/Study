#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Maze {
private:
	vector<vector<int>> maze;
	int height, width;

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

	void graphToMaze(const vector<vector<int>>& adjacencyList, int height, int width) {
		this->height = height;
		this->width = width;
		initializeMaze(width);

		int i = 0, j = 0, currentI = 0;
		while (((i + 1) * (j + 1)) < adjacencyList.size()) {
			if (!adjacencyList[currentI].empty()) {
				maze[i][j] = 0;
			}
			else {
				maze[i][j] = 1;
			}


			if ((j + 1) % width == 0) {
				i++;
				j = 0;
			}
			else {
				j++;
			}
			currentI++;
		}
		maze[height - 1][width - 1] = 1;
	}

	void printMaze() {
		for (int i = 0; i < maze.size(); i++) {
			for (int j = 0; j < maze.size(); j++) {
				cout << maze[i][j] << " ";
			}
			cout << endl;
		}
	}

	void printMazeWithPath(vector<int> path) {
		int countPath = 0, currenPath = 0;
		for (int i = 0; i < maze.size(); i++) {
			for (int j = 0; j < maze.size(); j++) {
				if (currenPath < path.size() && countPath == path[currenPath]) {
					if (currenPath == 0) {
						cout << 'S' << " ";
					}
					else if (currenPath == path.size() - 1) {
						cout << 'F' << " ";
					}
					else {
						cout << '@' << " ";
					}
					currenPath++;
				}
				else {
					cout << maze[i][j] << " ";
				}
				countPath++;
			}
			cout << endl;
		}
	}

};

class Graph {
private:
	vector<vector<int>> adjacencyList;
	int height, width;

public:
	Graph() = default;

	Graph(vector<vector<int>> vec, int height, int width) {
		this->height = height;
		this->width = width;

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
		height = maze.size();
		width = maze[0].size();

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
	tuple<vector<int>, int, int> bfs(int start) {
		int n = adjacencyList.size();
		int finish = 0;

		queue<int> queueBurning;
		vector<bool> used(n);

		vector<int> length(n), parent(n);

		queueBurning.push(start);
		used[start] = true;
		parent[start] = -1;

		while (!queueBurning.empty()) {
			int vertex = queueBurning.front();
			queueBurning.pop();


			if (((vertex + 1) % width == 0) || (vertex % width == 0) || ((vertex - width) < 0) || ((vertex + width) > (width * height))) {
				finish = vertex;
				break;
			}

			for (int i = 0; i < adjacencyList[vertex].size(); i++) {
				int currentVertex = adjacencyList[vertex][i];
				if (!used[currentVertex]) {
					used[currentVertex] = true;
					queueBurning.push(currentVertex);
					length[currentVertex] = length[vertex] + 1;
					parent[currentVertex] = vertex;
				}
			}
		}

		if (!used[finish]) {
			cout << "No path!" << endl;
		}
		else {
			vector<int> path;
			for (int v = finish; v != -1; v = parent[v]) {
				path.push_back(v);
			}

			reverse(path.begin(), path.end());
			return make_tuple(path, height, width);
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
		{1,0,0,0,0,0,1},
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
	//graph.printGraph();
	//cout << "-----------" << endl;

	//int start = 0; cout << "Enter start position: "; cin >> start;
	auto path = graph.bfs(8);

	Maze maze1;
	maze1.graphToMaze(graph.getLinkGraph(), get<1>(path), get<2>(path));
	//maze1.printMaze();
	maze1.printMazeWithPath(get<0>(path));

	return 0;
}