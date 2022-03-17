//You should change the *user_name* with your username





#ifndef arithmeticOperations_h
#define arithmeticOperations_h

#include <iostream>
#include<fstream>
using namespace std;

int temp=0;
int temp2=0;
int increment = 0;
int increment2=0;
int arrays=0;

string aggregation(string biggernumber, string smallernumber,int size, int size2);

void multipication(string maindata1,string maindata2, int size1,int size2){
    string result[maindata2.length()+1];
    int main_array[maindata2.length()][maindata1.length()+1];
    for(int i=0;i<size2;++i){
        for( int j=0;j<size1+1;j++){
            main_array[i][j]=-1;
        }
    }

    
    int arrays_numbers=size1;


    increment = 0;
    for(int j=size2-1;j>=0;j--){
       
        for(int i=size1-1;i>=0;i--){
            temp = (maindata1[i]-48)*( maindata2[j] - 48);

            temp2 = (increment+temp)%10;

           
            main_array[arrays][arrays_numbers]=temp2;
            arrays_numbers--;
            increment = (temp+increment)/10;
            
        }
        if(increment>0){
            
            main_array[arrays][arrays_numbers]=increment;
            
        }
        arrays_numbers=size1;
        arrays++;
        temp=0;
        temp2=0;
        increment = 0;

    }
    int control=0;
    
    fstream File;

    File.open("/Users/*user_name*/Desktop/textfile2.txt",ios::out);
    if(File.is_open()){
        
    
    for(int i=0;i<arrays;++i){

            for(int j=0;j<=size1;j++){
            
                if(main_array[i][j]<10 && main_array[i][j]>0){
                    control=1;
                }
                if(main_array[i][j]<10 && main_array[i][j]>=0 && control!=0){
                    File<<main_array[i][j];
                }
            
            
            }
            control=0;
            File<<endl;
        }
    }
    
    File.close();
    File.open("/Users/*user_name*/Desktop/textfile2.txt",ios::in);
    int string_counter=0;
    if(File.is_open()){
        
        while(getline(File,result[string_counter])){
           
            string_counter++;
        }
    }
    File.close();
    string temp=result[0];
    string zero = "0";
    for(int i=1;i<string_counter;++i){
        for(int j=1;j<=i;++j){
            result[i]=result[i]+zero;
        }
        
        if(temp.length()>result[i].length()){
            temp=aggregation(temp, result[i], temp.length(), result[i].length());
            
        }
        else{
            temp=aggregation(result[i],temp, result[i].length(),temp.length());
        }
    }
    cout<<temp;

    
    
    
    
}
string aggregation(string biggernumber, string smallernumber,int size, int size2){
    fstream File;
    File.open("/Users/*user_name*/Desktop/textfile3.txt",ios::out);
    File.close();
    increment=0;
    int main_array2[size+1];
    int difference=size-size2;
    arrays=size;
    for(int i=size-1;i>=0;--i){
        
        if(i-difference<0)
            temp=biggernumber[i]-48;

        else
            temp=biggernumber[i]+smallernumber[i-difference]-96;
        
        temp2=(increment+temp)%10;
        main_array2[arrays]=temp2;
        arrays--;
        increment=(temp+increment)/10;
        
    }
    
    if(increment>0){
        main_array2[arrays]=increment;
    }
    int control=0;

    File.open("/Users/*user_name*/Desktop/textfile3.txt",ios::out);
    if(File.is_open()){
        for(int i=0;i<=size;++i){
            if(main_array2[i]<10 && main_array2[i]>0)
                control=2;
            
             if(control!=0 && main_array2[i]<10 && main_array2[i]>=0){
                File<<main_array2[i];
            }
          
        }
    }
    string result;
    File.close();
    File.open("/Users/*user_name*/Desktop/textfile3.txt",ios::in);
    if(File.is_open()){
        getline(File,result);
    }
    return result;
}


#endif /* arithmeticOperations_h */
