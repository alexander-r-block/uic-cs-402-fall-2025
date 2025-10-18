
#include "testing.h"
#include "sorting_race.h"

#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement the appropriate algorithms as described below.
 *   You must follow the specifications as written
 *   below (e.g., stability, in-place, etc.).
 *
 * - DO NOT MODIFY THE FUNCTION SIGNATURES!!!
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project1.h".
 *
 * - The file "testing.cpp" has various functions you can utilize to test
 *   your code. You can also add your own tests!
 *
 * - If you are working in a group, please modify the comments directly below.
 *
 */



/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Member 1
//   Member 2


namespace alex {

/* Bubble Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously compare adjacent elements and swap them if necessary.
 *            This is a stable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void bubble_sort(vector<T> &list, bool descending) {
    // Your code here!
    if(list.size() == 0 || list.size() == 1) return;
    for(int i = 0; i < list.size()-1; ++i) {
        bool swapped = false;
        for(auto right = list.begin(); right != list.end()-i-1; ++right) {
            if(!descending && *right > *(right+1)) {
                iter_swap(right, right+1);    
                swapped = true;
            }
            else if(descending && *right < *(right+1)) {
                iter_swap(right, right+1);    
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}














/* Selection Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously finds the minimium (or maximum) element in the list, 
 *            then swaps it with the first non-sorted element of the list.
 *            This is an unstable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void selection_sort(vector<T> &list, bool descending) {
    // Your code here!
    for(auto left = list.begin(); left != list.end(); ++left) {
        auto val = left;
        for(auto right = left; right != list.end(); ++right) {
            if(!descending && *right < *val) {
                val = right;
            }
            if(descending && *right > *val) {
                val = right;
            }
        }
        iter_swap(val, left);
    }
}















/* Insertion Sort 
 *
 * 5 points
 * 
 * Algorithm: Iterates through the list and inserts the current element into
 *            the correct sorted position of the prefix of the list.
 *            This is a stable, in-place sorting algorithm. Your implementation
 *            does not need to be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */

template<typename T>
void insertion_sort(vector<T> &list, bool descending) {
    // Your code here!
    for (auto iter = list.begin(); iter != list.end(); ++iter) {
        if(!descending) {
            auto const insert_point = std::upper_bound(list.begin(), iter, *iter);
            std::rotate(insert_point, iter, iter+1);
        }
        else {
            auto const insert_point = std::upper_bound(list.begin(), iter, *iter, std::greater<>{});
            std::rotate(insert_point, iter, iter+1);
        }
    }
}










/* Quicksort 
 *
 * 10 points
 * 
 * Algorithm: Sorts by first choosing a random pivot from the list, then 
 *            partitioning the list into two halves with respect to the 
 *            pivot, then recursing on each half.
 *            This is an unstable sorting algorithm. Not required to be
 *            implemented as an in-place sort.
 *            
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
/* Quick Partition
 *
 * Helper function for Quicksort. You will implement this to help with your
 * quicksort algorithm above.
 *
 */

template<typename T>
vector<T> quick_partition(vector<T> &list, unsigned int pivot_index, bool left, bool descending) {
    // Your code here!
    //
    // You can use the helper function 
    //      unsigned int get_rand_index(unsigned int len)
    
    if(list.empty()) return {};
    if(list.size() == 1) return vector<T>(list);

    T pivot = list[pivot_index];
    vector<T> out_list {};
    
    for(int i = 0; i < list.size(); i++) {
        if(i == pivot_index) continue;
        T item = list[i];
        if(!descending) {
            if(left && item < pivot) out_list.push_back(item);
            else if(!left && item >= pivot) out_list.push_back(item);
        }
        else{
            if(left && item > pivot) out_list.push_back(item);
            else if(!left && item <= pivot) out_list.push_back(item);
        }
    }
    return out_list; 
}
template<typename T>
void quicksort(vector<T> &list, bool descending) {
    // Your code here! 
    
    if(list.size() == 0 || list.size() == 1) return;

    unsigned int pivot_ind = get_rand_index(list.size());
    
    vector<T> left_list = quick_partition(list, pivot_ind, true, descending);
    vector<T> right_list = quick_partition(list, pivot_ind, false, descending);
    

    if(left_list.size() >= 2) quicksort(left_list, descending);
    if(right_list.size() >= 2) quicksort(right_list, descending);

    vector<T> ret_list = left_list;
    ret_list.push_back(list[pivot_ind]);
    ret_list.insert(ret_list.end(), right_list.begin(), right_list.end());
    
    list.clear();
    list = vector<T>(ret_list);
}












/* Merge Sort 
 *
 * 10 points
 * 
 * Algorithm: Sorts the list by recursively sorting the left and right
 *            halves, then merging the two left and right halves together.
 *            This is a stable sorting algorithm. Not required to be implemented
 *            as an in-place sort.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void merge_sort(vector<T> &list, bool descending) {
    // Your code here!
    if(list.size() > 1) {
        list = merge_recurse(list, descending);
    }
}

template<typename T>
vector<T> merge_recurse(vector<T> list, bool descending) {
    vector<T> merge_list {};
    switch(list.size()) {
        case 0:
        case 1:
            break;
        case 2:
            if((!descending && list[0] > list[1]) || (descending && list[0] < list[1])) {
                std::swap(list[0], list[1]);
            }
            break;
        default:
            unsigned int mid = (list.size() % 2 == 0) ? list.size()/2 : list.size()/2 + 1;
            vector<T> left = merge_recurse(vector<T>(list.begin(), list.begin()+mid));
            vector<T> right = merge_recurse(vector<T>(list.begin()+mid, list.end()));
            auto iter1 = left.begin();
            auto iter2 = right.begin();
            while(iter1 != left.end() || iter2 != right.end()) {
                if(iter1 == left.end()) {
                    merge_list.push_back(*iter2);
                    ++iter2;
                }
                else if(iter2 == right.end()) {
                    merge_list.push_back(*iter1);
                    ++iter1;
                }
                else {
                    if(!descending) {
                        if(*iter1 <= *iter2) {
                            merge_list.push_back(*iter1);
                            ++iter1;
                        }
                        else {
                            merge_list.push_back(*iter2);
                            ++iter2;
                        }
                    }
                    else {
                        if(*iter1 >= *iter2) {
                            merge_list.push_back(*iter1);
                            ++iter1;
                        }
                        else {
                            merge_list.push_back(*iter2);
                            ++iter2;
                        }
                    }
                }
            }
        break;
    }
    return merge_list;
}












/* Bucket Merge Sort
 *
 * 20 points
 * 
 * Algorithm: Bucket Merge Sort we discussed in class. Works by
 *            partitioning the input list into small, fixed-length segments,
 *            sorting each of those segments using some fast algorithm, then
 *            merging each of the segments together.
 *            This is a stable, in-place sorting algorithm.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 *
 */

vector<unsigned int> calc_bucket_indices(unsigned int N, unsigned int num_buckets) {
    vector<unsigned int> bucket_indices {};
    if(num_buckets == 2) {
        bucket_indices = {0, N/2};
    }
    else {
        unsigned int right_size = (N % 2 == 0) ? N/2 : N/2+1;
        bucket_indices = calc_bucket_indices(N/2, num_buckets/2);
        vector<unsigned int> right_indices = calc_bucket_indices(right_size, num_buckets/2);
        
        for(unsigned int index : right_indices) {
            bucket_indices.push_back(index + N/2);
        }
    }
    
    return bucket_indices;
}

template<typename T>
void bucket_merge_sort(vector<T> &list, bool descending) {
    // Your code here!
    if(list.size() <= 32) {
        insertion_sort(list, descending);
    }
    else {
        unsigned int N = list.size();
        unsigned int num_buckets = my_int_pow(2,std::ceil(std::log2(N))-5);
        vector<unsigned int> bucket_indices = calc_bucket_indices(N, num_buckets);
        
    
        // insertion sort each bucket
        for(int i = 0; i < num_buckets; ++i) {
            auto start_iter = list.begin() + bucket_indices[i];
            auto start_copy = start_iter;
            auto end_iter = (i < num_buckets-1) ? list.begin() + bucket_indices[i+1] : list.end();
            
            while(start_iter != end_iter) {
                if(!descending) { 
                    const auto insert_point = std::upper_bound(start_copy, start_iter, *start_iter);
                    std::rotate(insert_point, start_iter, start_iter+1);
                }
                else {
                    const auto insert_point = std::upper_bound(start_copy, start_iter, *start_iter, std::greater<>{});
                    std::rotate(insert_point, start_iter, start_iter+1);
                }
                ++start_iter;
            }
        }
    
    
        unsigned int bi_size = bucket_indices.size();
        while(num_buckets > 1) {
            for(int i = 0; i < num_buckets; i += 2) {
                unsigned int offset = bi_size / num_buckets;
    
                auto start_iter1 = list.begin() + bucket_indices[i*offset];
                auto start_iter2 = list.begin() + bucket_indices[(i+1)*offset];
                auto end_iter = ((i+2)*offset < bi_size) ? list.begin() + bucket_indices[(i+2)*offset] : list.end();
                while(start_iter2 != end_iter) {
                    if(start_iter1 == start_iter2) ++start_iter2;
                    else if((!descending && *start_iter1 <= *start_iter2) || (descending && *start_iter1 >= *start_iter2)) ++start_iter1;
                    else {
                        std::rotate(start_iter1, start_iter2, start_iter2+1);
                        ++start_iter2;
                    }
                }
            }
            num_buckets = num_buckets/2;
        }
    }
}




/* Binary Radix Sort
 *
 * 20 points
 *
 * Algorithm: Radix Sort in binary!
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 */
template<Integral T> 
void binary_radix_sort(vector<T> &list, bool descending) {
    // Branch on if we have unsigned or signed types
    unsigned int num_bits = sizeof(T)*8;
    unsigned int i = 0;
    T mask = 1;
    
    vector<T> work_list = {};
    vector<T> zero_list {};
    vector<T> one_list {};
    if(std::is_unsigned<T>::value) {
        work_list = list;
        
        while(i < num_bits) {
            for(T item : work_list) {
                if(item & mask) one_list.push_back(item);
                else zero_list.push_back(item);
            }
            work_list.clear();

            if(!descending) {
                work_list = zero_list;
                work_list.insert(work_list.end(), one_list.begin(), one_list.end());
            }
            else {
                work_list = one_list;
                work_list.insert(work_list.end(), zero_list.begin(), zero_list.end());
            }

            zero_list.clear();
            one_list.clear();
            
            ++i;
            mask = mask << 1;
        }
        list.clear();
        list = work_list;
    }
    else {
        vector<T> neg_work_list {};
        vector<T> neg_zero_list {};
        vector<T> neg_one_list {};

        for(T item : list) {
            if(item < 0) neg_work_list.push_back(item);
            else work_list.push_back(item);
        }

        while(i < num_bits-1) {
            for(T item: work_list) {
                if(item & mask) one_list.push_back(item);
                else zero_list.push_back(item);
            }
            for(T item: neg_work_list) {
                if(item & mask) neg_one_list.push_back(item);
                else neg_zero_list.push_back(item);
            }
            work_list.clear();
            neg_work_list.clear();

            if(!descending) {
                work_list = zero_list;
                work_list.insert(work_list.end(), one_list.begin(), one_list.end());
                neg_work_list = neg_zero_list;
                neg_work_list.insert(neg_work_list.end(), neg_one_list.begin(), neg_one_list.end());
            }
            else {
                work_list = one_list;
                work_list.insert(work_list.end(), zero_list.begin(), zero_list.end());
                neg_work_list = neg_one_list;
                neg_work_list.insert(neg_work_list.end(), neg_zero_list.begin(), neg_zero_list.end());
            }
            zero_list.clear();
            one_list.clear();
            neg_zero_list.clear();
            neg_one_list.clear();
            ++i;
            mask = mask << 1;

            list.clear();
            if(!descending) {
                list = neg_work_list;
                list.insert(list.end(), work_list.begin(), work_list.end());
            }
            else {
                list = work_list;
                list.insert(list.end(), neg_work_list.begin(), neg_work_list.end());
            }
        }
    }
}



/* Your Hybrid Sort
 *
 * 25 points
 *
 * Algorithm: Your own custom Hybrid Sorting algorithm! Remember, a hybrid
 *            sort tries to take advantage of two (or more) sorting algorithms
 *            to speed up data processing.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 */
template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending) {
    // Your code here!
    if(list.size() <= 32) {
        insertion_sort(list, descending);
        return;
    }
    //if(std::is_integral<T>::value) {
    //    binary_radix_sort(list, descending);
    //}
    else {
        unsigned int mid = (list.size() % 2 == 0) ? list.size()/2 : list.size()/2 + 1;
        vector<T> left_list(list.begin(), list.begin()+mid);
        vector<T> right_list(list.begin()+mid, list.end());
        
        vector<T> merge_list {};

        my_hybrid_sort(left_list, descending);
        my_hybrid_sort(right_list, descending);

        auto iter1 = left_list.begin();
        auto iter2 = right_list.begin();
        while(iter1 != left_list.end() || iter2 != right_list.end()) {
            if(iter1 == left_list.end()) {
                merge_list.push_back(*iter2);
                ++iter2;
            }
            else if(iter2 == right_list.end()) {
                merge_list.push_back(*iter1);
                ++iter1;
            }
            else {
                if(!descending) {
                    if(*iter1 <= *iter2) {
                        merge_list.push_back(*iter1);
                        ++iter1;
                    }
                    else {
                        merge_list.push_back(*iter2);
                        ++iter2;
                    }
                }
                else {
                    if(*iter1 >= *iter2) {
                        merge_list.push_back(*iter1);
                        ++iter1;
                    }
                    else {
                        merge_list.push_back(*iter2);
                        ++iter2;
                    }
                }
            }
        }

        
        list.clear();
        list = vector<T>(merge_list);
    }
}



