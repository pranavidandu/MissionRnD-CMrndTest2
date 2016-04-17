/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit 
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any 
number of times.
Output :
Return a Common Route String which covers maxiumum Islands 

Example 1 : 
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ" 
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation : 
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs 
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before 
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB 
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost ) 
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int path(char * hacklist, char *codelist, int i, int j, int *cost, char *com_route, int index){
	if (hacklist[i] != codelist[j]){
		com_route[index] = '\0';
		return *cost;
	}
	*cost += hacklist[i] - 64;
	com_route[index++] = hacklist[i];
	path(hacklist, codelist, i + 1, j + 1,  cost, com_route, index);
}
void copy(char *temp, char *main, int i){
	printf("im jhgfd\n");
	if (temp[i] == '\0'){
		main[i] = '\0';
		return;
	}
	main[i] = temp[i];
	copy(temp, main, i++);
}
char * find_common_route(char * hacklist, char *codelist, int *cost){
	if(hacklist == NULL || codelist == NULL)
		return NULL;
	int i = 0, j = 0, temp = 0;
	char *com_route = (char*)malloc(sizeof(int)*100);
	char *temp_route = NULL;
	int k = 0;
	for (i = 0; hacklist[i] != '\0'; i++){
		*cost = 0;
		k = 0;
		for (j = 0; codelist[j] != '\0'; j++){
			if (hacklist[i] == codelist[j]){
				*cost += hacklist[i] - 64;
				com_route[k++] = hacklist[i];
				*cost = path(hacklist, codelist, i + 1, j + 1, cost, com_route, k);
				printf("%s comm\n", com_route);
				//printf("im out cost befor %d\n", *cost);
				//temp_route = com_route;
				if (temp_route == NULL){
					int m = 0;
					while (com_route[m] != '\0'){
						//printf("no comin\n");
						temp_route[m] = com_route[m];
						m++;
					}
					temp_route[m] = '\0';
					printf("temp %s\n", temp_route);
					break;
				}
				if (temp == *cost){
					if (temp_route[0] < com_route[0]){
						int m = 0;
						while (com_route[m] != '\0'){
							temp_route[m] = com_route[m];
							m++;
						}
						temp_route[m] = '\0';
					}
					else{
						int m = 0;
						while (temp_route[m] != '\0'){
							com_route[m] = temp_route[i];
							m++;
						}
						com_route[m] = '\0';
					}
				}
				else if (temp > *cost){
					printf("temp > cost\n");
					*cost = temp;
					//int m = 0;
					int m = 0;
					while (temp_route[m] != '\0'){
						com_route[m] = temp_route[i];
						m++;
					}
					com_route[m] = '\0';
				}
				else{
					temp = *cost;
					//copy(temp_route, com_route, 0);
				}
				printf("cost %d is after\n", *cost);
				printf("->%s \n", com_route);
				break;
			}
		}
	}
	printf("%s string\n", com_route);
	return com_route;
}

