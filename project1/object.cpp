#include<vector>
#include<string>

using namespace std;

struct pos
{
    int x;
    int y;
};
class object
{
    public:
    int type;
    int (*feature[128])(void);
    
};