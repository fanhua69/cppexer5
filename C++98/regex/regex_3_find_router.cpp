//
//  regex_3_find_router.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-03.
//

#include <stdio.h>
#include "headers.h"
#include <regex>
#include <functional>

namespace regex
{

    struct Request {

        // request method, POST, GET; path; HTTP version
        std::string method, path, http_version;

        // use smart pointer for reference counting of content:
        std::shared_ptr<std::istream> content;

        // hash container, key-value dict:
        std::unordered_map<std::string, string> header;

        // use regular expression for path match:
        std::smatch path_match;
    };

    typedef std::map<string, unordered_map<string, std::function<void (ostream&, Request&)>>> resource_type;

    template <typename socket_type>
    class ServerBase
    {
        public:
            resource_type resource;
            resource_type default_resource;

            void start() {

            }

        protected:
            Request parse_request(std::istream &stream) const
            {

            }

    };


    template <typename SERVER_TYPE>
    void start_server(SERVER_TYPE &server)
    {
        // process GET request for /match/[digit+numbers],
        // e.g. GET request is /match/abc123, will return abc123
        server.resource["fill_your_reg_ex"]["GET"] =
            [](ostream &response, Request& request)
            {
                string number = request.path_match[1];
                response << "HTTP/1.1 200 OK\r\nContent-Length: "
                            << number.length() << "\r\n\r\n" << number;
            };

        // Process default GET request;
        // anonymous function will be called
        // if no other matches response files in folder web /
        // default : index.html
        server.default_resource["fill_your_reg_ex"]["GET"] =
            [](ostream &response, Request& request)
            {
                string filename = "www/";
                string path = request.path_match[1];

                // forbidden use `..` access content outside folder web/
                size_t last_pos = path.rfind(".");
                size_t current_pos = 0;
                size_t pos;

                while((pos = path.find('.', current_pos)) != string::npos && pos != last_pos)
                {
                    current_pos = pos;
                    path.erase(pos,1);
                    last_pos--;
                }
            };

        server.start();

    }





}
