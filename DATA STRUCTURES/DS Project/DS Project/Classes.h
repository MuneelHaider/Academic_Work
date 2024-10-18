#pragma once
#include <iostream>
using namespace std;

/****************************************
*
*   Muneel Haider 21i-0640
*   Muhammad Abdullah 21i-0643
*   Abdullah Zahoor 21i-2481
*
*   Data Structures Project 2023 Spring
*
*                                       */

struct cordinates {

	int x;
	int y;

	cordinates(int a = 0, int b = 0) {

		x = a;
		y = b;
	}
};

struct Player {

	int score;
	char letter;
	cordinates location;
	bool alive;
	bool win;

	Player(int a = 0, int b = 0) {

		location.x = a;
		location.y = b;

		letter = 'X';
		score = 0;
		alive = true;
		win = false;
	}

	void PlayerUp() {

		if (location.y != 0) {
	
			location.y--;
		}
		else {

			cout << "Cant move up." << endl << endl;
		}
	}

	void PlayerDown(int r) {

		if (location.y != r - 1) {

			location.y++;
		}
	}

	void PlayerRight(int r) {

		if (location.x != r - 1) {

			location.x++;
		}
	}

	void PlayerLeft() {

		if (location.x != 0) {

			location.x--;
		}
	}


};

struct map{

	int weight;
	char letter;
	int id;

	map(int w = 0, char l = '\0', int i = 0) {

		weight = w;
		letter = l;
		id = i;
	}
};

int score = 0;

struct graphClass {

	int size;
	int area[400][400];

