#include <vector>


// undirected edges
struct Edge {
    int u;
    int v;
};

std::pair<int, std::vector<int>> light_post_problem(int n, const std::vector<Edge>& edges, const std::vector<int>& costs);


int main() {

    int n1 = 1;
    std::vector<Edge> e1 = {};
    std::vector<int> c1 = {5};

    int n2 = 2;
    std::vector<Edge> e2 = { Edge(0,1) };
    std::vector<int> c2 = {1, 2};

    int n3 = 2;
    std::vector<Edge> e3 = { Edge(0,1), Edge(0,2) };
    std::vector<int> c3 = {50, 2, 3};

    std::pair<int, std::vector<int>> sol1 = {5, {0}};
    std::pair<int, std::vector<int>> sol2 = {1, {0}};
    std::pair<int, std::vector<int>> sol3 = {5, {1,2}};

    auto ans1 = light_post_problem(n1, e1, c1);
    auto ans2 = light_post_problem(n2, e2, c2);
    auto ans3 = light_post_problem(n3, e3, c3);

    double total_score = 3.0;
    double score = 0.0;

    if(ans1 == sol1) ++score;
    if(ans2 == sol2) ++score;
    if(ans3 == sol3) ++score;


    RESULT(100*(score / total_score));

    return 0;
}
