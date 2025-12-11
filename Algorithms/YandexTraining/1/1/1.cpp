#include <iostream>
#include <string>

int main() {
    int t_room;
    int t_cond;
    std::string regime;

    std::cin >> t_room >> t_cond;
    std::cin >> regime;

    if (regime == "freeze") {
        if (t_room <= t_cond) {
            std::cout << t_room << std::endl;
        } else {
            std::cout << t_cond << std::endl;
        }
    }
    else if (regime == "heat") {
        if (t_room >= t_cond) {
            std::cout << t_room << std::endl;
        } else {
            std::cout << t_cond << std::endl;
        }
    }
    else if (regime == "auto") {
        std::cout << t_cond << std::endl;
    }
    else {
        std::cout << t_room << std::endl;
    }

    return 0;
}


// t_room, t_cond = map(int, input().split())
// regime = input()
// if regime == 'freeze':
// 	if t_room <= t_cond:
// 		print(t_room)
// 	else:
// 		print(t_cond)
// elif regime == 'heat':
// 	if t_room >= t_cond:
// 		print(t_room)
// 	else:
// 		print(t_cond)
// elif regime == 'auto':
// 	print(t_cond)
// else:
// 	print(t_room)