#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <random>
#include <math.h>

#ifndef testing
#define testing



using namespace std;

/* Helper function to print vector */
template<typename T>
void print_list(vector<T>& list);


/* Generate shuffled list of integers from 0 to len-1 */
vector<int> gen_unique_list(unsigned int len);

/* Generate random list of integers of size len */
vector<int> gen_random_list(unsigned int len);

/* Generate descending list of integers of size len */
vector<int> gen_descending_list(unsigned int len);

/* Generates a list of ascending integers of size len */
vector<int> gen_ascending_list(unsigned int len);


/* Generates an ascending list with 3 random swaps */
vector<int> gen_asending_3swap_list(unsigned int len);

/* Genarates a list of all equal entries of length len */
vector<int> gen_all_equal_list(unsigned int len);

/* Generates list containing many duplicates of length len */
vector<int> gen_many_dupes_list(unsigned int len);

/* Generate ascending list with 1% of entries then randomly changed */
vector<int> gen_one_percent_rand_list(unsigned int len);


/**** Student Tests Here ****/
/* Feel free to write your own tests here! */

bool is_list_sorted(vector<int> &list, bool descending=false);

#endif
