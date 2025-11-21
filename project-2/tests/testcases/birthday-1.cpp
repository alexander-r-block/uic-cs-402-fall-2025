#include <functional>
#include <random>

// todo: both bd1 and bd2, get large list of primes to sample from to choose random hash functions



std::vector<unsigned int> birthday_attack_1(std::function<unsigned short(unsigned int)> hash_function);

const std::vector<unsigned int> primes = {
    2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 15013, 15017, 15031, 15053, 15061, 15073, 15077, 15083, 15091, 15101, 15107, 15121, 15131, 15137, 15139, 15149, 15161, 15173, 15187, 15193, 15199, 15217, 15227, 15233, 15241, 15259, 15263, 15269, 15271, 15277, 15287, 15289, 15299, 15307, 15313, 15319, 15329, 15331, 15349, 15359, 15361, 15373, 15377, 15383, 15391, 15401, 15413, 15427, 15439, 15443, 15451, 15461, 15467, 15473, 15493, 15497, 15511, 15527, 15541, 15551, 15559, 15569, 15581, 15583, 15601, 15607, 15619, 15629, 15641, 15643, 15647, 15649, 15661, 15667, 15671, 15679, 15683, 15727, 15731, 15733, 15737, 15739, 15749, 15761, 15767, 15773, 15787, 15791, 15797, 15803, 15809, 15817, 15823, 15859, 15877, 15881, 15887, 15889, 15901, 15907, 15913, 15919, 15923, 15937, 15959, 15971, 15973, 15991, 16001,
};


unsigned int my_sample_int() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(0);
    return dist(mt);
}

int main() {
    double total_score = 20.0;
    double score = 0.0;

    unsigned int n = primes.size();

    int runs = 0;
    int runs_upper = 5;

    for(int i = 0; i < 20;) {
        unsigned int a = my_sample_int() % n;
        unsigned int b = my_sample_int() % n;
        while(a == b) {
            b = my_sample_int() % n;
        }

        a = primes[a];
        b = primes[b];

        std::function<unsigned short(unsigned int)> hash = [&a, &b](unsigned int x) -> unsigned short {return static_cast<unsigned short>(a*(x<<2)+b);};

        std::vector<unsigned int> result = birthday_attack_1(hash);
        if(result.size() != 2) {
            if(runs == runs_upper) {
                ++i;
                runs = 0;
            }
            else ++runs;
            continue;
        }
        if(hash(result[0]) == hash(result[1]) && result[0] != result[1]) {
            ++score;
            ++i;
        }
    }

    RESULT(100*(score / total_score));

    return 0;
}