	graphClass(int s = 0) {

		size = s;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {

				area[i][j] = 0;
			}
		}
	}

	void add_Edge(int a, int b, int score) {

		if (a >= 0 && b >= 0 && a < size && b < size) {

			area[a][b] = score;
		}
	}

	void printGraph() {

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {

				cout << area[i][j] << " ";
			}
			cout << endl;
		}
	}

	/*************************************/

	int Indexer(int rows, int cols) {

		int result = (rows * 20) + cols;

		return result;
	}

	int** CreateAdjacencyMatrix_From_Map(map** game, int rows, int cols) {

		int TotalNodes = rows * cols;

		int current = 0;
		int tempArray[4] = { 0 };
		int t1 = 0;
		int t2 = 0;
		int temp = 0;

		int** adjacency_matrix = new int* [TotalNodes];
		for (int i = 0; i < TotalNodes; i++) {

			adjacency_matrix[i] = new int[TotalNodes];

			for (int j = 0; j < TotalNodes; j++) {

				if (i == j) {

					adjacency_matrix[i][j] = 0;
				}
				else {

					adjacency_matrix[i][j] = 100000; // Initialize the matrix with a large score
				}
			}
		}

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < cols; j++) {

				current = Indexer(i, j);
				tempArray[4];

				tempArray[0] = Indexer(i - 1, j);
				tempArray[1] = Indexer(i + 1, j);
				tempArray[2] = Indexer(i, j - 1);
				tempArray[3] = Indexer(i, j + 1);

				for (int k = 0; k < 4; k++) {

					t1 = tempArray[k] / 20;
					t2 = tempArray[k] % 20;

					if ((t1 >= 0 && t1 < rows) && (t2 >= 0 && t2 < cols)) {

						temp = game[i][j].weight + game[t1][t2].weight;

						adjacency_matrix[current][tempArray[k]] = temp - 1;
					}
				}
			}
		}

		return adjacency_matrix;
	}

	int MinimumDistanceCalc(int* distance, bool* flag, int n) {

		int min = 100000;
		int min_index = 0;

		for (int i = 0; i < n; i++) {
		
			if (flag[i] == false && distance[i] <= min) {
			
				min = distance[i];
				min_index = i;
			}
		}

		return min_index;
	}

	void CheckAVL(map** game, int rows, int cols) {

		if (game[rows][cols].letter == 'C') {}
		else if (game[rows][cols].letter == 'J') {

			score += 50;
		}
		else if (game[rows][cols].letter == 'P') {

			score += 70;
		}
		else if (game[rows][cols].letter == 'W') {

			score += 30;
		}
		else if (game[rows][cols].letter == '%') {

			cout << endl << endl;
			cout << "You DIED! GG noob EZ";
			cout << endl << endl;
			exit(0);
		}
		else if (game[rows][cols].letter == '#') {}
		else if (game[rows][cols].letter == '&') {

			score -= 50;
		}
		else if (game[rows][cols].letter == '$') {

			score -= 70;
		}
		else if (game[rows][cols].letter == '@') {

			score -= 30;
		}

		if (score < 0) {

			cout << endl << endl;
			cout << "You DIED! GG noob EZ";
			cout << endl << endl;
			exit(0);
		}
	}

	void printPath_Parent(int* parentArray, int start, int end, map** game) {

		int rows = 0;
		int cols = 0;
		int temp = 0;

		if (start == end) {
			
			rows = start / 20;
			cols = start % 20;

			CheckAVL(game, rows, cols);

			cout << endl << "(" << rows << " , " << cols << " , " << game[rows][cols].letter << ")" << endl;
		}
		else {

			temp = parentArray[end];

			printPath_Parent(parentArray, start, temp, game);

			rows = end / 20;
			cols = end % 20;
			
			CheckAVL(game, rows, cols);

			cout << "-> (" << rows << " , " << cols << " , " << game[rows][cols].letter << ")" << endl;
		}
	}

	void dijkstra(int** adjacency_matrix, int start, int end, map** game, int rows, int cols) {
		
		int TotalNodes = rows * cols;

		int* dist = new int[TotalNodes];

		bool* BoolFlags = new bool[TotalNodes];
		
		int* parentArray = new int[TotalNodes];

		int temp = 0;

		bool flag1 = false;

		for (int i = 0; i < TotalNodes; i++) {
		
			dist[i] = 100000;

			BoolFlags[i] = false;
		}


		dist[start] = 0;
		parentArray[start] = -1;
		

		for (int i = 0; i < TotalNodes - 1; i++) {
		
			temp = MinimumDistanceCalc(dist, BoolFlags, TotalNodes);

			BoolFlags[temp] = true;

			for (int j = 0; j < TotalNodes; j++) {

				flag1 = (dist[temp] + adjacency_matrix[temp][j]) < dist[j];

				if (!BoolFlags[j] && adjacency_matrix[temp][j] && (dist[temp] != 100000) && flag1) {

					dist[j] = dist[temp] + adjacency_matrix[temp][j];
					parentArray[j] = temp;
				}
			}
		}

		cout << "The shortest path using Dijkstra's Algorithm from " << start << " to " << end << " is : ";
		
		printPath_Parent(parentArray, start, end, game);

		cout << "The shortest distance using Dijkstra's Algorithm from " << start << " to " << end << " is: " << dist[end] << endl;
	}

	void Floyd(int** graph, int n, int x, int y) {
		
		bool flag = false;

		int** distance = new int * [n];

		for (int i = 0; i < n; i++) {
			
			distance[i] = new int[n] ;
		}
		
		for (int i = 0; i < n; i++) {
		
			for (int j = 0; j < n; j++) {
			
				distance[i][j] = graph[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
		
			for (int j = 0; j < n; j++) {
			
				for (int k = 0; k < n; k++) {
				
					flag = (distance[j][i] + distance[i][k]) < distance[j][k];

					if (distance[j][i] != 10000 && distance[i][k] != 10000 && flag) {
					
						distance[j][k] = distance[j][i] + distance[i][k];
					}
				}
			}
		}

		cout << "The shortest path between " << x << " and " << y << " using Floyd's Algorithm is: " << distance[x][y] << endl;
	}

	void PrimsAlgorithm(int** matrix, int start, int end, map** game, int rows, int cols) {

		int t_vertices = rows * cols;

		int* parentArray = new int[t_vertices];

		int* score = new int[t_vertices];

		bool* BoolFlag = new bool[t_vertices];

		bool flag = false;
		int minimumscore = 0;
		int temp = 0;

		for (int i = 0; i < t_vertices; i++) {

			score[i] = 1000000;
			BoolFlag[i] = false;
		}

		score[start] = 0;
		parentArray[start] = -1;

		for (int i = 0; i < t_vertices - 1; i++) {

			minimumscore = 1000000;
			temp = -1;

			for (int j = 0; j < t_vertices; j++) {

				flag = score[j] < minimumscore;

				if (!BoolFlag[j] && flag) {

					minimumscore = score[j];
					temp = j;
				}
			}

			BoolFlag[temp] = true;

			for (int j = 0; j < t_vertices; j++) {

				flag = matrix[temp][j] < score[j];

				if (matrix[temp][j] && !BoolFlag[j] && flag) {

					parentArray[j] = temp;
					score[j] = matrix[temp][j];
				}
			}
		}

		int r = 0;
		int c = 0;
		int parentArrayRow = 0;
		int parentArrayCol = 0;

		cout << "Minimum spanning tree edges and their weights using Prims Algorithm:" << endl;
		for (int i = 1; i < t_vertices; i++) {

			r = i / cols;
			c = i % cols;

			parentArrayRow = parentArray[i] / cols;
			parentArrayCol = parentArray[i] % cols;

			cout << "From (" << parentArrayRow << "," << parentArrayCol << ") to (" << r << "," << c << ") - weight: " << game[r][c].weight << endl;
		}
	}
};

/*****************************************************/

struct node {

	int score;
	int height;
	node* left;
	node* right;

	node(int k = 0) {

		score = k;
		height = 1;
		left = NULL;
		right = NULL;
	}
};

struct AVL {

	node* root;

	AVL() {
	
		root = NULL;
	}

	int getHeight(node* current) {
		
		if (current != NULL) {

			return current->height;
		}

		return 0;
	}

	int BalanceAVLFactor(node* current) {

		return (getHeight(current->right) - getHeight(current->left));
	}

	void AdjustHeight(node* current) {

		int height_Left = getHeight(current->left);
		int height_Right = getHeight(current->right);

		if (height_Left > height_Right) {

			current->height = height_Left + 1;
		}
		else {

			current->height = height_Right + 1;
		}
	}

	node* rotateRight(node* head) {
		
		node* current = head->left;
		head->left = current->right;
		current->right = head;

		AdjustHeight(head);
		AdjustHeight(current);
		
		return current;
	}

	node* rotateLeft(node* head) {
		
		node* current = head->right;
		head->right = current->left;
		current->left = head;

		AdjustHeight(head);
		AdjustHeight(current);
		
		return current;
	}

	node* BalanceAVL(node* current) {

		AdjustHeight(current);
		
		int temp = 0;
		temp = BalanceAVLFactor(current);

		if (temp == 2) {
		
			temp = BalanceAVLFactor(current->right);

			if (temp < 0) {
			
				current->right = rotateRight(current->right);
			}

			return rotateLeft(current);
		}
		else if (temp == -2) {
			
			temp = BalanceAVLFactor(current->left);

			if (temp > 0) {
			
				current->left = rotateLeft(current->left);
			}
			
			return rotateRight(current);
		}
		
		return current;
	}

	node* insert(node* current, int score) {
		
		if (current == NULL) {
		
			node* temp = new node(score);

			return temp;
		}
		else if (score < current->score) {
			
			current->left = insert(current->left, score);
		}
		else {
			
			current->right = insert(current->right, score);
		}
		
		return BalanceAVL(current);
	}

	void insert(int score) {
		
		root = insert(root, score);
	}

	void InOrderTraversal(node* head, int& sum) {

		if (head != NULL) {

			InOrderTraversal(head->left, sum);
			sum += head->score;
			InOrderTraversal(head->right, sum);
		}
	}

	void DeathNote() {

		cout << endl << endl;
		cout << "Your score at the end of the game is: " << score << endl << endl;
	}
};