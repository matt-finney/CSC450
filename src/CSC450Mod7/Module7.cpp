#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

/*
    Matthew Finney
    CSC450 - Module 7
    
    Creates two threads:
    The first thread counts up from 0 to 20. When it reaches 20, it signals the second thread to start counting down from 20 to 0.
    
    https://github.com/matt-finney/CSC450/
*/

// Shared variables for counting and synchronization
int counter = 0;
bool reached_goal = false;

mutex mtx;
condition_variable cv;

// Function for the first thread to count up
void countUp() 
{
    while (true) 
    {
        {
            // Lock the mutex to safely access shared variables
            lock_guard<mutex> lock(mtx);

            // Check if the counter has exceeded the goal
            // if it has, break out of the loop
            if (counter > 20) 
            {
                break;
            }

            cout << "Counting up: " << counter << endl;

            if (counter == 20) 
            {
                // Signal the second thread to start counting down
                reached_goal = true;
                cv.notify_one();
                break;
            }

            counter++;
        }

        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

// Function for the second thread to count down
void countDown() 
{
    // Lock the mutex and wait for the signal from the first thread
    unique_lock<mutex> lock(mtx);

    cv.wait(lock, [] { return reached_goal; });

    // Count down from 20 to 0
    while (counter >= 0) 
    {
        cout << "Counting down: " << counter << endl;

        if (counter == 0) 
        {
            break;
        }

        // Decrement the counter and release the lock before sleeping
        counter--;
        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(200));
        lock.lock();
    }
}

int main() 
{
    // Create two threads for counting up and counting down
    thread thread1(countUp);
    thread thread2(countDown);

    thread1.join();
    thread2.join();

    cout << "Finished!" << endl;
    return 0;
}