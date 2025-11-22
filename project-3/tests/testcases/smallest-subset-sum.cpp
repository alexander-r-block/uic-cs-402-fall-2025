#include <vector>
#include <string>

using std::vector;
using std::string;
using std::pair;

vector<pair<unsigned int,string>> smallest_subset_sum(unsigned int n, unsigned int t, const vector<pair<unsigned int, string>>& values);


int main() {

    vector<pair<unsigned int, string>> values = { {1, "dog"}, {1, "cat"}, {2, "bird"}, {3, "mouse"}, {1, "snake"}, {4, "fish"} };
    unsigned int n = 6;
    unsigned int t = 5;

    vector<pair<unsigned int, string>> sol = { {1,"dog"}, {4, "fish"} };

    auto ans = smallest_subset_sum(n, t, values);
    
    if(sol == ans) PASS();
    else FAIL();

    return 0;
}
