#include<bits/stdc++.h>
//#include<dos.h>
//#include<stdio.h>
//#include<conio.h>
//#include<malloc.h>
//#include<string.h>
#include<time.h>
#include<windows.h>

#define R 6371
#define TO_RAD (3.1415926536 / 180)

#define V 10 //vertices

using namespace std;


/*-------------------------------------------------------------------------*/

int dist(double th1, double ph1, double th2, double ph2)
{
	double dx, dy, dz;
	ph1 -= ph2;
	ph1 *= TO_RAD, th1 *= TO_RAD, th2 *= TO_RAD;

	dz = sin(th1) - sin(th2);
	dx = cos(ph1) * cos(th1) - cos(th2);
	dy = sin(ph1) * cos(th1);
	return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}



// A utility function to find the vertex with minimum distance
// value, from the set of vertices not yet included in shortest
// path tree

 struct edge
{
    int eno,p1,p2;
    float p1_lat,p1_lng;
    float p2_lat,p2_lng;
};

  struct n_e
{
    int n,e;
};

struct node
{
    char place[30];
    int num;
    float lat,lng;
}node[10];

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min1 = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min1)
            min1 = dist[v], min_index = v;

    return min_index;
}

// Function to print shortest path from source to j
// using parent array
void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    //printf("%d ", j);

    for(int temp=0;temp<10;temp++)
            if(node[temp].num == j)

               printf("%s -> ",node[temp].place);

	//	cout<<" Office"<<endl;
}

// A utility function to print the constructed distance
// array
int printSolution(int dist[], int n, int parent[],int src,int target)
{
    //int src = 0;
    //printf("Vertex\t  Distance  \tPath\n");
    for (int i = 1; i < V; i++)
    {
       // printf("\n%d -> %d \t\t %d\t\t%d   ", src, i, dist[i], src);
       if(i==target)
       {
           printf("\n");

        for(int temp=0;temp<10;temp++)
            if(node[temp].num == src || node[temp].num == i)
               printf("%s\t",node[temp].place);

               cout<<endl<<endl;

               cout<<" The shortest distance between the two location is "<<dist[i];
       cout<<endl<<endl;
       cout<<"Shortest Path to reach your Office"<<endl<<endl;
       for(int temp=0;temp<10;temp++)
            if(node[temp].num == src)
               printf("%s -> ",node[temp].place);


		printPath(parent, i);
		cout<<" Office reached"<<endl;
       }
    }
}

// Funtion that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void dijkstra(int graph[V][V], int src,int target)
{
    int dist[V];  // The output array. dist[i] will hold
                  // the shortest distance from src to i

    // sptSet[i] will true if vertex i is included / in shortest
    // path tree or shortest distance from src to i is finalized
    bool sptSet[V];

    // Parent array to store shortest path tree
    int parent[V];

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
   // dist[src] = 0;
   dist[0] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to src
        // in first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is
            // an edge from u to v, and total weight of path from
            // src to v through u is smaller than current value of
            // dist[v]
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // print the constructed distance array
    printSolution(dist, V, parent,src,target);
}

/*-------------------------------------------------------*/


int emp_count=-1;
int flagggg=0;
int vg=0;
int ma=0;

struct category
	{
		string cname;
		string cjob[100];
		double cpoints[100];
		};
	struct category cat[5];

struct record_number
{
    char nmbr[100];
	int id;
};
struct record_number *r,*r1;
/*begin job by designation*/
struct desgn{
	char id[10];
	string name,post[100];
};
struct desgn designation[10];
int desig[10]={0};  // counter for no. of designation free in a company
/* end job by designation*/


/*structure of company*/
struct company
{
	char cmp_name[100];
	int cmp_id;
	int status;
	int prefer;
	int companysetpreferencearray[4];
	int b[4];
	int score;
};
struct company cmp[4];
/*end of company structure*/
void readcompany()
{
	FILE *e;
	e=fopen("company.txt","r");
	for(int i=0;i<4;i++)
	{
		fscanf(e,"%d%s%d%d",&cmp[i].cmp_id,cmp[i].cmp_name,&cmp[i].status,&cmp[i].prefer);
		//cout<<cmp[i].cmp_name<<" "<<cmp[i].cmp_id<<endl;
	}
	fclose(e);
}

