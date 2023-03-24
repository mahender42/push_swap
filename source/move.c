#include "../push_swap.h"

void move_rev (t_data *data)
{
    int i;

    i = data->cheap;
    while (data->stack_b[i].cost_a < 0 && data->stack_b[i].cost_b < 0)
    {
        ft_printf("cost_a: %d, cost_b: %d\n", data->stack_b[i].cost_a, data->stack_b[i].cost_b);
        data->stack_b[i].cost_a++;
		data->stack_b[i].cost_b++;
		reverse_ab(data);
        i = (i + 1) % data->len_b;
        ft_printf("cost_a: %d, cost_b: %d\n", data->stack_b[0].cost_a, data->stack_b[0].cost_b);
    }
    if (data->stack_b[i].cost_a < 0)
    {
        while (data->stack_b[i].cost_a < 0)
        {
    		data->stack_b[i].cost_a++;
		    reverse_a(data, 0);
        }
    }
    if (data->stack_b[i].cost_b < 0)
    {
        while (data->stack_b[i].cost_b < 0)
        {
            data->stack_b[i].cost_b++;
		    reverse_b(data, 0);
            i = (i + 1) % data->len_b;
        }
    }
}

void move_rot (t_data *data)
{
    int i;

    i = data->cheap;
    while (data->stack_b[i].cost_a > 0 && data->stack_b[i].cost_b > 0)
    {
		data->stack_b[i].cost_a--;
		data->stack_b[i].cost_b--;
		rotate_ab(data);
        i = (i - 1) % data->len_b;
    }
    if (data->stack_b[i].cost_a > 0)
    {
        while (data->stack_b[i].cost_a > 0)
        {
            data->stack_b[i].cost_a--;
		    rotate_a(data, 0);
        }
    }
    if (data->stack_b[i].cost_b > 0)
    {
        while (data->stack_b[i].cost_b > 0)
        {
            data->stack_b[i].cost_b--;
		    rotate_b(data, 0);
            i = (i - 1) % data->len_b;
        }
    }
}
