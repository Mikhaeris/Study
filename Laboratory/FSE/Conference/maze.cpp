#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <tuple>
#include <algorithm>
#include <windows.h>

using namespace std;

class Graph {
protected:
	int height, width;

public:
	Graph() = default;

	virtual void mazeToGraph(const vector<vector<int>>& maze) = 0;

	virtual void printGraph() const = 0;

};

class WeightedGraph : public Graph {
private:
	vector<vector<pair<int, int>>> adjacencyListWithWeight;

public:

	WeightedGraph() = default;

	void mazeToGraph(const vector<vector<int>>& startMatrix) override {
		height = startMatrix.size();
		width = startMatrix[0].size();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				vector<pair<int, int>> tempVertexadjacencyListWithWeight;
				if (startMatrix[i][j] == 0) {
					if (j - 1 >= 0 && startMatrix[i][j - 1] == 0) {
						tempVertexadjacencyListWithWeight.push_back(make_pair(i * width + (j - 1), 1 + rand() % 11));
					}
					if (i - 1 >= 0 && startMatrix[i - 1][j] == 0) {
						tempVertexadjacencyListWithWeight.push_back(make_pair((i - 1) * width + j, 1 + rand() % 11));
					}
					if (j + 1 < width && startMatrix[i][j + 1] == 0) {
						tempVertexadjacencyListWithWeight.push_back(make_pair(i * width + (j + 1), 1 + rand() % 11));
					}
					if (i + 1 < height && startMatrix[i + 1][j] == 0) {
						tempVertexadjacencyListWithWeight.push_back(make_pair((i + 1) * width + j, 1 + rand() % 11));
					}
				}
				adjacencyListWithWeight.push_back(tempVertexadjacencyListWithWeight);
			}
		}
	}

	/*pair<vector<vector<int>>, pair<int, int>> mstGraphTest() {
		int n = height*width;
		const int INF = INT_MAX;

		vector<int> min_e(n, INF), sel_e(n, -1);
		min_e[0] = 0;
		set < pair<int, int> > q;
		q.insert(make_pair(0, 0));
		for (int i = 0; i < n; ++i) {
			if (q.empty()) {
				cout << "No MST!";
				exit(0);
			}
			int v = q.begin()->second;
			q.erase(q.begin());

			if (sel_e[v] != -1)
				cout << v << " " << sel_e[v] << endl;

			for (size_t j = 0; j < adjacencyListWithWeight[v].size(); ++j) {
				int to = adjacencyListWithWeight[v][j].first,
					cost = adjacencyListWithWeight[v][j].second;
				if (cost < min_e[to]) {
					q.erase(make_pair(min_e[to], to));
					min_e[to] = cost;
					sel_e[to] = v;
					q.insert(make_pair(min_e[to], to));
				}
			}
		}
	}*/

	pair<vector<vector<int>>, pair<int, int>> mstGraph() {
		int n = height * width;
		const int INF = 1000000000;

		vector<int> min_e(n, INF), sel_e(n, -1);
		vector<bool> visited(n, false);
		min_e[0] = 0;

		vector<vector<int>> MST(n);

		set<pair<int, int>> q;
		q.insert(make_pair(0, 0));

		for (int i = 0; i < n; ++i) {
			if (q.empty()) {
				cerr << "No MST!" << endl;
				return {};
			}

			auto it = q.begin();
			int v = it->second;
			q.erase(it);

			if (visited[v]) {
				continue;
			}
			visited[v] = true;

			if (sel_e[v] != -1) {
				MST[sel_e[v]].push_back(v);
				MST[v].push_back(sel_e[v]);
			}

			for (size_t j = 0; j < adjacencyListWithWeight[v].size(); ++j) {
				int to = adjacencyListWithWeight[v][j].first;
				int cost = adjacencyListWithWeight[v][j].second;

				if (!visited[to] && cost < min_e[to]) {
					q.erase(make_pair(min_e[to], to));
					min_e[to] = cost;
					sel_e[to] = v;
					q.insert(make_pair(min_e[to], to));
				}
			}
		}

		return make_pair(MST, make_pair(height, width));
	}

	void printGraph() const override {
		int count = 0;
		for (auto i : adjacencyListWithWeight) {
			cout << count << ": ";
			for (auto j : i) {
				cout << "|n: " << j.first << " w: " << j.second << "| ";
			}
			count++;
			cout << endl;
		}
	}

};

