#include <iostream>
#include <cpr/cpr.h>

using namespace std;

int main()
{
    cpr::Response r = cpr::Get(cpr::Url("https://httpbin.org/html"),
        cpr::Header({{"accept", "text.html"}}));

    for(int i = (r.text.find("<h1>") + 4); i != r.text.find("</h1>"); ++i)
        std::cout << r.text[i];
    std::cout << std::endl;
    return 0;
}
