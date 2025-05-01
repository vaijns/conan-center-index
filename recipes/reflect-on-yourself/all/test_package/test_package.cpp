#include <reflect-on-yourself.hpp>

#include <cstdint>
#include <string>
#include <optional>
#include <iostream>

struct user{
    std::uint64_t id;
    std::string email;
    std::optional<std::string> name;
};

template<> struct roy::provide_reflection<user>
    : roy::reflection::for_type<user>
        ::with_default_builders
        ::with_auto_name
        ::with_fields<
            roy::reflection::for_field<&user::id>
                ::with_default_builders
                ::with_auto_name
                ::result,
            roy::reflection::for_field<&user::email>
                ::with_default_builders
                ::with_auto_name
                ::result,
            roy::reflection::for_field<&user::name>
                ::with_default_builders
                ::with_auto_name
                ::result
        >
        ::result{};

int main(int argc, char* argv[]){
    std::cout << roy::reflection_of<user>::name() << "\n";
    return 0;
}
