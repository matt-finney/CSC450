/*
    Matthew Finney
    CSC450 - Module 8
    
    Creates two threads:
    The first thread counts up from 0 to 20. When it reaches 20, it signals the second thread to start counting down from 20 to 0.
    
    https://github.com/matt-finney/CSC450/
*/

public class Module8
{
    // Shared variables for counting and synchronization
    static int counter = 0;
    static boolean reached_goal = false;
    static final Object lock = new Object(); // Creates a lock object to synchronize the threads

    // Function for the first thread to count up
    public static void countUp()
    {
        while (true)
        {
            
            synchronized (lock)
            {
                // Check if the counter has exceeded the goal
                if (counter > 20)
                {
                    break;
                }

                System.out.println("Counting up: " + counter);

                if (counter == 20)
                {
                    // Signal the second thread to start counting down
                    reached_goal = true;
                    lock.notify();
                    break;
                }

                counter++;
            }

            try
            {
                Thread.sleep(200);
            }
            catch (InterruptedException e)
            {
                Thread.currentThread().interrupt();
                return;
            }
        }
    }

    // Function for the second thread to count down
    public static void countDown()
    {
        synchronized (lock)
        {
            while (!reached_goal)
            {
                try
                {
                    lock.wait();
                }
                catch (InterruptedException e)
                {
                    Thread.currentThread().interrupt();
                    return;
                }
            }

            // Count down from 20 to 0
            while (counter >= 0)
            {
                System.out.println("Counting down: " + counter);

                if (counter == 0)
                {
                    break;
                }

                counter--;

                try
                {
                    lock.wait(200);
                }
                catch (InterruptedException e)
                {
                    Thread.currentThread().interrupt();
                    return;
                }
            }
        }
    }

    public static void main(String[] args)
    {
        // Create two threads for counting up and counting down
        Thread thread1 = new Thread(() -> countUp());
        Thread thread2 = new Thread(() -> countDown());

        thread1.start();
        thread2.start();

        try
        {
            thread1.join();
            thread2.join();
        }
        catch (InterruptedException e)
        {
            Thread.currentThread().interrupt();
        }

        System.out.println("Finished!");
    }
}