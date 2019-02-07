/* 
So the commands I have described in exercise2 are applied to this as well. 
In this implementation,you are going to have two std::queue type variables, Engine work queue and clean work queue.
Engine and the cleaning crew should be represented by one thread each, not from the one function as we done before.

These threads should run itaratively while checking for done flag, which should be set upon the user
request from the console which is the input 100 to stop. In each iteration each thread check corresponding
queue for a work.

You can put command from the main thread to each corresponding queue.
If the running thread finds any command in the corresponding queue it should execute the command and
sleep for one second. If not thread should sleep for two seconds. 

Note in this implementation,captain does not have to wait for any command to finish and he should spend one second at least between
two commands.
*/

#include <iostream>
#include <thread>
#include <queue>

class thread_guard
{
    std::thread &m_thread;

  public:
    thread_guard(std::thread &t) : m_thread(t) {}

    ~thread_guard()
    {
        if (m_thread.joinable())
            m_thread.join();
    }
};

void cleanShip()
{
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 0; i < 4; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        printf("Cleaning %d, ", i);
    }
    printf("\nCleaned the ship from thread %u\n", std::this_thread::get_id());
    printf("\n");
}

void throttleFullSpeed(auto it)
{
    for (int i = 0; i < 4; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        printf("raising speed %d, ", i);
    }
    printf("\nFull speed from thread %u\n", std::this_thread::get_id());
}

void stopEngine(auto it)
{
    for (int i = 0; i < 4; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        printf("raising speed %d, ", i);
    }
    printf("\nEngine stopped from thread %u\n", std::this_thread::get_id());
}

void drive()
{
    for (int i = 0; i < 4; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        printf("driving %d, ", i);
    }

    printf("\nDrive complete from thread %u\n", std::this_thread::get_id());
    printf("\n");
}

int main()
{
    std::queue<int> engineWork_q;
    std::queue<int> cleanerWork_q;

    int command = 0;

    while (command != 100)
    {
        std::cin >> command;

        if (command == 1)
        { //cleaning
            cleanerWork_q.push(1);
            std::thread Cleaners(cleanShip, 1);
            Cleaners.detach();
        }
        else if (command == 2)
        { //full speed
            engineWork_q.push(2);
        }
        else if (command == 3)
        { //stop engine
            engineWork_q.push(3);
        }
        else if (command != 100)
        {
            printf("invalid input\n");
        }
        
        std::thread EngineCrew( throttleFullSpeed, *(engineWork_q.pop()) );
        thread_guard tg(EngineCrew);

        std::thread EngineCrew(stopEngine, 3);
        thread_guard tg(EngineCrew);

        //captain functions - main thread
        drive(); //can be improved here, if engine stops captain should not be able to drive
    }

    return 0;
}
