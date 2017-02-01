#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz size()
#define x first
#define y second
#define forn(i, n) for(int i=0; i<(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;

string ffmpeg="C:\\ffmpeg-20150626-git-f1e1730-win64-static\\bin\\ffmpeg.exe";
string vidpath="C:\\Users\\User\\YandexDisk\\MGSU\\";

void printParams(string params)
{
	forn(i,params.size())
	{
		if(params[i]==' ')
		{
			cout <<endl;
			continue;
		}
		cout <<params[i];
	}
	cout <<endl;
}

cutVideo(string name)
{
	string params=ffmpeg+" -i "+vidpath+name+" ";
	//start time & length (hh:mm:ss)
	params+="-ss 00:01:39 -t 00:00:05 ";
	params+=vidpath+"Convert5s_"+name;
	
	cout <<"TO 5 sec\n"<<params<<endl;
	printParams(params);
	system(params.c_str());
}

makePics(string name)
{
	string params=ffmpeg+" -i "+vidpath+name+" ";
	//start time & length (hh:mm:ss)
	//params+="-ss 00:00:31 -t 00:00:05 ";
	
	//make new directory
	string dir=vidpath;
	forn(i,name.size())
	{
		if(name[i]=='.')
			break;
		dir+=name[i];
	}		
	dir+="_pics";
	system(string("mkdir "+dir).c_str());
	params+=dir+"\\images%06d.png";

	cout <<"TO pics\n"<<params<<endl;
	printParams(params);
	system(params.c_str());
}

makeSlow(string name)
{
	string params=ffmpeg+" -i "+vidpath+name+" ";
	//start time & length (hh:mm:ss)
	//params+="-ss 00:00:31 -t 00:00:05 ";
	
	params+="-r 24 -filter:v \"setpts=10.0*PTS\" ";
	params+=vidpath+"Slow_"+name;
	
	cout <<"TO slooow\n"<<params<<endl;
	printParams(params);
	system(params.c_str());
}

int main()
{
	//freopen("z.out","wt",stdout);
	cutVideo("YDXJ0219.mp4");
	makePics("Convert5s_YDXJ0219.mp4");
	makeSlow("Convert5s_YDXJ0219.mp4");
	return 0;
}
