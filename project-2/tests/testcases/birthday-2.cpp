
#include <functional>
#include <random>



std::vector<unsigned int> birthday_attack_2(std::function<unsigned short(unsigned int)> hash_function);

unsigned short hash(unsigned int input) {
    const unsigned int a = 3177205741;
    const unsigned int b = 2371597069;
    return static_cast<unsigned short>(a*input + b);
}

int main() {
    double total_score = 5.0;
    double score = 0.0;
    
    for(int i = 0; i < 10; ++i) {
        std::vector<unsigned int> result = birthday_attack_2(hash);
        if(result.size() != 2) {
            continue;
        }
        if(hash(result[0]) == hash(result[1]) && result[0] != result[1]) {
            score = 5.0;
            break;
        }
    }

    RESULT(100*(score / total_score));

    return 0;
}
