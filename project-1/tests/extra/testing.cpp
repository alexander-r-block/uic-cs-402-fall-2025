#include "testing.h"


/* Helper function to print vector */

//template<typename T>
//void print_list(std::vector<T>& list) {
//    std::cout << "[ ";
//    for(T n : list) {
//        std::cout << n << ' ';
//    }
//    //for(int i = 0; i < list.size(); i++) std::cout << list[i] << ' ';
//
//    std::cout << "]\n";
//}

/* Generate shuffled list of integers from 0 to len-1 */


std::vector<unsigned short> gen_unique_unsigned_short_list(unsigned int len);

std::vector<long> gen_unique_long_list(unsigned int len);
std::vector<unsigned long> gen_unique_unsigned_long_list(unsigned int len);

std::vector<short> gen_unique_short_list(unsigned int len) {
    std::vector<short> int_list {};
    std::srand(std::time({}));
    for(short i = 0; i < len; i++) {
        unsigned int is_neg = static_cast<unsigned int>(rand());
        if(is_neg % 2) {
            int_list.push_back(-(i+1));
        }
        else int_list.push_back(i+1);
    }

    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };

    std::ranges::shuffle(int_list,rng);

    return int_list;
}

std::vector<unsigned short> gen_unique_unsigned_short_list(unsigned int len) {
    std::vector<unsigned short> int_list {};
    for(unsigned short i = 0; i < len; i++) {
        int_list.push_back(i+1);
    }

    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };

    std::ranges::shuffle(int_list,rng);

    return int_list;
}

std::vector<int> gen_unique_int_list(unsigned int len) {
    std::vector<int> int_list {};
    std::srand(std::time({}));
    for(int i = 0; i < len; i++) {
        unsigned int is_neg = static_cast<unsigned int>(rand());
        if(is_neg % 2) {
            int_list.push_back(-(i+1));
        }
        else int_list.push_back(i+1);
    }

    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };

    std::ranges::shuffle(int_list,rng);

    return int_list;
}

std::vector<unsigned int> gen_unique_unsigned_int_list(unsigned int len) {
    std::vector<unsigned int> int_list {};
    for(unsigned int i = 0; i < len; i++) {
        int_list.push_back(i+1);
    }

    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };

    std::ranges::shuffle(int_list,rng);

    return int_list;
}

std::vector<long> gen_unique_long_list(unsigned int len) {
    std::vector<long> int_list {};
    std::srand(std::time({}));
    for(long i = 0; i < len; i++) {
        unsigned int is_neg = static_cast<unsigned int>(rand());
        if(is_neg % 2) {
            int_list.push_back(-(i+1));
        }
        else int_list.push_back(i+1);
    }

    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };

    std::ranges::shuffle(int_list,rng);

    return int_list;
}

std::vector<unsigned long> gen_unique_unsigned_long_list(unsigned int len) {
    std::vector<unsigned long> int_list {};
    for(unsigned long i = 0; i < len; i++) {
        int_list.push_back(i+1);
    }

    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };

    std::ranges::shuffle(int_list,rng);

    return int_list;
}

/* Generate random list of integers of size len */
std::vector<int> gen_random_list(unsigned int len) {

    std::vector<int> int_list {};

    std::srand(std::time({}));
    for(int i = 0; i < len; i++) {
        int_list.push_back(static_cast<int>(rand()) * ( -1 + (static_cast<int>(rand()) % 2)*2   )  );
    }

    return int_list;
}

/* Generate descending list of integers of size len */
std::vector<int> gen_descending_list(unsigned int len) { 
    std::vector<int> int_list {};
    std::srand(std::time({}));
    int start_int = static_cast<int>( (rand() % len)*((-1) + 2*(rand() % 2))  );
    for(int i = 0; i < len; i++) {
        int_list.push_back(start_int);
        --start_int;
    }

    return int_list;
}

/* Generates a list of ascending integers of size len */
std::vector<int> gen_ascending_list(unsigned int len) { 
    std::vector<int> int_list {};
    std::srand(std::time({}));
    int start_int = static_cast<int>( (rand() % len)*((-1) + 2*(rand() % 2))  );
    for(int i = 0; i < len; i++) {
        int_list.push_back(start_int);
        ++start_int;
    }

    return int_list;
}