/*structure of employee*/
struct employee{
	string emp_name;
	string email;
	int status;
	int experience;
	string achieve[100];
	int id;
	int a[4];
};
struct employee emp[4];
/*end of employee structure*/


void resume()
{
	int xx;
	cout<<"****** Your Phone Number ******\n";
	cout<<r->nmbr<<endl;
	cout<<"****** Enter Name ******\n";
	cin>>emp[emp_count].emp_name;
	cout<<"****** Enter Email ******\n";
	cin>>emp[emp_count].email;
	cout<<"****** Enter Experience ******\n";
	cin>>emp[emp_count].experience;
	cout<<"****** Enter Achievements ******\n";
	//ma=0;
	while(1)
	{
		cin>>emp[emp_count].achieve[ma];
		ma++;
		cout<<"Want to exit press 0";
		cin>>xx;
		if(xx==0)
		break;
	}
	emp[emp_count].id=r->id;
//	cout<<emp_count<<" "<<emp[emp_count].id;
}

void applycat()
{
	int xx;
	cout<<"****** Your Phone Number ******\n";
	cout<<r->nmbr<<endl;
	cout<<"****** Enter Name ******\n";
	cin>>emp[emp_count].emp_name;
	cout<<"****** Enter Email ******\n";
	cin>>emp[emp_count].email;
	cout<<"****** Enter Experience ******\n";
	cin>>emp[emp_count].experience;
	cout<<"****** Enter Achievements ******\n";
	//ma=0;
	while(1)
	{
		cin>>emp[emp_count].achieve[ma];
		ma++;
		cout<<"Want to exit press 0";
		cin>>xx;
		if(xx==0)
		break;
	}
	emp[emp_count].id=r->id;

//	cout<<emp_count<<" "<<emp[emp_count].id;
}


/* apply function for job in a company */
void job_apply_function()
{
	system("cls");
	if(flagggg==0)
	{
		resume();
		flagggg=1;
	}
}
/*end of apply fuction */


/*start of companysetprefence */
void companysetpreference(int i)
{
	srand(time(NULL));
	double x=0;
	double y=0;
	if(i==1)
	{
	if(emp[emp_count].experience==0)
		x=2;
	else
	x=(0.8*emp[emp_count].experience);
	y=y+x;

	double q=0;
	q=ma*0.4;
	y=y+q;
	double w=0;
	w=rand()%5+1;
	y=y+w;
	cmp[i].companysetpreferencearray[emp_count]=y;
	//cout<<cmp[i].companysetpreferencearray[emp_count]<<endl;
	cout<<"Company has set your preference..."<<endl;
	cout<<"Your score as given by "<<cmp[i].cmp_name<<" is "<<y<<endl;
	cout<<"Now apply for next company if want to..."<<endl;
	}
	if(i==0)
	{
			if(emp[emp_count].experience==0)
		x=1;
	else
	x=(0.7*emp[emp_count].experience);
	y=y+x;

	double q=0;
	q=ma*0.5;
	y=y+q;
	double w=0;
	w=rand()%4+1;
	y=y+w;
	cmp[i].companysetpreferencearray[emp_count]=y;
	//cout<<cmp[i].companysetpreferencearray[emp_count]<<endl;
	cout<<"Company has set your preference..."<<endl;
	cout<<"Your score as given by "<<cmp[i].cmp_name<<" is "<<y<<endl;
	cout<<"Now apply for next company if want to..."<<endl;
	}
	if(i==2)
	{
			if(emp[emp_count].experience==0)
		x=2;
	else
	x=(0.6*emp[emp_count].experience);
	y=y+x;

	double q=0;
	q=ma*0.7;
	y=y+q;
	double w=0;
	w=rand()%6+1;
	y=y+w;
	cmp[i].companysetpreferencearray[emp_count]=y;
	//cout<<cmp[i].companysetpreferencearray[emp_count]<<endl;
	cout<<"Company has set your preference..."<<endl;
	cout<<"Your score as given by "<<cmp[i].cmp_name<<" is "<<y<<endl;
	cout<<"Now apply for next company if want to..."<<endl;
	}
	if(i==3)
	{
			if(emp[emp_count].experience==0)
		x=1;
	else
	x=(0.9*emp[emp_count].experience);
	y=y+x;

	double q=0;
	q=ma*0.2;
	y=y+q;
	double w=0;
	w=rand()%5+1;
	y=y+w;
	cmp[i].companysetpreferencearray[emp_count]=y;
	//cout<<cmp[i].companysetpreferencearray[emp_count]<<endl;
	cout<<"Company has set your preference..."<<endl;
	cout<<"Your score as given by "<<cmp[i].cmp_name<<" is "<<y<<endl;
	cout<<"Now apply for next company if want to..."<<endl;
	}
}

