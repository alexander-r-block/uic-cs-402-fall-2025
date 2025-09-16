#include "testing.h"



/* Helper function to print vector */
template<typename T>
void print_list(vector<T>& list) {
    std::cout << "[ ";
    for(T n : list) {
        std::cout << n << ' ';
    }
    std::cout << "]\n";
}


/* Generate shuffled list of integers from 0 to len-1 */
vector<int> gen_unique_list(unsigned int len) {
    vector<int> int_list {};
    for(int i = 0; i < len; i++) {
        int_list.push_back(i+1);
    }

    auto rd = random_device {};
    auto rng = default_random_engine { rd() };

    ranges::shuffle(int_list,rng);

    return int_list;
}

/* Generate random list of integers of size len */
vector<int> gen_random_list(unsigned int len) {

    vector<int> int_list {};

    srand(time({}));
    for(int i = 0; i < len; i++) {
        int_list.push_back(static_cast<int>(rand()));
    }

    return int_list;
}

/* Generate descending list of integers of size len */
vector<int> gen_descending_list(unsigned int len) { 
    vector<int> int_list {};
    srand(time({}));
    int start_int = static_cast<int>( (rand() % len)*((-1)^(rand() % 2))  );
    for(int i = 0; i < len; i++) {
        int_list.push_back(start_int);
        --start_int;
    }

    return int_list;
}

/* Generates a list of ascending integers of size len */
vector<int> gen_ascending_list(unsigned int len) { 
    vector<int> int_list {};
    srand(time({}));
    int start_int = static_cast<int>( (rand() % len)*((-1)^(rand() % 2))  );
    for(int i = 0; i < len; i++) {
        int_list.push_back(start_int);
        ++start_int;
    }

    return int_list;
}


/* Generates an ascending list with 3 random swaps */
vector<int> gen_asending_3swap_list(unsigned int len) {
    vector<int> int_list = gen_ascending_list(len);
    srand(time({}));
    for(int i = 0; i < 3; i++) {
        unsigned int swap_index1 = static_cast<unsigned int>( rand() % len );
        unsigned int swap_index2 = static_cast<unsigned int>( rand() % len );

        int temp = int_list[swap_index1];
        int_list[swap_index1] = int_list[swap_index2];
        int_list[swap_index2] = temp;
    }
}

/* Genarates a list of all equal entries of length len */
vector<int> gen_all_equal_list(unsigned int len) {
    vector<int> int_list = {};
    srand(time({}));
    int choice = static_cast<int>( rand() );
    for(int i = 0; i < len; i++) {
        int_list.push_back(choice);
    }

    return int_list;
}

/* Generates list containing many duplicates of length len */
vector<int> gen_many_dupes_list(unsigned int len) {
    vector<int> int_list = {};
    srand(time({}));
    while(int_list.size() < len) {
        unsigned int num_dupes = static_cast<unsigned int>( rand() % 17 );
        int item = static_cast<int>( rand() );
        for(int j = 0; j < num_dupes && int_list.size() < len; j++) {
            int_list.push_back(item);
        }
    }

    return int_list;
}

/* Generate ascending list with 1% of entries then randomly changed */
vector<int> gen_one_percent_rand_list(unsigned int len) {
    vector<int> int_list = gen_ascending_list(len);

    unsigned int percent = ceil(len*.01);

    srand(time({}));
    for(int i = 0; i < percent; i++) {
        unsigned int index = static_cast<unsigned int>( rand() % len );
        unsigned int value = static_cast<int>( rand() );

        int_list[index] = value;
    }

    return int_list;
}


/**** Student Tests Here ****/
/* Feel free to write your own tests here! */