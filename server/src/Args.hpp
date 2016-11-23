#ifndef ARGS_HPP
#define ARGS_HPP

#include <ArcadeTUI/Types.hpp>

struct Args 
{
    string Socket = "arcadetui.sock";
};

Args parse_args(int argc, char** argv);

#endif // ARGS_HPP
