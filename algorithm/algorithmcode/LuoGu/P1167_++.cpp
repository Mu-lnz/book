#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int monthlist[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};
int n;
int key[1000000];
int ans;
int year1,year2;
int month1,month2;
int day1,day2;
int hour1,hour2; 
int minute1,minute2;
int sumrun;//两个年份内有多少个闰年。  
int time1,time2,time3;//time3，两天差
int time4;//计算两天的小时差 
int time5;//计算两天的分差 
int time6;//计算两天之间的时间差（分钟） 
int isrun(int year);

int main(){
	cin>>n;
	for(int x=0;x<n;x++)
	cin>>key[x];
	sort(key,key+n);
	scanf("%d-%d-%d-%d:%d",&year1,&month1,&day1,&hour1,&minute1);
	scanf("%d-%d-%d-%d:%d",&year2,&month2,&day2,&hour2,&minute2);
	
	//不管两头年份，计算其中间有多少个闰年 
	for(int x=year1+1;x<year2;x++){
		if(isrun(x))
		sumrun++;
	}
	//回归到该年1月1日 
	for(int x=1;x<=month1;x++){
		time1+=monthlist[x];
		if(isrun(year1)&&x==2)
		time1++; 
	} 
	for(int x=1;x<=month2;x++){
		time2+=monthlist[x];
		if(isrun(year2)&&x==2)
		time2++;
	} 
	
	time1-=monthlist[month1]-day1;//本年剩余天数 
	time2-=monthlist[month2]-day2;
	time3=(year2-year1)*365+sumrun+time2-time1;//两年不算头尾的日子差 
    cout<<time3<<endl;
	time4=hour2-hour1;//两天的小时差 
	time5=minute2-minute1;//两天的分差 
	time6=time3*24*60+time4*60+time5; //计算两天的时间差（分钟）
    cout<<time6<<endl;
	for(int x=0;x<n;x++){
		if(time6-key[x]>=0){
			time6-=key[x];
			ans++; 
		}
		else break;
	}
	cout<<ans<<endl;
	return 0;
}
int isrun(int year){
	if(year%400==0) return 1;
	else if(year%100!=0&&year%4==0)return 1;
	else return 0;
}