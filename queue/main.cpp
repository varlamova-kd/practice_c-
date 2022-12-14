#include <string>
#include <vector>
#include <manager.h>

/*Реализовать класс менеджер потоков для различных задач. Класс должен принимать вектор «задач» - допустим это будут std::string.
 *  выбирать 2 «задачи» с наибольшим числом символов и выделять ей поток. При каждом добавлении вектора —
 *  происходит выделение потоков двум задачам, остальные задачи хранятся в пуле задач. Вектор может содержать 0-10 элементов.*/

int main()
{
    std::vector<std::string> v1 = {"aa", "bb", "c", "ngnhkn"};
    std::vector<std::string> v2 = {"ku"};
    Manager man1 = Manager(v1);
    Manager man2 = Manager(v2);
    Manager man3 = Manager({});
    man1.choice();
    man2.choice();
    man3.choice();
    return 0;
}
