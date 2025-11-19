
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

double ln_norm(unsigned int n, GridNode a, GridNode b) {
    double out = 0.0;
    double x = abs(a.x - b.x);
    double y = abs(a.y - b.y);
    if(n == std::numeric_limits<unsigned int>::max()) {
        out = std::max( x, y  );
    }
    else {
        x = std::pow(x,n);
        y = std::pow(y,n);
        out = std::pow( x+y, 1/static_cast<double>(n) );
    }
    return out;
}


bool hard_check_ans(std::vector<GridNode>& ans, std::vector<GridNode>& sol, GridNode& source, GridNode& target) {
    if(ans.size() != sol.size()) return false;
    int sz = ans.size();
    if(ans[0].x != source.x || ans[0].y != source.y || ans[sz-1].x != target.x || ans[sz-1].y != target.y) return false;
    for(int i = 0; i < sz; ++i) {
        if(ans[i].x != sol[i].x || ans[i].y != sol[i].y || 
            ans[i].path_cost != sol[i].path_cost ||
            ans[i].pred_x != sol[i].pred_x || ans[i].pred_y != sol[i].pred_y
        ) return false;
    }
    return true;
}
bool soft_check_ans(std::vector<GridNode>& ans, std::vector<GridNode>& sol, GridNode& source, GridNode& target) {
    if(ans.size() != sol.size()) return false;
    int sz = ans.size();
    if(sz == 0) return true;
    if(ans[0].x != source.x || ans[0].y != source.y || ans[sz-1].x != target.x || ans[sz-1].y != target.y) return false;
    if(ans[sz-1].path_cost != sol[sz-1].path_cost || ans[0].path_cost != 0) return false;

    return true;
}

