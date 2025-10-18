#include <vector>
#include <algorithm>


//#include "/grading_dir/tests/extra/testing.h"
#include "/grading_dir/tests/extra/testing.cpp"



template<typename T>
void bucket_merge_sort(std::vector<T>& list, bool descending = false);


int main() {

    double total_points = 10.0;
    double score = 0.0;
    



    // (unsigned) int different number tests; one point per pair (10 total)
    double asc_des_score = 0.0;
    unsigned int size_list[10] = {32, 64, 128, 256, 1024, 4098, 16384, 65536, 262144, 1048576}; 
    int perturb_list[10] = {0, 0, 13, -5, -19, 17, 7, -3, 9, -11};
    for(int i = 5; i < 10; ++i) {

        std::vector<int> ascending_test1 = gen_unique_int_list(size_list[i]+perturb_list[i]);
        std::vector<int> descending_test1(ascending_test1);

        std::vector<unsigned int> ascending_test2 = gen_unique_unsigned_int_list(size_list[i]+perturb_list[i]);
        std::vector<unsigned int> descending_test2(ascending_test2);

        bucket_merge_sort(ascending_test1);
        bucket_merge_sort(ascending_test2);
        bucket_merge_sort(descending_test1,true);
        bucket_merge_sort(descending_test2,true);

        if(std::is_sorted(ascending_test1.begin(), ascending_test1.end())) ++asc_des_score;
        if(std::is_sorted(descending_test1.begin(), descending_test1.end(), std::greater<>{})) ++asc_des_score;
        if(std::is_sorted(ascending_test2.begin(), ascending_test2.end())) ++asc_des_score;
        if(std::is_sorted(descending_test2.begin(), descending_test2.end(), std::greater<>{})) ++asc_des_score;

    }
    score += (asc_des_score / 2);
    
    


    RESULT(100*(score / total_points));


    return 0;
}
