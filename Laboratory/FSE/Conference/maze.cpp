#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <windows.h>

class Graph {
protected:
	int height, width;

public:
	Graph() = default;

	virtual void convertMazeToGraph(const std::vector<std::vector<int>>& maze) = 0;

	virtual void printGraph() const = 0;

};

class WeightedGraph : public Graph {
private:
	std::vector<std::vector<std::pair<int, int>>> adjacencyListWithWeight;

public:

	WeightedGraph() = default;

	void convertMazeToGraph(const std::vector<std::vector<int>>& startMatrix) override {
		height = startMatrix.size();
		width = startMatrix[0].size();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				std::vector<std::pair<int, int>> tempVertexadjacencyListWithWeight;
				if (startMatrix[i][j] == 0) {
					if (j - 1 >= 0 && startMatrix[i][j - 1] == 0) {
						tempVertexadjacencyListWithWeight.push_back(std::make_pair(i * width + (j - 1), 1 + rand() % 11));
					}
					if (i - 1 >= 0 && startMatrix[i - 1][j] == 0) {
						tempVertexadjacencyListWithWeight.push_back(std::make_pair((i - 1) * width + j, 1 + rand() % 11));
					}
					if (j + 1 < width && startMatrix[i][j + 1] == 0) {
						tempVertexadjacencyListWithWeight.push_back(std::make_pair(i * width + (j + 1), 1 + rand() % 11));
					}
					if (i + 1 < height && startMatrix[i + 1][j] == 0) {
						tempVertexadjacencyListWithWeight.push_back(std::make_pair((i + 1) * width + j, 1 + rand() % 11));
					}
				}
				adjacencyListWithWeight.push_back(tempVertexadjacencyListWithWeight);
			}
		}
	}

	std::pair<std::vector<std::vector<int>>, std::pair<int, int>> mstGraph() {
		int n = height * width;
		const int INF = INT_MAX;

		std::vector<std::vector<int>> MST(n);

		std::vector<int> minEdgeWeights(n, INF), parent(n, -1);
		minEdgeWeights[0] = 0;

		std::vector<bool> used(n, false);
		std::set<std::pair<int, int>> pQueue;

		pQueue.insert(std::make_pair(0, 0));
		for (int i = 0; i < n; ++i) {
			if (pQueue.empty())
				return {};

			int vertex = pQueue.begin()->second;
			pQueue.erase(pQueue.begin());
			used[vertex] = true;

			if (parent[vertex] != -1) {
				MST[parent[vertex]].push_back(vertex);
				MST[vertex].push_back(parent[vertex]);
			}

			for (size_t j = 0; j < adjacencyListWithWeight[vertex].size(); ++j) {
				int to = adjacencyListWithWeight[vertex][j].first;
				int cost = adjacencyListWithWeight[vertex][j].second;

				if (cost < minEdgeWeights[to] && !used[to]) {
					pQueue.erase(std::make_pair(minEdgeWeights[to], to));
					minEdgeWeights[to] = cost;
					parent[to] = vertex;
					pQueue.insert(std::make_pair(minEdgeWeights[to], to));
				}
			}
		}
		return make_pair(MST, std::make_pair(height, width));
	}

	void printGraph() const override {
		int count = 0;
		for (auto& i : adjacencyListWithWeight) {
			std::cout << count << ": ";
			for (auto& j : i) {
				std::cout << "|n: " << j.first << " w: " << j.second << "| ";
			}
			count++;
			std::cout << std::endl;
		}
	}

};

class NoWeightedGraph : public Graph {
private:
	std::vector<std::vector<int>> adjacencyList;

public:
	NoWeightedGraph() = default;

	NoWeightedGraph(std::vector<std::vector<int>>& vec, int& height, int& width) {
		this->height = height;
		this->width = width;

		adjacencyList = vec;
	}

	const std::vector<std::vector<int>>& getLinkGraph() {
		return adjacencyList;
	}

	void convertMazeToGraph(const std::vector<std::vector<int>>& maze) override {
		height = maze.size();
		width = maze[0].size();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				std::vector<int> tempVertexAdjacencyList;
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

	std::vector<int> breadthFirstSearch(int start) {
		if (start == 0) start = width;

		int n = adjacencyList.size();
		int finish = -1;

		std::queue<int> queueBurning;
		std::vector<bool> used(n);

		std::vector<int> length(n), parent(n);

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
			std::cout << "No path!" << std::endl;
		}
		else {
			std::vector<int> path;
			for (int v = finish; v != -1; v = parent[v]) {
				path.push_back(v);
			}

			reverse(path.begin(), path.end());
			return path;

			/*cout << "Path: ";
			for (size_t i = 0; i < path.size(); ++i) {
				cout << path[i] << " ";
			}
			cout << endl;*/
		}
	}