class NoWeightedGraph : public Graph {
private:
	vector<vector<int>> adjacencyList;

public:
	NoWeightedGraph() = default;

	NoWeightedGraph(vector<vector<int>> vec, int height, int width) {
		this->height = height;
		this->width = width;

		adjacencyList = vec;
	}

	const vector<vector<int>>& getLinkGraph() {
		return adjacencyList;
	}

	void mazeToGraph(const vector<vector<int>>& maze) override {
		height = maze.size();
		width = maze[0].size();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				vector<int> tempVertexAdjacencyList;
				if (maze[i][j] == 0) {
					if (j - 1 >= 0 && maze[i][j - 1] == 0) {
						tempVertexAdjacencyList.push_back(i * width + (j - 1));
					}
					if (i - 1 >= 0 && maze[i - 1][j] == 0) {
						tempVertexAdjacencyList.push_back((i - 1) * width + j);
					}
					if (j + 1 < width && maze[i][j + 1] == 0) {
						tempVertexAdjacencyList.push_back(i * width + (j + 1));
					}
					if (i + 1 < height && maze[i + 1][j] == 0) {
						tempVertexAdjacencyList.push_back((i + 1) * width + j);
					}
				}
				adjacencyList.push_back(tempVertexAdjacencyList);
			}
		}
	}

	// Bfs
	tuple<vector<int>, int, int> breadthFirstSearch(int start) {
		if (start == 0) start = width;

		int n = adjacencyList.size();
		int finish = -1;

		queue<int> queueBurning;
		vector<bool> used(n);

		vector<int> length(n), parent(n);

		queueBurning.push(start);
		used[start] = true;
		parent[start] = -1;

		while (!queueBurning.empty()) {
			int vertex = queueBurning.front();
			queueBurning.pop();

			if (vertex != start && (((vertex + 1) % width == 0) || (vertex % width == 0) || ((vertex - width) < 0) || ((vertex + width) >= (width * height)))) {
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

		if (finish == -1 || !used[finish]) {
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

	void printGraph() const override {
		for (int i = 0; i < adjacencyList.size(); i++) {
			cout << i << ": ";
			for (int j = 0; j < adjacencyList[i].size(); j++) {
				cout << adjacencyList[i][j] << " ";
			}
			cout << endl;
		}
	}
};

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
			maze.push_back(vector<int>(width, 1));
		}
	}

	void enterMaze() {
		int n = 0; cout << "Enter n: "; cin >> n;
		initializeMaze(height, width);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin >> maze[i][j];
			}
		}
	}

	void generateMaze() {
		int countHeightVertex = 5 + rand() % 11;
		int countWidthVertex = 5 + rand() % 11;

		vector<vector<int>> startMatrix(countHeightVertex, vector<int>(countWidthVertex, 0));

		WeightedGraph tempGraph;
		tempGraph.mazeToGraph(startMatrix);
		//tempGraph.printGraph();

		auto answer = tempGraph.mstGraph();

		mstGraphToMaze(answer.first, answer.second.first, answer.second.second);
	}

	void generateMazeWithParameters(int height, int width) {
		int countHeightVertex = height / 2;
		int countWidthVertex = width / 2;

		vector<vector<int>> startMatrix(countHeightVertex, vector<int>(countWidthVertex, 0));

		WeightedGraph tempGraph;
		tempGraph.mazeToGraph(startMatrix);
		//tempGraph.printGraph();

		auto answer = tempGraph.mstGraph();

		mstGraphToMaze(answer.first, answer.second.first, answer.second.second);
	}

	void mstGraphToMaze(const vector<vector<int>>& adjacencyList, int height, int width) {
		this->height = height * 2 - 1;
		this->width = width * 2 - 1;
		initializeMaze(this->height, this->width);

		int aL = 0;
		for (int i = 0; i < this->height; i += 2) {
			for (int j = 0; j < this->width; j += 2) {
				maze[i][j] = 0;
				vector<int> vecVex = adjacencyList[aL];
				stable_sort(vecVex.begin(), vecVex.end());

				for (int k = 0; k < vecVex.size(); k++) {
					int margin = aL - vecVex[k];
					if (margin > 1) {
						maze[i - 1][j] = 0;
						maze[i - 2][j] = 0;
					}
					if (margin == 1) {
						maze[i][j - 1] = 0;
						maze[i][j - 2] = 0;
					}
					if (margin == -1) {
						maze[i][j + 1] = 0;
						maze[i][j + 2] = 0;
					}
					if (margin < -1) {
						maze[i + 1][j] = 0;
						maze[i + 2][j] = 0;
					}

				}

				aL++;
			}
		}

		this->height = this->height + 2;
		this->width = this->width + 2;

		for (int i = 0; i < this->height - 2; i++) {
			if (i == 0) maze[i].insert(maze[i].begin(), 0);
			else maze[i].insert(maze[i].begin(), 1);

			if (i == this->height - 3) maze[i].push_back(0);
			else maze[i].push_back(1);
		}

		vector<int> border(maze[0].size(), 1);

		maze.insert(maze.begin(), border);
		maze.push_back(border);

		/*for (int i = 0; i < this->height; i++) {
			for (int j = 0; j < this->width; j++) {
				cout << maze[i][j] << " ";
			}
			cout << endl;
		}*/

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
				cout << (maze[i][j] == 1 ? u8"\u25A0" : " ") << " ";
			}
			cout << endl;
		}
	}

	tuple<bool, int> vertexInPath(vector<int> path, int vertex) {
		for (int i = 0; i < path.size(); i++) {
			if (path[i] == vertex) {
				if (i == 0) {
					return tuple<bool, int>(true, 1);
				}
				else if (i == path.size() - 1) {
					return tuple<bool, int>(true, 2);
				}
				else {
					return tuple<bool, int>(true, 0);
				}
			}
		}
		return tuple<bool, int>(false, 0);
	}

	void printMazeWithPath(vector<int> path) {
		int countPath = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				auto answer = vertexInPath(path, countPath);
				if (get<0>(answer)) {
					if (get<1>(answer) == 1) {
						cout << 'S' << " ";
					}
					else if (get<1>(answer) == 2) {
						cout << 'F' << " ";
					}
					else {
						cout << u8"\u25CB" << " ";
					}
				}
				else {
					cout << (maze[i][j] == 1 ? u8"\u25A0" : " ") << " ";
				}
				countPath++;
			}
			cout << endl;
		}
	}

};

