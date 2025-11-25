
#include <vector>
#include <limits>
#include <functional>
#include <cmath>
#include <fstream>
#include <iostream>
#include <unordered_map>

#include "/grading_dir/tests/extra/racing.cpp"

const std::string who_am_i();

const std::string filename = "/grading_dir/results/feedback/" + who_am_i() + " [a-star].txt";

auto operator==(const GridEdge& g1, const GridEdge& g2) {
    return ((g1.from_x == g2.from_x) && (g1.from_y == g2.from_y) && (g1.to_x == g2.to_x) && (g1.to_y == g2.to_y));
}

std::string edge_to_string(const GridEdge& ge) {
    return "( (" + std::to_string(ge.from_x) + "," + std::to_string(ge.from_y) + "), (" + std::to_string(ge.to_x) + "," + std::to_string(ge.to_y) + ") )";
}

template <>
struct std::hash<GridEdge>
{
  std::size_t operator()(const GridEdge& k) const
  {
    // Compute individual hash values for first,
    // second and third and combine them using XOR
    // and bit shifting:

    return ((hash<int>()(k.from_x)
             ^ (hash<int>()(k.from_y) << 1)) >> 1)
             ^ (hash<int>()(k.to_x) << 1)
             ^ (hash<int>()(k.to_y) >> 1);
  }
};

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


bool hard_check_ans(std::vector<GridNode>& ans, std::vector<GridNode>& sol, GridNode& source, GridNode& target, std::ofstream& out) {
    if(ans.size() != sol.size()) {
        out << "\tHard check failed: lists not same size" << std::endl;
        return false;
    }
    int sz = ans.size();
    if(ans[0].x != source.x || ans[0].y != source.y) {
        out << "\tHard check failed: ans[0] not the source node" << std::endl;
        return false;
    }
    if(ans[sz-1].x != target.x || ans[sz-1].y != target.y) {
        out << "\tHard check failed: ans[ans.size()-1] not the target node" << std::endl;
        return false;
    }
    for(int i = 0; i < sz; ++i) {
        if(ans[i].x != sol[i].x || ans[i].y != sol[i].y) {
            out << "\tHard check failed: ans[i].x/y != sol[i].x/y for i=" << i << std::endl;
            return false;
        }

        if(ans[i].path_cost != sol[i].path_cost) {
            out << "\tHard check failed: ans[i].cost != sol[i].cost for i=" << i << std::endl;
            return false;
        }
            
        if(ans[i].pred_x != sol[i].pred_x || ans[i].pred_y != sol[i].pred_y) {
            out << "\tHard check failed: ans[i].pred_x/y != sol[i].pred_x/y for i="<< i << std::endl;
            return false;
        }
    }
    return true;
}
double soft_check_ans(std::vector<GridNode>& ans, std::vector<GridNode>& sol, GridNode& source, GridNode& target, std::ofstream& out, std::vector<GridEdge>& edges) {
    int asz = ans.size();
    int ssz = sol.size();
    if(asz == 0 && ssz == 0) return 1.0;
    if(ans[0].x != source.x || ans[0].y != source.y) {
        out << "Soft check failed: first entry of answer is not the source node." << std::endl;
        return 0.0;
    }
    if(ans[asz-1].x != target.x || ans[asz-1].y != target.y) {
        out << "Soft check failed: last entry of answer is not the target node." << std::endl;
        return 0.0;
    }
    if(ans[asz-1].path_cost != sol[ssz-1].path_cost) {
        out << "Soft check failed: path_cost of target node is incorrect." << std::endl;
        double cost = 0.0; // now compute the actual path cost in the answer to double check.
        GridNode prev = ans[0];
        GridNode curr;
        for(int i = 1; i < asz; ++i) {
            curr = ans[i];
            if(curr.pred_x != prev.x || curr.pred_y != prev.y) {
                out << "\tError: GridNode " << i-1 << " is not the predecessor of GridNode " << i << std::endl;
            }
            cost += (abs(curr.x - prev.x)==0 || abs(curr.y-prev.y)==0) ? 1.0 : 1.5;
            prev = curr;
        }
        if(cost == sol[ssz-1].path_cost) {
            out << "\tDiagnosis: stored path cost is not the actual path cost." << std::endl;
            return 0.5;
        }
        if(cost < sol[ssz-1].path_cost) {
            out << "\tDiagnosis: found a shorter path? Checking if all edges in path exist in graph." << std::endl;
            out << "\tComputed Path cost = " << cost << "; my path cost = " << sol[ssz-1].path_cost << std::endl;
            std::unordered_map<GridEdge, int> edgeMap; 
            for(GridEdge e: edges) ++edgeMap[e];
            bool invalidEdge = false;
            for(int i = 0; i < asz-1; ++i) {
                GridEdge e(ans[i].x, ans[i].y, ans[i+1].x, ans[i+1].y);
                if(edgeMap[e] == 0) {
                    out << "\t\tEdge " << edge_to_string(e) << " does not exist in graph." << std::endl;
                    invalidEdge = true;
                }
            }
            out << "\tSomehow shorter path was found? What is happening?" << std::endl;
            return (invalidEdge) ? 0.0 : 1.0;
        }
        out << "\tDiagnosis: path is not a shortest path." << std::endl;
        return 0.0;
        //return 0.5;
    }
    if(ans[0].path_cost != 0) {
        out << "Soft check failed: path_cost of source node is not zero." << std::endl;
        return 0.0;
    }

    return 1.0;
}

int main() {

    double total_score = 24.0;
    double score = 0.0;

    std::ofstream out_file(filename);
    
    // empty test
    //std::vector<GridNode> empty_res = a_star_algorithm(0, 0, {}, GridNode(), GridNode(), alex::heuristic_cost);
    //if(empty_res.empty()) ++score;


    // singleton test
    std::vector<GridNode> single_res = a_star_algorithm(1, 1, {}, GridNode(), GridNode(), alex::heuristic_cost);
    if(single_res[0].x == 0 && single_res[0].y == 0 && single_res[0].path_cost == 0) ++score;
    else out_file << "Singleton test failed." << std::endl;

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

    if(hard_check_ans(ans1, sol1, src1, tgt1, out_file)) ++score;
    else out_file << "First hard check failed." << std::endl;


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

    if(hard_check_ans(ans2, sol2, src2, tgt2, out_file)) ++score;
    else out_file << "Second hard check failed." << std::endl;





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

    score += soft_check_ans(ans3, sol3, src3, tgt3, out_file, t3);
    

    // random tests
    std::vector<unsigned int> norms = {2, 3, 4, 5, std::numeric_limits<unsigned int>::max()};
    for(int i = 0; i < 20; ++i) {
        int n = 12 + (alex::sample_int() % 16);
        int m = 12 + (alex::sample_int() % 16);
        std::vector<GridEdge> edges = alex::gen_random_grid(m,n);
        GridNode src(1,1,0,-1,-1);
        GridNode tgt(m-2,n-2,0,-1,-1);

        unsigned int norm = norms[alex::sample_int() % 5];

        std::function<double(GridNode,GridNode)> heur = [&norm](GridNode a, GridNode b) -> double {return ln_norm(norm,a,b);};

        std::vector<GridNode> ans = a_star_algorithm(m, n, edges, src, tgt, heur);
        std::vector<GridNode> sol = alex::a_star_algorithm(m ,n, edges, src, tgt, heur);

        score += soft_check_ans(ans, sol, src, tgt, out_file, edges);
    }

    out_file.close();



    RESULT(100*(score/total_score));

    return 0;
}
