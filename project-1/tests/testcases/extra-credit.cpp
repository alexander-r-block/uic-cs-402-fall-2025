#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>


//#include "/grading_dir/tests/extra/testing.h"
#include "/grading_dir/tests/extra/testing.cpp"
#include "/grading_dir/tests/extra/sorting_race.cpp"


const std::string who_am_i();

/* Bubble Sort */
// 1 point of Extra Credit
template<typename T>
void bubble_sort(std::vector<T> &list, bool descending = false);

/* Selection Sort */
// 1 point of Extra Credit
template<typename T>
void selection_sort(std::vector<T> &list, bool descending = false);

/* Insertion Sort */
// 1 point of Extra Credit
template<typename T>
void insertion_sort(std::vector<T> &list, bool descending = false); 

///* Quick Sort */
// QUICKSORT not tested; too much variability because of randomness
//template<typename T>
//std::vector<T>& quick_partition(std::vector<T> &list, unsigned int pivot_index, bool descending = false);
//
//template<typename T>
//void quicksort(std::vector<T> &list, bool descending = false);


/* Merge Sort */
// 1 point of Extra Credit
template<typename T>
void merge_sort(std::vector<T> &list, bool descending = false);

/* Bucket Merge Sort */
// 2 points of Extra Credit
template<typename T>
void bucket_merge_sort(std::vector<T> &list, bool descending = false);


/* Binary Radix Sort */
// 1 point of Extra Credit
template<typename T>
void binary_radix_sort(std::vector<T> &list, bool descending = false);


/* Your Hybrid Sort */
// 1 point of Extra Credit
template<typename T>
void my_hybrid_sort(std::vector<T> &list, bool descending = false);


/* Base B Radix Sort */
// 2 points of Extra Credit
template<typename T> 
void radix_sort(std::vector<T> &list, unsigned int base = 10, bool descending = false);

unsigned int sort_race(
    std::function<void(std::vector<int>&, bool)> alex_func,
    std::function<void(std::vector<int>&, bool)> student_func, 
    const unsigned int list_size, 
    const unsigned int num_runs
) {

    std::srand(std::time({}));
    std::chrono::duration<double, std::micro> alex_average {};
    std::chrono::duration<double, std::micro> student_average {};

    unsigned int tests_valid = 1;

    int rand_pert = static_cast<int>(std::rand() % 17);
    rand_pert *= (static_cast<unsigned int>(std::rand() % 2)) ? (-1) : 1;

    for(unsigned int i = 0; i < num_runs; ++i) {
        std::vector<int> alex_test_1a = gen_unique_int_list(list_size + rand_pert);
        std::vector<int> alex_test_1d(alex_test_1a);
        std::vector<int> alex_test_2a = gen_ascending_list(list_size + rand_pert);
        std::vector<int> alex_test_2d(alex_test_2a);
        std::vector<int> alex_test_3a = gen_descending_list(list_size + rand_pert);
        std::vector<int> alex_test_3d(alex_test_3a);
        std::vector<int> alex_test_4a = gen_many_dupes_list(list_size + rand_pert);
        std::vector<int> alex_test_4d(alex_test_4a);
        std::vector<int> alex_test_5a = gen_one_percent_rand_list(list_size + rand_pert);
        std::vector<int> alex_test_5d(alex_test_5a); 
        std::vector<int> alex_test_6a = gen_random_list(list_size + rand_pert);
        std::vector<int> alex_test_6d(alex_test_6a);

        std::vector<int> student_test_1a(alex_test_1a);
        std::vector<int> student_test_1d(alex_test_1d);
        std::vector<int> student_test_2a(alex_test_2a);
        std::vector<int> student_test_2d(alex_test_2d);
        std::vector<int> student_test_3a(alex_test_3a);
        std::vector<int> student_test_3d(alex_test_3d);
        std::vector<int> student_test_4a(alex_test_4a);
        std::vector<int> student_test_4d(alex_test_4d);
        std::vector<int> student_test_5a(alex_test_5a);
        std::vector<int> student_test_5d(alex_test_5d); 
        std::vector<int> student_test_6a(alex_test_6a);
        std::vector<int> student_test_6d(alex_test_6d); 

        std::vector<std::vector<int>*> alex_tests { &alex_test_1a, &alex_test_1d, &alex_test_2a, &alex_test_2d, &alex_test_3a, &alex_test_3d, &alex_test_4a, &alex_test_4d, &alex_test_5a, &alex_test_5d, &alex_test_6a, &alex_test_6d };

        std::vector<std::vector<int>*> student_tests { &student_test_1a, &student_test_1d, &student_test_2a, &student_test_2d, &student_test_3a, &student_test_3d, &student_test_4a, &student_test_4d, &student_test_5a, &student_test_5d, &student_test_6a, &student_test_6d };

        for(int i = 0; i < 12; ++i) {

            if(i % 2) { // i is odd
                const auto a_start = std::chrono::high_resolution_clock::now();
                alex_func(*alex_tests[i], true);
                const auto a_stop = std::chrono::high_resolution_clock::now();

                const auto s_start = std::chrono::high_resolution_clock::now();
                student_func(*student_tests[i], true);
                const auto s_stop = std::chrono::high_resolution_clock::now();

                alex_average += (a_stop - a_start);
                student_average += (s_stop - s_start);

                if(tests_valid && !std::is_sorted(student_tests[i]->begin(), student_tests[i]->end(), std::greater<>{})) tests_valid = 0;
            }
            else { // i is even
                const auto a_start = std::chrono::high_resolution_clock::now();
                alex_func(*alex_tests[i], false);
                const auto a_stop = std::chrono::high_resolution_clock::now();

                const auto s_start = std::chrono::high_resolution_clock::now();
                student_func(*student_tests[i], false);
                const auto s_stop = std::chrono::high_resolution_clock::now();

                alex_average += (a_stop - a_start);
                student_average += (s_stop - s_start);

                if(tests_valid && !std::is_sorted(student_tests[i]->begin(), student_tests[i]->end())) tests_valid = 0;
            }
        }
    }
    alex_average = alex_average / num_runs;
    student_average = student_average / num_runs;
    

    return (student_average <= alex_average && tests_valid) ? 1 : 0;
}

