#include <iostream>
#include <math.h>
using namespace std;

//this is the introduction menu.
void Menu(int *typenumber, int *operation, int *suboperation){
  cout<<"First especify your type number."<<endl;
  cout<<"1 - Bin // 2 - Oct // 3 - Dec // 4 - Hex"<<endl;
  cout<<"Especify number type: ";
  cin>>*typenumber;
  cout<<"                    Welcome to the Calculator               "<<endl;
  cout<<"------------------------------MENU------------------------------"<<endl;
  cout<<"-------------------------Basic Operations-----------------------"<<endl;
  cout<<"------------1 - (+) // 2 - (-) // 3 - (*) // 4 - (/)------------"<<endl;
  cout<<"------------------------Especial Operations---------------------"<<endl;
  cout<<"1 - (--> bin) // 2 - (--> oct) // 3 - (--> dec) // 4 - (--> hex)"<<endl;
  cout<<"Basic operations(1) or especial operations(2) ?: ";
  cin>>*operation;
  cout<<"Type your suboperation: ";
  cin>>*suboperation;
};

//this is the function responsible for translating octal base into decimal base.
int octtodec(int *number, bool *base){
  int i, oct, decimal0, z = 0, index = 0;
  oct = *number;
  cout<<"Now, how many digits he are: ";
  cin>>i;
  while (i >= 1){
    z = (*number%10);
    *number/=10;
    decimal0 += z*(pow(8, index));
    index++;
    --i;
  };
  if(*base==true)
    cout<<"Your number in decimal base -> "<<decimal0<<endl;
    
  return(decimal0);
};

//this is the function responsible for translating decimal base into octal base.
void dectooct(int *number){
  int i, j, octvector[32];
  i = 0;
  while(*number>0){
    octvector[i]=(*number%8);
    *number /= 8;
    i++;
  };
  cout<<"Your number in octal: ";
  for(j=i-1;j>=0;j--)
    cout<<octvector[j];

  cout<<endl;
};

//this is the function responsible for translating binary base into decimal base.
int bintodec(int *number, bool *base){
  int i, bin, decimal0, z = 0, index = 0;
  bin = *number;
  cout<<"Now, how many digits he are: ";
  cin>>i;
  while (i >= 1){
    z = (*number%10);
    *number/=10;
    decimal0 += z*(pow(2, index));
    index++;
    --i;
  };
  if(*base==true)
    cout<<"Your number in decimal base -> "<<decimal0<<endl;
  
    return(decimal0);
};

//this is the function responsible for translating deciaml base into binary base.
void dectobin(int *number){
  int i, j, binaryvector[32];
  i = 0;
  while(*number>0){
    binaryvector[i]=(*number%2);
    *number /= 2;
    i++;
  };
  cout<<"Your number in binary: ";
  for(j=i-1;j>=0;j--)
    cout<<binaryvector[j];

  cout<<endl;
};

//this is the function responsible for translating hex base into decimal base.
int hextodec(char hexnumber[], bool *base1) {
  int size = strlen(hexnumber); 
  // Initializing base value to 1, i.e 16^0 
  int base = 1, dec = 0; 
  // Extracting characters as digits from last character 
  for (int i=size-1; i>=0; i--) {    
    // if character lies in '0'-'9', converting  
    // it to integral 0-9 by subtracting 48 from 
    // ASCII value. 
    if (hexnumber[i]>='0' && hexnumber[i]<='9'){ 
      dec += (hexnumber[i] - 48)*base; 
                 
      // incrementing base by power 
      base = base * 16; 
    }
    // if character lies in 'A'-'F' , converting  
    // it to integral 10 - 15 by subtracting 55  
    // from ASCII value 
    else if (hexnumber[i]>='A' && hexnumber[i]<='F'){ 
          dec += (hexnumber[i] - 55)*base; 
          
          // incrementing base by power 
          base = base*16; 
        } 
    };
    if(*base1==true)
      cout<<"Your number in decimal: "<<dec<<endl;

    return(dec);
};

//this is the function responsible for translating decimal base into hex base.
void dectohex(int *number){
  char hexvalue[32];
  int i, j;
  i = 0;
  while(*number>0){
    hexvalue[i]=(*number%16);
    if(hexvalue[i]>=(0) && hexvalue[i]<=(9)){
      hexvalue[i] = (hexvalue[i] + 48);
    }
    else if (hexvalue[i]>=10 && hexvalue[i]<=15){ 
          hexvalue[i] = (hexvalue[i] + 55);  
         };
    *number /= 16;
    i++;
  };
    cout<<"Your number in hexadecimal: ";
    for(j=i-1;j>=0;j--)
      cout<<hexvalue[j];

  cout<<endl;
}

//this function is responsible for all operations involving the octal base.
void OctalMenu(int *number, int *operation, int *suboperation, int *Num, bool *base){
  cout<<"Type the octal number: ";
  cin>>*number;
  if(*operation==1){
    switch(*suboperation){
      case(1): //adiction
        cout<<"Enter the other number you want to add (this number in octal*): ";
        cin>>*Num;
        cout<<(*number + *Num)<<endl;
      break;
      case(2): //substract
        cout<<"Enter the other number you want to substract (this number in octal*): ";
        cin>>*Num;
        cout<<(*number - *Num)<<endl;
      break;
      case(3): //multiply
        cout<<"Enter the other number you want to multiply (this number in octal*): ";
        cin>>*Num;
        cout<<(*number * *Num)<<endl;
      break;
      case(4): //div
        cout<<"Enter the other number you want to divide (this number in octal*): ";
        cin>>*Num;
        cout<<(*number / *Num)<<endl;
      break; 
    }
  }else if(*operation==2){
          switch(*suboperation){
            case(1):
              *base = !true;
              *Num = octtodec(number, base);
              dectobin(Num);
            break;
            case(2):
              cout<<"Your number is already in octal"<<endl;
            break;
            case(3):
              *base = true;
              *Num = octtodec(number, base);
            break;
            case(4):
              *base = !true;
              *Num = octtodec(number, base);
              dectohex(Num);
            break;
          };
        }else cout<<"Type one valid operation"<<endl;
};

