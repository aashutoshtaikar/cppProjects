#include <iostream>
#include <thread>

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

void throttleFullSpeed()
{
    for (int i = 0; i < 4; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        printf("raising speed %d, ", i);
    }
    printf("\nFull speed from thread %u\n", std::this_thread::get_id());
}

void stopEngine()
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
    int command = 0;

    while (command != 100)
    {
        std::cin >> command;

        if (command == 1)
        { //cleaning
            std::thread Cleaners(cleanShip);
            Cleaners.detach();
        }
        else if (command == 2)
        { //full speed
            std::thread EngineCrew(throttleFullSpeed);
            EngineCrew.join();
            //thread_guard tg(EngineCrew);
        }
        else if (command == 3)
        { //stop engine
            std::thread EngineCrew(stopEngine);
            thread_guard tg(EngineCrew); //improved by RAII
        }
        else if (command != 100)
        {
            printf("invalid input\n");
        }

        //captain functions - main thread
        drive(); //can be improved here, if engine stops captain should not be able to drive
    }

    return 0;
}
