#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/sched.h>


asmlinkage long sys_hello(void) {
	printk("Hello, World!\n");
	return 0;
}

asmlinkage int sys_set_weight(int weight) {
	if (weight<0) return -EINVAL;
	else{
		return current->weight;
	}
	return 0;
}

asmlinkage int sys_get_weight(void) {
	printk("weight: %d\n", current->weight);
	return current->weight;
}


asmlinkage int sys_get_ancestor_sum(void) {
	struct task_struct * iter = current;
	int sum = 0;
	while(iter->pid !=1)
	{
		sum += iter->weight;
		iter = iter->parent;
	}
	return sum;
}

task_struct * get_heaviest_descendant(struct task_struct * task)
{
	int max = task->weight;
	struct task_struct * iter;
	struct list_head * list;
	list_for_each(list, &task->children)
	{
		iter = list_entry(list, struct task_struct, sibling);
		task_struct * temp = get_heaviest_descendant(iter);
		if (temp->weight > max) {
			max = temp->;
		}
	}
	return temp;
}

//recursive func to call all childs
asmlinkage pid_t sys_get_heaviest_descendant(void) 
{
	if (list_empty(&current->children)) return -ECHILD;
	else
	{
		return get_heaviest_descendant(current)->pid;
	}
	
}