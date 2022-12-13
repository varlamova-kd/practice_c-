#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <queue>

/*Реализовать класс менеджер потоков для различных задач. Класс должен принимать вектор «задач» - допустим это будут std::string.
 *  выбирать 2 «задачи» с наибольшим числом символов и выделять ей поток. При каждом добавлении вектора —
 *  происходит выделение потоков двум задачам, остальные задачи хранятся в пуле задач. Вектор может содержать 0-10 элементов.*/

using namespace std;

class Compare
{
public:
    bool operator() (const string& s1,const string& s2)
    {
        if (s1.size() < s2.size())
            return true;
        else
            return false;
    }
};

void do_task(int i)
{
    cout << "task " << i+1 << " done!" << endl;
}

class Manager
{
private:
    vector<string> input;
    priority_queue<string, vector<string>, Compare> pool;
    string top1, top2;
public:
    Manager(vector<string> Inp)
    {
        input = Inp;
        pool = {};
        top1 = "";
    }

    void choice()
    {
        //находим задачи для потоков
        for (size_t i = 0; i<input.size(); i++)
        {
            pool.push(input[i]);
        }
        if (pool.empty())
            cout << "Not enough tasks in the pool" << endl;
        else
        {
            for (size_t i = 0; i<2; i++)
            {
                if (i == 1 && pool.empty())
                    cout << "Not enough tasks in the pool" << endl;
                else
                {
                    top1 = pool.top();
                    pool.pop();
                    thread thr(do_task, i); //выделяем поток
                    thr.join();
                }
            }
            cout << pool.top() << endl; //просто для проверки
        }
    }
};

int main()
{
    vector<string> v1 = {"aa", "bb", "c", "ngnhkn"};
    vector<string> v2 = {"ku"};
    Manager man1 = Manager(v1);
    Manager man2 = Manager(v2);
    Manager man3 = Manager({});
    man1.choice();
    man2.choice();
    man3.choice();
    return 0;
}
