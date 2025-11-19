#include <vector>
#include <limits.h>

#include "/grading_dir/tests/extra/racing.cpp"

std::vector<Node> dijkstras_algorithm(int n, std::vector<Edge> edges, int source);


int main() {


    // empty test
    std::vector<Edge> empty_test = {};
    std::vector<Node> empty_res = dijkstras_algorithm(0, empty_test, -1);
    if(empty_res.empty()) PASS();
    else FAIL();

    return 0;
}
