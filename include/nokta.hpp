
#ifndef nokta_hpp
#define nokta_hpp
using namespace std;
class Nokta
{
public:
    Nokta(int x, int y, int z);
    ~Nokta();
    int orjinUzaklik(int x, int y, int z);
    int veri;
    Nokta *sonraki;
    Nokta *onceki;
    int x;
    int y;
    int z;
    

private:
};
#endif