/* end of companysetprefence*/


/*set preference for  a company*/
void setpreference(char applychoice[])
{
	for(int i=0;i<4;i++)
	{

		int rr=strcmp(applychoice,cmp[i].cmp_name);
		/*cout<<applychoice<<" "<<cmp[i].cmp_name<<endl;
		cout<<endl;
		cout<<" "<<rr;*/
		if(rr==0)
		{
			emp[emp_count].a[vg]=cmp[i].cmp_id;
			cout<<emp[emp_count].a[vg]<<" "<<cmp[i].cmp_id<<endl;
			companysetpreference(i);
			break;
		}
	}
	vg++;
	return;
}
void menu();

/* job by designation function */
void jobbydesignation()
{
	FILE *fp2;
	int x;
	char temp[1000];
    string temp1[100];
	int j=0;
	char ii[100];
	fp2=fopen("designation.txt","r");
	int q=0;
	int mmm=0;
	int applyvariable;
	char applychoice[100];
	string dsgn;
	int flag1=0;
	cout<<"Enter your designation choice"<<endl;
	cin>>dsgn;
	while(q<4)// 4 is no of companies
	{
		fscanf(fp2,"%s",ii);
		if(strlen(ii)==1)
		{
			strcpy(designation[q].id,ii);
			while(fscanf(fp2,"%s",temp)!=EOF && strlen(temp)!=1)
			{
				temp1[j]=temp;
				if(j>0)
				{
					designation[q].post[j]=temp1[j];
					desig[q]++;
					j++;
				}
				else
					designation[q].name=temp1[0];
				j++;
			}
		}
		else
			exit(0);
		for(int k=1;k<j;k++)
 		{
			if(designation[q].post[k]==dsgn)
        	{
        		cout<<"("<<++mmm<<")"<<"Job Available in "<<designation[q].name<<" "<<"\n";
				flag1=1;
        		break;
        	}
        }
        j=0;
		fseek(fp2, -2, SEEK_CUR);
		q++;
    }
	fclose(fp2);
    if(flag1==1)
	{
		while(1)
		{

			cout<<"Want to Apply(1/0)\n";
			cin>>applyvariable;
			if(applyvariable==1)
			{
				cout<<"Choose in which company to apply according to your preference\n";
				cin>>applychoice;
				job_apply_function();
				setpreference(applychoice);
			}
			else
			{
				menu();
			}
		}
		// menu pe jaa... applied for all job and logout.. next employee will login...
	}
	else
	{
		cout<<"Job is not availiable as per your designation\n";
		Sleep(1000);
		system("cls");
		menu();
	}
}

int find(int x)
{
	int i;
	for(i=0;i<5;i++)
	{
		if(emp[i].id==x)
			return i;
	}
}
/* start of findbestmatch */
void findbestmatch()
{
	int x[4][4],y[4][4],i,j;
	 for(i=0;i<4;i++)
	 {
		emp[i].status=0;
	 	for(j=0;j<4;j++)
	 	{
	 		x[i][j]=emp[i].a[j];
		}
	 }
	 for(i=0;i<4;i++)
	 {
		cmp[i].status=0;
	 	for(j=0;j<4;j++)
	 	{
	 		y[i][j]=cmp[i].b[j];
		}
	 }
	  i=0;
	  int count=0,r,w,var1,var2;
	  while(emp[i].status==0&&count!=4)
	  {
	  	// loop for no. of companys he apply's for
		for(r=0;r<4;r++){
			for(j=0;j<4;j++){
		if(emp[i].a[r]==cmp[j].cmp_id)
		{
			if(cmp[j].status==0)// company is free
			{
				cmp[j].prefer=emp[i].id;// contains most prefered man for job....
				emp[i].status=1;
				cmp[j].status=1;
				count++;
				break;
			}
			else
			{
				// check company's preference list, if current is prefered before present then change....
				for(w=0;w<3;w++)
				{
					if(cmp[j].b[w]==emp[i].id)
						var1=w;// store index of current employee....
					if(cmp[j].b[w]==cmp[j].prefer)
						var2=w;// store present employee's index....
				}
				if(var1<var2)
				{
					count--;
					int emp_index=find(cmp[j].prefer);
					emp[emp_index].status=0;
					cmp[j].prefer=emp[i].id;// most eligible man for job....
					emp[i].status=1;
					count++;
					break;
				}
				else
				{
					break;
				}
			 }//end else
		}//end if
	  }	//end for j
		if(emp[i].status==1)
			break;
	}//end for r
	  	i++;
	  	if(i==4&&count!=4)
	  		i=0;
	  	if(i==4&&count==4)
	  		break;
	}// end while
	  // done pairing....
	  for(int i=0;i<4;i++)
	  {
	   		cout<<"Company name is "<<cmp[i].cmp_name<<" ,Id is "<<cmp[i].cmp_id<<" and company's choice is "<<emp[cmp[i].prefer].emp_name<<endl;
	  }
	  exit(0);
}
/*end of findbestmatch */