void DecMenu(int *number, int *operation, int *suboperation, int *Num){
  cout<<"Type the decimal number: ";
  cin>>*number;
  if(*operation==1){
    switch(*suboperation){
      case(1): // addition
        cout<<"Enter the other number you want to add (this number in decimal*): ";
        cin>>*Num;
        cout<<(*number + *Num)<<endl;
      break;
      case(2): //substract
        cout<<"Enter the other number you want to substract (this number in decimal*): ";
        cin>>*Num;
        cout<<(*number - *Num)<<endl;
      break;
      case(3): //multiply
        cout<<"Enter the other number you want to multiply (this number in decimal*): ";
        cin>>*Num;
        cout<<(*number * *Num)<<endl;
      break;
      case(4): //div
        cout<<"Enter the other number you want to divide (this number in decimal*): ";
        cin>>*Num;
        cout<<(*number / *Num)<<endl;
      break;
    }
  }else if(*operation==2){
          switch(*suboperation){
            case(1):
              dectobin(number);
            break;
            case(2):
              dectooct(number);
            break;
            case(3):
              cout<<"Your number is already in decimal"<<endl;
            break;
            case(4):
              dectohex(number);
            break;
          };
        }else cout<<"Type onde valid operation"<<endl;
};

void BinMenu(int *number, int *operation, int *suboperation, int *Num, bool *base){
  cout<<"Type the binary number: ";
  cin>>*number;
  if(*operation==1){
    switch(*suboperation){
      case(1): // addition
        cout<<"Enter the other number you want to add (this number in binary*): ";
        cin>>*Num;
        cout<<(*number + *Num)<<endl;
      break;
      case(2): //substract
        cout<<"Enter the other number you want to substract (this number in binary*): ";
        cin>>*Num;
        cout<<(*number - *Num)<<endl;
      break;
      case(3): //multiply
        cout<<"Enter the other number you want to multiply (this number in binary*): ";
        cin>>*Num;
        cout<<(*number * *Num)<<endl;
      break;
      case(4): //div
        cout<<"Enter the other number you want to divide (this number in binary*): ";
        cin>>*Num;
        cout<<(*number / *Num)<<endl;
      break;
    }
  }else if(*operation==2){
          switch(*suboperation){
            case(1):
              cout<<"Your number is already in binary"<<endl;
            break;
            case(2):
              *base = !true;
              *Num = bintodec(number, base);
              dectooct(Num);
            break;
            case(3):
              *base = true;
              bintodec(number, base);
            break;
            case(4):
              *base = !true;
              *Num = bintodec(number, base);
              dectohex(Num);
            break;
          };
        }else cout<<"Type onde valid operation"<<endl;
};

void HexMenu(char hexnumber[], int *operation, int *suboperation, int *Num, bool *base){
  cout<<"Type the Hexadecimal number: ";
  cin>>hexnumber;
  if(*operation==1){
    switch(*suboperation){
      case(1): // addition
        cout<<"Enter the other number you want to add (this number in hexadecimal*): ";
        cin>>*Num;
        //cout<<(*hexnumber + *Num)<<endl;
      break;
      case(2): //substract
        cout<<"Enter the other number you want to substract (this number in hexadecimal*): ";
        cin>>*Num;
        //cout<<(*hexnumber - *Num)<<endl;
      break;
      case(3): //multiply
        cout<<"Enter the other number you want to multiply (this number in hexadecimal*): ";
        cin>>*Num;
        //cout<<(*hexnumber * *Num)<<endl;
      break;
      case(4): //div
        cout<<"Enter the other number you want to divide (this number in hexadecimal*): ";
        cin>>*Num;
        //cout<<(*hexnumber / *Num)<<endl;
      break;
    }
  }else if(*operation==2){
          switch(*suboperation){
            case(1):
              *base = !true;
              *Num = hextodec(hexnumber, base);
              dectobin(Num);
            break;
            case(2):
              *base = !true;
              *Num = hextodec(hexnumber, base);
              dectooct(Num);
            break;
            case(3):
              *base = true;
              hextodec(hexnumber, base);
            break;
            case(4):
              cout<<"Your number is already in hexadecimal."<<endl;
            break;
          };
        }else cout<<"Type onde valid operation"<<endl;
};

int main(){
  int Num, number, typenumber, operation, suboperation;
  char hexnumber[32], loop;
  bool base;
  do{
    Menu(&typenumber, &operation, &suboperation);
    switch(typenumber){
      case(1):
        BinMenu(&number, &operation, &suboperation, &Num, &base);
      break;
      case(2):
        OctalMenu(&number, &operation, &suboperation, &Num, &base);
      break;
      case(3):
        DecMenu(&number, &operation, &suboperation, &Num);
      break;
      case(4):
        HexMenu(hexnumber, &operation, &suboperation, &Num, &base);
      break;
    };
    cout<<"Do you want to make any more operations? [S/N]";
    cin>>loop;
    if(loop=='S'||loop=='s')
      system("clear");
    
  }while(loop=='S'||loop=='s');
  system("clear");
  
  return(0);
};
