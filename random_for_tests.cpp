#include "random_for_tests.h"


std::default_random_engine &global_urng()
{
    static std::default_random_engine u{};
    return u;
}

void randomize()
{
    static std::random_device rd{};
    global_urng().seed(rd());
}

int pick(int l, int r)
{
    static std::uniform_int_distribution<> d{};
    using parm_t = decltype(d)::param_type; //не парся, скомпилит)))
    return d(global_urng(),parm_t{l,r});
}

double pick(double l, double r)
{
    static std::uniform_real_distribution<> d{};
    using parm_t = decltype(d)::param_type; //не парся, скомпилит)))
    return d(global_urng(),parm_t{l,r});
}
