#include <vector>
#include <fstream>
// Struct for tree in first-child, next-sibling representation
struct TreeNode {
    int id;
    TreeNode* first_child;
    TreeNode* next_sibling;
};

TreeNode* bits_to_tree(const std::vector<bool>& bits);

bool check_equal(TreeNode* t1, TreeNode* t2, std::ofstream& out) {
    if(t1 == nullptr && t2 == nullptr) {
        out << "\tBoth pointers are null." << std::endl;
        return true;
    }
    if(t1 != nullptr && t2 == nullptr) {
        out << "\tSolution is null, answer is not" << std::endl;
        return false;
    }
    if(t1 == nullptr && t2 != nullptr) {
        out << "\tAnswer is null, solution is not" << std::endl;
        return false;
    }
    if(t1->id != t2->id) { 
        out << "\tID's don't match" << std::endl;
        return false;
    }
    out << "\tRecursing..." << std::endl;
    return check_equal(t1->first_child, t2->first_child, out)
            && check_equal(t1->next_sibling, t2->next_sibling, out);
}

int main() {
    std::ofstream out_file("bits-to-tree-info.txt");

    const std::vector<bool> test1 = {1, 0};
    const std::vector<bool> test2 = {1, 0, 1, 0, 1, 1, 0, 1, 0, 0};


    out_file << "Generating first answer" << std::endl;
    TreeNode* ans1 = bits_to_tree(test1);
    out_file << "Generating second answer" << std::endl;
    TreeNode* ans2 = bits_to_tree(test2);

    TreeNode* sol1 = new TreeNode(0, new TreeNode(1), nullptr);
    TreeNode* sol2 = new TreeNode(
      0, new TreeNode(1,
        nullptr,
        new TreeNode(2,
          nullptr,
          new TreeNode(3,
            new TreeNode(4, nullptr, new TreeNode(5))
          )
        )
      )
    );

    double total_score = 2.0;
    double score = 0.0;

    out_file << "Checking first answer" << std::endl;
    if(check_equal(ans1, sol1, out_file)) ++score;
    out_file << "Checking second answer" << std::endl;
    if(check_equal(ans2, sol2, out_file)) ++score;

    out_file.close();

    RESULT(100*(score / total_score));

    return 0;

}
