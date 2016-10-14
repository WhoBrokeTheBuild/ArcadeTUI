#ifndef ARGS_HPP
#define ARGS_HPP

#include <ArcadeTUI/Types.hpp>

struct Args 
{
    string Socket = "arcadetui.sock";
};

Args parse_args(int argc, char** argv)
{
    Args args;
    for (int i = 0; i < argc; ++i) {
        string arg = string(argv[i]);
        string val = (i + 1 < argc ? argv[i + 1] : "");

        if (arg[0] == '-') {
            if (arg[1] == '-') {
                if (arg == "socket") {
                    args.Socket = val;
                }
            }
            else {
                switch (arg[1]) {
                case 's':
                    args.Socket = val;
                    break;
                }
            }
        }
    }
    return args;
}

#endif // ARGS_HPP