/* start of adminlogin */
void adminlogin()
{
	int variable,k=0,j;
	for(int i=0;i<4;i++)
	{
			emp[i].id=i;
			cmp[i].companysetpreferencearray[0]=4;
			cmp[i].companysetpreferencearray[1]=8;
			cmp[i].companysetpreferencearray[2]=1;
			cmp[i].companysetpreferencearray[3]=6;
			emp[i].a[0]=0;
			emp[i].a[1]=1;
			emp[i].a[2]=2;
			emp[i].a[3]=3;
	}

	cmp[0].b[0]=3;
	cmp[0].b[1]=1;
	cmp[0].b[2]=2;
	cmp[0].b[3]=0;
	cmp[1].b[0]=1;
	cmp[1].b[1]=0;
	cmp[1].b[2]=2;
	cmp[1].b[3]=3;
	cmp[2].b[0]=0;
	cmp[2].b[1]=1;
	cmp[2].b[2]=2;
	cmp[2].b[3]=3;
	cmp[3].b[0]=0;
	cmp[3].b[1]=1;
	cmp[3].b[2]=2;
	cmp[3].b[3]=3;
	for(int i=0;i<4;i++)
	{
		while(k<4)
		{
		int max=cmp[i].companysetpreferencearray[0];
		for(j=0;j<4;j++)
		{
			if(max<=cmp[i].companysetpreferencearray[j])
			{
				max=cmp[i].companysetpreferencearray[j];
				variable=j;
			}
		}
		cmp[i].b[k]=emp[variable].id;
		//cout<<cmp[i].b[k]<<" "<<max<<endl;
		k++;
		cmp[i].companysetpreferencearray[variable]=0;
		max=0;
		}
		k=0;
	}
	for(int i=0;i<4;i++)
	{
		cout<<"Employee "<<emp[i].emp_name<<" ,Id is "<<emp[i].id<<" preferences are"<<endl;
		for(j=0;j<4;j++)
		{
			cout<<" "<<emp[i].a[j]<<" ";
		}
		cout<<endl;
		cout<<"Company preference "<<cmp[i].cmp_name<<" preferneces are "<<endl;
		for(j=0;j<4;j++)
		{
			cout<<" "<<cmp[i].b[j]<<" ";
		}
		cout<<endl;
	}
	findbestmatch();
}
/* end of adminlogin*/


int empcountnumberarray[4];
int g=0;
void login()
{
		FILE *fp;
		flagggg=0;
		vg=0;
		ma=0;
		int c;
		char temp[1000];
		int flag=0;
    	printf("Enter your Phone Number and id number\n");
        cin>>r->nmbr>>r->id;
		if(g==0)
		{
			empcountnumberarray[0]=r->id;
			g++;
			emp_count++;
		}
		for(int i=0;i<g;i++)
		{
			if(empcountnumberarray[i]!=r->id)
			{
				 c=1;
			}
			else
				c=0;
		}
		if(c==1)
		{
			g++;
			emp_count++;
		}
      	fp=fopen("record_number.txt","r");
        while(fscanf(fp,"%s",temp)!=EOF)
        {
			int rr=strcmp(temp,r->nmbr);
			if(rr==0)
				flag=1;
    	}
    	fclose(fp);
    	if(flag)
    	{
			printf("Already logged in");
			Sleep(1000);
			system("cls");
			menu();    // driven menu

    	}
        else
        {
        	cout<<"New Login"<<endl;
        	fp=fopen("record_number.txt","a");
        	fprintf(fp,"%s\n",r->nmbr);
        	fclose(fp);
			Sleep(1000);
			system("cls");
			menu();  // driven menu

		}
}

