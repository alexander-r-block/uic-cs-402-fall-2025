#include <vector>
#include <random>
#include <concepts>
#include <chrono>
#include <type_traits>


#ifndef ALEX_BLOCK_PROJECT1
#define ALEX_BLOCK_PROJECT1

using namespace std;



/*** Helper Functions ***/
inline unsigned int get_rand_index(unsigned int len) {
    srand(time({}));
    return static_cast<unsigned int>(rand() % len);
}


/*** STUDENT HELPER FUNCTIONS HERE ***/

template<typename T>
vector<T> merge_recurse(vector<T> list, bool descending = false);

inline int my_int_pow(const int base, const unsigned int power) {

  if (power == 0) return 1;
  if (power == 1) return base;

  int tmp = my_int_pow(base, power/2);
  if ((power % 2) == 0) { return tmp * tmp; }
  else { return base * tmp * tmp; }
}

/*** END STUDENT HELPER FUNCTIONS ***/





/*** DO NOT MODIFY BELOW ***/
/*** Main Functions for Students to Implement ***/

/** Helper type for integrals only **/
template<class T>
concept Integral = is_integral<T>::value;


/* Bubble Sort */
template<typename T>
void bubble_sort(vector<T> &list, bool descending = false);

/* Selection Sort */
template<typename T>
void selection_sort(vector<T> &list, bool descending = false);

/* Insertion Sort */
template<typename T>
void insertion_sort(vector<T> &list, bool descending = false); 

/* Quick Sort */
template<typename T>
vector<T>& quick_partition(vector<T> &list, unsigned int pivot_index, bool descending = false);

template<typename T>
void quicksort(vector<T> &list, bool descending = false);


/* Merge Sort */
template<typename T>
void merge_sort(vector<T> &list, bool descending = false);

/* Bucket Merge Sort  */
template<typename T>
void bucket_merge_sort(vector<T> &list, bool descending = false);


/* Binary Radix Sort */
template<Integral T>
void binary_radix_sort(vector<T> &list, bool descending = false);


/* Your Hybrid Sort */
template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending = false);


/* Base B Radix Sort */
template<Integral T> 
void radix_sort(vector<T> &list, unsigned int base = 10, bool descending = false);



#endif
