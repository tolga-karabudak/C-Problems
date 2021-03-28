

typedef struct node_s {
	int data;
	struct node_s *next;
} node_t;

node_t *Getnode(void);
void add_beginning(node_t *headp, int item);
void add_after(node_t *p, int item);
void display_list(node_t *headp);

node_t *Getnode(void)
{
	node_t *node;
	node = (node_t *)malloc(sizeof(node_t));
	node->next = NULL;
	return (node);
}

void add_after(node_t *p, int item)
{
	node_t *newp, *temp;
	temp=p;
	newp = Getnode();
	newp->data = item;
	newp->next = NULL;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next = newp;
}

void display_list(node_t *headp)
{
	node_t *p;
	if (headp == NULL)
	printf("The List is EMPTY !!!");
	else
	{
		p = headp;
		while (p != NULL)
		{
			printf("%d", p->data);
			if (p->next != NULL)
				printf("-->");
			p = p->next;
			if(p==NULL)
				printf("-->NULL");
		}
	}
	printf("\n");
}

void add_beginning(node_t *headp, int item)
{
//	node_t *newp;
//	newp = Getnode();
	headp->data = item;
	headp->next = NULL;

}

