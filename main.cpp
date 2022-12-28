#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

// global key to decrypt message
int key[58];
int main()
{
//int c=0XEF;
//int b=0XBD;

 // key array to store key value when we get them





        string     sentences[8];

        sentences[0]="68AF0BEF7F39982DA975B5E6D06947E61C22748C94A2155CFCCC464DEAFB6F4844DB2D7312ED192B6B7251580C61D5A296964E824A16648B16B9";
        sentences[1]="70A20FBD7E209324A979BFE2997A46E61B22749692EB1655FA995D46A9FA654F43C93F2114A21E3E227714580A6790B88BD74F9E09107D8B0EAC";
        sentences[2]="6FA20DBA622CDD28EC68F0F0C16D41A7023778C29EB8455EFC894B46EDA96C46459E2D2A1CEF1239707F571604618CEB9DD85E955013628B0DAE";
        sentences[3]="6FA20DBA6220893AA970A4B5CD664CE609286D8799B80010F68A0F56FAE868405BD72A2A51E118386E7214520E6994AC9D964E824A16648B16B9";
        sentences[4]="71A80AAA6227DD20FB68A0E1D6695BA71C3864C285AE1445F09E4A50A9EA6B5B52D82B3F51E3192922645D5100769ABE8B965C89480F6F910BB3";
        sentences[5]="7DA30ABD753A8E63FB70BEF1D66340BC0D24748D99EB065FEC804B03F9FB6F5F52D02A731CE31B24617F5B431C2496AA94DA1D865D17778109B3";
        sentences[6]="75B34EA66369932CFD31A0E7D86D5DAF0F3171C283A44542FC805603FAE6664C5BC77E3C1FA204346F7B51421D6D96EB9DD85E955013628B0DAE";
        sentences[7]="75E71DA771259163E774A6F0CB2E5BA3192378C283A30010EA8D4246A9F96B5A44C9312115A21823227B415A1B6D85A79D965C844A0C638C16B3";
        int space=0X20;
        // these are the characters that are most likely to be fount in the plain text saved in tokens array i can just put the whole alphabet
        vector <int> tokens={0x20};
        int x;
        int y;
        string temp;
        int counter=0;

for(int m=0;m<tokens.size();m++){


    for(int i=0; i<8 ;i++){





        for(int j=0 ;j<116;j+=2){


            temp=sentences[i].substr(j,2); // looping through the words of each sentence to check if its  a space

            for(int k=0;k<8;k++){


                if(k!=i){

                  std::stringstream m1;
                  std::stringstream m2;
                  m1 << std::hex << temp;
                  m2 << std::hex <<sentences[k].substr(j,2);
                  m1 >> x;
                  m2 >> y;
                  int flag=(x^y)^tokens[m];
                 // cout<<flag<<endl;
                  if ((flag >=97 && flag<=122 )| flag==tokens[m]){
                    counter ++;
                  }else{
                  counter=0;
                  break;
                  }

                }

            }
            if(counter == 0){

            }
            else if(counter>6){
                    key[(j/2)]=(x^tokens[m]);         // getting part of the key

            }

        }







    }

// new token to find other keys
}
 // decryption using key

for (int i=0;i<8;i++){
for(int j=0 ;j<116;j+=2){

            temp=sentences[i].substr(j,2);
            std::stringstream m1;
            std::stringstream m2;
            m1 << std::hex << temp;
            m2 << std::hex <<key[j/2];
            m1 >> x;
            m2 >> y;
            if(key[j/2]){
            char letter=char((x^y));  // casting ascii  to character to print sentences
            cout<<letter;
            }else{
            cout<<"?";}                // i do not know this yet


}
cout<<endl;
}

// hard coding the rest :)

cout<<endl;
cout<<"************************************************************************************************************************"<<endl;
cout<<"i can easily guess the words now and get the key for the remaining locations as at least i know a letter in any sentence in each location"<<endl;
// hard coding the rest of the key XD

key[0]=0x75^0x69;   // last sentence must begin with i
key[4]=0x7f^0x6f;    // the word open
key[14]=0x47^0x6e;    // the word design
key[16]=0x1c^0x70;   // the word principle
key[17]=0x22^0x72;   // the word principle
key[18]=0x74^0x69;   // the word principle
key[20]=0x94^0x63;   // the word principle
key[24]=0xfc^0x65;     // principle
key[30]=0x65^0x6f;       // the word software in second sentence
key[31]=0x4f^0x66;
key[32]=0x43^0x74;
key[38]=0x12^0x65;         //the word symmetric in 3rd sentence
key[39]=0x39^0x74;
key[41]=0x7f^0x69;         // the followinfg word is key
key[44]=0x04^0x6b;
key[48]=0x9d^0x65;          // the word encryption
key[51]=0x95^0x72;
key[53]=0x13^0x70;
key[54]=0x62^0x74;
key[55]=0x8b^0x69;
key[56]=0x0d^0x6f;
key[57]=0xae^0x6e;



for (int i=0;i<8;i++){
for(int j=0 ;j<116;j+=2){

            temp=sentences[i].substr(j,2);
            std::stringstream m1;
            std::stringstream m2;
            m1 << std::hex << temp;
            m2 << std::hex <<key[j/2];
            m1 >> x;
            m2 >> y;
            if(key[j/2]){
            char letter=char((x^y));  // casting ascii  to character to print sentences
            cout<<letter;
            }else{
            cout<<"?";}                // i do not know this yet


}
cout<<endl;
}

}
