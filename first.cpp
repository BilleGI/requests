#include <iostream>
#include <cpr/cpr.h>

const std::string httpbin = "http://httpbin.org/";

void registr (std::string& request)
{
    for(int i =0 ; i < request.size(); ++i)
    {
        if(request[i] >= 'A' && request[i] <= 'Z')
            request[i] = std::tolower(request[i]);
    }
}

int main()
{
    std::cout << "Tht program executans various HTTP requests to the service." << std::endl;

    while(true)
    {
        cpr::Response r;
        std::string request;

        std::cout << "List requests: " << std::endl;
        std::cout << "delete" << std::endl;
        std::cout << "get" << std::endl;
        std::cout << "patch" << std::endl;
        std::cout << "post" << std::endl;
        std::cout << "put" << std::endl;

        std::cout << "Enter the request or exet: ";
        std::cin >> request;

        std::string reqURL = httpbin + request;
        if (request == "exet")
            break;
        if(request == "delete")
            r = cpr::Delete(cpr::Url(reqURL));
        else if(request == "get")
            r = cpr::Get(cpr::Url(reqURL));
        else if(request == "patch")
            r = cpr::Patch(cpr::Url(reqURL));
        else if(request == "post")
            r = cpr::Post(cpr::Url(reqURL));
        else if(request == "put")
            r = cpr::Put(cpr::Url(reqURL));

        if(r.status_code == 200)
        {
            std::cout << "Request - " << request << std::endl;
            std::cout << r.text;
        }
        else
            std::cerr << "Error. Pleas, enter the correct request." << std::endl;
        for (int i = 0; i < 50; ++i)
            std::cout << "-";
        std::cout << std::endl;
    }
    return 0;
}