/* Base B Radix Sort 
 *
 * 25 Points
 *
 * Algorithm: Implement Radix Sort as discussed in class, but with
 *            respect to any unspecified base.
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 *   unsigned int base: the base with which to implement the radix sort. 
 *                      Note that base should be at least 2. The default
 *                      base is 10.
 *
 *   bool decending: if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default).
 *
 *
 * Additional Information:
 *   - If you are enrolled in the graduate section of this course, you MUST
 *     implement this function (i.e., it counts towards your total grade).
 *
 *   - If you are enrolled in the undergraduate section of this course, this
 *     function is optional and worth extra credit.
 *
 *
 */
template<Integral T>
void radix_sort(vector<T> &list, unsigned int base, bool descending) {
    // Your code here!
    if(list.size() == 0 || list.size() == 1) return;
    if(std::is_unsigned<T>::value) {
        unsigned int num_digits = (8*sizeof(T) / std::ceil(log2(base))); 
        
        vector<T> work_list = list;
        vector<vector<T>> buckets(base);

        for(int i = 0; i < num_digits; ++i) {
            for(T item: work_list) {
                buckets[(item / my_int_pow(base, i)) % base].push_back(item);
            }
            work_list.clear();
            if(!descending) {
                for(int j = 0; j < base; ++j) {
                    work_list.insert(work_list.end(), buckets[j].begin(), buckets[j].end());
                    buckets[j].clear();
                }
            } 
            else {
                for(int j = base-1; j >= 0; --j) {
                    work_list.insert(work_list.end(), buckets[j].begin(), buckets[j].end());
                    buckets[j].clear();
                }
            }
        }
        list.clear();
        list = work_list;
    }
    else {
        unsigned int num_digits = ((8*sizeof(T)-1) / std::ceil(log2(base))); 
        
        vector<T> work_list {};
        vector<vector<T>> buckets(base);

        vector<T> neg_work_list = {};
        vector<vector<T>> neg_buckets(base);

        for(T item: list) {
            if(item < 0) neg_work_list.push_back((-1)*item);
            else work_list.push_back(item);
        }

        for(int i = 0; i < num_digits; ++i) {
            for(T item: work_list) {
                buckets[(item / my_int_pow(base, i)) % base].push_back(item);
            }
            for(T item: neg_work_list) {
                neg_buckets[(item / my_int_pow(base, i)) % base].push_back(item);
            }
            
            work_list.clear();
            neg_work_list.clear();
            if(!descending) {
                for(int j = 0; j < base; ++j) {
                    work_list.insert(work_list.end(), buckets[j].begin(), buckets[j].end());
                    buckets[j].clear();
                }
                for(int j = base-1; j >= 0; --j) {
                    neg_work_list.insert(neg_work_list.end(), neg_buckets[j].begin(), neg_buckets[j].end());
                    neg_buckets[j].clear();
                }
            }
            else {
                for(int j = 0; j < base; ++j) {
                    neg_work_list.insert(neg_work_list.end(), neg_buckets[j].begin(), neg_buckets[j].end());
                    neg_buckets[j].clear();
                }
                for(int j = base-1; j >= 0; --j) {
                    work_list.insert(work_list.end(), buckets[j].begin(), buckets[j].end());
                    buckets[j].clear();
                }
            }
        }
        for(int j = 0; j < neg_work_list.size(); ++j) {
            neg_work_list[j] *= -1;
        }
        list.clear();
        if(!descending) {
            list = neg_work_list;
            list.insert(list.end(), work_list.begin(), work_list.end());
        }
        else {
            list = work_list;
            list.insert(list.end(), neg_work_list.begin(), neg_work_list.end());
        }
    }
}

}


