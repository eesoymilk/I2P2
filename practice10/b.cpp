#include <string>

void
IdiotSandwich::print(std::ostream &out)
{
    out << "An idiot sandwich with intelligence level " << getINT() << " only.";
}
void NormalSandwich::print(std::ostream &out)
{
    out << getName() << ". Masterpiece of sandwiches.";
}
Dish::~Dish() { delete food; }
std::istream & operator >> (std::istream &in, Dish &d)
{
    std::string s;
    in >> s;
    if(s != "Ramsay") d.food = new NormalSandwich(s);
    else
    {
        int x;
        in >> x;
        d.food = new IdiotSandwich(x);
    }
    return in;
}