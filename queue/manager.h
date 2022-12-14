#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <queue>
#include <compare.h>
#include <do_task.h>

using namespace std;

class Manager
{
private:
    vector<string> input;
    priority_queue<string, vector<string>, Compare> pool;
    string top1;
public:
    Manager(const vector<string>& Inp)
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
