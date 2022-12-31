#include<bits/stdc++.h>
using namespace std;

map<string,int> store_path;
string final_path="";
vector<pair<int,int>> vec_pair;




int solve_min_path(int row,int col,vector<vector<int>> &matrix,
int &cnt)
{
    //final_path=final_path+inter_path;
   // string path=to_string(row)+"-->"+to_string(col);
    //inter_path=path;
    int n=matrix.size();
    int m=matrix[0].size();
    
    //cnt++;
    if(row==n-1 && col==m-1)
    {
       cnt++;
        
        return matrix[row][col];
    }
    if(row>=n ||  col>=m)
    {
        return INT_MAX;
    }
    /*if(store_path.find(path)!=store_path.end())
    {
        cnt++;
        return store_path[path];
    }*/
    
    int left=solve_min_path(row+1,col,matrix,cnt);
    int right=solve_min_path(row,col+1,matrix,cnt);
  //  cnt++;
    return min(left,right)+matrix[row][col];
}

int solve_min_path_dp(int row,int col,vector<vector<int>> &matrix,
vector<vector<int>> &dp)
{
    //final_path=final_path+inter_path;
    //string path=to_string(row)+"-->"+to_string(col);
    //inter_path=path;
    int n=matrix.size();
    int m=matrix[0].size();
    
    //vis[row][col]=1;
    
    if(row==n-1 && col==m-1)
    {
        
        return dp[row][col]=matrix[row][col];
    }
    if(row>=n ||  col>=m)
    {
        return INT_MAX;
    }
    if(dp[row][col]!=-1)
    {
        return dp[row][col];
    }
    int left=solve_min_path_dp(row+1,col,matrix,dp);
    int right=solve_min_path_dp(row,col+1,matrix,dp);
    int mini=INT_MAX;
    
    mini=min(left,right);
    
   /* if (std::find(vec_pair.begin(), vec_pair.end(),make_pair(row,col)) != vec_pair.end() )
    {
        //we have arrived at the destination point.
    }
else
{
    if(mini==left)
    {
            vec_pair.push_back({row+1,col});

    }
    else
    {
            vec_pair.push_back({row,col+1});

    }
}*/
    return dp[row][col]=min(left,right)+matrix[row][col];
}

int main()
{
    cout<<"------------------------------Maze Game in C++--------------------------------"<<endl;
    int n,m,s,e;
    cout<<endl;
    cout<<"Enter the Dimensions of the Maze(N*M):\n";
    cout<<endl;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<"Enter the Start and End Range for filling the matrix with random Number in matrix:"<<endl;
    cin>>s>>e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            
         int rand_val=s+(rand()%(e-s+1));
        matrix[i][j]=rand_val; 
        }
        
    }
    cout<<"Loading......"<<endl;
    cout<<"The Contents of the maze are:\n";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           cout<<matrix[i][j]<<"|";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"-----------------------Rules in Maze Game---------------------------------------------"<<endl;
   
    int delay;
    cout<<"Loading................"<<endl;
    cout<<"Enter the time in seconds to be delayed:"<<flush;
    cin>>delay;
    delay *= CLOCKS_PER_SEC;
    clock_t now = clock();
    while(clock() - now <delay);
    cout<<"1.We can either move in Rightward or in Downward Direction.\n";
    cout<<"2.Entry Point is :(0,0)"<<"  Exit Point is :"<<"("<<n-1<<","<<m-1<<")"<<endl;
    cout<<"3.When we reach the Exit Point we are supposed to consider the Smallest Path Sum."<<endl;
    // cout<<""<<endl;
    // cout<<"Exit Point is :"<<"("<<n-1<<","<<m-1<<")"<<endl;
    int row=0,col=0;
     cout<<endl;
    
    //vec_pair.push_back({0,0});

   // int res=solve_min_path(row,col,matrix);
 //  cout<<"Shortest Path Sum:"<<res<<endl;
   
    cout<<"--------------------------------------------------------------------------------------"<<endl;

    

    cout<<"Normal Solution along with Time Tracking Approach:"<<endl;
    cout<<endl;
    cout<<"Shortest Path from entry Point to exit Point is : \n"<<endl;
    int cnt=0; 
    cout<<endl;
    clock_t start, end;
    start = clock();
    int res=solve_min_path(row,col,matrix,cnt);
    end = clock();
    cout<<"Shortest Path Sum is: "<<res<<endl;
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken;
    cout << " secs " << endl;
    
    cout<<"--------------------------------------------------------------------------------------"<<endl;

    
    cout<<"Optimization Done Through Dynamic Programming along with Time Tracking Approach:\n"<<endl;
    cout<<"Shortest Path from entry Point to exit Point is : \n"<<endl;
    cout<<endl;
    clock_t start1, end1;
    start1 = clock();
    int dp_res=solve_min_path_dp(row,col,matrix,dp);
    end1 = clock();
    cout<<"Shortest Path Sum is: "<<dp_res<<endl;
    cout<<endl;
    double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : "  << fixed<< time_taken1;
    cout << " secs " << endl;
    cout<<endl;
    
    cout<<"--------------------------------------------------------------------------------------"<<endl;

    
    cout<<"The Conclusion is Loading....."<<endl;
    int delay1;
    cout<<"Enter the time in seconds to be delayed:"<<flush;
    
    cout<<endl;
    cin>>delay1;
    delay1 *= CLOCKS_PER_SEC;
    clock_t now1 = clock();
    while(clock() - now1 <delay1);
    cout<<"Conclusion"<<endl;
    cout<<endl;
    cout<<"Optimization with Dynamic Programming helps us to Arrive at Solution within a smaller period of time"<<endl;
    cout<<endl;
    cout<<"We have Achieved Rduction in Time Using Memoization Technique in Dynamic Programming."<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;

    return 0;
}