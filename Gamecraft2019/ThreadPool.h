#ifndef THREADPOOL_H
#define THREADPOOL_H


/// <summary>
/// Inlined ThreadPool class.
/// Uses std::thread, std::mutex, std::queue.
/// Utilises typedef job function.
/// </summary>

#include <thread>
#include <iostream>
#include <queue>
#include <mutex>
#include <atomic>
#include <vector>

typedef std::function<void()> job;
//typedef void(*jobfunc);

class ThreadPool
{
public:
	/// <summary>
	/// ThreadPool constructor.
	/// Thread_count initialised to max hardware can use.
	/// </summary>
	/// <param name="thread_count"></param>
	ThreadPool(size_t thread_count = std::thread::hardware_concurrency()) :
		isRunning(true),
		njobs(0)
	{
		auto thread_loop = [&](size_t id) {
			//While threadpool is running
			while (isRunning)
			{
				//Lock the thread
				mtx.lock();
				//If there are no functions in the queue
				if (!job_queue.empty())
				{
					//Create function(job) from front of queue
					auto job = job_queue.front();
					//Pop from queue
					job_queue.pop();
					
					//Execute critical section
					job();

					//Unlock the thread
					mtx.unlock();
					//Decrement number of jobs on queue
					njobs--;
				}
				else //If queue is not empty
				{
					//Unlock the thread
					mtx.unlock();
					//Cause thread to wait, allowing other threads to execute
					std::this_thread::yield();
				}
			}
		};
		//Reserve necessary threads in pool
		threads.reserve(thread_count);
		//Loop in range of threads
		for (size_t i = 0; i < thread_count; i++)
		{
			//Push back the needed threads into pool
			threads.push_back(std::thread(thread_loop, i));
		}
	}

	/// <summary>
	/// ThreadPool destructor
	/// </summary>
	virtual ~ThreadPool() 
	{
		//Set loop condition to false
		isRunning = false;
		//Call thread.join for all threads in pool
		for (std::thread& t : threads)
		{
			//Block current thread
			t.join();
		}
	}

	/// <summary>
	/// Adds a function j
	/// to the execution queue
	/// </summary>
	/// <param name="j"></param>
	void addJob(job j)
	{
		//Lock the thread
		mtx.lock();
		//Push new job into queue
		job_queue.push(j);
		//Increment current jobs
		njobs++;
		//Unlock thread
		mtx.unlock();
	}

	/// <summary>
	/// Clears the queue of all functions
	/// </summary>
	void clearJobs()
	{
		//Create new empty queue
		std::queue<job> eq;
		//Lock the thread
		mtx.lock();
		//Rest job count to null
		njobs -= job_queue.size();
		//Swap job queue with empty queue
		std::swap(job_queue, eq);
		//Unlock the thread
		mtx.unlock();
	}

	/// <summary>
	/// Checks if the value of the atomic variable
	/// is greater than zero, and makes the thread
	/// wait.
	/// </summary>
	void wait()
	{
		while (njobs.load() > 0)
		{
			std::this_thread::yield();
		}
	}
private:
	bool isRunning; //Bool to control loop
	std::queue<job> job_queue; //Queue of jobs(functions to be executed)
	std::atomic<size_t> njobs; //Atomic variable to flag number of jobs running
	std::mutex mtx; //Mutual exclusion object for locking threads
	std::vector<std::thread> threads; //Vector thread pool
};

#endif
