#include "pch.h"
#include "Q1.h"
#include "Q2.h"

//---------------------------------------------------------
//Test Case for Matrix Implementation of Graph 
//----------------------------------------------------------
//Test adding a vertex to an empty graph
TEST(GraphTest, AddVertexEmptyGraph) {
	Graph graph(0);
	graph.addVertex();
	EXPECT_EQ(1, graph.getNumVertices());
}
//
// Test adding an edge to a graph
TEST(GraphTest, AddEdge) {
	Graph graph(2);
	graph.addEdge(0, 1, 1);
	EXPECT_EQ(1, graph.getMatrix()[0][1]);
}
//



/////////////////////////////

TEST(GraphTest, BfsTraversal) {
	Graph graph(4);
	graph.addEdge(0, 1, 1);
	graph.addEdge(0, 2, 1);
	graph.addEdge(1, 2, 1);
	graph.addEdge(2, 0, 1);
	graph.addEdge(2, 3, 1);
	graph.addEdge(3, 3, 1);

//	testing::internal::CaptureStdout();
	graph.bfsTraversal(2);
	std::string output = testing::internal::GetCapturedStdout();
	std::string expectedOutput = "BFS Traversal: 2 0 3 1 \n";
	EXPECT_EQ(expectedOutput, output);
}
/////////////////////////////


//// Test depth-first traversal on a graph
TEST(GraphTest, DfsTraversal) {
	Graph graph(4);
	graph.addEdge(0, 1, 1);
	graph.addEdge(0, 2, 1);
	graph.addEdge(1, 2, 1);
	graph.addEdge(2, 0, 1);
	graph.addEdge(2, 3, 1);
	graph.addEdge(3, 3, 1);
	testing::internal::CaptureStdout();
	graph.dfsTraversal(2);
	std::string output = testing::internal::GetCapturedStdout();
	std::string expectedOutput = "DFS Traversal: 2 0 3 1 \n";
	EXPECT_EQ(expectedOutput, output);
}
////---------------------------------------------------------
////Test Case for Adjacency List Implementation of Graph 
////----------------------------------------------------------
//
//
//TEST(GraphTest, GraphdisplayEmpty) {
//	Graph g(5);
//	std::stringstream buffer;
//	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
//	g.Graphdisplay();
//	std::string output = buffer.str();
//	ASSERT_EQ(output, "1\n2\n3\n4\n5\n");
//	std::cout.rdbuf(old);
//}
////
//TEST(GraphTest, GraphdisplayNonEmpty) {
//    Graph g(5);
//    g.insertEdge(1, 2);
//    g.insertEdge(1, 3);
//    g.insertEdge(2, 4);
//    g.insertEdge(3, 5);
//    std::stringstream buffer;
//    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
//    g.Graphdisplay();
//    std::string output = buffer.str();
//    std::string expectedOutput = "1->2->3->\n2->4->\n3->5->\n4\n5\n";
//    ASSERT_EQ(expectedOutput, output);
//    std::cout.rdbuf(old);
//}
////
//TEST(GraphTest, GraphdisplayEmptyGraph) {
//	Graph g(0);
//	std::stringstream buffer;
//	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
//	g.Graphdisplay();
//	std::string output = buffer.str();
//	ASSERT_EQ(output, "EMPTY GRAPH\n");
//	std::cout.rdbuf(old);
//}
////
//TEST(GraphTest, GraphdisplaySingleVertex) {
//	Graph g(1);
//	std::stringstream buffer;
//	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
//	g.Graphdisplay();
//	std::string output = buffer.str();
//	ASSERT_EQ(output, "1\n");
//	std::cout.rdbuf(old);
//}
////
//TEST(GraphTest, GraphdisplayMultipleVertices) {
//	Graph g(3);
//	std::stringstream buffer;
//	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
//	g.Graphdisplay();
//	std::string output = buffer.str();
//	ASSERT_EQ(output, "1\n2\n3\n");
//	std::cout.rdbuf(old);
//}
////
//TEST(GraphTest, insertEdge) {
//	Graph g(5);
//	g.insertEdge(1, 2);
//	g.insertEdge(1, 3);
//	g.insertEdge(2, 4);
//	g.insertEdge(3, 5);
//	std::stringstream buffer;
//	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
//	g.Graphdisplay();
//	std::string output = buffer.str();
//	ASSERT_EQ(output, "1->2->3->\n2->4->\n3->5->\n4\n5\n");
//	std::cout.rdbuf(old);
//}