unsigned int stable_sort_race(
    std::function<void(std::vector<StableInt>&, bool)> alex_func,
    std::function<void(std::vector<StableInt>&, bool)> student_func, 
    const unsigned int list_size, 
    const unsigned int num_runs
) {

    std::srand(std::time({}));
    std::chrono::duration<double, std::micro> alex_average {};
    std::chrono::duration<double, std::micro> student_average {};

    unsigned int tests_valid = 1;

    int rand_pert = static_cast<int>(std::rand() % 17);
    rand_pert *= (static_cast<unsigned int>(std::rand() % 2)) ? (-1) : 1;

    for(unsigned int i = 0; i < num_runs; ++i) {
        std::vector<StableInt> alex_test_1a = gen_stable_int_unique(list_size + rand_pert);
        std::vector<StableInt> alex_test_1d(alex_test_1a);
        std::vector<StableInt> alex_test_2a = gen_stable_int_ascending(list_size + rand_pert);
        std::vector<StableInt> alex_test_2d(alex_test_2a);
        std::vector<StableInt> alex_test_3a = gen_stable_int_descending(list_size + rand_pert);
        std::vector<StableInt> alex_test_3d(alex_test_3a);
        std::vector<StableInt> alex_test_4a = gen_stable_int_many_dupes(list_size + rand_pert);
        std::vector<StableInt> alex_test_4d(alex_test_4a);
        std::vector<StableInt> alex_test_5a = gen_stable_int_one_percent(list_size + rand_pert);
        std::vector<StableInt> alex_test_5d(alex_test_5a); 
        std::vector<StableInt> alex_test_6a = gen_stable_int_random(list_size + rand_pert); 
        std::vector<StableInt> alex_test_6d(alex_test_6a); 

        std::vector<StableInt> student_test_1a(alex_test_1a);
        std::vector<StableInt> student_test_1d(alex_test_1d);
        std::vector<StableInt> student_test_2a(alex_test_2a);
        std::vector<StableInt> student_test_2d(alex_test_2d);
        std::vector<StableInt> student_test_3a(alex_test_3a);
        std::vector<StableInt> student_test_3d(alex_test_3d);
        std::vector<StableInt> student_test_4a(alex_test_4a);
        std::vector<StableInt> student_test_4d(alex_test_4d);
        std::vector<StableInt> student_test_5a(alex_test_5a);
        std::vector<StableInt> student_test_5d(alex_test_5d); 
        std::vector<StableInt> student_test_6a(alex_test_6a);
        std::vector<StableInt> student_test_6d(alex_test_6d); 

        std::vector<std::vector<StableInt>*> alex_tests { &alex_test_1a, &alex_test_1d, &alex_test_2a, &alex_test_2d, &alex_test_3a, &alex_test_3d, &alex_test_4a, &alex_test_4d, &alex_test_5a, &alex_test_5d, &alex_test_6a, &alex_test_6d };

        std::vector<std::vector<StableInt>*> student_tests { &student_test_1a, &student_test_1d, &student_test_2a, &student_test_2d, &student_test_3a, &student_test_3d, &student_test_4a, &student_test_4d, &student_test_5a, &student_test_5d, &student_test_6a, &student_test_6d };

        for(int i = 0; i < 12; ++i) {

            if(i % 2) { // i is odd
                const auto a_start = std::chrono::high_resolution_clock::now();
                alex_func(*alex_tests[i], true);
                const auto a_stop = std::chrono::high_resolution_clock::now();

                const auto s_start = std::chrono::high_resolution_clock::now();
                student_func(*student_tests[i], true);
                const auto s_stop = std::chrono::high_resolution_clock::now();

                alex_average += (a_stop - a_start);
                student_average += (s_stop - s_start);

                if(tests_valid && !is_stable_sorted(*student_tests[i], true)) tests_valid = 0;
            }
            else { // i is even
                const auto a_start = std::chrono::high_resolution_clock::now();
                alex_func(*alex_tests[i], false);
                const auto a_stop = std::chrono::high_resolution_clock::now();

                const auto s_start = std::chrono::high_resolution_clock::now();
                student_func(*student_tests[i], false);
                const auto s_stop = std::chrono::high_resolution_clock::now();

                alex_average += (a_stop - a_start);
                student_average += (s_stop - s_start);

                if(tests_valid && !is_stable_sorted(*student_tests[i], false)) tests_valid = 0;
            }
        }
    }
    alex_average = alex_average / num_runs;
    student_average = student_average / num_runs;
    

    return (student_average <= alex_average && tests_valid) ? 1 : 0;
}

