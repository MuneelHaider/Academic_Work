//#pragma once
//#include <iostream>
//#include <list>
//using namespace std;
//
//struct GraphNode {
//
//    int id;
//    list<GraphNode*> neighbors;
//
//	GraphNode(int nodeId) : id(nodeId) {}
//
//    void addNeighbor(GraphNode* neighbor) {
//
//        neighbors.push_back(neighbor);
//    }
//
//    int getID() {
//
//        return id;
//    }
//
//   list<GraphNode*>& getNeighbors()  {
//        
//	   return neighbors;
//    }
//};
//
//
//
//struct Graph {
//
//	list<GraphNode*> nodes;
//
//	Graph(int numNodes) {
//
//		for (int i = 1; i <= numNodes; i++) {
//
//			nodes.push_back(new GraphNode(i));
//		}
//	}
//
//	void addNode(GraphNode* node) {
//
//		nodes.push_back(node);
//	}
//
//	void addEdge(GraphNode* node1, GraphNode* node2) {
//
//		node1->addNeighbor(node2);
//		node2->addNeighbor(node1);
//	}
//
//	GraphNode* getNode(int nodeId) {
//
//		for (const auto& node:nodes) {
//			
//			if (node->getID() == nodeId) {
//			
//				return node;
//			}
//		}
//		return nullptr;
//	}
//
//	void insertEdge(int from, int to)  {
//
//		GraphNode* nodeFrom = getNode(from);
//		GraphNode* nodeTo = getNode(to);
//
//		if (nodeFrom && nodeTo) {
//		
//			nodeFrom->addNeighbor(nodeTo);
//		}
//	}
//	
//	void Graphdisplay() {
//
//		if (nodes.empty()) {
//		
//			cout << "EMPTY GRAPH" << endl;
//		}
//		else {
//			
//			for (const auto& node:nodes) {
//
//				cout << node->getID();
//				
//				if (!node->getNeighbors().empty()) {
//					
//					cout << "->";
//					for (const auto& neighbor : node->getNeighbors()) {
//				
//						cout << neighbor->getID() << "->";
//					}
//				}
//				cout << endl;
//			}
//		}
//	}
//};