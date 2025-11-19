#include <vector>
#include <limits.h>

// todo: generate random dag; see https://stackoverflow.com/questions/12790337/generating-a-random-dag

#include "/grading_dir/tests/extra/racing.cpp"

//struct Edge {
//    int from;
//    int to;
//    int weight; // default = 1 if unweighted graph
//};

std::vector<int> dag_single_source(int n, std::vector<Edge> edges, int source);

int main() {

    // empty test
    std::vector<Edge> empty_test = {};
    std::vector<int> empty_res = dag_single_source(0, empty_test, -1);
    if(empty_res.empty()) PASS();
    else FAIL();

    return 0;
}
