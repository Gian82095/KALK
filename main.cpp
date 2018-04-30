#include"data.h"

int main()
{
    orario a(12, 20, 20);
    orario b(11, 00, 10);
    orario c(03, 03, 03);
    orario d(01, 01, 01);
    orario e(02, 20, 19);


    data z(29, 02, 2016, 12, 20, 20);
    data w(29, 02, 2016);

    data f(w);

    cout << f;
}
