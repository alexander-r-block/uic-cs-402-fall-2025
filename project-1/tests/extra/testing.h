#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <random>
#include <math.h>
#include <concepts>
#include <type_traits>

#ifndef TESTING
#define TESTING



/* Structs for testing stable sorting*/ 
struct StableInt {
    int val;
    unsigned int pos;

    bool operator> (const StableInt &) const;
    bool operator>=(const StableInt &) const;
    bool operator< (const StableInt &) const;
    bool operator<=(const StableInt &) const;
    bool operator==(const StableInt &) const;
    bool operator!=(const StableInt &) const;

    friend std::ostream& operator<<(std::ostream&, StableInt const&);
};

inline bool StableInt::operator>(const StableInt &s) const { return val > s.val; }
inline bool StableInt::operator>=(const StableInt &s) const { return val >= s.val; }
inline bool StableInt::operator<(const StableInt &s) const { return val < s.val; }
inline bool StableInt::operator<=(const StableInt &s) const {return val <= s.val; }
inline bool StableInt::operator==(const StableInt &s) const {return val == s.val; }
inline bool StableInt::operator!=(const StableInt &s) const {return val != s.val; }
inline std::ostream& operator<<(std::ostream& os, const StableInt& si) {
    return os << "(" <<  si.val << ", " << si.pos << ")";
}


struct StableChar {
    char val;
    unsigned int pos;

    bool operator> (const StableChar &) const;
    bool operator>=(const StableChar &) const;
    bool operator< (const StableChar &) const;
    bool operator<=(const StableChar &) const;
    bool operator==(const StableChar &) const;
    bool operator!=(const StableChar &) const;

    friend std::ostream& operator<<(std::ostream&, StableChar const&);
};

inline bool StableChar::operator> (const StableChar &s) const { return val > s.val; }
inline bool StableChar::operator>=(const StableChar &s) const { return val >= s.val; }
inline bool StableChar::operator< (const StableChar &s) const { return val < s.val; }
inline bool StableChar::operator<=(const StableChar &s) const { return val <= s.val; }
inline bool StableChar::operator==(const StableChar &s) const { return val == s.val; }
inline bool StableChar::operator!=(const StableChar &s) const { return val != s.val; }

inline std::ostream& operator<<(std::ostream& os, const StableChar& si) {
    return os << "(" <<  si.val << ", " << si.pos << ")";
}


struct StableString {
    std::string val;
    unsigned int pos;

    bool operator>(const StableString &) const;
    bool operator>= (const StableString &) const;
    bool operator<(const StableString &) const;
    bool operator<=(const StableString &) const;
    bool operator==(const StableString &) const;
    bool operator!=(const StableString &) const;

    friend std::ostream& operator<<(std::ostream&, StableString const&);

};

inline bool StableString::operator>(const StableString &s) const { return (val.compare(s.val) > 0); }
inline bool StableString::operator>= (const StableString &s) const { return (val.compare(s.val) >= 0); }
inline bool StableString::operator<(const StableString &s) const { return (val.compare(s.val) < 0); }
inline bool StableString::operator<=(const StableString &s) const {return (val.compare(s.val) <= 0); }
inline bool StableString::operator==(const StableString &s) const {return (val.compare(s.val) == 0); }
inline bool StableString::operator!=(const StableString &s) const {return (val.compare(s.val) != 0); }
inline std::ostream& operator<<(std::ostream& os, const StableString& si) {
    return os << "(" <<  si.val << ", " << si.pos << ")";
}

/* Helper function to print vector */
template<typename T>
inline void print_list(std::vector<T>& list) {
    std::cout << "[ ";
    for(T n : list) {
        std::cout << n << ' ';
    }
    std::cout << "]\n";
}

/* Generate shuffled list of integers from 0 to len-1 */



std::vector<int> gen_unique_int_list(unsigned int len);
std::vector<unsigned int> gen_unique_unsigned_int_list(unsigned int len);

std::vector<short> gen_unique_short_list(unsigned int len);
std::vector<unsigned short> gen_unique_unsigned_short_list(unsigned int len);

std::vector<long> gen_unique_long_list(unsigned int len);
std::vector<unsigned long> gen_unique_unsigned_long_list(unsigned int len);

/* Generate random list of integers of size len */
std::vector<int> gen_random_list(unsigned int len);

/* Generate descending list of integers of size len */
std::vector<int> gen_descending_list(unsigned int len);

/* Generates a list of ascending integers of size len */
std::vector<int> gen_ascending_list(unsigned int len);

/* Generates an ascending list with 3 random swaps */
std::vector<int> gen_asending_3swap_list(unsigned int len);

/* Genarates a list of all equal entries of length len */
std::vector<int> gen_all_equal_list(unsigned int len);

/* Generates list containing many duplicates of length len */
std::vector<int> gen_many_dupes_list(unsigned int len);

/* Generate ascending list with 1% of entries then randomly changed */
std::vector<int> gen_one_percent_rand_list(unsigned int len);

std::vector<StableInt> gen_stable_int_many_dupes(unsigned int len);
std::vector<StableInt> gen_stable_int_one_percent(unsigned int len);
std::vector<StableInt> gen_stable_int_unique(unsigned int len);
std::vector<StableInt> gen_stable_int_ascending(unsigned int len);
std::vector<StableInt> gen_stable_int_descending(unsigned int len);
std::vector<StableInt> gen_stable_int_random(unsigned int len);

std::vector<StableChar> gen_stable_char_many_dupes(unsigned int len);
std::vector<StableChar> gen_stable_char_one_percent(unsigned int len);

std::vector<StableString> gen_stable_string_many_dupes(unsigned int len);
std::vector<StableString> gen_stable_string_one_percent(unsigned int len);
/**** Student Tests Here ****/
/* Feel free to write your own tests here! */

bool is_stable_sorted(const std::vector<StableInt>& list, bool descending = false);
bool is_stable_sorted(const std::vector<StableChar>& list, bool descending = false);
bool is_stable_sorted(const std::vector<StableString>& list, bool descending = false);





#endif