	void printGraph() const override {
		for (int i = 0; i < adjacencyList.size(); i++) {
			std::cout << i << ": ";
			for (int j = 0; j < adjacencyList[i].size(); j++) {
				std::cout << adjacencyList[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};

class Maze {
private:
	std::vector<std::vector<int>> maze;
	int height, width;

public:
	Maze() = default;

	Maze(std::vector<std::vector<int>>& vec) {
		height = vec.size();
		width = vec[0].size();

		initializeMaze(height, width);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				maze[i][j] = vec[i][j];
			}
		}
	}

	const std::vector<std::vector<int>>& getLinkMaze() {
		return maze;
	}

	void initializeMaze(int& height, int& width) {
		maze.resize(height, std::vector<int>(width, 1));
	}

	void enterMaze() {
		int n = 0; std::cout << "Enter n: "; std::cin >> n;
		initializeMaze(height, width);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				std::cin >> maze[i][j];
			}
		}
	}

	void generateMaze() {
		int countHeightVertex = 5 + rand() % 11;
		int countWidthVertex = 5 + rand() % 11;

		std::vector<std::vector<int>> startMatrix(countHeightVertex, std::vector<int>(countWidthVertex, 0));

		WeightedGraph tempGraph;
		tempGraph.convertMazeToGraph(startMatrix);
		//tempGraph.printGraph();

		auto answer = tempGraph.mstGraph();

		convertMstGraphToMaze(answer.first, answer.second.first, answer.second.second);
	}

	void generateMaze(int height, int width) {
		if (height % 2 == 0)
			height--;
		if (width % 2 == 0)
			width--;

		int countHeightVertex = (height - 1) / 2;
		int countWidthVertex = (width - 1) / 2;

		std::vector<std::vector<int>> startMatrix(countHeightVertex, std::vector<int>(countWidthVertex, 0));

		WeightedGraph tempGraph;
		tempGraph.convertMazeToGraph(startMatrix);
		//tempGraph.printGraph();

		auto answer = tempGraph.mstGraph();

		convertMstGraphToMaze(answer.first, answer.second.first, answer.second.second);
	}

	void convertMstGraphToMaze(const std::vector<std::vector<int>>& adjacencyList, int& height, int& width) {
		this->height = height * 2 - 1;
		this->width = width * 2 - 1;
		initializeMaze(this->height, this->width);

		int aL = 0;
		for (int i = 0; i < this->height; i += 2) {
			for (int j = 0; j < this->width; j += 2) {
				maze[i][j] = 0;
				std::vector<int> vecVex = adjacencyList[aL];
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

		std::vector<int> border(maze[0].size(), 1);

		maze.insert(maze.begin(), border);
		maze.push_back(border);
	}

	void convertGraphToMaze(const std::vector<std::vector<int>>& adjacencyList) {

		for (int index = 0; index < adjacencyList.size(); index++) {
			int i = index / width;
			int j = index % width;

			maze[i][j] = !adjacencyList[index].empty() ? 0 : 1;
		}
	}

	void printMaze() {
		std::cout << height << "x" << width << std::endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				std::cout << (maze[i][j] == 1 ? u8"\u25A0" : " ") << " ";
			}
			std::cout << std::endl;
		}
	}

	std::pair<bool, int> vertexInPath(std::vector<int>& path, int& vertex) {
		for (int i = 0; i < path.size(); i++) {
			if (path[i] == vertex) {
				if (i == 0) {
					return std::make_pair(true, 1);
				}
				else if (i == path.size() - 1) {
					return std::make_pair(true, 2);
				}
				else {
					return std::make_pair(true, 0);
				}
			}
		}
		return std::make_pair(false, 0);
	}

	void printMazeWithPath(std::vector<int>& path) {
		int countPath = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				auto answer = vertexInPath(path, countPath);
				if (answer.first) {
					if (answer.second == 1) {
						std::cout << 'S' << " ";
					}
					else if (answer.second == 2) {
						std::cout << 'F' << " ";
					}
					else {
						std::cout << u8"\u25CB" << " ";
					}
				}
				else {
					std::cout << (maze[i][j] == 1 ? u8"\u25A0" : " ") << " ";
				}
				countPath++;
			}
			std::cout << std::endl;
		}
	}

};

int main() {
	SetConsoleOutputCP(CP_UTF8);

	srand(static_cast<unsigned int>(time(nullptr)));

	Maze maze;
	//maze.enterMaze();
	maze.generateMaze();

	/*int height = 0, width = 0; cout << "Enter height and width: "; cin >> height >> width;
	maze.generateMaze(height, width);*/

	maze.printMaze();
	std::cout << "-----------" << std::endl;

	NoWeightedGraph graph;
	graph.convertMazeToGraph(maze.getLinkMaze());
	//graph.printGraph();
	//cout << "-----------" << endl;

	std::vector<int> path = graph.breadthFirstSearch(0);

	maze.printMazeWithPath(path);

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