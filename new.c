#include "stdio.h"

//session 1：数组和int的联合确保数组a是按照int的4字节对齐的
//所以a+1的地址肯定不是字对齐的。
union BusError{
 char a[10];
 int i;
};

int main(int argc, char* argv[])
{
 printf("Hello World!/n");

 union BusError u;
 int *p = &(u.i);
 //session 2：然后试图往这个地址存储4个字节的数据，但这个访问只是按照单字节的char对齐
 //所以会引发总线错误
 //但是很遗憾，在vc中并未提示是总线错误
 //但也很庆幸，gcc中会提示你 bus error（core dump） 总线错误（信息已转储）
 //gcc将你从地址拉回天堂，我们应该感谢它
 *p = 16;

 printf("bus error ? a[1]-a[4]=>*p = %d/n", *p);

 //conclusion:总线错误几乎都是由于未对齐的读或写引起的。
 //它之所以称为总线错误，是因为出现未对齐的内存访问请求时，被堵塞的组件就是地址总线。
 //对齐的意思就是数据项只能存储在地址是数据项大小的整倍数的内存位置上。
 //页和cache的大小都是经过精心设计的，这样只要遵守对齐规则就可以保证一个原子数据项
 //不会跨过一个页或cache块的边界。

 //总线错误也有可能由于引用一块物理上不存在的内存引起。

 return 0;
}
