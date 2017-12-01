#include <QString>
#include <QtTest>
#include <limits>
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
    void test_VieteCardanoMethod();
   // void test_operator_multiply();
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

void Test_slinearalgebra::test_VieteCardanoMethod()
{
    for (int i=0;i<50;++i)
    {
        //Генерация случайного (воспроизводимого) вектора
        SVector_3D vec1{pick(-50.,50.),pick(-50.,50.),pick(-50.,50.)};
        vec1.sort();//выполняем сортировку
        //проверка выполения условия
        SMatrix_3x3 mat(1.);
        mat.a(1,1)=vec1.x;
        mat.a(2,2)=vec1.y;
        mat.a(3,3)=vec1.z;

        SVector_3D roots1=mat.eigenvalues();
        //проверка выполения условия
        using namespace  std;
        const double accurance=1e-7;
        QVERIFY(fabs(vec1.x-roots1.x)<=accurance);
        QVERIFY(fabs(vec1.y-roots1.y)<=accurance);
        QVERIFY(fabs(vec1.z-roots1.z)<=accurance);
    }
}

/*void Test_slinearalgebra::test_operator_multiply()
{
    //первое перемножение
    SMatrix_3x3 mat1({1,4,7},{2,5,8},{7,8,9});// тк смотри 99 строкуSMatrix_3x3::SMatrix_3x3(const SVector_3D &col1, const SVector_3D &col2, const SVector_3D &col3)
    SMatrix_3x3 mat2({10,13,16},{11,14,17},{12,15,18});
    SMatrix_3x3 testmean({84,201,318},{90,216,342},{96,231,366}); // задали вручную, посчитав результат перемноения
    SMatrix_3x3 meanmat;
    meanmat = mat1*mat2;
    //const double accurance=1e-7;
    QVERIFY(meanmat==testmean);//нет оператора равно для этого Smatrix_3ч класса


}*/
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