void fun();
void logout()
{
	cout<<"You have been successfully logged out"<<endl;
	Sleep(1000);
	system("cls");
	fun();
}
int arr[100]={0};
/*start of job by company */
void computeLPSArray(char pat[], int M, int *lps);

void kmp(char pat[], char txt[],int y)
{

    int M = strlen(pat);
    int N = strlen(txt);

    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;
    computeLPSArray(pat, M, lps);

    int i = 0;
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {

      	for(int i=0;i<10;i++)
      	{
      		int rr=strcmp(cmp[i].cmp_name,txt);
      		if(rr==0)
			{
				arr[i]++;
				if(arr[i]<=1){
				cout<<"Company found : "<<txt<<endl;
			//	done=1;
				if(y>=cmp[i].score)
        		{
					cout<<"You are eligible for the interview in "<<cmp[i].cmp_name<<endl;
				}
				else
					cout<<"You are not eligible for this company"<<endl;
			}
			}
		}
        j = lps[j-1];
      }

      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}

void computeLPSArray(char pat[], int M, int *lps)
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           len = lps[len-1];
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
/*end of lps*/

int funcompany()
{
	int a[5]={4,1,4,2,3};
	int ans,y=0;
	cout<<"There is a quiz"<<endl<<endl;
	cout<<"You have to answer following questions"<<endl;
	cout<<endl;
	cout<<"(1) If one-third of one-fourth of a number is 15, then three-tenth of that number is:"<<endl;
	cout<<"(1) 35"<<endl;
	cout<<"(2) 36"<<endl;
	cout<<"(3) 45"<<endl;
	cout<<"(4) 54"<<endl;
	cout<<"Enter your Choice"<<endl;
	cin>>ans;
	if(ans==a[0])
		y=y+1;
	cout<<"(2) In the first 10 overs of a cricket game, the run rate was only 3.2. What should be the run rate in the remaining 40 overs to reach the target of 282 runs?"<<endl;
	cout<<"(1) 6.25"<<endl;
	cout<<"(2) 6.5"<<endl;
	cout<<"(3) 6.75"<<endl;
	cout<<"(4) 7"<<endl;
	cout<<"Enter your Choice"<<endl;
	cin>>ans;
	if(ans==a[1])
		y=y+1;
	cout<<"(3) (112 x 54) = ?"<<endl;
	cout<<"(1) 67000"<<endl;
	cout<<"(2) 76500"<<endl;
	cout<<"(3) 77200"<<endl;
	cout<<"(4) 70000"<<endl;
	cout<<"Enter your Choice"<<endl;
	cin>>ans;
	if(ans==a[2])
		y=y+1;
	cout<<"(4) What least number must be added to 1056, so that the sum is completely divisible by 23 ?"<<endl;
	cout<<"(1) 3"<<endl;
	cout<<"(2) 2"<<endl;
	cout<<"(3) 18"<<endl;
	cout<<"(4) 21"<<endl;
	cout<<"Enter your Choice"<<endl;
	cin>>ans;
	if(ans==a[3])
		y=y+1;
	cout<<"(5) The largest 4 digit number exactly divisible by 88 is: "<<endl;
	cout<<"(1) 9768"<<endl;
	cout<<"(2) 9988"<<endl;
	cout<<"(3) 9944"<<endl;
	cout<<"(4) 8888"<<endl;
	cout<<"Enter your Choice"<<endl;
	cin>>ans;
	if(ans==a[4])
		y=y+1;
	return y;
}

