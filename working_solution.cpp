#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool find_A(vector <string>,int&,int&);
string path(vector <string>,int,int);
bool is_valid(vector <string>,int,int);
class ABCPath{
	public:
		int length(vector <string> grid)
		{
			int i=0,j=0;
			vector<int> ret;
			while(find_A(grid,i,j))
			{
				string str=path(grid,i,j);
				cout<<str<<endl;
				ret.push_back(str.size());
			}
			if(ret.size()==0)
				return 0;
			int largest=ret[0];
			for(i=0;i<ret.size();++i)
			{
				if(ret[i]>largest)
					largest=ret[i];
			}
			return largest;
		}	
};
int main()
{
	vector <string> grid={ "ABC",
    					   "ADP",
    					   "LGE",
    					   "NAF" };
    ABCPath obj;
    cout<<"The grid is as\n";
    for(auto i=0;i<grid.size();++i)
    {
    	for(auto j=0;j<grid[i].size();++j)
    		cout<<grid[i][j];
    	cout<<"\n";
	}
    cout<<"The longest path is "<<obj.length(grid);
    return 0;
}
bool find_A(vector <string> grid,int& a,int& b)
{
	static int i,j;
	for(;i<grid.size();++i,j=0)
	{
		for(;j<grid[i].size();++j)
		{
		 	if(grid[i][j]=='A')
		 	{
		 		a=i;
		 		b=j++;
		 		return true;
			}
		}
	}
	return false;
}
string path(vector <string> grid,int i,int j)
{
	if(!is_valid(grid,i,j))
		return 0;
	string Path;
	if(i>0 && grid[i-1][j]==(grid[i][j]+1))
		Path=path(grid,i-1,j);
	if(i<(grid.size()-1) && grid[i+1][j]==(grid[i][j]+1))
		Path=path(grid,i+1,j);
	if(j<(grid[i].size()-1) && grid[i][j+1]==(grid[i][j]+1))
		Path=path(grid,i,j+1);
	if(j>0 && grid[i][j-1]==(grid[i][j]+1))
		Path=path(grid,i,j-1);
	if(i<(grid.size()-1)&&j<(grid[i].size()-1) && grid[i+1][j+1]==(grid[i][j]+1))
		Path=path(grid,i+1,j+1);
	if(i>0 && j>0 && grid[i-1][j-1]==(grid[i][j]+1))
		Path=path(grid,i-1,j-1);
	if(i>0 && j<(grid[i].size()-1) && grid[i-1][j+1]==(grid[i][j]+1))
		Path=path(grid,i-1,j+1);
	if(i<(grid.size()-1) && j>0 && grid[i+1][j-1]==(grid[i][j]+1))
		Path=path(grid,i+1,j-1);
	return grid[i][j]+Path;
}
bool is_valid(vector <string> grid,int i,int j)
{
	return (i>=0 && i<grid.size() && j>=0 && j<grid[i].size());
}
