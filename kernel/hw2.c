#include <linux/kernel.h>

asmlinkage long sys_hello(void)
{
	printk("Hello, World!\n");
	return 0;
}

asmlinkage int set_weight(int weight)
{
}
asmlinkage int get_weight(void)
{
}
asmlinkage int get_ancestor_sum(void)
{
}
asmlinkage pid_t get_heaviest_descendant(void)
{
}