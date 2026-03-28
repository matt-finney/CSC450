#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

int counter = 0;
bool reached_goal = false;

mutex mtx;
condition_variable cv;

void countUp() 
{
    while (true) 
    {
        {
            lock_guard<mutex> lock(mtx);

            if (counter > 20) 
            {
                break;
            }

            cout << "Counting up: " << counter << endl;

            if (counter == 20) 
            {
                reached_goal = true;
                cv.notify_one();
                break;
            }

            counter++;
        }

        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void countDown() 
{
    unique_lock<mutex> lock(mtx);

    cv.wait(lock, [] { return reached_goal; });

    while (counter >= 0) 
    {
        cout << "Counting down: " << counter << endl;

        if (counter == 0) 
        {
            break;
        }

        counter--;
        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(200));
        lock.lock();
    }
}

int main() 
{
    thread thread1(countUp);
    thread thread2(countDown);

    thread1.join();
    thread2.join();

    cout << "Finished!" << endl;
    return 0;
}