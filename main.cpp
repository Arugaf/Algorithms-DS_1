#include "stack.h"
#include "queue.h"

int main() {
    Queue<int> queue;
    int n = 0;
    int operation = 0;
    int value = 0;

    std::cin >> n;

    while (n--) {
        std::cin >> operation >> value;

        switch (operation) {
            case 2: {
                if (value != queue.PopFront()) {
                    std::cout << "NO";
                    return 0;
                }

                break;
            }

            case 3: {
                queue.PushBack(value);
                break;
            }

            default: {
                continue;
            }
        }
    }

    std::cout << "YES";

    return 0;
}