/* start of jobbycompany */
void jobbycompany()
{
	int y=funcompany();
	system("cls");

	cout<<"******************* Your Score for the Quiz is *****************"<<endl;
	cout<<"                         "<<y<<"                              "<<endl;
	FILE *fp2;
	int am,i,choice;
	int ch;
	int j=0;
	char temp3[100];
	string temp4[100];char ini[100];int temp10;
			fp2=fopen("company1.txt","r");
			am=0;
			//cout<<1;
			while(fscanf(fp2,"%s%d",temp3,&temp10)!=EOF)
			{	//cout<<1;
				temp4[am]=temp3;

				//cout<<temp4[am]<<" ";
				strcpy(cmp[am].cmp_name,temp3);
				//cout<<company[am].name1<<" ";
				cmp[am].score=temp10;
					am++;
			}
			int flagg=0;
			//cout<<am;
			cout<<"*********************** Select one preferable option **********************"<<endl;
			cout<<endl;
			cout<<"1:Search the company"<<endl;
			cout<<"2:Select from the list"<<endl;
			int vg=am;
			am=0;
			cin>>choice;
			int xx;
			if(choice==2)
			{
				for(i=0;i<vg;i++)
				{
						cout<<am<<":"<<cmp[am].cmp_name<<endl;
						am++;
				}
				cout<<"Select your comapny"<<endl;
				cin>>xx;
				if(y>=cmp[xx].score)
				{
					cout<<"You are eligible for the interview in "<<cmp[xx].cmp_name<<endl;
				}
				else
				{
					cout<<"You are not eligible for this company"<<endl;
				}
			}
			else
			if(choice==1)
			{
				cout<<"enter the initial of company"<<endl;
				cin>>ini;
				while(flagg!=10)
				{
					kmp(ini,cmp[flagg].cmp_name,y);
					flagg++;
				}
			}
			int men;
			cout<<endl<<endl;
			cout<<"Want to go main menu, press 0";
			cin>>men;
			if(men==0)
			{
				system("cls");
				menu();
			}

}
/*end of jobbycompany  */



