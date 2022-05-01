#include <iostream>
using namespace std;

class Test {
    public :
        int x;
        Test(int _x)
        {
            x = _x;
        }
        
};

int main()
{
    Test my_test(5);
    cout<<my_test.x;
    return 0;
}