/* Generates an ascending list with 3 random swaps */
std::vector<int> gen_asending_3swap_list(unsigned int len) {
    std::vector<int> int_list = gen_ascending_list(len);
    std::srand(std::time({}));
    for(int i = 0; i < 3; i++) {
        unsigned int swap_index1 = static_cast<unsigned int>( rand() % len );
        unsigned int swap_index2 = static_cast<unsigned int>( rand() % len );

        int temp = int_list[swap_index1];
        int_list[swap_index1] = int_list[swap_index2];
        int_list[swap_index2] = temp;
    }
    return int_list;
}

/* Genarates a list of all equal entries of length len */
std::vector<int> gen_all_equal_list(unsigned int len) {
    std::vector<int> int_list = {};
    srand(time({}));
    int choice = static_cast<int>( rand() );
    for(int i = 0; i < len; i++) {
        int_list.push_back(choice);
    }

    return int_list;
}

/* Generates list containing many duplicates of length len */
std::vector<int> gen_many_dupes_list(unsigned int len) {
    std::vector<int> int_list = {};
    srand(time({}));
    while(int_list.size() < len) {
        unsigned int num_dupes = static_cast<unsigned int>( rand() % 17 );
        int item = static_cast<int>( rand() % 513 );
        for(int j = 0; j < num_dupes && int_list.size() < len; j++) {
            int_list.push_back(item);
        }
    }

    return int_list;
}

/* Generate ascending list with 1% of entries then randomly changed */
std::vector<int> gen_one_percent_rand_list(unsigned int len) {
    std::vector<int> int_list = gen_ascending_list(len);

    unsigned int percent = ceil(len*.01);

    srand(time({}));
    for(int i = 0; i < percent; i++) {
        unsigned int index = static_cast<unsigned int>( rand() % len );
        unsigned int value = static_cast<int>( rand() );

        int_list[index] = value;
    }

    return int_list;
}

std::vector<StableInt> gen_stable_int_many_dupes(unsigned int len) {
    std::vector<StableInt> list {}; 
    std::vector<int> int_list = gen_many_dupes_list(len);

    for(unsigned int i = 0; i < len; ++i) {
        list.push_back(StableInt(int_list[i],i));
    }
    return list;
}
std::vector<StableInt> gen_stable_int_one_percent(unsigned int len) {
    std::vector<StableInt> list {}; 
    std::vector<int> int_list = gen_one_percent_rand_list(len);

    for(unsigned int i = 0; i < len; ++i) {
        list.push_back(StableInt(int_list[i],i));
    }
    return list;
}
std::vector<StableInt> gen_stable_int_unique(unsigned int len) {
    std::vector<StableInt> list{};
    std::vector<int> int_list = gen_unique_int_list(len);

    for(unsigned int i = 0; i < len; ++i) {
        list.push_back(StableInt(int_list[i],i));
    }
    return list;
}
std::vector<StableInt> gen_stable_int_ascending(unsigned int len) {
    std::vector<StableInt> list {}; 
    std::vector<int> int_list = gen_ascending_list(len);

    for(unsigned int i = 0; i < len; ++i) {
        list.push_back(StableInt(int_list[i],i));
    }
    return list;
}
std::vector<StableInt> gen_stable_int_descending(unsigned int len) {
    std::vector<StableInt> list {}; 
    std::vector<int> int_list = gen_descending_list(len);

    for(unsigned int i = 0; i < len; ++i) {
        list.push_back(StableInt(int_list[i],i));
    }
    return list;
}
std::vector<StableInt> gen_stable_int_random(unsigned int len) {
    std::vector<StableInt> list {}; 
    std::vector<int> int_list = gen_random_list(len);

    for(unsigned int i = 0; i < len; ++i) {
        list.push_back(StableInt(int_list[i],i));
    }
    return list;
}


std::vector<StableChar> gen_stable_char_many_dupes(unsigned int len) {
    std::vector<char> char_list = {};
    srand(time({}));
    while(char_list.size() < len) {
        unsigned int num_dupes = static_cast<unsigned int>( rand() % 17 );
        char item = static_cast<char>( rand() );
        for(int j = 0; j < num_dupes && char_list.size() < len; j++) {
            char_list.push_back(item);
        }
    }

    std::vector<StableChar> list {};
    for(unsigned int i = 0; i < len; ++i) {
        list.push_back(StableChar(char_list[i],i));
    }

    return list;
}