unsigned int radix_sort_race(
    std::function<void(std::vector<int>&, unsigned int, bool)> alex_func,
    std::function<void(std::vector<int>&, unsigned int, bool)> student_func, 
    const unsigned int list_size, 
    const unsigned int num_runs,
    unsigned int base
) {
    std::srand(std::time({}));
    std::chrono::duration<double, std::micro> alex_average {};
    std::chrono::duration<double, std::micro> student_average {};

    unsigned int tests_valid = 1;

    int rand_pert = static_cast<int>(std::rand() % 17);
    rand_pert *= (static_cast<unsigned int>(std::rand() % 2)) ? (-1) : 1;

    for(unsigned int i = 0; i < num_runs; ++i) {
        std::vector<int> alex_test_1a = gen_unique_int_list(list_size + rand_pert);
        std::vector<int> alex_test_1d(alex_test_1a);
        std::vector<int> alex_test_2a = gen_ascending_list(list_size + rand_pert);
        std::vector<int> alex_test_2d(alex_test_2a);
        std::vector<int> alex_test_3a = gen_descending_list(list_size + rand_pert);
        std::vector<int> alex_test_3d(alex_test_3a);
        std::vector<int> alex_test_4a = gen_many_dupes_list(list_size + rand_pert);
        std::vector<int> alex_test_4d(alex_test_4a);
        std::vector<int> alex_test_5a = gen_one_percent_rand_list(list_size + rand_pert);
        std::vector<int> alex_test_5d(alex_test_5a); 
        std::vector<int> alex_test_6a = gen_random_list(list_size + rand_pert);
        std::vector<int> alex_test_6d(alex_test_6a);

        std::vector<int> student_test_1a(alex_test_1a);
        std::vector<int> student_test_1d(alex_test_1d);
        std::vector<int> student_test_2a(alex_test_2a);
        std::vector<int> student_test_2d(alex_test_2d);
        std::vector<int> student_test_3a(alex_test_3a);
        std::vector<int> student_test_3d(alex_test_3d);
        std::vector<int> student_test_4a(alex_test_4a);
        std::vector<int> student_test_4d(alex_test_4d);
        std::vector<int> student_test_5a(alex_test_5a);
        std::vector<int> student_test_5d(alex_test_5d); 
        std::vector<int> student_test_6a(alex_test_6a);
        std::vector<int> student_test_6d(alex_test_6d); 

        std::vector<std::vector<int>*> alex_tests { &alex_test_1a, &alex_test_1d, &alex_test_2a, &alex_test_2d, &alex_test_3a, &alex_test_3d, &alex_test_4a, &alex_test_4d, &alex_test_5a, &alex_test_5d, &alex_test_6a, &alex_test_6d };

        std::vector<std::vector<int>*> student_tests { &student_test_1a, &student_test_1d, &student_test_2a, &student_test_2d, &student_test_3a, &student_test_3d, &student_test_4a, &student_test_4d, &student_test_5a, &student_test_5d, &student_test_6a, &student_test_6d };

        for(int i = 0; i < 12; ++i) {

            if(i % 2) { // i is odd
                const auto a_start = std::chrono::high_resolution_clock::now();
                alex_func(*alex_tests[i], base, true);
                const auto a_stop = std::chrono::high_resolution_clock::now();

                const auto s_start = std::chrono::high_resolution_clock::now();
                student_func(*student_tests[i], base, true);
                const auto s_stop = std::chrono::high_resolution_clock::now();

                alex_average += (a_stop - a_start);
                student_average += (s_stop - s_start);

                if(tests_valid && !std::is_sorted(student_tests[i]->begin(), student_tests[i]->end(), std::greater<>{})) tests_valid = 0;
            }
            else { // i is even
                const auto a_start = std::chrono::high_resolution_clock::now();
                alex_func(*alex_tests[i], base, false);
                const auto a_stop = std::chrono::high_resolution_clock::now();

                const auto s_start = std::chrono::high_resolution_clock::now();
                student_func(*student_tests[i], base, false);
                const auto s_stop = std::chrono::high_resolution_clock::now();

                alex_average += (a_stop - a_start);
                student_average += (s_stop - s_start);

                if(tests_valid && !std::is_sorted(student_tests[i]->begin(), student_tests[i]->end())) tests_valid = 0;
            }
        }
    }
    alex_average = alex_average / num_runs;
    student_average = student_average / num_runs;
    

    return (student_average <= alex_average && tests_valid) ? 1 : 0;
}

