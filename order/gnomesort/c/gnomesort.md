#地精排序Gnome Sort

>>>The simplest sort algorithm is not Bubble Sort..., it is not Insertion
Sort..., it's Gnome Sort!

号称最简单的排序算法,只有一层循环,默认情况下前进冒泡,一旦遇到冒泡的情
况发生就往回冒,直到把这个数字放好为止

直接看它排序的过程,待排数组[6 2 4 1 5 9]

先设计一个标识i=0然后从头开始判断,什么时候(i < 6)不成立,什么时候排序结束,

所以,如何控制i的值是这个算法的关键

例如待排数组:

[6 2 4 1 5 9]

[0 1 2 3 4 5]

 

看一下具体的排序过程

[ i = 0 ]时啥也不干,先让i自增1,达到值为1才开始真正的比较

交换前[6 2 4 1 5 9][ i = 0]

交换后[6 2 4 1 5 9][ i = 1]

 

[ i = 1 ]比较6和2,发生交换,只要发生交换i就减1

交换前[6 2 4 1 5 9][ i = 1]

交换后[2 6 4 1 5 9][ i = 0]

 

[ i = 0 ]又成0了,啥也不干,自增变成1再说

交换前[2 6 4 1 5 9][ i = 0]

交换后[2 6 4 1 5 9][ i = 1]

 

[ i = 1 ]再比较2和6,不交换,只要不要换就自增1

交换前[2 6 4 1 5 9][ i = 1]

交换后[2 6 4 1 5 9][ i = 2]

 

[ i = 2 ]比较6和4,发生交换,只要交换就减1

交换前[2 6 4 1 5 9][ i = 2]

交换后[2 4 6 1 5 9][ i = 1]

 

[ i = 1 ]比较2和4,不交换,只要不交换就自增1

交换前[2 4 6 1 5 9][ i = 1]

交换后[2 4 6 1 5 9][ i = 2]

 

[ i = 2 ]比较4和6,不交换,只要不交换就自增1

交换前[2 4 6 1 5 9][ i = 2]

交换后[2 4 6 1 5 9][ i = 3]

 

[ i = 3 ]比较6和1,交换,只要交换就减1

交换前[2 4 6 1 5 9][ i = 3]

交换后[2 4 1 6 5 9][ i = 2]

 

[ i = 2 ]比较4和1,交换,只要交换就减1

交换前[2 4 1 6 5 9][ i = 2]

交换后[2 1 4 6 5 9][ i = 1]

 

[ i = 1 ]比较2和1,交换,只要交换就减1

交换前[2 1 4 6 5 9][ i = 1]

交换后[1 2 4 6 5 9][ i = 0]

 

[ i = 0 ]时啥也不干,先让i自增1,达到值为1才开始真正的比较

交换前[1 2 4 6 5 9][ i = 0]

交换后[1 2 4 6 5 9][ i = 1]

[ i = 1]比较1和2,不交换,只要不交换就自增1

[ i = 2]比较2和4,不交换,只要不交换就自增1

[ i = 3]比较4和6,不交换,只要不交换就自增1

[ i = 4]比较6和5,交换,只要交换就减1

交换前[1 2 4 6 5 9][ i = 4]

交换后[1 2 4 5 6 9][ i = 3]

[ i = 3]比较4和5,不交换,只要不交换就自增1

[ i = 4]比较5和6,不交换,只要不交换就自增1

[ i = 5]比较6和9,不交换,只要不交换就自增1

[ i = 6]表达式(i < n)不成立,排序结束,

顺序输出结果即可:[ 1 2 4 5 6 9]