void merge(double *,int, int , int );
void mergesort(double *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }

    return;
}
void merge(double *a, int low, int high, int mid)
{
	double c[50];
    int i, j, k;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

	double applycat1()
	{
		//resume();
		/*calculating the points for the resume*/
	srand(time(NULL));
	double x=0;
	double y=0;
	if(emp[emp_count].experience==0)
		x=2;
	else
	x=(0.8*emp[emp_count].experience);
	//x=0.8*2;
	y=y+x;
	double q=0;
	//q=3*0.4;
	q=ma*0.4;
	y=y+q;
	double w=0;
	w=rand()%4+1;
	y=y+w;
	return y;
	//cout<<y;
	}
	void bsearch(double res_point,double temp_point[],int low,int high)
	{
		//cout<<res_point;
		int x=0;
		int index1=0;
		int index=0;
		int eligible=0;
		for(int i=low;i<=high;i++)
		{
			if(res_point>=temp_point[i])
			{
				eligible=1;
				if(x==0)
				{
					cout<<endl;
					cout<<"Category available is "<<cat[i/2].cname<<endl<<endl;
					x=1;
				}
				cout<<"the post which can be apply is "<<index1<<": "<<cat[i/2].cjob[index]<<endl;
				index++;
				index1++;
				if(index%2==0)
				{
					x=0;
					index=0;
				}
			}
		}
		if(eligible==0)
		{
			cout<<endl;
			cout<<"******* Sorry You are not eligible to apply for any company *******"<<endl;
			cout<<"              Your score did not meet the expectation              "<<endl;
		}
		else
		{
			/*NOW APPLY TO THE COMPANY ACCORDING TO THE NEED*/

			int cho;
			cout<<"*********CHOOSE ANY ONE POST TO APPLY***********"<<endl;
			cin>>cho;
			cout<<"Congrats, you are eligible for the interview"<<endl;
		}
		Sleep(5000);
		system("cls");
		menu();
	}

/* start of jobbycategory */

void jobbycategory()
{
	FILE *fp4,*fp5;
	char temp5[100];
	string temp6[100];
	int cc=0;
	int dd=0;
	fp4=fopen("category.txt","r");
	while(fscanf(fp4,"%s",temp5)!=EOF)
	{
		temp6[cc]=temp5;
		cat[cc].cname=temp6[cc];
		//cout<<cat[cc].cname<<" ";
		cc++;

	}
	int vgma=cc;
	double points;
	double temp_point[100];
	//cout<<endl;
	fp5=fopen("job.txt","r");
	cc=0;
	while(fscanf(fp5,"%s%lf",temp5,&points)!=EOF)
	{
		temp6[cc]=temp5;
		temp_point[cc]=points;
		cc++;
	}
	int valll;
	int vv=0; // for the category's job
	cc=0;   //for the category
	valll=1; //for the category
	while(valll<=5)
	{
		for(int i=0;i<2;i++)
		{
			cat[cc].cjob[i]=temp6[vv];
			cat[cc].cpoints[i]=temp_point[vv];
	//		cout<<cat[cc].cpoints[i]<<endl;
			vv++;
		}
		//vv++;
		cc++;
		valll++;
	}

	/*END OF READING*/

	/*sort all the ppoints of the category*/
	mergesort(temp_point,0,9);
	//for(int i=0;i<=9;i++)
	//cout<<temp_point[i]<<" ";
	applycat();
	double res_point=applycat1();
	system("cls");
	cout<<"*********************** Your Calculated Resume Point ***************************"<<endl;
	cout<<res_point<<endl;
	/* temporarily assign the points of resume this is testing.. will be done using original resume*/
	bsearch(res_point,temp_point,0,9);
}
/*end of jobbycategory*/



/* start of jobbylocation*/

void jobbylocation()
{
	  FILE *fp1,*fp2,*fp;;
        int n1,m1,k1,u1,v1,z1,i1,i2,src ,target;
        float l1,l2,lo1,lo2;
        struct edge e[11];
        struct n_e ne;

        fp = fopen("file1.dat","r");
        fp1 = fopen("file_edge.dat","r");
        fp2 = fopen("file_ne.dat","r");

        fread(&ne,sizeof(struct n_e),1,fp2);
        fread(&e,sizeof(struct edge),11,fp1);
        fread(&node,sizeof(struct node),10,fp);
       // cout<<"Enter number of nodes and Edges\n";
       // n1 = ne.n;  //vertices
        m1 = ne.e;   //edges

         int graph[V][V];

       for(i1=0;i1<V;i1++)
       {
           for(i2=0;i2<V;i2++)
           {
               graph[i1][i2] = 0;
           }
       }


      for(i1=0;i1<m1;i1++)
            {
                //cout<<"Information For Edge #"<<i1+1<<endl<<endl;

            u1 = e[i1].p1;
            //cout<<"Enter latitude for "<<u<<" ";
            l1 = e[i1].p1_lat;
             // cout<<"Enter longitude for "<<u<<" ";
            lo1 = e[i1].p1_lng;
                v1 = e[i1].p2;
            //cout<<"Enter latitude for "<<v<<" ";
            l2 = e[i1].p2_lat;
             // cout<<"Enter longitude for "<<v<<" ";
            lo2 = e[i1].p2_lng;
            z1=dist(lo1,l1,lo2,l2);
            //cout<<"Weight is "<<z1<<endl;
               graph[u1][v1] = z1;
               graph[v1][u1] = z1;

            //cout<<"            *Edge Added*            \n";
            }
            system("cls");
            cout<<endl;
	cout<<"Our Main Centre is Karol Bagh";
	cout<<endl;
   src = 0;
   cout<<"Enter the city from the given locations in which you want the job\n";
   for(int i=0;i<10;i++)
    {
        printf("%s %d\n",node[i].place,node[i].num);
    }
    cin>>target;
    dijkstra(graph, src,target);

    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    int vall;
    cout<<endl;
    cout<<"Want to go to main menu press 0"<<endl;
    cin>>vall;
    if(vall==0)
    {
    	system("cls");
    	menu();
	}
}
/*end of jobbylocation  */


/* driven menu*/
void menu()
{
    printf("Now select one option:\n");
	printf("1: Job By Category\n");
	printf("2: Job By Company\n");
	printf("3: Job By Location\n");
	printf("4: Job By Designation\n");
	printf("5: Logout\n");
	int ch;
	cin>>ch;
	if(ch==1)
		jobbycategory();
	if(ch==2)
		jobbycompany();
	if(ch==3)
		jobbylocation();
	if(ch==4)
		jobbydesignation();
	if(ch==5)
		logout();
}

void fun()
{
	int o;
	cout<<"Want admin login Press 1 else 0";
	cin>>o;
	if(o==1)
	adminlogin();
	else
    login();
}
/* main function  */
int main()
{
	r=(struct record_number *)malloc(sizeof(struct record_number));
	readcompany();
	fun();
return 0;
}


