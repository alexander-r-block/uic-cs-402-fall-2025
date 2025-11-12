#include <vector>
#include <limits.h>

struct Edge {
    int from;
    int to;
    int weight; // default = 1 if unweighted graph
};

std::vector<int> dag_single_source(int n, std::vector<Edge> edges, int source);

int main() {
    double total_score = 3.0;
    double score = 0.0;

    std::vector<Edge> test1 = {Edge(0,1,1), Edge(0,2,-1), Edge(2,1,1)};
    std::vector<int> ans1 = {0, 0, -1};
    std::vector<int> ans3 = {INT_MAX, 1, 0};

    std::vector<Edge> test2 = {Edge(0, 1, 2), Edge(0,2,2), Edge(1,3,-2), Edge(1,4,2), Edge(2,5,-3), Edge(2,6,3)};
    std::vector<int> ans2 = {0, 2, 2, 0, 4, -1, 5};

    std::vector<int> res1 = dag_single_source(3, test1, 0);
    if(res1 == ans1) ++score;
    std::vector<int> res3 = dag_single_source(3, test1, 2);
    if(res3 == ans3) ++score;

    std::vector<int> res2 = dag_single_source(7, test2, 0);
    if(res2 == ans2) ++score;


    RESULT(100*(score / total_score));
    return 0;
}