int main() {

    double total_score = 24.0;
    double score = 0.0;
    
    // empty test
    //std::vector<GridNode> empty_res = a_star_algorithm(0, 0, {}, GridNode(), GridNode(), alex::heuristic_cost);
    //if(empty_res.empty()) ++score;


    // singleton test
    std::vector<GridNode> single_res = a_star_algorithm(1, 1, {}, GridNode(), GridNode(), alex::heuristic_cost);
    if(single_res[0].x == 0 && single_res[0].y == 0 && single_res[0].path_cost == 0) ++score;

    // easy tests

    std::vector<GridEdge> t1 = {
        GridEdge(0,0,1,0), GridEdge(0,0,0,1), GridEdge(1,0,2,0), GridEdge(1,0,1,1), GridEdge(1,0,2,1),
        GridEdge(2,0,2,1), GridEdge(2,0,3,0), GridEdge(3,0,3,1), GridEdge(3,0,4,0), GridEdge(0,1,1,1), 
        GridEdge(0,1,0,2), GridEdge(1,1,1,2), GridEdge(2,1,3,2), GridEdge(3,1,4,1), GridEdge(3,1,3,2), 
        GridEdge(0,2,1,2), GridEdge(1,2,2,2), GridEdge(1,2,1,3), GridEdge(2,2,3,2), GridEdge(3,2,4,2), 
        GridEdge(4,2,4,3), GridEdge(4,1,4,2), GridEdge(1,3,0,4), GridEdge(4,3,3,3), GridEdge(4,3,3,4), 
        GridEdge(0,4,1,4), GridEdge(1,4,2,4), GridEdge(2,4,3,4), GridEdge(3,4,4,4) 
    };
    int m1 = 5;
    int n1 = 5;

    GridNode src1(0,0,0,-1,-1);
    GridNode tgt1(4,4,0,-1,-1);

    std::vector<GridNode> sol1 = { 
        src1, 
        GridNode(1,0,1,0,0), GridNode(2,1,2.5,1,0), GridNode(3,2,4,2,1), GridNode(4,2,5,3,2),
        GridNode(4,3,6,4,2), GridNode(3,4,7.5,4,3), GridNode(4,4,8.5,3,4)
    };

    std::vector<GridNode> ans1 = a_star_algorithm(m1, n1, t1, src1, tgt1, alex::heuristic_cost);

    if(hard_check_ans(ans1, sol1, src1, tgt1)) ++score;


    std::vector<GridEdge> t2;
    std::vector<GridNode> sol2;
    int m2 = 7;
    int n2 = 7;
    int cost = 1;
    GridNode src2(m2-1, n2-1, 0, -1, -1);
    GridNode tgt2(0,0,0,-1,-1);
    sol2.push_back(src2);
    for(int y = n2-1; y>=0; --y) {
        switch(y%2) {
            case 1:
                for(int x = 0; x < m2-1; ++x) {
                    sol2.push_back(GridNode(x+1,y,cost,x,y));
                    ++cost;
                    t2.push_back(GridEdge(x,y,x+1,y));
                }
                if(y > 0) {
                    sol2.push_back(GridNode(m2-1,y-1,cost,m2-1,y));
                    ++cost;
                    t2.push_back(GridEdge(m2-1,y,m2-1,y-1));
                }
                break;
            default:
                for(int x = m2-1; x > 0; --x) {
                    sol2.push_back(GridNode(x-1,y,cost,x,y));
                    ++cost;
                    t2.push_back(GridEdge(x,y,x-1,y));
                }
                if(y > 0) {
                    sol2.push_back(GridNode(0,y-1,cost,0,y));
                    ++cost;
                    t2.push_back(GridEdge(0,y,0,y-1));
                }
                break;
        }
    }

    auto ans2 = a_star_algorithm(m2, n2, t2, src2, tgt2, alex::heuristic_cost);

    if(hard_check_ans(ans2, sol2, src2, tgt2)) ++score;





    std::vector<GridEdge> t3;
    int m3 = 9;
    int n3 = 5;

    // horizontal edges
    for(int y = 1; y < n3-1; ++y) {
        for(int x = 0; x < m3-1; ++x) {
            t3.push_back(GridEdge(x,y,x+1,y));
            t3.push_back(GridEdge(x+1,y,x,y));
        }
    }
    // vertical edges
    for(int x = 0; x < m3; ++x) {
        for(int y = 0; y < n3-1; ++y) {
            t3.push_back(GridEdge(x,y,x,y+1));
            t3.push_back(GridEdge(x,y+1,x,y));
        }
    }
    // diagonal edges
    for(int y = 0; y < n3-1; ++y) {
        for(int x = 1; x < m3; ++x) {
            t3.push_back(GridEdge(x,y,x-1,y+1));
            t3.push_back(GridEdge(x-1,y+1,x,y));
        }
    }

    GridNode src3(1,3,0,-1,-1);
    GridNode tgt3(6,1,0,-1,-1);
    std::vector<GridNode> sol3 = {
        src3,
        GridNode(2,2,1.5,1,3), GridNode(3,1,3,2,2), GridNode(4,1,4,3,1),
        GridNode(5,1,5,4,1), GridNode(6,1,6,5,1)
    };

    std::vector<GridNode> ans3 = a_star_algorithm(m3, n3, t3, src3, tgt3, alex::heuristic_cost);

    if(soft_check_ans(ans3, sol3, src3, tgt3)) ++score;
    

    // random tests
    std::vector<unsigned int> norms = {1, 2, 3, 4, 5, std::numeric_limits<unsigned int>::max()};
    for(int i = 0; i < 20; ++i) {
        int n = 12 + (alex::sample_int() % 16);
        int m = 12 + (alex::sample_int() % 16);
        std::vector<GridEdge> edges = alex::gen_random_grid(m,n);
        GridNode src(1,1,0,-1,-1);
        GridNode tgt(m-2,n-2,0,-1,-1);

        unsigned int norm = norms[alex::sample_int() % 6];

        std::function<double(GridNode,GridNode)> heur = [&norm](GridNode a, GridNode b) -> double {return ln_norm(norm,a,b);};

        std::vector<GridNode> ans = a_star_algorithm(m, n, edges, src, tgt, heur);
        std::vector<GridNode> sol = alex::a_star_algorithm(m ,n, edges, src, tgt, heur);

        if(soft_check_ans(ans, sol, src, tgt)) ++score;
    }



    RESULT(100*(score/total_score));

    return 0;
}