int main() {
	SetConsoleOutputCP(CP_UTF8);

	srand(static_cast<unsigned int>(time(nullptr)));

	//maze.enterMaze();

	Maze maze;
	maze.generateMaze();

	/*int height = 0, width = 0; cout << "Enter height and width: "; cin >> height >> width;
	maze.generateMazeWithParameters(height, width);*/

	maze.printMaze();
	cout << "-----------" << endl;

	NoWeightedGraph graph;
	graph.mazeToGraph(maze.getLinkMaze());
	//graph.printGraph();
	//cout << "-----------" << endl;

	//int start = 0; cout << "Enter start position: "; cin >> start;
	auto path = graph.breadthFirstSearch(0);

	Maze maze1;
	maze1.graphToMaze(graph.getLinkGraph(), get<1>(path), get<2>(path));
	//maze1.printMaze();
	maze1.printMazeWithPath(get<0>(path));

	return 0;
}



/*Maze maze({
{1, 1, 1, 1, 1},
{0, 0, 0, 0, 1},
{1, 1, 1, 0, 1},
{0, 0, 0, 0, 1},
{1, 1, 1, 1, 1}, });*/

/*Maze maze({
{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{1,0,1,1,1,0,1},
{1,0,0,0,1,0,1},
{1,1,1,1,1,0,1},
{1,0,0,0,0,0,0},
{1,1,1,1,1,1,1}
});*/

/*Maze maze({
{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,1,1,1,0,1},
{1,0,0,0,1,0,1},
{1,1,1,1,1,0,1},
{1,0,0,0,0,0,0},
{1,1,1,1,1,1,1}
});*/

/*Maze maze({
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
{1,0,1,0,1,0,1,0,1,0,1,0,1,1,1},
{1,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
{1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
{1,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
{1,0,1,0,1,0,1,0,1,0,1,1,1,0,1},
{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0,0,0,1,0,1,0,1},
{1,0,1,1,1,0,1,0,1,0,1,0,1,1,1},
{1,0,0,0,0,0,1,0,1,0,1,0,0,0,1},
{1,1,1,1,1,0,1,0,1,1,1,1,1,0,1},
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
});*/