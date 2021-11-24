 #include <bits/stdc++.h>
 using namespace std;
 //1000000 represents infinity
 int vertices=7;
 int arr[7][7]={{1000000,6,5,5,1000000,1000000,1000000},
{1000000,1000000,1000000,1000000,-1,1000000,1000000},
{1000000,-2,1000000,1000000,1,1000000,1000000},
{1000000,1000000,-2,1000000,1000000,-1,1000000},
{1000000,1000000,1000000,1000000,1000000,1000000,3},
{1000000,1000000,1000000,1000000,1000000,1000000,3},
{1000000,1000000,1000000,1000000,1000000,1000000,1000000}};

void bellmanFord(int edge[][2],int o){
    int distance[vertices];
    int previous[vertices];
    for(int i=0;i<vertices;i++){
        distance[i]=1000000;
        previous[i]=0;
    }
    distance[0]=0;
    int temp,ll=0;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<o;j++){
            temp=distance[edge[j][0]]+arr[edge[j][0]][edge[j][1]];
            if (temp<distance[edge[j][1]]){
                distance[edge[j][1]]=temp;
                previous[edge[j][1]]=edge[j][0];
                ll+=1;
            }
        }
    }
    for(int j=0;j<o;j++){
            if (distance[edge[j][0]]+arr[edge[j][0]][edge[j][1]]<distance[edge[j][1]]){
                cout << "Negative Cycle exists"<< endl;
                exit(0);
                break;
            }
    }
    cout << "Vertex" << "  Distance" << endl;
    for(int i=0;i<vertices;i++){
        cout << "  "<< i+1 << "        " <<distance[i] << "  " <<endl;
    }
 }

 int main()
 {
    //int vertices;
    /*cout << "Enter Total Number of Vertices : ";
    cin >> vertices;*/
    //vertices=7;

    int edge[vertices][2];
    int o=0;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            if ((arr[i][j])!=1000000){
                edge[o][0]=i;
                edge[o][1]=j;
                o++;
            }
        }
    }
    /*for(int i=0;i<o-1;i++){
        cout << edge[i][0] << " " << edge[i][1] << endl;
    }*/
    bellmanFord(edge,o-1);

 }