int main() {

    double total_points = 10.0;
    double score = 0.0;

    const unsigned int large_list_size {65536};
    const unsigned int small_list_size {1024};
    const unsigned int num_runs { 15 };

    std::string filename = "/grading_dir/results/" + who_am_i() + ".txt";
    std::ofstream out_file(filename);

    out_file << "Extra Credit Results for " << who_am_i() << "\n";

    // Bubble Test (stable)
    if(stable_sort_race(alex::bubble_sort<StableInt>, bubble_sort<StableInt>, small_list_size, num_runs)) {
        ++score;
        out_file << "\tBeat bubble_sort\n";
    }

    // Selection Test
    if(sort_race(alex::selection_sort<int>, selection_sort<int>, small_list_size, num_runs)) {
        ++score;
        out_file << "\tBeat selection_sort\n";
    }

    // Insertion Test (stable)
    if(stable_sort_race(alex::insertion_sort<StableInt>, insertion_sort<StableInt>, small_list_size, num_runs)) {
        ++score;
        out_file << "\tBeat insertion_sort\n";
    }

    // Merge Test (stable)
    if(stable_sort_race(alex::merge_sort<StableInt>, merge_sort<StableInt>, large_list_size, num_runs)) {
        ++score;
        out_file << "\tBeat merge_sort\n";
    }

    // Bucket Merge Test (stable)
    if(stable_sort_race(alex::bucket_merge_sort<StableInt>, bucket_merge_sort<StableInt>, large_list_size, num_runs)) {
        score += 2;
        out_file << "\tBeat bucket_merge_sort\n";
    }

    // Binary Radix Test
    if(sort_race(alex::binary_radix_sort<int>, binary_radix_sort<int>, large_list_size, num_runs)) {
        ++score;
        out_file << "\tBeat binary_radix_sort\n";
    }

    // Hybrid Test
    if(sort_race(alex::my_hybrid_sort<int>, my_hybrid_sort<int>, large_list_size, num_runs)) {
        ++score;
        out_file << "\tBeat my_hybrid_sort\n";
    }

    // General Radix Testsort_race(alex::my_hybrid_sort<int>, my_hybrid_sort<int>, large_list_size, num_runs)
    if(radix_sort_race(alex::radix_sort<int>, radix_sort<int>, large_list_size, num_runs, 10)) {
        score += 2;
        out_file << "\tBeat radix_sort\n";
    }

    out_file << "Testing complete";

    out_file.close();

    RESULT(100*(score / total_points));

    return 0;
}
