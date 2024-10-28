#include<iostream>
using namespace std;
#define MAX_ELEMS 100
struct bst
{
	int data;
	int lindex;
	int rindex;
};
void MakeNode(struct bst * tree, int data)
{
	tree->data = data;
	tree->lindex = tree->rindex = -1;
}

void Insertleft( struct bst *tree, int data)
{
	MakeNode(tree, data);
}

void Insertright( struct bst * tree, int data)
{
	MakeNode(tree, data);
}
void Insert(struct bst * tree, int treeIndex, int data)
{
	int baseIndex = 0;
	
	while(baseIndex <= treeIndex)
	{
		if(data <= tree[baseIndex].data)
		{
			if(tree[baseIndex].lindex == -1)
			{
				tree[baseIndex].lindex = treeIndex;
				Insertleft(&tree[treeIndex], data);
				return;
			}
			else
			{
				baseIndex = tree[baseIndex].lindex;
				continue;
			}

		}
		else // data is > tree[baseIndex].data
		{
			if(tree[baseIndex].rindex == -1)
			{
				tree[baseIndex].rindex = treeIndex;
				Insertright(&tree[treeIndex], data);
				return;
			}
			else
			{
				baseIndex = tree[baseIndex].rindex;
				continue;
			}
		}
	}
}
void Intrav(struct bst * tree, int index)
{
	if(tree[index].lindex != -1)
		Intrav( tree, tree[index].lindex );
	cout<<"DataIn ="<<tree[index].data<<endl;
	if(tree[index].rindex != -1)
		Intrav( tree, tree[index].rindex );
}

void Pretrav(struct bst * tree, int index)
{
	cout<<"DataPre ="<<tree[index].data<<endl;
	if(tree[index].lindex != -1)
		Pretrav( tree, tree[index].lindex );
	if(tree[index].rindex != -1)
		Pretrav( tree, tree[index].rindex );
}

void Posttrav(struct bst * tree, int index)
{
	if(tree[index].lindex != -1)
		Posttrav( tree, tree[index].lindex );
	if(tree[index].rindex != -1)
		Posttrav( tree, tree[index].rindex );
	cout<<"DataPost ="<<tree[index].data<<endl;
}

int main()
{
	struct bst tree[MAX_ELEMS];
	memset(tree, 0, sizeof(tree));
	int treeIndex = 0;

	MakeNode(&tree [treeIndex], 50);
	treeIndex++;
	Insert(tree, treeIndex, 10);
	treeIndex++;
	Insert(tree, treeIndex, 60);
	treeIndex++;
	Insert(tree, treeIndex, 25);
	treeIndex++;
	Insert(tree, treeIndex, 30);
	treeIndex++;
	Insert(tree, treeIndex, 92);
	treeIndex++;
	Insert(tree, treeIndex, 15);
	treeIndex++;
	Insert(tree, treeIndex, 67);
	
	Intrav(tree, 0);
	Pretrav(tree,0);
	Posttrav(tree, 0);

	return 0;
}