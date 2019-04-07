#ifndef RAND_NUM_PAIR_HPP_INCLUDED
#define RAND_NUM_PAIR_HPP_INCLUDED

namespace RandomNumberPair {

    static long long seed = 12345;   /**< Зерно  */

    /** \brief Установить зерно генератора случайных чисел
     * \param _seed Зерно
     */
    inline void set_rand_seed(long _seed) {
        seed = _seed;
    }

    /** \brief Получить случайное число для пары чисел
     * \param x Первое число из пары
     * \param y Второе число из пары
     * \return случайное число
     */
    double get_from_pair(long long x, long long y) {
        long long xm7;
        long long xm13;
        long long xm1301081;
        long long ym8461;
        long long ym105467;
        long long ym105943;
    	for(char i = 0; i < 80; ++i) {
            xm7 = x % 7;
            xm13 = x % 13;
            xm1301081 = x % 1301081;
            ym8461 = y % 8461;
            ym105467 = y % 105467;
            ym105943 = y % 105943;
            y = x + seed;
            x += (xm7 + xm13 + xm1301081 + ym8461 + ym105467 + ym105943);
        }
        return (double)(xm7 + xm13 + xm1301081 + ym8461 + ym105467 + ym105943) / 1520972.0;
    }

    long long get_hash(long long x, long long y) {
        long long xm7;
        long long xm13;
        long long xm1301081;
        long long ym8461;
        long long ym105467;
        long long ym105943;
        for(char i = 0; i < 80; ++i) {
            xm7 = x % 7;
            xm13 = x % 13;
            xm1301081 = x % 1301081;
            ym8461 = y % 8461;
            ym105467 = y % 105467;
            ym105943 = y % 105943;
            y = x + seed;
            x += (xm7 + xm13 + xm1301081 + ym8461 + ym105467 + ym105943);
        }
        return (xm7 + xm13 + xm1301081 + ym8461 + ym105467 + ym105943) & 2097151;
    }

}

#endif // RAND_NUM_PAIR_HPP_INCLUDED
