//BM63 跳台阶

/*动态规划方法比较：
https://www.bilibili.com/video/BV1AB4y1w7eT/?spm_id_from=333.337.search-card.all.click&vd_source=4ef09d0903f77e434bb290c006ad999c
1.暴力求解
2.递归求解
3.记忆化搜索/带备忘录的递归/递归树的减枝(purning)，使用哈希/数组保存大量重复计算的部分
将递归的算法改为非递归的算法，被称为迭代。
改写成迭代形式。
如：L(0)=MAX{L(1),L(2),L(3),L(4)}+1;
	L(1)=MAX{L(2),L(3),L(4)}+1;
	L(2)=MAX{L(3),L(4)}+1;
	L(3)=MAX{L(4)}+1;
	L(4)=1;
这样就可以自底向上迭代计算（如使用两层循环），避免的函数调用的堆栈/进程切换开销。
如果迭代时分支较多，不如将一次迭代分为多次去做，如BM69.
*/
int jumpFloor(int number) {
	int cache[50];
	for (int i = 0; i < 50; i++) {
		cache[i] = 0;
	}
	cache[1] = 1;
	cache[2] = 2;
	for (int i = 3; i < 50; i++) {
		cache[i] = cache[i - 1] + cache[i - 2];
	}
	return cache[number];
}