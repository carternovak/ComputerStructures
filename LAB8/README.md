1. Just 2: 
"A"
"B"

2. It kept running, waiting for the last thread to call the third function, but since 
semaphore is 0 (because it was initialized as 2 and has been decremented twice at this point)
it cannot decrement the value in the third function and then proceed with the function.
Semaphore must be incremented one more time to call the third function.

3.
sem_post(&semaphore); // FIX for code issue
