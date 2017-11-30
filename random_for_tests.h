#ifndef RANDOM_FOR_TESTS_H
#define RANDOM_FOR_TESTS_H
#include <random>
/* 4 функции для работы с генератором сл.чисел
 * используй randomize если хочешь невоспроизводимый
 * результат, т.е пока НЕ ИСПОЛЬЗУЙ randomize вообще
 * все что нужно для счастья - pick - возвращает случайное
 * в диапазонах [l,r);
 */

std::default_random_engine& global_urng();
void randomize();
int pick(int l, int r);
double pick(double l, double r);


#endif // RANDOM_FOR_TESTS_H
