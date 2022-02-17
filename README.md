## Question 1
First counter:
Elapsed time is 1464222ms

Secound counter:
Elapsed time is 22786ms

Third counter:
Elapsed time is 21860ms


Conclusion:

If we modify the function to make better use of cache, we would get a better result.
The first method did not make good use of cache. We would get a much better result.
The second method applied hashing, so that caches can be utilized better.
However the cache was false sharing, because 2 threads can fall in the same cache line and invalidate each other,
so we tried padding in the third counter, which got us a best result.

I think results would be different on other computers.
How multiple threads interact with each other is undetermined, so it is difficult to have the same amount of time.
Also, different processor might also have different cache line, this padding is not compatiable.


## Question 2
I think using jthread is much easier as it joins on destruction by default. This help avoid potential bugs.

I applied jthread with github link: https://github.com/josuttis/jthread. For submission I commented out the package reference.