//unsigned int stable_sort_race(
//    std::function<void(std::vector<StableInt>&, bool)> alex_func,
//    std::function<void(std::vector<StableInt>&, bool)> student_func, 
//    const unsigned int list_size, 
//    const unsigned int num_runs
//) {
//
//    std::srand(std::time({}));
//    std::chrono::duration<double, std::micro> alex_average {};
//    std::chrono::duration<double, std::micro> student_average {};
//
//    unsigned int tests_valid = 1;
//
//    int rand_pert = static_cast<int>(std::rand() % 17);
//    rand_pert *= (static_cast<unsigned int>(std::rand() % 2)) ? (-1) : 1;
//
//    for(unsigned int i = 0; i < num_runs; ++i) {
//        std::vector<StableInt> alex_test_1a = gen_stable_int_unique(list_size + rand_pert);
//        std::vector<StableInt> alex_test_1d(alex_test_1a);
//        std::vector<StableInt> alex_test_2a = gen_stable_int_ascending(list_size + rand_pert);
//        std::vector<StableInt> alex_test_2d(alex_test_2a);
//        std::vector<StableInt> alex_test_3a = gen_stable_int_descending(list_size + rand_pert);
//        std::vector<StableInt> alex_test_3d(alex_test_3a);
//        std::vector<StableInt> alex_test_4a = gen_stable_int_many_dupes(list_size + rand_pert);
//        std::vector<StableInt> alex_test_4d(alex_test_4a);
//        std::vector<StableInt> alex_test_5a = gen_stable_int_one_percent(list_size + rand_pert);
//        std::vector<StableInt> alex_test_5d(alex_test_5a); 
//
//        std::vector<StableInt> student_test_1a(alex_test_1a);
//        std::vector<StableInt> student_test_1d(alex_test_1d);
//        std::vector<StableInt> student_test_2a(alex_test_2a);
//        std::vector<StableInt> student_test_2d(alex_test_2d);
//        std::vector<StableInt> student_test_3a(alex_test_3a);
//        std::vector<StableInt> student_test_3d(alex_test_3d);
//        std::vector<StableInt> student_test_4a(alex_test_4a);
//        std::vector<StableInt> student_test_4d(alex_test_4d);
//        std::vector<StableInt> student_test_5a(alex_test_5a);
//        std::vector<StableInt> student_test_5d(alex_test_5d); 
//
//        std::vector<std::vector<StableInt>*> alex_tests { &alex_test_1a, &alex_test_1d, &alex_test_2a, &alex_test_2d, &alex_test_3a, &alex_test_3d, &alex_test_4a, &alex_test_4d, &alex_test_5a, &alex_test_5d };
//
//        std::vector<std::vector<StableInt>*> student_tests { &student_test_1a, &student_test_1d, &student_test_2a, &student_test_2d, &student_test_3a, &student_test_3d, &student_test_4a, &student_test_4d, &student_test_5a, &student_test_5d };
//
//        for(int i = 0; i < 10; ++i) {
//
//            if(i % 2) { // i is odd
//                const auto a_start = std::chrono::high_resolution_clock::now();
//                alex_func(*alex_tests[i], true);
//                const auto a_stop = std::chrono::high_resolution_clock::now();
//
//                const auto s_start = std::chrono::high_resolution_clock::now();
//                student_func(*student_tests[i], true);
//                const auto s_stop = std::chrono::high_resolution_clock::now();
//
//                alex_average += (a_stop - a_start);
//                student_average += (s_stop - s_start);
//
//                if(tests_valid && !is_stable_sorted(*student_tests[i], true)) tests_valid = 0;
//            }
//            else { // i is even
//                const auto a_start = std::chrono::high_resolution_clock::now();
//                alex_func(*alex_tests[i], false);
//                const auto a_stop = std::chrono::high_resolution_clock::now();
//
//                const auto s_start = std::chrono::high_resolution_clock::now();
//                student_func(*student_tests[i], false);
//                const auto s_stop = std::chrono::high_resolution_clock::now();
//
//                alex_average += (a_stop - a_start);
//                student_average += (s_stop - s_start);
//
//                if(tests_valid && !is_stable_sorted(*student_tests[i], false)) tests_valid = 0;
//            }
//        }
//    }
//    alex_average = alex_average / num_runs;
//    student_average = student_average / num_runs;
//    
//    cout << "valid tests? " << tests_valid << endl;
//    cout << alex_average << endl;
//    cout << student_average << endl;
//
//    return (student_average <= alex_average && tests_valid) ? 1 : 0;
//}
//
//int main() {
//    cout << stable_sort_race(&alex::insertion_sort<StableInt>, &alex::selection_sort<StableInt>, 64, 5) << endl;
//}

