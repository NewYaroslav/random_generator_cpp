#include <iostream>
#include "normal_rand.hpp"
#include "rand_num_pair.hpp"

int main()
{
    std::cout << "NormalRand" << std::endl;
    NormalRand::set_rand_seed(123);
    std::cout << "set rand seed: " << NormalRand::rand_dummy << std::endl;
    for(int i = 0; i < 10; ++i) {
        std::cout << NormalRand::standard_variate() << std::endl;
    }
    NormalRand::set_rand_seed(123);
    std::cout << "set rand seed: " << NormalRand::rand_dummy << std::endl;
    for(int i = 0; i < 10; ++i) {
        std::cout << NormalRand::standard_variate() << std::endl;
    }
    NormalRand::set_rand_seed(456);
    std::cout << "set rand seed: " << NormalRand::rand_dummy << std::endl;
    for(int i = 0; i < 10; ++i) {
        std::cout << NormalRand::standard_variate() << std::endl;
    }

    std::cout << "RandomNumberPair" << std::endl;
    RandomNumberPair::set_rand_seed(123);
    std::cout << "set rand seed: " << RandomNumberPair::seed << std::endl;
    std::cout << RandomNumberPair::get_from_pair(101, 555) << std::endl;
    std::cout << RandomNumberPair::get_from_pair(101, 555) << std::endl;
    std::cout << RandomNumberPair::get_from_pair(55, 77) << std::endl;

    std::cout << RandomNumberPair::get_hash(101, 555) << std::endl;
    std::cout << RandomNumberPair::get_hash(55, 77) << std::endl;
    std::cout << RandomNumberPair::get_hash(55, 77) << std::endl;
    return 0;
}
