# random_generator_cpp
Различные алгоритмы генераторов случайных чисел и прочего

### Описание

Данная *header-only* библиотека содержит различные алгоритмы генераторов случайных чисел. 

На данный момент поддерживается:

* генератор случайной стандартно нормально распределённой величины
* генератор случайной величины на основе пары чисел

### Как пользоваться?

```C++
#include "normal_rand.hpp"
#include "rand_num_pair.hpp"

\\...

std::cout << "NormalRand" << std::endl;
NormalRand::set_rand_seed(123);
for(int i = 0; i < 10; ++i) {
	std::cout << NormalRand::standard_variate() << std::endl;
}

std::cout << "RandomNumberPair" << std::endl;
RandomNumberPair::set_rand_seed(123);
std::cout << RandomNumberPair::get_from_pair(101, 555) << std::endl;
std::cout << RandomNumberPair::get_from_pair(101, 555) << std::endl;
std::cout << RandomNumberPair::get_from_pair(55, 77) << std::endl;

```
