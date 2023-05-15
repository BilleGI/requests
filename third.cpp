#include <iostream>
#include <cpr/cpr.h>
#include <map>

const std::string http = "http://httpbin.org/";

void regist(std::string& request)
{
    for(int i = 0; i < request.size(); ++i)
    {
        if(request[i] >= 'A' && request[i] <='Z')
            request[i] = std::tolower(request[i]);
    }
}

int main()
{
    std::map<std::string, std::string> arguments;
    std::string request;
    std::cout << "The program sends a get or post request with arguments." << std::endl;

    while(true)
    {
        std::cout << "Enter the argument or get/post for exit: ";
        getline(std::cin, request);
        regist(request);

        if(request == "get" || request == "post")
            break;
        std::cout << "Enter a value: ";

        getline(std::cin, arguments[request]);
    }

    cpr::Response r;
    if(request == "get")
    {
        cpr::Parameters parameters;
        for( auto it = arguments.begin(); it != arguments.end(); ++it )
            parameters.Add({it->first, it->second});
        r = cpr::Get(cpr::Url(http+request), parameters);
    }

    else if(request == "post")
    {
        cpr::Payload pay{};
        for(auto it = arguments.begin(); it != arguments.end(); ++it)
            pay.Add(cpr::Pair(it->first, it->second));

        r = cpr::Post(cpr::Url(http+request), pay);
    }

    if(r.status_code == 200)
        std::cout << r.text;
    else
        std::cerr << "Error!" << std::endl;

    return 0;
}
