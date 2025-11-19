#include <vector>
#include <limits.h>

#include "/grading_dir/tests/extra/racing.cpp"

std::vector<Node> dijkstras_algorithm(int n, std::vector<Edge> edges, int source);

bool soft_check_ans(int n, const std::vector<Node>& ans, const std::vector<Node>& correct) {
    if(ans.size() != n) return false;
    for(int i = 0; i < n; ++i) {
        int score = 0;
        if(ans[i].id == i) ++score;
        if(ans[i].path_cost == correct[i].path_cost) ++score;
        if(score < 2) return false;
    }
    return true;
}

bool hard_check_ans(int n, const std::vector<Node>& ans, const std::vector<Node>& correct) {
    if(ans.size() != n) return false;
    for(int i = 0; i < n; ++i) {
        int score = 0;
        if(ans[i].id == i) ++score;
        if(ans[i].path_cost == correct[i].path_cost) ++score;
        if(ans[i].pred == correct[i].pred) ++score;
        if(score < 3) return false;
    }
    return true;
}

int main() {
    double total_score = 19.0;
    double score = 0.0;


    // empty test
    //std::vector<Edge> empty_test = {};
    //std::vector<Node> empty_res = dijkstras_algorithm(0, empty_test, -1);
    //if(empty_res.empty()) ++score;


    // singleton test
    std::vector<Node> single_res = dijkstras_algorithm(1, {}, 0);
    if(single_res[0].id == 0 && single_res[0].path_cost == 0) ++score;

    // easy tests
    std::vector<Edge> t1 = {Edge(0,1), Edge(0,4,2), Edge(1,2,20), Edge(1,3,3), Edge(1,4,15), Edge(3,2,7), Edge(3,4,2), Edge(4,1,1), Edge(2,3,5)};
    int n1 = 5;
    int s1 = 1;
    std::vector<Node> sol1 = {Node(0, INT_MAX, -1), Node(1,0,-1), Node(2,10,3), Node(3,3,1), Node(4,5,3) };
    std::vector<Node> ans1 = dijkstras_algorithm(n1, t1, s1);

    if(hard_check_ans(n1, ans1, sol1)) ++score;

    std::vector<Edge> t2 = {Edge(3,4), Edge(4,2), Edge(2,5), Edge(5,1), Edge(1,0)};
    int n2 = 6;
    int s2 = 2;
    std::vector<Node> sol2 = {Node(0, 3, 1), Node(1,2,5), Node(2,0,-1), Node(3,INT_MAX,-1), Node(4,INT_MAX,-1), Node(5,1,2)};
    std::vector<Node> ans2 = dijkstras_algorithm(n2, t2, s2);
    if(hard_check_ans(n2, ans2, sol2)) ++score;

    std::vector<Edge> t3 = {Edge(0,1,1), Edge(0,2,2), Edge(1,3,2), Edge(2,3,1), Edge(3,4,3)};
    int n3 = 5;
    int s3 = 0;
    std::vector<Node> sol3 = {Node(0,0,-1), Node(1,1,0), Node(2,2,0), Node(3,3,2), Node(4,6,3)};
    std::vector<Node> ans3 = dijkstras_algorithm(n3, t3, s3);
    if(soft_check_ans(n3, ans3, sol3)) ++score;

    // random tests
    for(int i = 0; i < 15; ++i) {
        int n = 25*(1 << (i/5));
        std::vector<Edge> edges = alex::gen_random_digraph(n);
        int src = alex::sample_int() % n;
        std::vector<Node> ans = dijkstras_algorithm(n, edges, src);
        std::vector<Node> sol = alex::dijkstras_algorithm(n, edges, src);

        if(soft_check_ans(n, ans, sol)) ++score;
    }


    RESULT(100*(score / total_score));
    return 0;
}
