#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/sched.h>



asmlinkage long sys_hello(void) {
	printk("Hello, World!\n");
	return 0;
}

asmlinkage long sys_set_weight(int weight) {
	if (weight>=0){
		current->weight = weight;
	} 
	else{
		return -EINVAL;
	}
	return 0;
}

asmlinkage long sys_get_weight(void) {
	printk("weight: %d\n", current->weight);
	return current->weight;
}


asmlinkage long sys_get_ancestor_sum(void) {
	struct task_struct * iter = current;
	int sum = 0;
	while(iter->pid !=1)
	{
		sum += iter->weight;
		iter = iter->parent;
	}
	return sum;
}

struct task_struct* get_heaviest_descendant(struct task_struct* task, bool is_first_call)
{
	int max = 0;
	if (!is_first_call)
	{
		max = task->weight;
	}
    struct task_struct* iter;
    struct list_head* list;
    struct task_struct* temp = NULL; // Initialize temp to NULL	
	struct task_struct* child_temp = NULL; // Initialize temp to NULL
    list_for_each(list, &task->children)
    {
		int status;
        iter = list_entry(list, struct task_struct, sibling);
        child_temp = get_heaviest_descendant(iter, false);
        if (child_temp != NULL && !WIFEXITED(waitpid(child_temp->pid, &status, WNOHANG)) && (child_temp->weight > max || (child_temp->weight == max && child_temp->pid < temp->pid))) {
            max = child_temp->weight;
            temp = child_temp; // Update temp only if child_temp is not NULL
        }
    }
    if (temp == NULL) {
        temp = task; // Set temp to current task if no heavier descendant is found
    }
    return temp;
}


//recursive func to call all childs
asmlinkage long sys_get_heaviest_descendant(void) 
{
	printk("yoram get_heaviest_descendant\n");
	if (list_empty(&current->children)){
		printk("yoram no child\n");
		return -ECHILD;
	} 
	else
	{
		printk("yoram has child\n");
		return (get_heaviest_descendant(current, true))->pid;
	}
	
}