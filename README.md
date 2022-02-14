## Question 1
First counter:
Elapsed time is 1464222ms

Secound counter:
Elapsed time is 22786ms

Third counter:
Elapsed time is 25513ms

Reason: If we modify the cache in the first method, we would get a much better result.1
However the cache line was false sharing, so we tried padding in the third counter.
Somehow different computer hardware has different cache line, this padding is not compatiable with my own computer

## Question 2
I think using jthread is much easier and time saving.
Result for counter1:
Count is 100000000
Elapsed time is 5161ms

I applied jthread with github link: https://github.com/josuttis/jthread.