//using namespace alex;

//int main() {
//
//    double total_points = 20.0;
//    double score = 0.0;
//    
//
//
//    // different type tests; 1 point each
//    std::vector<StableChar> char_test = gen_stable_char_one_percent(9);
//    std::vector<StableString> string_test = gen_stable_string_one_percent(9);
//
//    std::vector<short> short_test = gen_unique_short_list(259);
//    std::vector<unsigned short> unsigned_short_test = gen_unique_unsigned_short_list(250);
//
//    std::vector<long> long_test = gen_unique_long_list(601);
//    std::vector<unsigned long> unsigned_long_test = gen_unique_unsigned_long_list(598);
//
//
//    bucket_merge_sort(char_test);
//    if(std::is_sorted(char_test.begin(), char_test.end())) ++score;
//
//    bucket_merge_sort(string_test);
//    if(std::is_sorted(string_test.begin(), string_test.end())) ++score;
//
//    bucket_merge_sort(short_test);
//    if(std::is_sorted(short_test.begin(), short_test.end())) ++score;
//
//    bucket_merge_sort(unsigned_short_test);
//    if(std::is_sorted(unsigned_short_test.begin(), unsigned_short_test.end())) ++score;
//
//    bucket_merge_sort(long_test);
//    if(std::is_sorted(long_test.begin(), long_test.end())) ++score;
//
//    bucket_merge_sort(unsigned_long_test);
//    if(std::is_sorted(unsigned_long_test.begin(), unsigned_long_test.end())) ++score;
//
//
//
//    // Stable Tests; 1 point per pair (or half a point each)
//    double stable_score = 0.0;
//    std::vector<StableInt> stable_int_test1 = gen_stable_int_many_dupes(1029);
//    std::vector<StableInt> stable_int_test2 = gen_stable_int_many_dupes(1027);
//
//    bucket_merge_sort(stable_int_test1);
//    bucket_merge_sort(stable_int_test2, true);
//
//    if(is_stable_sorted(stable_int_test1)) ++stable_score;
//    if(is_stable_sorted(stable_int_test2,true)) ++stable_score;
//
//    std::vector<StableChar> stable_char_test1 = gen_stable_char_many_dupes(1027);
//    std::vector<StableChar> stable_char_test2 = gen_stable_char_many_dupes(1029);
//
//    bucket_merge_sort(stable_char_test1);
//    bucket_merge_sort(stable_char_test2, true);
//
//    if(is_stable_sorted(stable_char_test1)) ++stable_score;
//    if(is_stable_sorted(stable_char_test2,true)) ++stable_score;
//
//    std::vector<StableString> stable_string_test1 = gen_stable_string_many_dupes(1027);
//    std::vector<StableString> stable_string_test2 = gen_stable_string_many_dupes(1029);
//
//    bucket_merge_sort(stable_string_test1);
//    bucket_merge_sort(stable_string_test2, true);
//
//    if(is_stable_sorted(stable_string_test2,true)) ++stable_score;
//    if(is_stable_sorted(stable_string_test1)) ++stable_score;
//
//
//    score += (stable_score / 2);
//
//
//    // (unsigned) int different number tests; 1 point per pair (or half a point each)
//    double asc_des_score = 0.0;
//    unsigned int size_list[10] = {32, 64, 128, 256, 1024, 4098, 16384, 65536, 262144, 1048576}; 
//    std::srand(std::time({}));
//    for(int i = 0; i < 10; ++i) {
//        unsigned int signed_test = static_cast<unsigned int>(std::rand() % 2); 
//        unsigned int rand_pert = (i > 2) ? static_cast<unsigned int>(std::rand() % 17) : 0;
//        if(signed_test) {
//            std::vector<int> ascending_test = gen_unique_int_list(size_list[i]+rand_pert);
//            std::vector<int> descending_test(ascending_test);
//
//            bucket_merge_sort(ascending_test);
//            bucket_merge_sort(descending_test,true);
//
//            if(std::is_sorted(ascending_test.begin(), ascending_test.end())) ++asc_des_score;
//            if(std::is_sorted(descending_test.begin(), descending_test.end(), std::greater<>{})) ++asc_des_score;
//            
//        }
//        else {
//            std::vector<unsigned int> ascending_test = gen_unique_unsigned_int_list(size_list[i]+rand_pert);
//            std::vector<unsigned int> descending_test(ascending_test);
//
//            bucket_merge_sort(ascending_test);
//            bucket_merge_sort(descending_test,true);
//
//            if(std::is_sorted(ascending_test.begin(), ascending_test.end())) ++asc_des_score;
//            if(std::is_sorted(descending_test.begin(), descending_test.end(), std::greater<>{})) ++asc_des_score;
//        }
//    }
//
//    score += (asc_des_score / 2);
//    
//    
//    // Empty list test; 1 point
//    std::vector<int> empty_test {};
//
//    bucket_merge_sort(empty_test);
//    if(std::is_sorted(empty_test.begin(), empty_test.end())) ++score;
//
//    //RESULT(100*(score / total_points));
//
//    cout << "Score = " << score;
//
//    return 0;
//}


