#include <stdio.h>
#include <stdlib.h>

#define char		int8_t
#define int		int32_t
#define long		int64_t

#define intMax 2147483647

#define numOfEntry 10

typedef struct tableNode{
	int32_t key;
	struct tableNode *next;
}tableNode;
//__attribute__((packed,aligned(1))) tableNode;

void initTable(struct tableNode  table[])
{
	int32_t i;
	for (i = 0; i < numOfEntry; i++){
		//table += i;
		table[i].key = intMax;
		table[i].next = NULL;
	}
}

int32_t hashFunt(int key)
{
	if (key < 0)
		key = -key;
	return key % numOfEntry;
}

int32_t searchKey(struct tableNode table[], int32_t key)
{
	int32_t index = hashFunt(key);
	//table += index;
	if (table[index].key == key)
		return 1;
	else{
		struct tableNode *nextNode = table[index].next;
		while (nextNode != NULL){
			if (nextNode -> key == key)
				return 1;

			nextNode = nextNode -> next;
		}
	}
	return 0;
}

void insertKey(struct tableNode table[], int32_t key)
{
	int32_t index = hashFunt(key);
	//table += index;

	printf("after add index %p\n", table);

	if (table[index].key == intMax)
		table[index].key = key;
	else{
		struct tableNode *nextNode;
		struct tableNode *newNode = malloc(sizeof(struct tableNode));

		nextNode = table[index].next;
		table[index].next = newNode;
		newNode -> key = key;
		newNode -> next = nextNode;
	}
}

void removeKey(struct tableNode table[], int32_t key)
{
	int32_t index = hashFunt(key);
	//table += (sizeof(struct tableNode) * index);	
	//table += index;
	if(table[index].key == key)
		table[index].key = intMax;
	else{
		struct tableNode *currNode = table[index].next;
		struct tableNode *prevNode = &table[index];
		while (currNode != NULL){
			if (currNode -> key == key){
				prevNode -> next = currNode -> next;
				free(currNode);
				break;
			}
			prevNode = currNode;
			currNode = currNode -> next;
		}
	}
}


int main()
{
	return 0;
}



/*
void printHashTable(struct tableNode table[])
{
	for (int i = 0; i < numOfEntry; i++){
		//table += (sizeof(struct tableNode) * i);
		//table += i;
		printf("entry %d \t %d", i, table[i].key);
		
		struct tableNode *nextLink;
		nextLink = table[i].next;
		while (nextLink != NULL){
			printf(" -> %d",nextLink -> key);
			nextLink = nextLink -> next;
		}
		printf(" -> NULL\n");
	}
	printf("\n");
}

int32_t main()
{
	struct tableNode table[numOfEntry];
	initTable(table);
	printHashTable(table);
	int32_t input, ret, key;

	for(;;){
		printf("\n 1 is insert mode\n 2 is remove mode\n 3 is search mode\n In mode, input -1 is exit mode\n");

		scanf("%d",&input);
		
		if (input == -1)
			break;
	

		switch (input)
		{
			case 1:
				for(;;){
					scanf("%d", &key);
					if (key == -1)
						break;
					insertKey(table, key);
					printHashTable(table);
				}
				break;

			case 2:
				for(;;){
					scanf("%d", &key);
					if (key == -1)
						break;
					removeKey(table, key);
					printHashTable(table);
				}
				break;
			
			case 3:
				for(;;){
					scanf("%d", &key);
					ret = searchKey(table, key);
					printHashTable(table);
					if (key == -1)
						break;

					if (ret == 1)
						printf("the key is in HashTable\n");
					else
						printf("Not in HashTable\n");	
				}
				break;
		}	// switch exit
	}	// for loop exit





	
	return 0;
}
*/
