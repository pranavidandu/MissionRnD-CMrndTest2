/*
***********************
Comment the Printfs  you used in the Problems before you submit,as Printf might lead to timeouts in large 
cases as I/O is costly operation than CPU operations.
***********************
Do Read All questions carefully ,before writing any Code .
Make sure you submit the Code you have written through tool ,
before the submit window Closes .
*****************
Note : Make sure your MSBuild Suceeds before you submit ,or else It will lead to 0 marks .
->If you are stuck on a question or a particular Test case
is failing , Do Solve the Next question .As long as you click on submit at correct time,
your submissions are safe .
**************
There are only Sample Test Cases provided .Your code will also be graded
using Test cases on our end ,So Do think about testcases in all possible ways .
Your score will totally be based on the number of TestCases your programs
have passed on our end ,so if your code just passes sample cases
and fails all testcases at our end ,you will get you 0 marks .
******************
You can fill in the Helper Functions and make use of it
if you want to test from MainMrndCTest2.cpp
******************
All the Best .
*/

#include <stdlib.h>
#include <stdio.h>
#include "FunctionHeadersMrndTest2.h"


struct oddevennode{
	int data;
	struct oddevennode * next;
	struct oddevennode * random;
};

struct node{
	int data;
	struct node *left;
	struct node *right;
};

//Helper Functions Start
struct oddevennode * createNode(int num) {
	struct oddevennode *newNode = (struct oddevennode *)malloc(sizeof(struct oddevennode));
	newNode->data = num;
	newNode->next = NULL;
	newNode->random = NULL;
	return newNode;
}
void addNode(struct oddevennode **head, int data){
	struct oddevennode * cur = createNode(data);
	if (*head == NULL){
		*head = cur;
	}
	else{
		struct oddevennode *temp = *head;
		cur->next = temp;
		*head = cur;
	}
}

//Helper Functions End

int compare_arrays(int *arr, int *arr2, int len){
	if (arr == NULL && arr2 == NULL){
		return 0;
	}
	int i = 0;
	for (i = 0; i < len; i++){
		if (arr[i] != arr2[i]){
			printf("yes arr[%d] %d arr2[%d] %d\n", i, arr[i], i, arr2[i]);
			return 0;
		}
	}
	return 1;
}

int * toArray(struct oddevennode *head, int len){
	int * res = (int *)malloc(len *(sizeof(struct oddevennode)));
	int i = 0;
	while (i < len){
		if (head == NULL){
			return NULL;
		}
		res[i] = head->data;

		head = head->random;
		if (i != len - 1){
			if (head == NULL){
				return NULL;
			}
		}
		i++;
	}
	if (head != NULL){
		return NULL;
	}
	return res;
}
int main(){
	
	//Test Odd Even SLL
	/*struct oddevennode *head = NULL;
	int nums[20] = { 10, 3, 6, 5, 8, 1, 3 };
	int odds_expected[20] = { 3, 5, 1, 3 };
	int evens_expected[20] = { 10, 6, 8 };
	int ans[2] = { 4, 3 };
	int totallen = ans[0] + ans[1];
	for (int i = totallen - 1; i >= 0; i--){
		addNode(&head, nums[i]);
	}
	int *res = oddeven_sll(head);

	int check = 0, check2 = 0, check3 = 0;
	if (res == NULL){
		check = 1;
	}
	struct oddevennode *oddnode = (head->next);
	struct oddevennode *evennode = head;
	printf("res %d %d\n", res[0], res[1]);
	check = compare_arrays(res, ans, 2);
	printf("check is %d\n", check);
	int * odd_arr_actual = toArray(oddnode, res[0]);
	int	* evens_arr_actual = toArray(evennode, res[1]);
	check2 = compare_arrays(odd_arr_actual, odds_expected, res[0]);
	check3 = compare_arrays(evens_arr_actual, evens_expected, res[1]);
	printf("check %d %d %d\n", check, check2, check3);
	printf("0 %d 1 %d\n", res[0], res[1]);*/
	//Test CommonRoute
	int cost = -1;
	char hacklist[100] = "CADBZAYZY";
	char codelist[100] = "BZAYACAFRDBZ";
	char ans[100] = "BZAY";
	int cost_ans = 54;
	char *res = NULL;
	res = find_common_route(hacklist, codelist, &cost);
	int check = 0;
	printf("%s %d\n", res, cost);
	//MangoCollector
	
	//Test Pillars
}