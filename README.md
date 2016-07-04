timating PI by shooting on a lake
A few years ago i read an article about estimating PI. <br>
This method uses an algorithm that takes two random coordinates "to shoot on" in a square.<br> After shooting it calculates distance from the botton left edge. If it is below 1.0, we have hit a quarter of a circle in this edge. 
We just count the hits. After a few thousand runs we simply calculate PI with:<br>
+ ``` ((hits/shots)*4.0)```

<br>
On an Intel i5 M520 @ 2.40GHz it takes about 92 seconds to shoot 2,147,483,647 times.
<br><br>
This is an example output of shooter.c:<br>
``` 
$ time ./shooting-pi
doing 2147483647 shots....
seeding RNG with 0x577a239b
0% done.
10% done.
20% done.
30% done.
40% done.
50% done.
60% done.
70% done.
80% done.
90% done.
100% done.
All done, i shot 2147483647 times and hit 1686641737 times (ratio=1:1.273230)
                        I calculated pi to be approx. 3.141615

real    1m32.397s
user    1m32.432s
sys     0m0.012s
```
## References
I can't remember which magazine or book it was, that gave me this article. But I am pretty sure i will find it again one day between all my stuff. This day i will have look, if i can publish it here or just reference it here by name, author and magazine/book.
