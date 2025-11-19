
#include <vector>
#include <limits>
#include <functional>
#include <cmath>

#include "/grading_dir/tests/extra/racing.cpp"


std::vector<GridNode> a_star_algorithm(
    int m, 
    int n, 
    std::vector<GridEdge> edges, 
    GridNode source, 
    GridNode target,
    function<double(GridNode,GridNode)> h
);


int main() {

    // empty test
    std::vector<GridNode> empty_res = a_star_algorithm(0, 0, {}, GridNode(), GridNode(), alex::heuristic_cost);
    if(empty_res.empty()) PASS();
    else FAIL();


    return 0;
}
