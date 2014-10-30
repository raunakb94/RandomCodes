/*n   – Total no. of items available
weight[] – Weight of each item
profit_array[] – Profit of each item
m   – Maximum Capacity of the Sack
unit[] – Profit of each item per Unit profit_array[]/weight[]
final_list[] – Final list of items put into the Sack
y[] – Intermediate list of selected items
final_profit  – Final Profit
final_weight  – Final Weight
current_profit  – Current Profit
current_weight  – Current Weight
*/
/*
 *There is a salesman that need to deliver some goods to customers.Each package has some weight.He can only carry x amount of weight at a time.
 *There is fixed amount of profit assocaited with each item.Salesman has to pick packages in such a way that he can earn maximum profit at a time.
  His manager suggested him to use below mentioned algorithm to maximize profit.
  But this algorithm has some bugs.You have to find and correct those bugs in given codes and make this code runnable.

  Program arguments will be passed in this order
   First parameter:n number of items
   Second parameter: max capacity of sack
   then n pair of weight and profit of items

   e.g    3 50 12 2 23 11 22 15
   3= number of items
   50 = capacity of sack

	weights profit
 	12 	2
	23	11
	22	15
 */




#include <stdio.h>

int n,max;//m->max
int weight[max],i,j,profit_array[max];
float unit[max];
int y[max],final_list[max],final_profit=-1,final_weight;
void get(int n, char *arg_array[]) // Improper Prototype
{
	int counter=2;
        n=atoi(arg_array[1]);
        max=atoi(arg_array[2]);
        printf("no of itmes : %d", n);
        printf("no of max capacity :%d",m);
	for(i=0;i<n;i++)
	{
		weight[i]=atoi(arg_array[++counter]);//w ->weight
        printf("%d \n",weight[i]);
	}
}
void show()
{
	float s=0.0;
	printf("\n\tItem\tWeight\tCost\tUnit Profit\tSelected ");
	for(i=1;i<n;i++)
		printf("\n\t%d\t%d\t%d\t%f\t%d",i+1,weight[i],profit_array[i],unit[i],final_list[i]);
	printf("\n\n The Sack now holds following items : ");
	for(i=1;i<n;i++)
		if(final_list[i]==1)
		{
			printf("%d\t",i+1);
			s +=  profit_array[i] * final_list[i];
		}
	printf("\n Maximum Profit: %f ",s);
}
/*Arrange the item based on high profit per Unit*/
void sort()
{
	int t,t1;
	float t2;
	for(i=0;i<n;i++)
		unit[i] =  profit_array[i] /  weight[i];
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(unit[j]  < unit[i])
			{
				t2 = unit[i];
				unit[i] = unit[j];
				unit[j] = t2;
				t = profit_array[i];
				profit_array[i] = profit_array[j];
				profit_array[j] = t;
				t1 = weight[i];
				weight[i] = weight[j];
				weight[j] =t1;
			}
		}
	}
}
float bound(float current_profit,float current_weight,int k)
{
	float b = current_profit;
	float c = current_weight;
	for(i=k;i<=n;i++)
	{
		c = weight[i];
		if( c < m)
			b = b +profit_array[i];
		else
			return (b+(1-(c-m)/ (float)weight[i])*profit_array[i]);
	}
	return b;
}
void find(int k,float current_profit,float current_weight)
{
	if(current_weight+weight[k] <= m)
	{
		y[k] = 1;
		if(k <= n)
			find(k,current_profit+profit_array[k],current_weight+weight[k]);
		if(((current_profit+profit_array[k]) > final_profit) && ( k == n))
		{
			final_profit = current_profit+profit_array[k];
			final_weight = current_weight+weight[k];
			for(j=0;j<=k;j++)
				final_list[j] = y[j];
		}
	}
	if(bound(current_profit,current_weight,k) < final_profit)
	{
		if( k <= n)
			find(k,current_profit,current_weight);
		if((current_profit > final_profit) && (k == n))
		{
			final_profit = current_profit;
			final_weight = current_weight;
			for(j=0;j<=k;j++)
				final_list[j] = y[j];
		}
	}
}
void main(int argc, char *argv[])
{
	get(int argc,*argv);
	printf("\n The Sack is arranged in the order…\n");
	sort();
	find(0,0.0,0.0);
	show();
}

