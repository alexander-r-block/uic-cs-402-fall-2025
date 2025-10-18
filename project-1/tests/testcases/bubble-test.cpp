
#include <vector>
#include <algorithm>
#include <iostream>

//#include "/grading_dir/tests/extra/testing.h"
#include "/grading_dir/tests/extra/testing.cpp"



template<typename T>
void bubble_sort(std::vector<T>& list, bool descending = false);


int main() {
    
    
    double total_points = 20.0;
    double score = 0.0;
    


    // different type tests; 1 point each (6 total)
    std::vector<StableChar> char_test = gen_stable_char_one_percent(9);
    std::vector<StableString> string_test = gen_stable_string_one_percent(9);

    std::vector<short> short_test = gen_unique_short_list(259);
    std::vector<unsigned short> unsigned_short_test = gen_unique_unsigned_short_list(250);

    std::vector<long> long_test = gen_unique_long_list(601);
    std::vector<unsigned long> unsigned_long_test = gen_unique_unsigned_long_list(598);


    bubble_sort(char_test);
    if(std::is_sorted(char_test.begin(), char_test.end())) ++score;

    bubble_sort(string_test);
    if(std::is_sorted(string_test.begin(), string_test.end())) ++score;

    bubble_sort(short_test);
    if(std::is_sorted(short_test.begin(), short_test.end())) ++score;

    bubble_sort(unsigned_short_test);
    if(std::is_sorted(unsigned_short_test.begin(), unsigned_short_test.end())) ++score;

    bubble_sort(long_test);
    if(std::is_sorted(long_test.begin(), long_test.end())) ++score;

    bubble_sort(unsigned_long_test);
    if(std::is_sorted(unsigned_long_test.begin(), unsigned_long_test.end())) ++score;



    // Stable Tests; 1 point per pair (or half a point each) (3 total)
    double stable_score = 0.0;
    std::vector<StableInt> stable_int_test1 = gen_stable_int_many_dupes(1029);
    std::vector<StableInt> stable_int_test2 = gen_stable_int_many_dupes(1027);

    bubble_sort(stable_int_test1);
    bubble_sort(stable_int_test2, true);

    if(is_stable_sorted(stable_int_test1)) ++stable_score;
    if(is_stable_sorted(stable_int_test2,true)) ++stable_score;

    std::vector<StableChar> stable_char_test1 = gen_stable_char_many_dupes(1027);
    std::vector<StableChar> stable_char_test2 = gen_stable_char_many_dupes(1029);

    bubble_sort(stable_char_test1);
    bubble_sort(stable_char_test2, true);

    if(is_stable_sorted(stable_char_test1)) ++stable_score;
    if(is_stable_sorted(stable_char_test2,true)) ++stable_score;

    std::vector<StableString> stable_string_test1 = gen_stable_string_many_dupes(1027);
    std::vector<StableString> stable_string_test2 = gen_stable_string_many_dupes(1029);

    bubble_sort(stable_string_test1);
    bubble_sort(stable_string_test2, true);

    if(is_stable_sorted(stable_string_test1)) ++stable_score;
    if(is_stable_sorted(stable_string_test2,true)) ++stable_score;

    score += (stable_score / 2);


    // (unsigned) int different number tests; one point per pair (10 total)
    double asc_des_score = 0.0;
    unsigned int size_list[10] = {32, 64, 128, 256, 1024, 4098, 16384, 65536, 262144, 1048576}; 
    int perturb_list[10] = {0, 0, 13, -5, -19, 17, 7, -3, 9, -11};
    for(int i = 0; i < 5; ++i) {

        std::vector<int> ascending_test1 = gen_unique_int_list(size_list[i]+perturb_list[i]);
        std::vector<int> descending_test1(ascending_test1);

        std::vector<unsigned int> ascending_test2 = gen_unique_unsigned_int_list(size_list[i]+perturb_list[i]);
        std::vector<unsigned int> descending_test2(ascending_test2);

        bubble_sort(ascending_test1);
        bubble_sort(ascending_test2);
        bubble_sort(descending_test1,true);
        bubble_sort(descending_test2,true);

        if(std::is_sorted(ascending_test1.begin(), ascending_test1.end())) ++asc_des_score;
        if(std::is_sorted(descending_test1.begin(), descending_test1.end(), std::greater<>{})) ++asc_des_score;
        if(std::is_sorted(ascending_test2.begin(), ascending_test2.end())) ++asc_des_score;
        if(std::is_sorted(descending_test2.begin(), descending_test2.end(), std::greater<>{})) ++asc_des_score;

    }

    score += (asc_des_score / 2);
    
    
    // Empty list test; 1 point
    std::vector<int> empty_test {};

    bubble_sort(empty_test);
    if(std::is_sorted(empty_test.begin(), empty_test.end())) ++score;

    RESULT(100*(score / total_points));


    return 0;
}
