
#include <vector>

#include "/grading_dir/tests/extra/racing.cpp"

//struct Edge {
//    int from;
//    int to;
//    int weight; // default = 1 if unweighted graph
//    Edge(int f, int t, int w = 1) {
//        from = f;
//        to = t;
//        weight = w;
//    }
//};

std::vector<int> topological_sort(int n, std::vector<Edge> edges);

bool is_valid_topo(int n, std::vector<Edge> edges, std::vector<int> order) {
    if(order.empty()) {
        std::vector<int> my_order = alex::topological_sort(n, edges);
        return my_order.empty();
    }
    std::vector<std::vector<int>> graph(n);
    std::vector<int> indeg(n,0);
    for(const Edge& e: edges) {
        graph[e.from].push_back(e.to);
        ++indeg[e.to];
    }
    for(int i = 0; i < n; ++i) {
        int curr = order[i];
        if(indeg[curr] != 0) return false;
        for(int& child: graph[curr]) {
            --indeg[child];
        }
    }
    return true;
}

int main() {

    double total_score = 15.0;
    double score = 0.0;


    // empty test
    std::vector<Edge> empty_test = {};
    std::vector<int> empty_res = topological_sort(0, empty_test);
    if(empty_res.empty()) ++score;

    // single node test
    std::vector<int> single_res = topological_sort(1, empty_test);
    if(is_valid_topo(1, empty_test, single_res)) ++score;

    // easy small tests
    std::vector<Edge> test1 = {Edge(0,1,1), Edge(1,2,1), Edge(2,3,1), Edge(3,4,1)};
    std::vector<Edge> test2 = {Edge(0,1,1), Edge(2,1,1), Edge(0,3,1), Edge(2,3,1)};
    std::vector<Edge> test3 = {Edge(0,1,1), Edge(1,2,1), Edge(2,3,1), Edge(3,0,1)}; // has a cycle


    std::vector<int> res1 = topological_sort(5, test1);
    if(is_valid_topo(5, test1, res1)) ++score;

    std::vector<int> res2 = topological_sort(4, test2);
    if(is_valid_topo(4, test2, res2)) ++score;

    std::vector<int> res3 = topological_sort(4, test3);
    if(is_valid_topo(4, test3, res3)) ++score;


    for(int i = 0; i < 10; ++i) {
        pair<int, std::vector<Edge>> rand_dag = alex::gen_random_dag();
        if(i%2) {
            int idx = alex::sample_int() % (rand_dag.second.size());
            Edge e = rand_dag.second[idx];
            rand_dag.second.push_back(Edge(e.to, e.from)); // add a cycle
        }
        std::vector<int> res = topological_sort(rand_dag.first, rand_dag.second);

        if(is_valid_topo(rand_dag.first, rand_dag.second, res)) ++score;
    }


    RESULT(100*(score / total_score));

    return 0;
}
