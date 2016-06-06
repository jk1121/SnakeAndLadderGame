# include<iostream>
# include<algorithm>
# include<set>
# include<cmath>
# include<iomanip>
# include<cstdlib>
# include<stack>
# include<queue>
# include<cstring>
# define R 3
# define C 3
# define MAX_CHARS 256
# define NO_OF_CHARS 26
 using namespace std;


struct node{
	int val;
	struct node *next;
};
typedef struct node node;

node *add(node *head , int vertex)
{
	node *traverse = new node();
	traverse->val =vertex;
	traverse->next =head;
	
	return traverse;
}

void printAdjList(node*adjList[],int vertices)
{
	int i;
	
	for(i=1;i<=vertices;i++)
	{
		node *temp = adjList[i];
		cout<<i<"->";
		while(temp!=NULL)
		{
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<"->NULL";
	}
	
}
void replace(node*head,int oldVertex,int newVertex)
{
	 node *temp = head;
	while(temp->next!=NULL)
	{
		if(temp->val ==oldVertex )
			break;
		temp = temp->next;
			
	}
	temp->val =newVertex;
}
void bfs(node *adjList[],int vertices ,int parent[],int level[])
{	
	int flag=1,lev=0,par,i;
	level[1]=lev;
	node *temp;
	while(flag)
	{
		flag=0;
		for(i=1;i<=vertices;i++)
		{
			if(level[i]==lev)
			{
				flag=1;
				par=i;
				temp =adjList[i];
				
				while(temp!=NULL)
				{
					if(parent[temp->val]!=0)
					{
						temp=temp->next;
						continue;
					}
					
					parent[temp->val]=par;
					level[temp->val]=lev+1;
					temp=temp->next;
				}
			}
		}
		
		
		++lev;
	} 
}

 int main(void)
 {
    int vertices=100,edges=0, v1,v2,s_count,l_count,i,j,t;
	node* adjList[vertices+1];
	int parent[vertices+1];
	int level[vertices+1];
 	
	cin>>t;
    while(t--)
    {
 		for(i=0;i<=vertices;i++)
 		{
 			adjList[i]=NULL;
 			parent[i]=0;
 			level[i]=-1;
		}
		
		for(i=1;i<=vertices;i++)
		{
			for(j=1;j<=6 && j+i<=vertices ;j++)
			{
				adjList[i]=add(adjList[i],j+i);
				++edges;
			}
		}
		
		cin>>l_count;
		for(i=0;i<l_count;i++)
		{
			cin>>v1>>v2;
			j = v1-6;
			if(j<1) j=1;
			for(;j<v1;j++)
				replace(adjList[j],v1,v2);
		}
		
		cin>>s_count;
		for(i=0;i<s_count;i++)
		{
			cin>>v1>>v2;
			j=v1-6;
			if(j<1)  j=1;
			for(;j<v1;j++)
				replace(adjList[j],v1,v2);
		}
		
		bfs(adjList,vertices,parent,level);
		cout<<level[vertices]<<"\n";
	}
 }

