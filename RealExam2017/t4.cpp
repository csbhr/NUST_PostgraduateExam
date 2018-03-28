#include<iostream>
#include<string>
#include<cmath>
#include<cctype>

using namespace std;

class  NumConversion{
	public:
		//十进制转为二进制
		static string TenToBin(long tenN){
			string binN="";
			while(tenN!=0){
				binN+=to_string(tenN%2);
				tenN=tenN/2; 
			}
			binN=NumConversion::strReverse(binN);
			return binN;
		}
		
		//十进制转为八进制 
		static string TenToOct(long tenN){
			string octN="";
			while(tenN!=0){
				octN+=to_string(tenN%8);
				tenN=tenN/8;
			}
			octN=NumConversion::strReverse(octN);
			return octN;
		}
		
		//十进制转为十六进制 
		static string TenToHex(long tenN){
			string hexN="";
			while(tenN!=0){
				long flag=tenN%16;
				if(flag==10){
					hexN+="A";
				}else if(flag==11){
					hexN+="B";
				}else if(flag==12){
					hexN+="C";
				}else if(flag==13){
					hexN+="D";
				}else if(flag==14){
					hexN+="E";
				}else if(flag==15){
					hexN+="F";
				}else{
					hexN+=to_string(flag);
				}
				tenN=tenN/16;
			}
			hexN=NumConversion::strReverse(hexN);
			return hexN;
		} 
		
		//二进制转为十进制 
		static long BinToTen(string binN){
			long tenN=0;
			for(int i=0;i<binN.size();i++){
				int flag=stoi(binN.substr(i,1));
				tenN+=flag*pow(2,binN.size()-i-1);
			} 
			return tenN;
		}
		
		//八进制转为十进制 
		static long OctToTen(string octN){
			long tenN=0;
			for(int i=0;i<octN.size();i++){
				int flag=stoi(octN.substr(i,1));
				tenN+=flag*pow(8,octN.size()-i-1);
			}
			return tenN;
		}
		
		//十六进制转为十进制 
		static long HexToTen(string hexN){
			for(char &c:hexN){
				c=toupper(c);
			}
			long tenN=0;
			for(int i=0;i<hexN.size();i++){
				string bu=hexN.substr(i,1);
				int flag;
				if(bu=="A"){
					flag=10;
				}else if(bu=="B"){
					flag=11;
				}else if(bu=="C"){
					flag=12;
				}else if(bu=="D"){
					flag=13;
				}else if(bu=="E"){
					flag=14;
				}else if(bu=="F"){
					flag=15;
				}else{
					flag=stoi(bu);
				}
				tenN+=flag*pow(16,hexN.size()-i-1);
			}
			return tenN;
		}
		
		//将字符串颠倒
		static string strReverse(string str){
			string strR=str;
			for(int i=str.size()-1,j=0;i>=0;i--,j++){
				strR[j]=str[i];
			}
			return strR;
		} 
};

int main(){
//	long tenN;
//	cin>>tenN;
//	string binN=NumConversion::TenToBin(tenN);
//	cout<<binN<<endl;
//	string octN=NumConversion::TenToOct(tenN);
//	cout<<octN<<endl;
//	string hexN=NumConversion::TenToHex(tenN);
//	cout<<hexN<<endl;
	string binN="1101";
	cout<<NumConversion::BinToTen(binN)<<endl;
	string octN="15";
	cout<<NumConversion::OctToTen(octN)<<endl;
	string hexN="fff";
	cout<<NumConversion::HexToTen(hexN)<<endl;
	return 0;
}
