/*Introduction to Circular Queue in Data Structures
We have completed learning the basics of queues and its operations so far. Before proceeding to the next section, let's catch up on what we covered in queues. Using a real-life example, we explored the meaning of queue. We learn that it follows the FIFO principle. We implemented a queue ADT and its basic operations using arrays. We wrote their code in C.


When we discussed queues, we decided to have two index variables f and r, which would maintain the two ends of the queue. If we follow the illustration below, we would see that our queue gets full when element 8 is pushed in the queue. In other words, we can only enqueue in a queue until the queue isn't full.



Figure 1: Using two integer variables to maintain the ends of a queue

Now, we start dequeuing some elements. Let’s remove the first three elements. And now, if you carefully observe, our queue is still full since the rear end is at the array’s threshold. But technically, it has space worth three elements left. And this is one characteristic cum drawback of a linear/normal queue when implemented using arrays. We don’t get to efficiently utilize the space acquired by the array in the heap. Here the remaining three spaces remain unused for the whole time.

 



Figure 2:  Dequeuing leaves vacant spaces behind

When we talk about utilizing these spaces rather than letting them go unused, we introduce circular queues.

Let’s now see how we can eliminate this drawback and what modifications this situation calls for.

1. One optimizing call would be to reset f and r to -1 whenever the queue becomes empty, or in other words, they both become equal. This makes all the space in the array reusable. Here, the queue was full since r equals the size - 1 of the array. But resetting both the index variables to -1 empties the queue.



Figure 3:  Resetting the index variables to -1

However, the efficiency of this method is limited by the requirement that the front and rear be the same. It is ineffective in the case of figure 2. Therefore we need a more optimized solution. This is when circular queues come to the rescue.

Circular queues:
In circular queues, we mainly focus on the point that we don’t increment our indices linearly. Linearly increasing indices cause the case of overflow when our index reaches the limit, which is size-1. 

In linear increment, i becomes i+1.

But in a circular increment ; i becomes (i+1)%size. This gives an upper cap to the maximum value making the index repeat itself.




And this makes us start from the beginning once we reach the threshold of the array. Refer to the illustration below to visualize the movement of the cursor.



Figure 4:  Conversion of a linear queue to a circular queue

And this is the circular implementation of the same array we used to implement linearly. This allows the leftover spaces to be used again. This wheel type array is called the circular queue.

*/