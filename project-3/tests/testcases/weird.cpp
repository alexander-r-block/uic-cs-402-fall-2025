
#include <vector>


// Struct for tree in first-child, next-sibling representation
struct TreeNode {
    int id;
    TreeNode* first_child;
    TreeNode* next_sibling;
};



std::vector<int> weird_traversal(TreeNode* root);

int main() {
    TreeNode* test = new TreeNode(
      0, 
      new TreeNode(1, nullptr,
        new TreeNode(
          2,
          new TreeNode(4,
            new TreeNode(6, nullptr, 
              new TreeNode(7, nullptr, new TreeNode(8))
            ),
            nullptr
          ),
          new TreeNode(3,
            new TreeNode(5,
              new TreeNode(9, nullptr,
                new TreeNode(10, nullptr,
                  new TreeNode(11, nullptr, new TreeNode(12))
                )
              )
            ),
            nullptr
          )
        )
      ),
      nullptr
    );

    std::vector<int> wd_trav = weird_traversal(test);

    const std::vector<int> wd_ans = {0, 4, 5, 12, 11, 10, 9, 8, 7, 6, 3, 2, 1};

    if(wd_trav == wd_ans) PASS();
    else FAIL();

    return 0;
}
