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
		height = vec.size();
		width = vec[0].size();

		initializeMaze(height, width);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				maze[i][j] = vec[i][j];
			}
		}
	}

	const vector<vector<int>>& getLinkMaze() {
		return maze;
	}

	void initializeMaze(int height, int width) {
		for (int i = 0; i < height; i++) {
			maze.push_back(vector<int>(width));
		}
	}

	void enterMaze() {
		cout << "Enter height: "; cin >> height;
		cout << "Enter width: "; cin >> width;

		initializeMaze(height, width);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin >> maze[i][j];
			}
		}
	}

	void generateMaze() {

	}

	void graphToMaze(const vector<vector<int>>& adjacencyList, int height, int width) {
		this->height = height;
		this->width = width;
		initializeMaze(height, width);

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
		cout << height << "x" << width << endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout << ((maze[i][j] == 1) ? "#" : " ") << " ";
			}
			cout << endl;
		}
	}

	tuple<bool, int> vertexInPath(vector<int> path, int vertex) {
		for (int i = 0; i < path.size(); i++) {
			if (path[i] == vertex) {
				if (i == 0) {
					return make_tuple(true, 1);
				}
				else if (i == path.size() - 1) {
					return make_tuple(true, 2);
				}
				else {
					return make_tuple(true, NULL);
				}
			}
		}
		return make_tuple(false, NULL);
	}

	void printMazeWithPath(vector<int> path) {
		int countPath = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				auto  answer = vertexInPath(path, countPath);
				if (get<0>(answer)) {
					if (get<1>(answer) == 1) {
						cout << 'S' << " ";
					}
					else if (get<1>(answer) == 2) {
						cout << 'F' << " ";
					}
					else {
						cout << '-' << " ";
					}
				}
				else {
					cout << ((maze[i][j] == 1) ? "#" : " ") << " ";
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

		adjacencyList = vec;
	}

	const vector<vector<int>>& getLinkGraph() {
		return adjacencyList;
	}

	void mazeToGraph(const vector<vector<int>>& maze) {
		height = maze.size();
		width = maze[0].size();

		int mazeSize = width;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
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
	tuple<vector<int>, int, int> BreadthFirstSearch(int start) {
		int n = adjacencyList.size();
		int finish = -1;

		queue<int> queueBurning;
		vector<int> used(n);

		vector<int> length(n), parent(n);

		queueBurning.push(start);
		used[start] = 1;
		parent[start] = -1;

		while (!queueBurning.empty()) {
			int vertex = queueBurning.front();
			queueBurning.pop();

			if (((vertex + 1) % width == 0) || (vertex % width == 0) || ((vertex - width) <= 0) || ((vertex + width) >= (width * height))) {
				finish = vertex;
				break;
			}

			for (int i = 0; i < adjacencyList[vertex].size(); i++) {
				int currentVertex = adjacencyList[vertex][i];
				if (used[currentVertex] == 0) {
					used[currentVertex] = 1;
					queueBurning.push(currentVertex);

					length[currentVertex] = length[vertex] + 1;
					parent[currentVertex] = vertex;
				}
			}
		}

		if (used[finish] == 0 || finish == -1) {
			cout << "No path!" << endl;
			return make_tuple(vector<int>(), 0, 0);
		}
		else {
			vector<int> path;
			for (int v = finish; v != -1; v = parent[v]) {
				path.push_back(v);
			}

			reverse(path.begin(), path.end());
			cout << "Path: ";
			for (size_t i = 0; i < path.size(); ++i) {
				cout << path[i] + 1 << " ";
			}
			cout << endl;

			return make_tuple(path, height, width);
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

	/*Maze maze({
		{1,1,1,1,1,1,1},
		{1,0,0,0,0,0,1},
		{1,0,1,1,1,0,1},
		{1,0,0,0,1,0,1},
		{1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0},
		{1,1,1,1,1,1,1}
		});*/

		/*Maze maze({
			{1,1,1,1,1,1,1},
			{1,0,0,0,0,0,1},
			{1,0,0,0,0,0,1},
			{1,0,1,1,1,0,1},
			{1,0,0,0,1,0,1},
			{1,1,1,1,1,0,1},
			{1,0,0,0,0,0,0},
			{1,1,1,1,1,1,1}
			});*/

	Maze maze({
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
		});

	//maze.enterMaze();

	maze.printMaze();
	cout << "-----------" << endl;

	Graph graph;
	graph.mazeToGraph(maze.getLinkMaze());
	//graph.printGraph();
	//cout << "-----------" << endl;

	int start = 0; cout << "Enter start position: "; cin >> start;
	auto path = graph.BreadthFirstSearch(start - 1);

	Maze maze1;
	maze1.graphToMaze(graph.getLinkGraph(), get<1>(path), get<2>(path));
	maze1.printMazeWithPath(get<0>(path));

	return 0;
}