std::vector<StableChar> gen_stable_char_one_percent(unsigned int len) {
    std::vector<char> char_list {};
    std::srand(std::time({}));

    char start_char = static_cast<char>( (rand() % 256)  );
    for(int i = 0; i < len; i++) {
        char_list.push_back(start_char);
        ++start_char;
    }

    unsigned int percent = (len % 10 == 0) ? len/10 : 1+(len/10);

    srand(time({}));
    for(int i = 0; i < percent; i++) {
        unsigned int index = static_cast<unsigned int>( rand() % len );
        char value = static_cast<char>( (rand() % 256) );

        char_list[index] = value;
    }

    std::vector<StableChar> list{};
    for(unsigned int i = 0; i < len; ++i) {
        list.push_back(StableChar(char_list[i],i));
    }
    
    return list;
}




std::vector<StableString> gen_stable_string_many_dupes(unsigned int len) {
    std::vector<std::string> string_list {};

    srand(time({}));

    while(string_list.size() < len) {
        unsigned int num_dupes = static_cast<unsigned int>( rand() % 17 );
        unsigned int str_len = static_cast<unsigned int>( rand() % 29 );
        std::string item  = "";
        while(item.length() < str_len) {
            item += static_cast<char>( rand() );
        }
        for(int j = 0; j < num_dupes && string_list.size() < len; j++) {
            string_list.push_back(item);
        }
    }

    std::vector<StableString> list {};
    for(unsigned int i = 0; i < len; ++i) {
        list.push_back(StableString(string_list[i],i));
    }

    return list;
}
std::vector<StableString> gen_stable_string_one_percent(unsigned int len) {
    std::vector<std::string> string_list {};
    std::srand(std::time({}));

    char start_char = static_cast<char>( (rand() % 256)  );
    std::string item = "";
    item += start_char;
    for(int i = 0; i < len; i++) {
        string_list.push_back(item);
        item += start_char;
    }

    unsigned int percent = (len % 10 == 0) ? len/10 : 1+(len/10);

    srand(time({}));
    for(int i = 0; i < percent; i++) {
        unsigned int index = static_cast<unsigned int>( rand() % len );
        char value = static_cast<char>( (rand() % 256) );

        string_list[index] = value;
    }

    std::vector<StableString> list{};
    for(unsigned int i = 0; i < len; ++i) {
        list.push_back(StableString(string_list[i],i));
    }
    
    return list;
}


bool is_stable_sorted(const std::vector<StableInt>& list, bool descending) {
    bool sorted = (!descending) ? std::is_sorted(list.begin(), list.end()) : std::is_sorted(list.begin(), list.end(), std::greater<>{});
    bool stable = true;
    if(sorted) {
        for(int i = 0; i < list.size(); ++i) {
            int j = i+1;
            while(stable && j < list.size() && list[j] == list[i]) {
                if(list[j-1].pos >= list[j].pos) {
                    stable = false;
                }
                ++j;
            }
            if(!stable) break;
        }
    }
    return (sorted && stable);
}
bool is_stable_sorted(const std::vector<StableChar>& list, bool descending) {
    bool sorted = (!descending) ? std::is_sorted(list.begin(), list.end()) : std::is_sorted(list.begin(), list.end(), std::greater<>{});
    bool stable = true;
    if(sorted) {
        for(int i = 0; i < list.size(); ++i) {
            int j = i+1;
            while(stable && j < list.size() && list[j] == list[i]) {
                if(list[j-1].pos >= list[j].pos) {
                    stable = false;
                }
                ++j;
            }
            if(!stable) break;
        }
    }
    return (sorted && stable);
}
bool is_stable_sorted(const std::vector<StableString>& list, bool descending) {
    bool sorted = (!descending) ? std::is_sorted(list.begin(), list.end()) : std::is_sorted(list.begin(), list.end(), std::greater<>{});
    bool stable = true;
    if(sorted) {
        for(int i = 0; i < list.size(); ++i) {
            int j = i+1;
            while(stable && j < list.size() && list[j] == list[i]) {
                if(list[j-1].pos >= list[j].pos) {
                    stable = false;
                }
                ++j;
            }
            if(!stable) break;
        }
    }
    return (sorted && stable);
}

/**** Student Tests Here ****/
/* Feel free to write your own tests here! */
