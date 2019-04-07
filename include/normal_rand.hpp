#ifndef NORMAL_RAND_HPP_INCLUDED
#define NORMAL_RAND_HPP_INCLUDED

namespace NormalRand {
    const int RAND_NTAB = 32;
    const int RAND_NWUP = 8;
    const float RAND_EPS = 1.2e-7;
    const float RAND_RNMX = (1.0 - RAND_EPS);
    const long RAND_IM1 = 2147483563;
    const long RAND_IM2 = 2147483399;
    const float RAND_AM = (1./RAND_IM1);
    const long RAND_IMM1 = (RAND_IM1-1);
    const long RAND_IA1 = 40014;
    const long RAND_IA2 = 40692;
    const long RAND_IQ1 = 53668;
    const long RAND_IQ2 = 52774;
    const long RAND_IR1 = 12211;
    const long RAND_IR2 = 3791;
    const long RAND_NDIV = (1 + RAND_IMM1 / RAND_NTAB);

    static long iy = 0;
    static long iv[RAND_NTAB];
    static long dummy2 = 123456789;

    static long rand_dummy = 12345;            /**< Зерно */

    /** \brief Очистить внутреннее состояние генератора случайных чисел
     */
    inline void clear_rand() {
        for(int i = 0; i < RAND_NTAB; ++i) {
            iv[i] = 0;
        }
        iy = 0;
        dummy2 = 123456789;
    }

    /** \brief Установить зерно генератора случайных чисел
     * \param dum Зерно
     */
    inline void set_rand_seed(long dum) {
        clear_rand();
        rand_dummy = dum;
    }

    /** \brief Cлучайная стандартная нормально распределённая величина типа float
     * \return Вернет случайную стандартную нормально распределённую величину типа float
     */
    float standard_variate() {
        int j;
        long k;
        static long dummy2 = 123456789;
        float temp;
        if(rand_dummy <= 0 || !iy) {
            if(rand_dummy < 0) {
                rand_dummy = -rand_dummy;
            } else if(rand_dummy == 0) {
                rand_dummy = 1;
            }
            dummy2 = rand_dummy;
            for(j = RAND_NTAB + RAND_NWUP - 1; j >= 0; j--) {
                k = rand_dummy / RAND_IQ1;
                if((rand_dummy = RAND_IA1 * (rand_dummy - k * RAND_IQ1) - RAND_IR1*k) < 0) {
                    rand_dummy += RAND_IM1;
                }
                if(j < RAND_NTAB) {
                    iv[j] = rand_dummy;
                }
            }
            iy = iv[0];
        }
        k = rand_dummy / RAND_IQ1;
        if((rand_dummy = RAND_IA1 * (rand_dummy - k * RAND_IQ1) - RAND_IR1 * k) < 0) {
            rand_dummy += RAND_IM1;
        }
        k = dummy2 / RAND_IQ2;
        if((dummy2 = RAND_IA2 * (dummy2 - k * RAND_IQ2) - RAND_IR2 * k) < 0) {
            dummy2 += RAND_IM2;
        }
        iy = iv[j = iy / RAND_NDIV] - dummy2;
        iv[j] = rand_dummy;
        if(iy < 1) {
            iy += RAND_IMM1;
        }
        if((temp = RAND_AM * iy) > RAND_RNMX) {
            return RAND_RNMX;
        }
        return temp;
    }

    /** \brief Получить случайное число из интервала
     * \param m начало интервала
     * \param n конец интервала
     * \return Вернет число из интеравала от m до n
     */
    long random_number(long m, long n) {
        return (standard_variate() * (n - m + 1)) + m;
    }
};

#endif // NORMAL_RAND_HPP_INCLUDED
