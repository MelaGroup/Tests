#include <QString>
#include <QtTest>
#include <../random_for_tests.h>
#include <../../SLib/slinearalgebra.h>

class Test_slinearalgebra : public QObject
{
    Q_OBJECT

public:
    Test_slinearalgebra();

private:


private Q_SLOTS:
    // здесь пишется сигнатура метода - теста
    void test_sort();
};

Test_slinearalgebra::Test_slinearalgebra()
{
    /* Сюда можно писать инициализацию элементов как
     * и в любой другой конструктор.*/
}
/* Тестирование проводится для каждого НЕТРИВИАЛЬНОГО метода
 * Например смотреть на операторы +,- и * бессмыслено т.к
 * они слишком просты, а вот функцию sort можно.
 * Функция sort сортирует компаненты вектора по убыванию,
 * это важно при упорядочивании главных компанент матрицы
 * по степени информативности*/

//здесь реализация методов - тестов
void Test_slinearalgebra::test_sort()
{
    for (int i=0;i<50;++i)
    {
        //Генерация случайного (воспроизводимого) вектора
        SVector_3D vec{pick(-50.,50.),pick(-50.,50.),pick(-50.,50.)};
        vec.sort();//выполняем сортировку
        //проверка выполения условия
        QVERIFY(vec.x >= vec.y && vec.y >= vec.z);
    }
    // В итоге мы проверили сортировку на 50 случайных векторах
}
/* Далее переходим к тестированию SMatrix_3x3
 * Сложных методов здесь гораздо больше и это:
 *  -VieteCardanoMethod()
 *  -operator*()
 *  -eigenvalues()
 *  -eigenvectors()
 * Так же тут есть особенность с индексацией строк и столбцов:
 * для внутренней матрицы 0,1,2 а для пользователя 1,2,3, так
 * что не запутайся
 *
 * И еще пару строк
 * -новый тест пишется под private Q_SLOTS:
 * -его название void test_METHODNAME()
 * -макросы типа QVERIFY описаны на http://doc.qt.io/qt-5/qtest.html
 * например QCOMPARE
 * -используй интернет калькуляторы для составления примеров:
 * например VieteCardanoMethod(-6,11,-6) должен давать 1,2,3 в неизвестном порядке
 * обрати внимание что main() нет - тем не менее если ты запустишь
 * ты получишь лог в выводе приложения
 *
 * Когда все сделаешь удали все комменты))
 */


QTEST_APPLESS_MAIN(Test_slinearalgebra)

#include "tst_test_slinearalgebra.moc" // не парся
