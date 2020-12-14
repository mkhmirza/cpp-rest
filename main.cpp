#include<cpprest/http_client.h>
#include<cpprest/filestream.h>

// Common utilities like string conversions
using namespace utility;                   

// Common features like URIs.
using namespace web;

// Common HTTP functionality                         
using namespace web::http;

// HTTP client features   
using namespace web::http::client;


int main(int argc, char* argv[])
{

    try {

    
        // request information by localhost:3000
        http_client client(U("http://127.0.0.1:3000/"));

        // create a client block which is using GET method and respondes with
        // a json object containing information
        client.request(methods::GET).then( [=](http_response res)
        {
            web::json::value response;
            // check if the status code is OK (200)
            if (res.status_code() ==  web::http::status_codes::OK){
                printf("Recieved Response Status: %u\n", res.status_code());

                // extracting json object
                response = res.extract_json().get();
                
                // printing json object using std output
                std::cout << response << std::endl;
            }

        }).wait();
    
    } catch(std::exception &e){
        printf("Error : %s\n",e.what());
    }



    return 0;
}