//int main() {
//    /**** STUDENT CODE HERE ****/ 
//
//    std::vector<StableInt> test_list1 = gen_stable_int_many_dupes(17380);
//    std::vector<StableInt> test_list2(test_list1);    
//    std::vector<StableChar> test_list3 = gen_stable_char_many_dupes(1738);
//    std::vector<StableChar> test_list4(test_list3);
//    std::vector<StableString> test_list5 = gen_stable_string_many_dupes(1738);
//    std::vector<StableString> test_list6(test_list5);
//
//
//    alex::bucket_merge_sort(test_list1, false);
//    alex::bucket_merge_sort(test_list2, true);
//
//    alex::bucket_merge_sort(test_list3, false);
//    alex::bucket_merge_sort(test_list4, true);
//
//    alex::bucket_merge_sort(test_list5, false);
//    alex::bucket_merge_sort(test_list6, true);
//
//    cout << "\tIs StableInt1 sorted? " << is_stable_sorted(test_list1, false) << endl;
//    cout << "\tIs StableInt2 sorted? " << is_stable_sorted(test_list2, true) << endl;
//    cout << "\tIs StableChar1 sorted? " << is_stable_sorted(test_list3, false) << endl;
//    cout << "\tIs StableChar2 sorted? " << is_stable_sorted(test_list4, true) << endl;
//    cout << "\tIs StableString1 sorted? " << is_stable_sorted(test_list5, false) << endl;
//    cout << "\tIs StableString2 sorted? " << is_stable_sorted(test_list6, true) << endl;
//
//    
//
//
//
//
//    /**** END STUDENT CODE ****/
//
//    /***** DO NOT MODIFY BELOW THIS LINE *****/
//    /*** INSTRUCTIONS ***
//     *
//     * Before submitting your code: 
//     *   - remove all code within the main function that you have written above the `do-not-modify` line;
//     *   - uncomment all lines below that begin with "//".
//     *
//     */
//    //vector<int> test_list {1, 2, 3, 4, 5};
//    //bubble_sort(test_list);
//    //selection_sort(test_list);
//    //insertion_sort(test_list);
//    //quicksort(test_list);
//    //merge_sort(test_list);
//    //bucket_merge_sort(test_list);
//    //binary_radix_sort(test_list);
//    //my_hybrid_sort(test_list);
//    //radix_sort(test_list);
//
//
//    return 0;
//}









