#include <string>

class Compare
{
public:
    bool operator() (const std::string& s1,const std::string& s2)
    {
        if (s1.size() < s2.size())
            return true;
        else
            return false;
    }
};
