1.
Single Thread Version
	Main Thread time: 0.000312s

Multi Thread Version
	Main Thread time: 3.839681s
	Thread 1 time: 2.820138s
	Thread 2 time: 3.839490s

2. No, the main thread time was only .0002 seconds longer than thread 2 time, so the combination of both thread 1 and thread 2 times exceed the main threads time.

3. Single Thread, because multithreading requires more threads (more space and time) and exchanging information between threads requires more time.

4. Which thread prints first is uncontrollable.
