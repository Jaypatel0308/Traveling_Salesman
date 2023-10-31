#include<stdio.h>

int graph[100][100]; //graph matrix
int node,new_node;
char name[100][100]; //array to store name of cities
int vis[100];
int cost;
char start_name[100], end_name[100];
int start,end;
int check(int i)
{
    for(int j=0;j<node;j++)
    {
        if(graph[i][j]!=0)
            return 1;
    }
    return 0;
} //function to check if the city exist or not

int get_ind(char temp[])
{
    for(int i=0;i<node;i++)
    {
        if(strcmp(temp,name[i])==0)
        {
            return i;
        }
    }
    return -1;
} //function to get index of given city name

void tsp()
{
    printf("\n\n");
    printf("\t\t\t\t\t\t\tPATH");
    printf("\n\n");
    int count=0,cur=start,next=-1;
    printf("The paths is : ");
    while(count<new_node-2)
    {
        int min=1000;
        vis[cur]=1; //assigning the value 1 to visited nodes
        printf("%s--> ",name[cur]); //displaying the initial path
        for(int i=0;i<node;i++)
        {
            if(vis[i]==0 && i!=cur && graph[cur][i]<=min && i!=(end) && check(i))
            {
                min=graph[cur][i];
                next = i;
            } //checking conditions and moving to next node seeing that it is not the destination node
        }
        cost+=min;
        cur=next;
        count++; //calculating the cost
    }
    printf("%s-->%s\n",name[cur],name[end]); //displaying the path
    cost+=graph[cur][end]; //calculating the cost
    printf("The total distance is %d\n",cost); //printing the cost
} //function of traveling salesman problem

void menu()
{
    int ch;
    printf("\nEnter 1 to add city");
        printf("\nEnter 2 to delete city");
        printf("\nEnter 3 to exit");
        printf("\n\nEnter the choice : ");
        scanf("%d",&ch); //displaying the menu and asking the choice from the user
        int temp=0;
        switch(ch)
        {
            case 1:
                    node++;
                    cost=0;
                    printf("\nEnter the name of city to be added : ");
                    scanf("%s",&name[node-1]); //taking name of new city to be added
                    printf("\n");
                    while(temp<node)
                    {
                        vis[temp]=0;
                        printf("Enter distance with city %s : ",name[temp]);
                        scanf("%d",&graph[temp][node-1]); //taking distances from other cities
                        graph[node-1][temp]=graph[temp][node-1];
                        temp++;
                    }
                    printf("\n");
                    new_node++;
                    tsp(); //displaying the path and cost after adding city
                    menu(); //calling menu
                break;
            case 2:cost=0;
                    int q1;
                    char tempp[100];
                    printf("\nEnter the name of city to be removed : ");
                    scanf("%s",&tempp); //taking name of city to be removed
                    q1=get_ind(tempp);
                    for(int i=0;i<node;i++)
                    {
                        vis[i]=0;
                        graph[i][q1]=0;
                        graph[q1][i]=0;
                    } //assigning the value 0 in adjacency matrix
                    printf("\n");
                    new_node--;
                    tsp(); //displaying path and cost after removing city
                    menu(); //calling main menu
                break;
            case 3: printf("\n");
                    pattern_2();
                    exit(0);
                break;
            default : printf("Invalid input! Enter again ");
                menu();
        }
}

void pattern_2()
{
    printf("\n\n");
    printf("\t\t\t\t********************** THANK YOU **********************");
    printf("\n\n");
    printf("\t\t\t\t                Prepared By : 19BCE085");
    printf("\n\n");
}

void main()
{
    printf("\n\n\t\t\t\t\t\t DROP-OFF Pvt. Ltd.");
    printf("\n\n\n");
    printf("Enter no. of cities : ");
    scanf("%d",&node); //taking input of number of cities
    printf("\n\n");
    printf("\t\t\t\t\t\t   CITY NAMES");
    printf("\n\n");
    for(int i=0;i<node;i++)
    {
        printf("Enter the name of city %d : ",i+1);
        scanf("%s",&name[i]);
    } //taking input of names of city
    printf("\n\n");
    printf("\t\t\t\t\t\t   DISTANCE");
    printf("\n\n");
    for(int i=0;i<node;i++)
    {
        vis[i]=0;
        for(int j=0;j<node;j++)
        {
            printf("Enter distance between %s and %s : ",name[i],name[j]);
            scanf("%d",&graph[i][j]);
        }
    } //taking distances between the cities
    printf("\nEnter the start destination city number : ");
    scanf("%s",&start_name); //taking starting destination
    start=get_ind(start_name); //getting index of starting destination
    printf("\nEnter the end destination city number : ");
    scanf("%s",&end_name); //taking end destination
    end=get_ind(end_name); //getting index of end destination
    printf("\n");
    new_node=node;
    tsp();
    menu();
}
