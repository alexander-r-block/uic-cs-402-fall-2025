

#include <iostream>
#include <algorithm>
#include <chrono>
#include <concepts>
#include <type_traits>

#include "testing.h"
#include "Firstname_Lastname_project1.h"

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
//template<typename T>
//void insertion_sort(vector<T> &list, bool descending = false);
template<typename T>
void insertion_sort(vector<T> &list, bool descending) {
    // Your code here!
    std::stable_sort(list.begin(), list.end());
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
template<typename T>
void quicksort(vector<T> &list, bool descending) {
    // Your code here!
}


/* Quick Partition
 *
 * Helper function for Quicksort. You will implement this to help with your
 * quicksort algorithm above.
 *
 */
template<typename T>
vector<T>& quick_partition(vector<T> &list, bool descending) {
    // Your code here!
    //
    // You can use the helper function 
    //      unsigned int get_rand_index(unsigned int len)
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
void merge_sort(vector<T> &list, bool decending) {
    // Your code here!
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
template<typename T>
void bucket_merge_sort(vector<T> &list, bool descending) {
    // Your code here!
}




/* Binary Radix Sort
 *
 * 20 points
 *
 * Algorithm:
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 */
//template<class T>
//concept Integral = std::is_integral<T>::value;
template<Integral T> 
void binary_radix_sort(vector<T> &list, bool descending) {
    // Your code here!
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
}






int main() {
    /**** STUDENT CODE HERE ****/ 






    /**** END STUDENT CODE ****/

    /***** DO NOT MODIFY BELOW THIS LINE *****/
    /*** INSTRUCTIONS ***
     *
     * Before submitting your code: 
     *   - remove all code within the main function that you have written above the `do-not-modify` line;
     *   - uncomment all lines below that begin with "//".
     *
     */
    vector<int> test_list {1, 2, 3, 4, 5};
    vector<unsigned int> test_list2 {1, 2, 3, 4, 5};
    vector<StableChar> test_list3  {};
    vector<StableInt> test_list4 {};
    vector<StableString> test_list5 {};
    vector<short> test_list6  {};
    vector<unsigned short> test_list7  {};
    vector<long> test_list8  {};
    vector<unsigned long> test_list9  {};


    insertion_sort(test_list);
    insertion_sort(test_list2);
    insertion_sort(test_list3);
    insertion_sort(test_list4);
    insertion_sort(test_list5);
    insertion_sort(test_list6);
    insertion_sort(test_list7);
    insertion_sort(test_list8);
    insertion_sort(test_list9);


    selection_sort(test_list);
    selection_sort(test_list2);
    selection_sort(test_list3);
    selection_sort(test_list4);
    selection_sort(test_list5);
    selection_sort(test_list6);
    selection_sort(test_list7);
    selection_sort(test_list8);
    selection_sort(test_list9);

    bubble_sort(test_list);
    bubble_sort(test_list2);
    bubble_sort(test_list3);
    bubble_sort(test_list4);
    bubble_sort(test_list5);
    bubble_sort(test_list6);
    bubble_sort(test_list7);
    bubble_sort(test_list8);
    bubble_sort(test_list9);


    merge_sort(test_list);
    merge_sort(test_list2);
    merge_sort(test_list3);
    merge_sort(test_list4);
    merge_sort(test_list5);
    merge_sort(test_list6);
    merge_sort(test_list7);
    merge_sort(test_list8);
    merge_sort(test_list9);

    quicksort(test_list);
    quicksort(test_list2);
    quicksort(test_list3);
    quicksort(test_list4);
    quicksort(test_list5);
    quicksort(test_list6);
    quicksort(test_list7);
    quicksort(test_list8);
    quicksort(test_list9);


    bucket_merge_sort(test_list);
    bucket_merge_sort(test_list2);
    bucket_merge_sort(test_list3);
    bucket_merge_sort(test_list4);
    bucket_merge_sort(test_list5);
    bucket_merge_sort(test_list6);
    bucket_merge_sort(test_list7);
    bucket_merge_sort(test_list8);
    bucket_merge_sort(test_list9);


    my_hybrid_sort(test_list);
    my_hybrid_sort(test_list2);
    my_hybrid_sort(test_list3);
    my_hybrid_sort(test_list4);
    my_hybrid_sort(test_list5);
    my_hybrid_sort(test_list6);
    my_hybrid_sort(test_list7);
    my_hybrid_sort(test_list8);
    my_hybrid_sort(test_list9);

    binary_radix_sort(test_list);
    binary_radix_sort(test_list2);
    binary_radix_sort(test_list6);
    binary_radix_sort(test_list7);
    binary_radix_sort(test_list8);
    binary_radix_sort(test_list9);

    radix_sort(test_list);
    radix_sort(test_list2);
    radix_sort(test_list6);
    radix_sort(test_list7);
    radix_sort(test_list8);
    radix_sort(test_list9);

    return 0;
}









